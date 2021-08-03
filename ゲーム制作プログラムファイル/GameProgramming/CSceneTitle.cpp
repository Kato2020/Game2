#include "CSceneTitle.h"

#include "CText.h"
#include "CKey.h"
#include "CUtil.h"

void CSceneTitle::Init(){
	//�e�N�X�`���t�@�C���̓ǂݍ���(1�s64��)
	mText.LoadTexture("FontWhite.tga", 1, 64);
	//�V�[���̐ݒ�
	mScene = ETITLE;
}

void CSceneTitle::Update(){

	if (CKey::Once(VK_RETURN)){
		//���̃V�[���̓Q�[��
		mScene = EGAMESELECTION;
	}

	//2D�̕`��J�n
	CUtil::Start2D(-400, 400, -300, 300);
	//�`�摤�̐ݒ�(�ΐF�̔�����)
	glColor4f(0.0f, 1.0f, 0.0f, 1.0f);
	//�����̕`��
	mText.DrawString("TITLE", -200, 0, 50, 50);
	glColor4f(0.0f, 0.0f, 0.0f, 1.0f);
	mText.DrawString("PUSH ENTER KEY", -200, -100, 16, 16);
	//2D�̕`��I��
	CUtil::End2D();
}

//���̃V�[���擾
CScene::EScene CSceneTitle::GetNextScene(){
	return mScene;
}