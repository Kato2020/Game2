#ifndef CMAP_H
#define CMAP_H

#include "CCharacter.h"

class CMap : public CCharacter{
public:
	//�R���X�g���N�^
	//CMap(���f��,�ʒu,��],�g�k)
	CMap(CModel*model, CVector position, CVector rotation, CVector scale);

	//�`�揈��
	void Render(); 
};

#endif