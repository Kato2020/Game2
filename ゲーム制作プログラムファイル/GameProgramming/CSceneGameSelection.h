#ifndef CSCENEGAMESELECTION_H
#define CSCENEGAMESELECTION_H

#include "CScene.h"
#include "CText.h"

class CSceneGameSelection :public CScene{
public:
	//デフォルトコンストラクタ
	CSceneGameSelection();
	//初期化処理のオーバーライド
	void Init();
	//更新処理のオーバーライド
	void Update();
	//次のシーン取得
	EScene GetNextScene();
	//テキストの変数
	CText mText;
	//次のゲームを指定
	int mNextGame;
};

#endif