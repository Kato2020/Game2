#ifndef CCHARACTER_H
#define CCHARACTER_H
//�ϊ��s��N���X�̃C���N���[�h
#include "CTransform.h"
//���f���N���X�̃C���N���[�h
#include "CModel.h"
//�^�X�N�N���X�̃C���N���[�h
#include "CTask.h"
/*
�L�����N�^�[�N���X
�Q�[���L�����N�^�[�̊�{�I�ȋ@�\���`����
*/
//�R���C�_�N���X�̐錾
class CCollider;

class CCharacter :public CTransform,public CTask{
public:
	CModel*mpModel; //���f���̃|�C���^
	//�`�揈��
	void Render();
	//�f�X�g���N�^
	~CCharacter();
	//�R���X�g���N�^
	CCharacter();
	//�Փˏ���
	virtual void Collision(CCollider*m, CCollider*o){}
	enum ETag
	{
		EZERO,         //�����l
		EPLAYER,       //�v���C���[
		EENEMY,        //�G
		EBULLETPLAYER, //�v���C���[�e
		EBULLETENEMY,  //�G�e
		EMAP,          //�R�[�X�̕�
		EBLOCK,        //��Q��
		EGOAL,         //�S�[��
	};
	ETag mTag;
};

#endif