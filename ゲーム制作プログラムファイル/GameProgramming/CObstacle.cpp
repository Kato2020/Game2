#include "CObstacle.h"
#include "CTaskManager.h"
#include "CModel.h"


void CObstacle::Init(){
	//�l�p�`���f���̓ǂݍ���
	mModelcube.Load("cube.obj", "cube.mtl");
}

CObstacle::CObstacle(CVector position, CVector rotation, CVector scale){
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

void CObstacle::Render(){
	//�e�̕`�揈��
	CCharacter::Render();
}