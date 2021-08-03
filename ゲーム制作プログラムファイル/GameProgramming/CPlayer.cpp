//プレイヤークラスのインクルード
#include "CPlayer.h"
//キー入力クラスのインクルード
#include "CKey.h"

#include "CTaskManager.h"
#include "CCollisionManager.h"
#include "CUtil.h"

#define GRAVITY 0.15  //重力
#define JUMPPOWER 5.0  //ジャンプ力

int mClearTime = 0; //リザルトに表示するクリアタイムを渡すための変数

CPlayer::CPlayer()
:mLine(this, &mMatrix, CVector(0.0f, 0.0f, -5.0f), CVector(0.0f, 0.0f, 5.0f))
, mLine2(this, &mMatrix, CVector(0.0f, 5.0f, 0.0f), CVector(0.0f, -3.0f, 0.0f))
, mLine3(this, &mMatrix, CVector(5.0f, 0.0f, 0.0f), CVector(-5.0f, 0.0f, 0.0f))
,mCollider(this, &mMatrix, CVector(0.0f, 0.0f, 0.0f), 0.5f)
, mJpspeed(0), mJump(false), mTime(0), mCount(0)
{
	//テクスチャファイルの読み込み(1行64列)
	mText.LoadTexture("FontWhite.tga", 1, 64);
	mTag = EPLAYER; //タグの設定
	CPlayer::mEnabled = true;
}

//更新処理
void CPlayer::Update(){
	//Aキー入力で回転
	if (CKey::Push('A')){
		//Y軸の回転値を増加
		mRotation.mY += 1;
	}
	//Dキー入力で回転
	if (CKey::Push('D')){
		//Y軸の回転値を増加
		mRotation.mY -= 1;
	}
	//上矢印キー入力で前進
	if (CKey::Push(VK_UP)){
		//Z軸方向に1進んだ値を回転移動させる
		mPosition = CVector(0.0f, 0.0f, 1.0f)*mMatrix;
	}
	//Sキー入力で上向き
	if (CKey::Push('S')){
		//X軸の回転値を減算
		mRotation.mX -= 1;
	}
	//Wキー入力で下向き
	if (CKey::Push('W')){
		//X軸の回転値を加算
		mRotation.mX += 1;
	}
	//キー入力でジャンプ
	if (CKey::Once(' ') && mJump==false){
		mJpspeed += JUMPPOWER;
		mJump = true;
	}
	//ジャンプの力を加算
	if (mJump == true){
		mPosition.mZ -= 0.3f;
		mJpspeed -= GRAVITY;
		mPosition.mY += mJpspeed;
	}

	//重力を設定
	if (mJump==false){
	mPosition.mY -= GRAVITY;
	}

	//時間を計測
	if (mCount < 60){
		mCount++;
	}
	else{
		mTime++;
		mCount = 0;
	}
	//クリアタイムを渡す
	mClearTime = mTime;

	//CCharacterの更新
	CTransform::Update();

}

void CPlayer::Collision(CCollider*m, CCollider*o){
	//自身のコライダタイプの判定
	switch (m->mType){
	case CCollider::ELINE://線分コライダ
		//相手のコライダが三角コライダの時
		if (o->mType == CCollider::ETRIANGLE){
			CVector adjust;//調整用ベクトル
			//三角形と線分の衝突判定
			CCollider::CollisionTriangleLine(o, m, &adjust);
			//位置の更新(mPosition+adjust)
			mPosition = mPosition - adjust*-1;
			//行列の更新
			CTransform::Update();
			//着地処理
			mJump = false;
			mJpspeed = 0;
		}
		break;
	case CCollider::ESPHERE://球コライダ
		//相手のコライダが三角コライダの時
		if (o->mType == CCollider::ETRIANGLE){
			CVector adjust;//調整用ベクトル
			//相手がゴールのコライダの場合
			if (o->mTag == EGOAL){
				//衝突しているか判定
				if(CCollider::CollisionTriangleSphere(o, m, &adjust)){
					//衝突しない位置まで戻す
					mPosition = mPosition - adjust*-1;
					CPlayer::mEnabled=false;
				}
			}
			//相手が壁のコライダの場合
			if (o->mTag == EMAP){
				//衝突しているか判定
				if (CCollider::CollisionTriangleSphere(o, m, &adjust)){
					//衝突しない位置まで戻す
					mPosition = mPosition - adjust*-1;
				}
			}
			//相手が床のコライダの場合
			if (o->mTag == EFLOOR){
				//衝突しているか判定
				if (CCollider::CollisionTriangleSphere(o, m, &adjust)){
					//衝突しない位置まで戻す
					mPosition = mPosition - adjust*-1;
				}
			}
		}
		break;
	}
}

//衝突処理
void CPlayer::TaskCollision()
{
	//コライダの優先度変更
	mLine.ChangePriority();
	mLine2.ChangePriority();
	mLine3.ChangePriority();

	mCollider.ChangePriority();

	//衝突処理を実行
	CCollisionManager::Get()->Collision(&mLine, COLLISIONRANGE);
	CCollisionManager::Get()->Collision(&mLine2, COLLISIONRANGE);
	CCollisionManager::Get()->Collision(&mLine3, COLLISIONRANGE);
}

void CPlayer::Render()
{
	//親の描画処理
	CCharacter::Render();

	//2Dの描画開始
	CUtil::Start2D(-400, 400, -300, 300);
	//描画側の設定(緑色の半透明)
	glColor4f(0.0f, 1.0f, 0.0f, 0.7f);
	//文字列編集エリアの作成
	char buf[64];
	sprintf_s(buf, "TIME:%dS", mTime);
	//文字列の描画
	mText.DrawString(buf, 280, 270, 8, 16);
	//2Dの描画終了
	CUtil::End2D();
}