#ifndef COBSTACLEBIG_H
#define COBSTACLEBIG_H

#include "CCharacter.h"

class CObstacleBig :public CCharacter{
public:
	//�R���X�g���N�^
	//CObstacleBig(�ʒu,��],�g�k)
	CObstacleBig(CVector position, CVector rotation, CVector scale);
	//��x�������s����
	void Init();
	//�`�揈��
	void Render();
	CModel mModelcube; //���f��
};

#endif