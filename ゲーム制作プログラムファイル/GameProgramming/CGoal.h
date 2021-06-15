#ifndef CGOAL_H
#define CGOAL_H

#include "CCharacter.h"

#include "CCollider.h"

class CGoal :public CCharacter{
public:
	//コンストラクタ
	//CGoal(モデル,位置,回転,拡縮)
	CGoal(CModel*model, CVector position, CVector rotation, CVector scale);

	CCollider mCollider1;
	
};

#endif 