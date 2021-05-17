#ifndef CMATERIAL_H
#define CMATERIAL_H

#include "CTexture.h"

/*
�}�e�G���A���N���X
�}�e���A���̃f�[�^������
*/
class CMaterial{
public:
	//�}�e���A����
	char mName[64];
	//�g�U���̐FRGBA
	float mDiffuse[4];
	//�f�t�H���g�R���X�g���N�^
	CMaterial();
	//�e�N�X�`��
	CTexture mTexture;
	//�}�e���A����L���ɂ���
	void Enabled();
	//�}�e���A���𖳌��ɂ���
	void Disabled();
	//�}�e���A�����̒��_��
	int mVertexNum;
};

#endif