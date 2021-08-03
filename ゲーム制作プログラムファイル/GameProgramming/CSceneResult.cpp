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
	//�`��F�̐ݒ�
	glColor4f(0.0f, 1.0f, 0.0f, 1.0f);
	//�����̕`��
	mText.DrawString("RESULT", -100, 150, 20, 20);
	//������ҏW�G���A�̍쐬
	char buf[64];
	sprintf_s(buf, "CLEAR TIME:%dS", mClearTime);
	//�`��F�̐ݒ�
	glColor4f(0.0f, 0.0f, 1.0f, 1.0f);
	//������̕`��
	mText.DrawString(buf, -250, 0, 20, 20);
	//�`��F�̐ݒ�
	glColor4f(0.0f, 0.0f, 0.0f, 1.0f);
	//�����̕`��
	mText.DrawString("PUSH ENTER KEY", -125, -150, 10, 10);
	//2D�̕`��I��
	CUtil::End2D();
}

//���̃V�[���擾
CScene::EScene CSceneResult::GetNextScene(){
	return mScene;
}