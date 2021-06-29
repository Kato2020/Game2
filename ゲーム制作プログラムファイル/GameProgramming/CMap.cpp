#include "CMap.h"
#include "CTaskManager.h"

CMap::CMap(CModel*model, CVector position, CVector rotation, CVector scale){
	//モデル、位置、回転、拡縮を設定する
	mpModel = model;      //モデルの設定
	mPosition = position; //位置の設定
	mRotation = rotation; //回転の設定
	mScale = scale;       //縮尺の設定
	//優先度を1に変更する
	mPriority = 1;
	CTaskManager::Get()->Remove(this);//削除して
	CTaskManager::Get()->Add(this);//追加する

	mTag = EMAP; //タグの設定

	CTransform::Update(); //行列を呼ぶ
}

void CMap::Collision(CCollider*m, CCollider*o){
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
		}
		break;
	}
}

void CMap::Render(){
	//親の描画処理
	CCharacter::Render();
}