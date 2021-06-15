#include "CGoal.h"
#include "CTaskManager.h"

CGoal::CGoal(CModel*model, CVector position, CVector rotation, CVector scale){
	//���f���A�ʒu�A��]�A�g�k��ݒ肷��
	mpModel = model;      //���f���̐ݒ�
	mPosition = position; //�ʒu�̐ݒ�
	mRotation = rotation; //��]�̐ݒ�
	mScale = scale;       //�k�ڂ̐ݒ�
	//�D��x��1�ɕύX����
	mPriority = 1;
	CTaskManager::Get()->Remove(this);//�폜����
	CTaskManager::Get()->Add(this);//�ǉ�����

	mTag = EGOAL; //�^�O�̐ݒ�

	CTransform::Update(); //�s����Ă�
}