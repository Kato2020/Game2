#ifndef CFLOOR_H
#define CFLOOR_H

#include "CCharacter.h"

class CFloor :public CCharacter{
public:
	//コンストラクタ
	//CFloor(モデル,位置,回転,拡縮)
	CFloor(CModel*model, CVector position, CVector rotation, CVector scale);
	//描画処理
	void Render();
};
#endif