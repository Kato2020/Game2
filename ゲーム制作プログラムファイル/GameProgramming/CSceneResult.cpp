#include "CSceneResult.h"

#include "CText.h"
#include "CKey.h"
#include "CUtil.h"
#include <stdio.h>

//�v���C���[�N���X�ɐ錾���ꂽ�ϐ���extern�錾
extern int mClearTime;

void CSceneResult::Init(){
	//�e�N�X�`���t�@�C���̓ǂݍ���(1�s64��)
	mText.LoadTexture("FontWhite.tga", 1, 64);
	//�V�[���̐ݒ�
	mScene = ERESULT;
}

void CSceneResult::Update(){

	if (CKey::Once(VK_RETURN)){
		//���̃V�[���̓Q�[��
		mScene = EGAMESELECTION;
	}

	//2D�̕`��J�n
	CUtil::Start2D(-400, 400, -300, 300);
	//�`�摤�̐ݒ�(�ΐF�̔�����)
	glColor4f(0.0f, 1.0f, 0.0f, 0.4f);
	//�����̕`��
	mText.DrawString("RESULT", -200, 0, 50, 50);
	mText.DrawString("Push ENTER Key", -200, -100, 16, 16);
	//������ҏW�G���A�̍쐬
	char buf[64];
	sprintf_s(buf, "ClearTime:%ds", mClearTime);
	//������̕`��
	mText.DrawString(buf, 350, 250, 8, 16);
	//2D�̕`��I��
	CUtil::End2D();
}

//���̃V�[���擾
CScene::EScene CSceneResult::GetNextScene(){
	return mScene;
}