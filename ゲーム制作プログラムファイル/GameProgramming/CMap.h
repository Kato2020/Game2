#ifndef CMAP_H
#define CMAP_H

#include "CCharacter.h"

class CMap : public CCharacter{
public:
	//コンストラクタ
	//CMap(モデル,位置,回転,拡縮)
	CMap(CModel*model, CVector position, CVector rotation, CVector scale);
	//衝突判定
	//void Collision(CCollider*m, CCollider*o);
	//描画処理
	void Render(); 
};

#endif