#include "CObstacleMoving.h"
#include "CTaskManager.h"
#include "CModel.h"

CObstacleMoving::CObstacleMoving()
:mMove(1.0f)
{}

void CObstacleMoving::Init(){
	//�l�p�`���f���̓ǂݍ���
	mModelcube.Load("cube.obj", "cube.mtl");
}

CObstacleMoving::CObstacleMoving(CVector position, CVector rotation, CVector scale){
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
}

void CObstacleMoving::Render(){
	//�e�̕`�揈��
	CCharacter::Render();
}