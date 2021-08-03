//�v���C���[�N���X�̃C���N���[�h
#include "CPlayer.h"
//�L�[���̓N���X�̃C���N���[�h
#include "CKey.h"

#include "CTaskManager.h"
#include "CCollisionManager.h"
#include "CUtil.h"

#define GRAVITY 0.15  //�d��
#define JUMPPOWER 5.0  //�W�����v��

int mClearTime = 0; //���U���g�ɕ\������N���A�^�C����n�����߂̕ϐ�

CPlayer::CPlayer()
:mLine(this, &mMatrix, CVector(0.0f, 0.0f, -5.0f), CVector(0.0f, 0.0f, 5.0f))
, mLine2(this, &mMatrix, CVector(0.0f, 5.0f, 0.0f), CVector(0.0f, -3.0f, 0.0f))
, mLine3(this, &mMatrix, CVector(5.0f, 0.0f, 0.0f), CVector(-5.0f, 0.0f, 0.0f))
,mCollider(this, &mMatrix, CVector(0.0f, 0.0f, 0.0f), 0.5f)
, mJpspeed(0), mJump(false), mTime(0), mCount(0)
{
	//�e�N�X�`���t�@�C���̓ǂݍ���(1�s64��)
	mText.LoadTexture("FontWhite.tga", 1, 64);
	mTag = EPLAYER; //�^�O�̐ݒ�
	CPlayer::mEnabled = true;
}

//�X�V����
void CPlayer::Update(){
	//A�L�[���͂ŉ�]
	if (CKey::Push('A')){
		//Y���̉�]�l�𑝉�
		mRotation.mY += 1;
	}
	//D�L�[���͂ŉ�]
	if (CKey::Push('D')){
		//Y���̉�]�l�𑝉�
		mRotation.mY -= 1;
	}
	//����L�[���͂őO�i
	if (CKey::Push(VK_UP)){
		//Z��������1�i�񂾒l����]�ړ�������
		mPosition = CVector(0.0f, 0.0f, 1.0f)*mMatrix;
	}
	//S�L�[���͂ŏ����
	if (CKey::Push('S')){
		//X���̉�]�l�����Z
		mRotation.mX -= 1;
	}
	//W�L�[���͂ŉ�����
	if (CKey::Push('W')){
		//X���̉�]�l�����Z
		mRotation.mX += 1;
	}
	//�L�[���͂ŃW�����v
	if (CKey::Once(' ') && mJump==false){
		mJpspeed += JUMPPOWER;
		mJump = true;
	}
	//�W�����v�̗͂����Z
	if (mJump == true){
		mPosition.mZ -= 0.3f;
		mJpspeed -= GRAVITY;
		mPosition.mY += mJpspeed;
	}

	//�d�͂�ݒ�
	if (mJump==false){
	mPosition.mY -= GRAVITY;
	}

	//���Ԃ��v��
	if (mCount < 60){
		mCount++;
	}
	else{
		mTime++;
		mCount = 0;
	}
	//�N���A�^�C����n��
	mClearTime = mTime;

	//CCharacter�̍X�V
	CTransform::Update();

}

void CPlayer::Collision(CCollider*m, CCollider*o){
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
			//���n����
			mJump = false;
			mJpspeed = 0;
		}
		break;
	case CCollider::ESPHERE://���R���C�_
		//����̃R���C�_���O�p�R���C�_�̎�
		if (o->mType == CCollider::ETRIANGLE){
			CVector adjust;//�����p�x�N�g��
			//���肪�S�[���̃R���C�_�̏ꍇ
			if (o->mTag == EGOAL){
				//�Փ˂��Ă��邩����
				if(CCollider::CollisionTriangleSphere(o, m, &adjust)){
					//�Փ˂��Ȃ��ʒu�܂Ŗ߂�
					mPosition = mPosition - adjust*-1;
					CPlayer::mEnabled=false;
				}
			}
			//���肪�ǂ̃R���C�_�̏ꍇ
			if (o->mTag == EMAP){
				//�Փ˂��Ă��邩����
				if (CCollider::CollisionTriangleSphere(o, m, &adjust)){
					//�Փ˂��Ȃ��ʒu�܂Ŗ߂�
					mPosition = mPosition - adjust*-1;
				}
			}
			//���肪���̃R���C�_�̏ꍇ
			if (o->mTag == EFLOOR){
				//�Փ˂��Ă��邩����
				if (CCollider::CollisionTriangleSphere(o, m, &adjust)){
					//�Փ˂��Ȃ��ʒu�܂Ŗ߂�
					mPosition = mPosition - adjust*-1;
				}
			}
		}
		break;
	}
}

//�Փˏ���
void CPlayer::TaskCollision()
{
	//�R���C�_�̗D��x�ύX
	mLine.ChangePriority();
	mLine2.ChangePriority();
	mLine3.ChangePriority();

	mCollider.ChangePriority();

	//�Փˏ��������s
	CCollisionManager::Get()->Collision(&mLine, COLLISIONRANGE);
	CCollisionManager::Get()->Collision(&mLine2, COLLISIONRANGE);
	CCollisionManager::Get()->Collision(&mLine3, COLLISIONRANGE);
}

void CPlayer::Render()
{
	//�e�̕`�揈��
	CCharacter::Render();

	//2D�̕`��J�n
	CUtil::Start2D(-400, 400, -300, 300);
	//�`�摤�̐ݒ�(�ΐF�̔�����)
	glColor4f(0.0f, 1.0f, 0.0f, 0.7f);
	//������ҏW�G���A�̍쐬
	char buf[64];
	sprintf_s(buf, "TIME:%dS", mTime);
	//������̕`��
	mText.DrawString(buf, 280, 270, 8, 16);
	//2D�̕`��I��
	CUtil::End2D();
}