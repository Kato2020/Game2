#ifndef CMATERIAL_H
#define CMATERIAL_H

#include "CTexture.h"

/*
マテエリアルクラス
マテリアルのデータを扱う
*/
class CMaterial{
public:
	//マテリアル名
	char mName[64];
	//拡散光の色RGBA
	float mDiffuse[4];
	//デフォルトコンストラクタ
	CMaterial();
	//テクスチャ
	CTexture mTexture;
	//マテリアルを有効にする
	void Enabled();
	//マテリアルを無効にする
	void Disabled();
	//マテリアル毎の頂点数
	int mVertexNum;
};

#endif