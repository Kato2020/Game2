#include "CObstacleManager.h"
#include <stdlib.h>

//�f�t�H���g�R���X�g���N�^
CObstacleManager::CObstacleManager()
:randomSeed(0), mObstacleType(0)
{}

//��x�������s����
void CObstacleManager::Init(){
	srand(randomSeed);
}

//�ʏ�̏�Q�����R�[�X��ɐ�������
void Generate(float range,float spacing){
	//�Ԋu���J���ăS�[���܂ŏ�Q���𐶐�
	for (int i = 0; i < range / spacing; i++){
		//���ʃT�C�Y�̏�Q���𐶐�����
		new CObstacle(CVector(0.0f, 0.0f, spacing*1), CVector(), CVector(1.0f, 1.0f, 1.0f));
	}
}

//3��ނ̏�Q�����R�[�X��Ƀ����_���ɐ�������
void GenerateRandom(float renge, float spacing){
	//�Ԋu���J���ăS�[���܂ŏ�Q���𐶐�
	for (int i = 0; i < renge / spacing; i++){
		//�����_���Ȓl�𐶐�
		int mObstacleType = rand();
		mObstacleType %= 3;
		switch (mObstacleType){
			case 0:
				//���ʃT�C�Y�̏�Q���𐶐�����
				new CObstacle(CVector(0.0f, 0.0f, spacing*1), CVector(), CVector(1.0f, 1.0f, 1.0f));
			case 1:
				//�傫���T�C�Y�̏�Q���𐶐�
			case 2:
				//���E�ɓ�����Q���𐶐�
		default:
			break;
		}
	}
}