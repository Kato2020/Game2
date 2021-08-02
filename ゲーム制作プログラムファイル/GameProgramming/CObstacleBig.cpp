#include "CObstacleBig.h"
#include "CTaskManager.h"
#include "CModel.h"


void CObstacleBig::Init(){
	
}

CObstacleBig::CObstacleBig(CVector position, CVector rotation, CVector scale){
	//�l�p�`���f���̓ǂݍ���
	mModelcube.Load("cube.obj", "cube.mtl");
	//���f���A�ʒu�A��]�A�g�k��ݒ肷��
	mpModel = &mModelcube;        //���f���̐ݒ�
	mPosition = position;   //�ʒu�̐ݒ�
	mRotation = rotation;   //��]�̐ݒ�
	mScale = scale;         //�k�ڂ̐ݒ�
	//�D��x��1�ɂ���
	mPriority = 1;
	CTaskManager::Get()->Remove(this);
	CTaskManager::Get()->Add(this);

	CTransform::Update(); //�s����Ă�

}
void CObstacleBig::Render(){
	//�e�̕`�揈��
	CCharacter::Render();
}