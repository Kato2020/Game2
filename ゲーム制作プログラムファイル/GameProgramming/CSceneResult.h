#ifndef CSCENERESULT_H
#define CSCENERESULT_H

#include "CScene.h"
#include "CText.h"

class CSceneResult :public CScene{
public:
	//�����������̃I�[�o�[���C�h
	void Init();
	//�X�V�����̃I�[�o�[���C�h
	void Update();
	//���̃V�[���擾
	EScene GetNextScene();
	//�e�L�X�g�̕ϐ�
	CText mText;
};

#endif 