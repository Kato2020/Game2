#ifndef CSCENEGAME_H
#define CSCENEGAME_H
#include "CScene.h"
#include "CModel.h"
#include "CCharacter.h"
#include "CPlayer.h"


/*
ゲームのシーン
*/
class CSceneGame : public CScene {
public:
	//初期化処理のオーバーライド
	void Init();
	//更新処理のオーバーライド
	void Update();

	//次のシーン取得
	EScene GetNextScene();

	//モデルクラスのインスタンス作成
	CModel mModel;

	CModel mBackGround;//背景モデルの変数

	CVector mEye;
	CPlayer mPlayer;

	CMatrix mBackGroundMatrix;
};

#endif
