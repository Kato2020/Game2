#ifndef CGOAL_H
#define CGOAL_H

#include "CCharacter.h"
#include "CCollider.h"

class CGoal :public CCharacter{
public:
	//コンストラクタ
	//CGoal(モデル,位置,回転,拡縮)
	CGoal(CModel*model, CVector position, CVector rotation, CVector scale);
	//一度だけ実行
	void Init();
	//衝突判定
	//void Collision(CCollider*m, CCollider*o);
	//衝突処理
	//void TaskCollision();
	//描画処理
	void Render();
};

#endif 