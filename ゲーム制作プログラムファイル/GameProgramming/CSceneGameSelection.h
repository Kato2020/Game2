#ifndef CSCENEGAMESELECTION_H
#define CSCENEGAMESELECTION_H

#include "CScene.h"
#include "CText.h"

class CSceneGameSelection :public CScene{
public:
	//�f�t�H���g�R���X�g���N�^
	CSceneGameSelection();
	//�����������̃I�[�o�[���C�h
	void Init();
	//�X�V�����̃I�[�o�[���C�h
	void Update();
	//���̃V�[���擾
	EScene GetNextScene();
	//�e�L�X�g�̕ϐ�
	CText mText;
	//���̃Q�[�����w��
	int mNextGame;
};

#endif