#include "CObstacleMoving.h"
#include "CTaskManager.h"
#include "CModel.h"

CObstacleMoving::CObstacleMoving()
:mMove(1.0f), mTime(120)
{}

CObstacleMoving::CObstacleMoving(CVector position, CVector rotation, CVector scale){
	//四角形モデルの読み込み
	mModelcube.Load("cube.obj", "cube.mtl");
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

//更新処理
void CObstacleMoving::Update(){
	mPosition.mX += mMove;
	//2秒経過するたびに動く方向を反転
	if (mTime <= 0){
		mMove = mMove*-1;
		mTime = 120;
	}
	mTime--;
}

void CObstacleMoving::Render(){
	//親の描画処理
	CCharacter::Render();
}