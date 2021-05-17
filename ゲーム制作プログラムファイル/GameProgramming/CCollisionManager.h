#ifndef CCOLLISIONMANAGER_H
#define CCOLLISIONMANAGER_H

#include "CTaskManager.h"
#include "CCollider.h"

class CCollisionManager :public CTaskManager
{
	//�}�l�[�W���̃C���X�^���X
	static CCollisionManager*mpInstance;
public:
	//�C���X�^���X�̎擾
	static CCollisionManager*Get();
	//�Փˏ���
	void Collision();
	//�Փˏ���
	void Collision(CCollider*c, int range);
	//�Փˏ����͈͂�藣��Ă���R���C�_�͏Փˏ������Ȃ�
    #define COLLISIONRANGE 30
};

#endif