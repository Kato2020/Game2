#include "CObstacleMoving.h"
#include "CTaskManager.h"
#include "CModel.h"

CObstacleMoving::CObstacleMoving()
:mMove(1.0f), mTime(120)
{}

CObstacleMoving::CObstacleMoving(CVector position, CVector rotation, CVector scale){
	//�l�p�`���f���̓ǂݍ���
	mModelcube.Load("cube.obj", "cube.mtl");
	//���f���A�ʒu�A��]�A�g�k��ݒ肷��
	mpModel = &mModelcube;  //���f���̐ݒ�
	mPosition = position;   //�ʒu�̐ݒ�
	mRotation = rotation;   //��]�̐ݒ�
	mScale = scale;         //�k�ڂ̐ݒ�
	//�D��x��1�ɂ���
	mPriority = 1;
	CTaskManager::Get()->Remove(this);
	CTaskManager::Get()->Add(this);

	CTransform::Update(); //�s����Ă�
}

//�X�V����
void CObstacleMoving::Update(){
	mPosition.mX += mMove;
	//2�b�o�߂��邽�тɓ��������𔽓]
	if (mTime <= 0){
		mMove = mMove*-1;
		mTime = 120;
	}
	mTime--;
}

void CObstacleMoving::Render(){
	//�e�̕`�揈��
	CCharacter::Render();
}