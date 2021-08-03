#ifndef CPLAYER_H
#define CPLAYER_H
//�L�����N�^�N���X�̃C���N���[�h
#include "CCharacter.h"
#include "CColliderLine.h"
#include "CText.h"
/*
�v���C���[�N���X
�L�����N�^�N���X���p��
*/
class CPlayer :public CCharacter{
private:
	//�W�����v�X�s�[�h
	float mJpspeed;
	//�W�����v���Ă��邩����
	bool mJump;
	//����
	int mTime;
	//��b���J�E���g����
	int mCount;
	//����
	float mSlowing;
public:
	//�X�V����
	void Update();
	CColliderLine mLine;//�����R���C�_
	CColliderLine mLine2;
	CColliderLine mLine3;
	//�{�̏Փ˔���p�R���C�_
	CCollider mCollider; //�{�̗p�R���C�_
	CPlayer();
	//�Փˏ���
	void Collision(CCollider*m, CCollider*o);
	//�Փˏ���
	void TaskCollision();
	//������̕`����s��CText�N���X�̕ϐ�mText
	CText mText;
	//�S�[�����ăQ�[�����I������������
	bool mEnabled;
	//�`�揈��
	void Render();
};

#endif