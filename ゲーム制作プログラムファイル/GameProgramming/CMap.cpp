#include "CMap.h"
#include "CTaskManager.h"

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

	CTransform::Update(); //�s����Ă�
}

void CMap::Collision(CCollider*m, CCollider*o){
	//���g�̃R���C�_�^�C�v�̔���
	switch (m->mType){
	case CCollider::ELINE://�����R���C�_
		//����̃R���C�_���O�p�R���C�_�̎�
		if (o->mType == CCollider::ETRIANGLE){
			CVector adjust;//�����p�x�N�g��
			//�O�p�`�Ɛ����̏Փ˔���
			CCollider::CollisionTriangleLine(o, m, &adjust);
			//�ʒu�̍X�V(mPosition+adjust)
			mPosition = mPosition - adjust*-1;
			//�s��̍X�V
			CTransform::Update();
		}
		break;
	}
}

void CMap::Render(){
	//�e�̕`�揈��
	CCharacter::Render();
}