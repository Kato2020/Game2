#ifndef CSCENERESULT_H
#define CSCENERESULT_H

#include "CScene.h"
#include "CText.h"

class CSceneResult :public CScene{
public:
	//初期化処理のオーバーライド
	void Init();
	//更新処理のオーバーライド
	void Update();
	//次のシーン取得
	EScene GetNextScene();
	//テキストの変数
	CText mText;
};

#endif 