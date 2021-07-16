#ifndef CSCENETITLE_H
#define CSCENETITLE_H

#include "CScene.h"

class CSceneTitle :public CScene{
public:
	//初期化処理のオーバーライド
	void Init();
	//更新処理のオーバーライド
	void Update();
	//次のシーン取得
	EScene GetNextScene();
};

#endif