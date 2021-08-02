#include "CObstacleManager.h"
//
#include <stdlib.h>
//
#include "CObstacle.h"
#include "CObstacleBig.h"
#include "CObstacleMoving.h"

#define CATEGORY 3 //��Q���̎��


//�f�t�H���g�R���X�g���N�^
CObstacleManager::CObstacleManager()
:mTime(0), mDivisionCenter(0)
{}

//��x�������s����
void CObstacleManager::Init(){
	//���Ԃ��V�[�h�l�Ƃ��ċ^�������̈����ɐݒ�
	srand((unsigned)time(&mTime));
}

//�`���[�g���A���p�R�[�X
void CObstacleManager::Generate(float range,float width,float spacing){
	//�R�[�X�̉�����3�����������S
	mDivisionCenter = width / 3 / 2;
	//�Ԋu���J���ăS�[���܂�
	for (int i = 0; i < range / spacing; i++){
		//�R�[�X�̍��[�����Q���̉��̈ʒu�������_���Ɍ��߂�
		float x = -width / 2 + mDivisionCenter + rand() % 3 * mDivisionCenter * 2;

		switch ((i+CATEGORY) % CATEGORY)
		{
		case 0:
			//���ʃT�C�Y�̏�Q���𐶐�����
			new CObstacle(CVector(x, 0.0f, spacing * i*-1.0f - 10.0f), CVector(), CVector(1.0f, 1.0f, 1.0f));
			break;
		case 1:
			//�傫���T�C�Y�̏�Q���𐶐�
			new CObstacleBig(CVector(x, 0.0f, spacing * i*-1.0f - 10.0f), CVector(), CVector(2.0f, 2.0f, 2.0f));
			break;
		case 2:
			//���E�ɓ�����Q���𐶐�
			new CObstacleMoving(CVector(x, 0.0f, spacing * i*-1.0f - 10.0f), CVector(), CVector(0.8f, 1.8f, 0.8f));
			break;
		default:
			break;
		}
	}
}

//3��ނ̏�Q�����R�[�X��Ƀ����_���ɐ�������
void CObstacleManager::GenerateRandom(float renge, float width, float spacing){
	//�R�[�X�̉�����3�����������S
	mDivisionCenter = width / 3 / 2;
	//�Ԋu���J���ăS�[���܂�
	for (int i = 0; i < renge / spacing; i++){
		//�R�[�X�̍��[�����Q���̉��̈ʒu�������_���Ɍ��߂�
		float x = -width / 2 + mDivisionCenter + rand() % 3 * mDivisionCenter * 2;
		//�^�������𐶐�
		unsigned int mObstacleRandom = rand();
		printf("mObstacleRandom:%d\n,mObstacleRandom");
		int mObstacleType = mObstacleRandom % CATEGORY;
		printf("mObstacleType:%d\n,mObstacleType");
		switch (mObstacleType){
			case 0:
				//���ʃT�C�Y�̏�Q���𐶐�����
				new CObstacle(CVector(x, 0.0f, spacing * i*-1.0f - 10.0f), CVector(), CVector(1.0f, 1.0f, 1.0f));
				break;
			case 1:
				//�傫���T�C�Y�̏�Q���𐶐�
				new CObstacleBig(CVector(x, 0.0f, spacing * i*-1.0f - 10.0f), CVector(), CVector(2.0f, 1.0f, 2.0f));
				break;
			case 2:
				//���E�ɓ�����Q���𐶐�
				new CObstacleMoving(CVector(x, 0.0f, spacing * i*-1.0f - 10.0f), CVector(), CVector(0.8f, 1.8f, 0.8f));
				break;
		default:
			break;
		}
	}
}