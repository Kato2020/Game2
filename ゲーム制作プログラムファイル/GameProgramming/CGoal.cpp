#include "CGoal.h"
#include "CTaskManager.h"
#include "CCollisionManager.h"
#include "CColliderMesh.h"

//���f������R���C�_�𐶐�
CColliderMesh mColliderMesh;
//�R���X�g���N�^
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

	mColliderMesh.Set(this, &mMatrix, mpModel);//���f������O�p�R���C�_�𐶐�

	CTransform::Update(); //�s����Ă�
}

/*void CGoal::Collision(CCollider*m, CCollider*o){
	//�������O�p�R���C�_�̎�
	if (m->mType == CCollider::ETRIANGLE){
		switch (o->mType)
		{
		case CCollider::ESPHERE:
			//����̐e���v���C���[�̎�
			if (o->mpParent->mTag == EPLAYER){
				//�Փ˂��Ă��鎞
				if (CCollider::Collision(m, o)){
					//�v���C���[������
					delete(o->mpParent);
				}
			}
		default:
			break;
		}
	}
}*/

//�Փˏ���
/*void CGoal::TaskCollision()
{
	//�R���C�_�̗D��x�ύX
	mColliderMesh.
		//�Փˏ��������s
		CCollisionManager::Get()->Collision(&mColliderMesh, COLLISIONRANGE);
}*/

void CGoal::Render(){
	//�e�̕`�揈�����Ă�
	CCharacter::Render();
}