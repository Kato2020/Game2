#ifndef CMODEL_H
#define CMODEL_H

// vector�̃C���N���[�h
#include <vector>
#include "CTriangle.h"
#include "CMaterial.h"

/*
���f���N���X
���f���f�[�^�̓��͂�\��
*/
class CModel{
public:
	//���f���t�@�C���̓���
	//Load(���f���t�@�C����,�}�e���A���t�@�C����)
	void Load(char*obj, char*mtl);
	//�O�p�`�̉ϒ��z��
	std::vector<CTriangle>mTriangles;
	//�}�e���A���|�C���^�̉ϒ��z��
	std::vector<CMaterial*>mpMaterials;
	//�`��
	void Render();
	//�`��
	//Render(�s��)
	void Render(const CMatrix &m);
	~CModel();
	//���_�z��
	float*mpVertex;//���_���W
	float*mpNormal;//�@��
	float*mpTextureCoord;//�e�N�X�`���}�b�s���O
	//�f�t�H���g�R���X�g���N�^
	CModel();

};

#endif