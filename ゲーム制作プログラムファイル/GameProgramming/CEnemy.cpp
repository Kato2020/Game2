#include "CEnemy.h"
#include "CEffect.h"
#include "CTaskManager.h"
#include "CCollisionManager.h"

//コンストラクタ
//CEnemy(モデル,位置,回転,拡縮)
CEnemy::CEnemy(CModel*model, CVector position,
	CVector rotation, CVector scale)
:mCollider1(this, &mMatrix, CVector(0.0f, 5.0f, 0.0f), 0.8f)
, mCollider2(this, &mMatrix, CVector(0.0f, 5.0f, 20.0f), 0.8f)
, mCollider3(this, &mMatrix, CVector(0.0f, 5.0f, -20.0f), 0.8f)
{
	//モデル,位置,回転,拡縮を設定する
	mpModel = model;      //モデルの設定
	mPosition = position; //位置の設定
	mRotation = rotation; //回転の設定
	mScale = scale;       //縮尺の設定
	//優先度を1に変更する
	mPriority = 1;
	CTaskManager::Get()->Remove(this);//削除して
	CTaskManager::Get()->Add(this);//追加する
}

//更新処理
void CEnemy::Update(){
	//行列を更新
	CTransform::Update();
	//位置を移動
	mPosition = CVector(0.0f, 0.0f, 0.9f)*mMatrix;
}

//衝突処理
//Collision(コライダ1,コライダ2)
void CEnemy::Collision(CCollider*m, CCollider*o){
	//相手がサーチの時は戻る
	if (o->mTag == CCollider::ESEARCH)
	{
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
		}
		break;
	case CCollider::ETRIANGLE://三角コライダの時
		CVector adjust;//調整値
		//三角コライダと球コライダの衝突判定
		if (CCollider::CollisionTriangleSphere(o, m, &adjust))
		{
			//衝突しない位置まで戻す
			mPosition = mPosition + adjust;
		}
		break;
	}
}
//衝突処理
void CEnemy::TaskCollision()
{
	//コライダの優先度変更
	mCollider1.ChangePriority();
	mCollider2.ChangePriority();
	mCollider3.ChangePriority();
	//衝突処理を実行
	CCollisionManager::Get()->Collision(&mCollider1, COLLISIONRANGE);
	CCollisionManager::Get()->Collision(&mCollider2, COLLISIONRANGE);
	CCollisionManager::Get()->Collision(&mCollider3, COLLISIONRANGE);

}
