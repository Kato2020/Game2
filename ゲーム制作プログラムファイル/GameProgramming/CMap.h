#ifndef CMAP_H
#define CMAP_H

#include "CCharacter.h"

#include "CCollider.h"

class CMap : public CCharacter{
public:
	//�R���X�g���N�^
	//CMap(���f��,�ʒu,��],�g�k)
	CMap(CModel*model, CVector position, CVector rotation, CVector scale);
	//��x�������s
	void Init();
	//�Փ˔���
	void Collision(CCollider*m, CCollider*o);
	//�`�揈��
	void Render(); 
};

#endif