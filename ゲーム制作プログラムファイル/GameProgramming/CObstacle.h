#ifndef COBSTACLE_H
#define COBSTACLE_H

#include "CCharacter.h"

class CObstacle :public CCharacter{
public:

	//�R���X�g���N�^
	//CObstacle(�ʒu,��],�g�k)
	CObstacle(CVector position, CVector rotation, CVector scale);

	void Init();
	//�`�揈��
	void Render();
};

#endif