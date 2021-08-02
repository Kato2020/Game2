#include "CFloor.h"
#include "CTaskManager.h"
#include "CColliderMesh.h"

CColliderMesh mColliderMesh3;

//�R���X�g���N�^
CFloor::CFloor(CModel*model, CVector position, CVector rotation, CVector scale){
	//���f���A�ʒu�A��]�A�g�k��ݒ肷��
	mpModel = model;      //���f���̐ݒ�
	mPosition = position; //�ʒu�̐ݒ�
	mRotation = rotation; //��]�̐ݒ�
	mScale = scale;       //�k�ڂ̐ݒ�
	//�D��x��1�ɕύX����
	mPriority = 1;
	CTaskManager::Get()->Remove(this);//�폜����
	CTaskManager::Get()->Add(this);//�ǉ�����

	mTag = EFLOOR; //�^�O�̐ݒ�

	mColliderMesh3.Set(this, &mMatrix, mpModel);//���f������O�p�R���C�_�𐶐�

	CTransform::Update(); //�s����Ă�
}

//�`�揈��
void CFloor::Render(){
	//�e�̕`�揈�����Ă�
	CCharacter::Render();
}