#ifndef CGOAL_H
#define CGOAL_H

#include "CCharacter.h"

#include "CCollider.h"

class CGoal :public CCharacter{
public:
	//�R���X�g���N�^
	//CGoal(���f��,�ʒu,��],�g�k)
	CGoal(CModel*model, CVector position, CVector rotation, CVector scale);

	CCollider mCollider1;
	
};

#endif 