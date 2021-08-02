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
	//描画側の設定(緑色の半透明)
	glColor4f(0.0f, 1.0f, 0.0f, 0.4f);
	//文字の描画
	mText.DrawString("RESULT", -200, 0, 50, 50);
	mText.DrawString("Push ENTER Key", -200, -100, 16, 16);
	//文字列編集エリアの作成
	char buf[64];
	sprintf_s(buf, "ClearTime:%ds", mClearTime);
	//文字列の描画
	mText.DrawString(buf, 350, 250, 8, 16);
	//2Dの描画終了
	CUtil::End2D();
}

//次のシーン取得
CScene::EScene CSceneResult::GetNextScene(){
	return mScene;
}