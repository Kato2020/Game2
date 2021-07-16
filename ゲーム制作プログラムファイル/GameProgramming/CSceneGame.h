#ifndef CSCENEGAME_H
#define CSCENEGAME_H
#include "CScene.h"
#include "CModel.h"
#include "CCharacter.h"
#include "CPlayer.h"


/*
�Q�[���̃V�[��
*/
class CSceneGame : public CScene {
public:
	//�����������̃I�[�o�[���C�h
	void Init();
	//�X�V�����̃I�[�o�[���C�h
	void Update();

	//���̃V�[���擾
	EScene GetNextScene();

	//���f���N���X�̃C���X�^���X�쐬
	CModel mModel;

	CModel mBackGround;//�w�i���f���̕ϐ�

	CVector mEye;
	CPlayer mPlayer;

	CMatrix mBackGroundMatrix;
};

#endif
