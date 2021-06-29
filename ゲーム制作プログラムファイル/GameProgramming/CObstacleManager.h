#ifndef COBSTACLEMANAGER_H
#define COBSTACLEMANAGER_H

#include "CObstacle.h"

class CObstacleManager{
public:
	//�f�t�H���g�R���X�g���N�^
	CObstacleManager();
	//��x�������s����
	void Init();
	//�ʏ�̏�Q�����R�[�X��ɐ�������
	//Generate(�}�b�v�̒���,�Ԋu)
	void Generate(float range, float spacing);
	//3��ނ̏�Q�����R�[�X�Ƀ����_���ɐ�������
	//GenerateRandom(�}�b�v�̒���,�Ԋu)
	void GenerateRandom(float range, float spacing);
private:
	//�V�[�h�l
	unsigned int  randomSeed;
	//���������Q���̎��
	int mObstacleType;
};

#endif