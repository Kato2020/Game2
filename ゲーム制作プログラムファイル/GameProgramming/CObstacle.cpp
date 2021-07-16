#include "CObstacle.h"
#include "CTaskManager.h"
#include "CModel.h"


void CObstacle::Init(){
	//四角形モデルの読み込み
	mModelcube.Load("cube.obj", "cube.mtl");
}

CObstacle::CObstacle(CVector position, CVector rotation, CVector scale){
	//モデル、位置、回転、拡縮を設定する
	mpModel = &mModelcube;  //モデルの設定
	mPosition = position;   //位置の設定
	mRotation = rotation;   //回転の設定
	mScale = scale;         //縮尺の設定
	//優先度を1にする
	mPriority = 1;
	CTaskManager::Get()->Remove(this);
	CTaskManager::Get()->Add(this);

	CTransform::Update(); //行列を呼ぶ
}

void CObstacle::Render(){
	//親の描画処理
	CCharacter::Render();
}