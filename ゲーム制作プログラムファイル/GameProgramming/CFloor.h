#ifndef CFLOOR_H
#define CFLOOR_H

#include "CCharacter.h"

class CFloor :public CCharacter{
public:
	//�R���X�g���N�^
	//CFloor(���f��,�ʒu,��],�g�k)
	CFloor(CModel*model, CVector position, CVector rotation, CVector scale);
	//�`�揈��
	void Render();
};
#endif