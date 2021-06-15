#include "CGoal.h"
#include "CTaskManager.h"

CGoal::CGoal(CModel*model, CVector position, CVector rotation, CVector scale){
	//モデル、位置、回転、拡縮を設定する
	mpModel = model;      //モデルの設定
	mPosition = position; //位置の設定
	mRotation = rotation; //回転の設定
	mScale = scale;       //縮尺の設定
	//優先度を1に変更する
	mPriority = 1;
	CTaskManager::Get()->Remove(this);//削除して
	CTaskManager::Get()->Add(this);//追加する

	mTag = EGOAL; //タグの設定

	CTransform::Update(); //行列を呼ぶ
}