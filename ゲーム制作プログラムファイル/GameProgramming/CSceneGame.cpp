#include "CSceneGame.h"
#include "CVector.h"
#include "CTriangle.h"
#include "CKey.h"
#include "CTransform.h"
#include "CTaskManager.h"
//OPenGL
#include "glut.h"
#include "CCollisionManager.h"
#include "CBillBoard.h"
#include "CCamera.h"
#include "CColliderMesh.h"
#include "CMap.h"

//�l�p�`���f��
CModel mModelcubeL;
CModel mModelcubeR;
//�O�p�R���C�_�̍쐬
CColliderTriangle mColliderTriangle;
CColliderTriangle mColliderTriangle2;
//���f������R���C�_�𐶐�
CColliderMesh mColliderMesh;

void CSceneGame::Init() {
	mEye = CVector(1.0f, 2.0f, 3.0f);

	//���f���t�@�C���̓���
	mModel.Load("cube.obj", "cube.mtl");

	mPlayer.mpModel = &mModel;
	mPlayer.mScale = CVector(0.1f, 0.1f, 0.1f);
	mPlayer.mPosition = CVector(0.0f, 0.0f, -3.0f)*mBackGroundMatrix;
	mPlayer.mRotation = CVector(0.0f, 180.0f, 0.0f);

	//�l�p�`���f���̓ǂݍ���
	mModelcubeL.Load("cube.obj", "cube.mtl");
	mModelcubeR.Load("cube.obj", "cube.mtl");

	//���ǂ̃C���X�^���X�쐬
	new CMap(&mModelcubeL, CVector(50.0f, 30.0f, 0.0f)
		*mBackGroundMatrix, CVector(), CVector(1.0f, 1.0f, 1.0f));
	//�E�ǂ̃C���X�^���X�쐬
	new CMap(&mModelcubeR, CVector(-50.0f, 30.0f, 0.0f)
		*mBackGroundMatrix, CVector(), CVector(1.0f, 1.0f, 1.0f));

	//�O�p�R���C�_�̊m�F
	mColliderTriangle.Set(NULL, NULL
		, CVector(-5.0f, 0.0f, -100.0f)
		, CVector(-5.0f, 0.0f, 0.0f)
		, CVector(5.0f, 0.0f, 0.0f));
	mColliderTriangle2.Set(NULL, NULL
		, CVector(5.0f, 0.0f, -100.0f)
		, CVector(-5.0f, 0.0f, -100.0f)
		, CVector(5.0f, 0.0f, 0.0f));


}

void CSceneGame::Update() {

	//�^�X�N�}�l�[�W���̍X�V
	CTaskManager::Get()->Update();
	//�R���W�����}�l�[�W���̏Փˏ���
	//�폜�@CCollisionManager::Get()->Collision();
	CTaskManager::Get()->TaskCollision();

	//���_1,���_2,���_3,�@���f�[�^�̍쐬
	CVector v0, v1, v2, n;

	//�@����������Őݒ肷��
	n.mX = 0.0f; n.mY = 1.0f; n.mZ = 0.0f;
	//���_1�̍��W��ݒ肷��
	v0.mX = 0.0f; v0.mY = 0.0f; v0.mZ = 0.5f;
	//���_2�̍��W��ݒ肷��
	v1.mX = 1.0f; v1.mY = 0.0f; v1.mZ = 0.0f;
	//���_3�̍��W��ݒ肷��
	v2.mX = 0.0f; v2.mY = 0.0f; v2.mZ = -0.5f;
	//�J�����̈ړ��̓��͏���
	if (CKey::Push('J'))
	{
		mEye.mX -= 0.1f;
	}
	if (CKey::Push('L'))
	{
		mEye.mX += 0.1f;
	}
	if (CKey::Push('I'))
	{
		mEye.mZ -= 0.1f;
	}
	if (CKey::Push('K'))
	{
		mEye.mZ += 0.1f;
	}
	if (CKey::Push('M'))
	{
		mEye.mY -= 0.1f;
	}
	if (CKey::Push('O'))
	{
		mEye.mY += 0.1f;
	}

	//mPlayer.Update();

	//�J�����̃p�����[�^���쐬����
	CVector e, c, u;//���_�A���S�_�A�����
	//���_�����߂�
	    e = CVector(-2.0f, 10.0f, -30.0f)*mPlayer.mMatrix;
		//�����_�����߂�
		c = mPlayer.mPosition;
	//����������߂�
		u = CVector(0.0f, 1.0f, 0.0f)*mPlayer.mMatrixRotate;
	//�J�����̐ݒ�
	//gluLookAt(e.mX, e.mY, e.mZ, c.mX, c.mY, c.mZ, u.mX, u.mY, u.mZ);


	//�J�����N���X�̐ݒ�
	Camera.Set(e, c, u);
	Camera.Render();

	//mPlayer.Render();

	//�^�X�N���X�g�̍폜
	CTaskManager::Get()->Delete();
	//�^�X�N�}�l�[�W���̕`��
	CTaskManager::Get()->Render();
	//�R���C�_�̕`��
	CCollisionManager::Get()->Render();
}

