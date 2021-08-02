#include "CMap.h"
#include "CTaskManager.h"
#include "CCollisionManager.h"
#include "CColliderMesh.h"

//���f������R���C�_�𐶐�
CColliderMesh mColliderMesh2;

CMap::CMap(CModel*model, CVector position, CVector rotation, CVector scale){
	//���f���A�ʒu�A��]�A�g�k��ݒ肷��
	mpModel = model;      //���f���̐ݒ�
	mPosition = position; //�ʒu�̐ݒ�
	mRotation = rotation; //��]�̐ݒ�
	mScale = scale;       //�k�ڂ̐ݒ�
	//�D��x��1�ɕύX����
	mPriority = 1;
	CTaskManager::Get()->Remove(this);//�폜����
	CTaskManager::Get()->Add(this);//�ǉ�����

	mTag = EMAP; //�^�O�̐ݒ�

	mColliderMesh2.Set(this, &mMatrix, mpModel);//���f������O�p�R���C�_�𐶐�

	CTransform::Update(); //�s����Ă�
}

/*void CMap::Collision(CCollider*m, CCollider*o){
	//�������O�p�R���C�_�̎�
	if (m->mType == CCollider::ETRIANGLE){
		switch (o->mType)
		{
		case CCollider::ETRIANGLE:
			//����̐e���v���C���[�̎�
			if (o->mpParent->mTag == EPLAYER){
				//�Փ˂��Ă��鎞
				if (CCollider::Collision(m, o)){
					
				}
			}
		default:
			break;
		}
	}
}*/

void CMap::Render(){
	//�e�̕`�揈��
	CCharacter::Render();
}