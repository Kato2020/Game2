#ifndef COBSTACLEMOVING_H
#define COBSTACLEMOVING_H

#include "CCharacter.h"

class CObstacleMoving :public CCharacter{
public:
	//�f�t�H���g�R���X�g���N�^
	CObstacleMoving();
	//�R���X�g���N�^
	//CObstacleMoving(�ʒu,��],�g�k)
	CObstacleMoving(CVector position, CVector rotation, CVector scale);
	//��x�������s����
	void Init();
	//�X�V����
	void Update();
	//�`�揈��
	void Render();
	CModel mModelcube; //���f��
private:
	float mMove; //���E�̓����̑傫��
};

#endif