#include "CEnemy2.h"
#include "CTaskManager.h"
#include "CEffect.h"
#include "CCollisionManager.h"
#include "CBullet.h"

#define OBJ "f16.obj" //モデルのファイル
#define MTL "f16.mtl" //モデルのマテリアルファイル
#define HP 3 //耐久値

CModel CEnemy2::mModel; //モデルデータの作成

//デフォルトコンストラクタ
CEnemy2::CEnemy2()
:mCollider(this, &mMatrix, CVector(0.0f, 0.0f, 0.0f), 0.4f)
, mColSearch(this, &mMatrix, CVector(0.0f, 0.0f, 100.0f), 30.0f)
, mpPlayer(0)
, mHp(HP)
{
	//モデルがないときは読み込む
	if (mModel.mTriangles.size() == 0)
	{
		mModel.Load(OBJ, MTL);
	}
	//モデルのポインタ設定
	mpModel = &mModel;
	mColSearch.mTag = CCollider::ESEARCH; //タグ設定
}

//コンストラクタ
//CEnemy(位置,回転,拡縮)
CEnemy2::CEnemy2(const CVector&position, const CVector&rotation,
	const CVector& scale)
:CEnemy2() //デフォルトコンストラクタを実行する
{
	//位置,回転,拡縮を設定する
	mPosition = position; //位置の設定
	mRotation = rotation; //回転の設定
	mScale = scale;       //拡縮の設定
	CTransform::Update(); //行列の更新
	//優先度を1に変更する
	mPriority = 1;
	CTaskManager::Get()->Remove(this); //削除して
	CTaskManager::Get()->Add(this); //追加する
}

//更新処理
void CEnemy2::Update(){
	//左向き(X軸)のベクトルを求める
	CVector vx = CVector(1.0f, 0.0f, 0.0f)*mMatrixRotate;
	//上向き(Y軸)のベクトルを求める
	CVector vy = CVector(0.0f, 1.0f, 0.0f)*mMatrixRotate;
	//前方向(Z軸)のベクトルを求める
	CVector vz = CVector(0.0f, 0.0f, 1.0f)*mMatrixRotate;
	//プレイヤーのポインタが0以外の時
	if (mpPlayer)
	{
		//プレイヤーまでのベクトルを求める
		CVector vp = mpPlayer->mPosition - mPosition;
		float dx = vp.Dot(vx); //左ベクトルとの内積を求める
		float dy = vp.Dot(vy); //上ベクトルとの内積を求める
		float dz = vp.Dot(vz); //前ベクトルとの内積を求める
		//X軸のズレが2.0以下
		if (-2.0f < dx && dx < 2.0f)
		{
			//Y軸のズレが2.0以下
			if (-2.0f < dy && dy < 2.0f)
			{
				//敵のZ軸が0.0以上の時
				if (dz>0.0f)
				{
					//弾を発射します
					CBullet*bullet = new CBullet();
					bullet->Set(0.1f, 1.5f);
					bullet->mPosition =
						CVector(0.0f, 0.0f, 10.0f)*mMatrix;
					bullet->mRotation = mRotation;
					bullet->Update();
				}
			}
		}
}
	mpPlayer = 0;

	//HPが0以下の時　撃破
	if (mHp <= 0)
	{
		mHp--;
		//15フレーム毎にエフェクト
		if (mHp % 15 == 0)
		{
			//エフェクト生成
			new CEffect(mPosition, 1.0f, 1.0f, "exp.tga", 4, 4, 2);
		}
		//下降させる
		mPosition.mY -= 0.03f;
		CTransform::Update();
		return;
	}
}

//衝突処理
//Collision(コライダ1,コライダ2)
void CEnemy2::Collision(CCollider*m, CCollider*o){
	//相手がサーチの時は戻る
	if (o->mTag == CCollider::ESEARCH)
	{
		return;
	}
	//自分がサーチ用の時
	if (m->mTag == CCollider::ESEARCH)
	{
		//相手が球コライダの時
		if (o->mType == CCollider::ESPHERE)
		{
			//相手がプレイヤーの時
			if (o->mpParent->mTag == EPLAYER)
			{
				//衝突している時
				if (CCollider::Collision(m, o))
				{
					//プレイヤーのポインタ設定
					mpPlayer = o->mpParent;
				}
			}
		}
		return;
	}
	//相手のコライダタイプの判定
	switch (o->mType)
	{
	case CCollider::ESPHERE://球コライダの時
		//コライダのmとoが衝突しているか判定
		if (CCollider::Collision(m, o)){
			//エフェクト生成
			new CEffect(o->mpParent->mPosition, 1.0f, 1.0f, "exp.tga", 4, 4, 2);
			//衝突している時は無効にする
			//mEnabled = false;
			mHp--; //ヒットポイントの減算
		}
		break;
	case CCollider::ETRIANGLE://三角コライダの時
		CVector adjust;//調整値
		//三角コライダと球コライダの衝突判定
		if (CCollider::CollisionTriangleSphere(o, m, &adjust))
		{
			//衝突しない位置まで戻す
			mPosition = mPosition + adjust;
			//撃破で地面に衝突すると無効
			if (mHp <= 0)
			{
				mEnabled = false;
			}			
		}
		break;
	}
}

void CEnemy2::TaskCollision()
{
	//コライダの優先度変更
	mCollider.ChangePriority();
	//衝突処理を実行
	CCollisionManager::Get()->Collision(&mCollider, COLLISIONRANGE);

	mColSearch.ChangePriority();
	CCollisionManager::Get()->Collision(&mColSearch, COLLISIONRANGE);
}