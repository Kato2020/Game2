#include "CSceneResult.h"

#include "CText.h"
#include "CKey.h"
#include "CUtil.h"
#include <stdio.h>

//プレイヤークラスに宣言された変数のextern宣言
extern int mClearTime;

void CSceneResult::Init(){
	//テクスチャファイルの読み込み(1行64列)
	mText.LoadTexture("FontWhite.tga", 1, 64);
	//シーンの設定
	mScene = ERESULT;
}

void CSceneResult::Update(){

	if (CKey::Once(VK_RETURN)){
		//次のシーンはゲーム
		mScene = EGAMESELECTION;
	}

	//2Dの描画開始
	CUtil::Start2D(-400, 400, -300, 300);
	//描画色の設定
	glColor4f(0.0f, 1.0f, 0.0f, 1.0f);
	//文字の描画
	mText.DrawString("RESULT", -100, 150, 20, 20);
	//文字列編集エリアの作成
	char buf[64];
	sprintf_s(buf, "CLEAR TIME:%dS", mClearTime);
	//描画色の設定
	glColor4f(0.0f, 0.0f, 1.0f, 1.0f);
	//文字列の描画
	mText.DrawString(buf, -250, 0, 20, 20);
	//描画色の設定
	glColor4f(0.0f, 0.0f, 0.0f, 1.0f);
	//文字の描画
	mText.DrawString("PUSH ENTER KEY", -125, -150, 10, 10);
	//2Dの描画終了
	CUtil::End2D();
}

//次のシーン取得
CScene::EScene CSceneResult::GetNextScene(){
	return mScene;
}