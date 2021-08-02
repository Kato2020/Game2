#include "CMap.h"
#include "CTaskManager.h"
#include "CCollisionManager.h"
#include "CColliderMesh.h"

//モデルからコライダを生成
CColliderMesh mColliderMesh2;

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

	mColliderMesh2.Set(this, &mMatrix, mpModel);//モデルから三角コライダを生成

	CTransform::Update(); //行列を呼ぶ
}

/*void CMap::Collision(CCollider*m, CCollider*o){
	//自分が三角コライダの時
	if (m->mType == CCollider::ETRIANGLE){
		switch (o->mType)
		{
		case CCollider::ETRIANGLE:
			//相手の親がプレイヤーの時
			if (o->mpParent->mTag == EPLAYER){
				//衝突している時
				if (CCollider::Collision(m, o)){
					
				}
			}
		default:
			break;
		}
	}
}*/

void CMap::Render(){
	//親の描画処理
	CCharacter::Render();
}