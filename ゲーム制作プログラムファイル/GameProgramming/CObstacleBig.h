#ifndef COBSTACLEBIG_H
#define COBSTACLEBIG_H

#include "CCharacter.h"

class CObstacleBig :public CCharacter{
public:
	//コンストラクタ
	//CObstacleBig(位置,回転,拡縮)
	CObstacleBig(CVector position, CVector rotation, CVector scale);
	//一度だけ実行する
	void Init();
	//描画処理
	void Render();
	CModel mModelcube; //モデル
};

#endif