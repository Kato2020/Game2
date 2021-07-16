#ifndef COBSTACLE_H
#define COBSTACLE_H

#include "CCharacter.h"

class CObstacle :public CCharacter{
public:
    //コンストラクタ
	//CObstacle(位置,回転,拡縮)
	CObstacle(CVector position, CVector rotation, CVector scale);
	//一度だけ実行する
	void Init();
	//描画処理
	void Render();
	CModel mModelcube; //モデル
};

#endif