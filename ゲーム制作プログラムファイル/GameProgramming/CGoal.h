#ifndef CGOAL_H
#define CGOAL_H

#include "CCharacter.h"
#include "CCollider.h"

class CGoal :public CCharacter{
public:
	//�R���X�g���N�^
	//CGoal(���f��,�ʒu,��],�g�k)
	CGoal(CModel*model, CVector position, CVector rotation, CVector scale);
	//��x�������s
	void Init();
	//�Փ˔���
	//void Collision(CCollider*m, CCollider*o);
	//�Փˏ���
	//void TaskCollision();
	//�`�揈��
	void Render();
};

#endif 