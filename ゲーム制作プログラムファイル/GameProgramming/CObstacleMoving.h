#ifndef COBSTACLEMOVING_H
#define COBSTACLEMOVING_H

#include "CCharacter.h"

class CObstacleMoving :public CCharacter{
public:
	//デフォルトコンストラクタ
	CObstacleMoving();
	//コンストラクタ
	//CObstacleMoving(位置,回転,拡縮)
	CObstacleMoving(CVector position, CVector rotation, CVector scale);
	//一度だけ実行する
	void Init();
	//更新処理
	void Update();
	//描画処理
	void Render();
	CModel mModelcube; //モデル
private:
	float mMove; //左右の動きの大きさ
};

#endif