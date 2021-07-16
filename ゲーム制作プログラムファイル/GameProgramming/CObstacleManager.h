#ifndef COBSTACLEMANAGER_H
#define COBSTACLEMANAGER_H

#include <time.h>

class CObstacleManager{
public:
	//�f�t�H���g�R���X�g���N�^
	CObstacleManager();
	//��x�������s����
	void Init();
	//�`���[�g���A���p�̏�Q�����R�[�X�ɐ�������
	//Generate(�R�[�X�̒���,�R�[�X�̕�, �Ԋu)
	void Generate(float range, float width, float spacing);
	//3��ނ̏�Q�����R�[�X�Ƀ����_���ɐ�������
	//GenerateRandom(�R�[�X�̒���,�R�[�X�̕�, �Ԋu)
	void GenerateRandom(float range, float width, float spacing);
private:
	//�V�X�e��������ۑ�����ϐ�
	time_t mTime;
	//�R�[�X�̉�����3�����������S
	float mDivisionCenter;
};

#endif