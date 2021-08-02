#include "CFloor.h"
#include "CTaskManager.h"
#include "CColliderMesh.h"

CColliderMesh mColliderMesh3;

//コンストラクタ
CFloor::CFloor(CModel*model, CVector position, CVector rotation, CVector scale){
	//モデル、位置、回転、拡縮を設定する
	mpModel = model;      //モデルの設定
	mPosition = position; //位置の設定
	mRotation = rotation; //回転の設定
	mScale = scale;       //縮尺の設定
	//優先度を1に変更する
	mPriority = 1;
	CTaskManager::Get()->Remove(this);//削除して
	CTaskManager::Get()->Add(this);//追加する

	mTag = EFLOOR; //タグの設定

	mColliderMesh3.Set(this, &mMatrix, mpModel);//モデルから三角コライダを生成

	CTransform::Update(); //行列を呼ぶ
}

//描画処理
void CFloor::Render(){
	//親の描画処理を呼ぶ
	CCharacter::Render();
}