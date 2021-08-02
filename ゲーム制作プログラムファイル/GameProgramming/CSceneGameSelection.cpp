#include "CSceneGameSelection.h"
#include <stdio.h>
#include "CText.h"
#include "CKey.h"
#include "CUtil.h"
#include "glut.h"

CSceneGameSelection::CSceneGameSelection()
:mNextGame(0)
{}

void CSceneGameSelection::Init(){
	//�e�N�X�`���t�@�C���̓ǂݍ���(1�s64��)
	mText.LoadTexture("FontWhite.tga", 1, 64);
	//�V�[���̐ݒ�
	mScene = EGAMESELECTION;
}

void CSceneGameSelection::Update(){
	//�Q�[���V�[����I��
	if (CKey::Once('A')){
		mNextGame = 0;
	}
	//�`���[�g���A���V�[����I��
	if (CKey::Once('D')){
		mNextGame = 1;
	}
	if (CKey::Once(VK_RETURN) && mNextGame == 0){
		//���̃V�[���̓Q�[��
		mScene = EGAME;
	}
	if (CKey::Once(VK_RETURN) && mNextGame == 1){
		//���̃V�[���̓`���[�g���A��
		mScene = ETUTORIAL;
	}
	
	//2D�̕`��J�n
	CUtil::Start2D(-400, 400, -300, 300);
	//�I�������Q�[���{�^���̔w�i�F��ύX
	if (mNextGame == 0){
		//�`��F�̐ݒ�(�F�̔�����)
		glColor4f(0.0f, 0.0f, 1.0f, 0.4f);
		glBegin(GL_TRIANGLES);
		glVertex2f(-300.0f, 200.0f);
		glVertex2f(-300.0f, -100.0f);
		glVertex2f(0.0f, 200.0f);
		glEnd();
		glBegin(GL_TRIANGLES);
		glVertex2f(-300.0f, -100.0f);
		glVertex2f(0.0f, -100.0f);
		glVertex2f(0.0f, 200.0f);
		glEnd();
	}
	if (mNextGame == 1){
		//�`��F�̐ݒ�(�F�̔�����)
		glColor4f(0.0f, 0.0f, 1.0f, 0.4f);
		glBegin(GL_TRIANGLES);
		glVertex2f(0.0f, 200.0f);
		glVertex2f(0.0f, -100.0f);
		glVertex2f(300.0f, 200.0f);
		glEnd();
		glBegin(GL_TRIANGLES);
		glVertex2f(0.0f, -100.0f);
		glVertex2f(300.0f, -100.0f);
		glVertex2f(300.0f, 200.0f);
		glEnd();
	}
	//�`�摤�̐ݒ�(�ΐF)
	glColor4f(0.0f, 1.0f, 0.0f, 0.7f);
	//�����̕`��
	mText.DrawString("Push ENTER Key", -200, -100, 16, 16);
	mText.DrawString("Tutorial", -200, -100, 16, 16);
	mText.DrawString("Game", -200, -100, 16, 16);
	//2D�̕`��I��
	CUtil::End2D();
}

//���̃V�[���擾
CScene::EScene CSceneGameSelection::GetNextScene(){
	return mScene;
}