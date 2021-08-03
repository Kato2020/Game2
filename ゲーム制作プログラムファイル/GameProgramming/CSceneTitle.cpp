#include "CSceneTitle.h"

#include "CText.h"
#include "CKey.h"
#include "CUtil.h"

void CSceneTitle::Init(){
	//テクスチャファイルの読み込み(1行64列)
	mText.LoadTexture("FontWhite.tga", 1, 64);
	//シーンの設定
	mScene = ETITLE;
}

void CSceneTitle::Update(){

	if (CKey::Once(VK_RETURN)){
		//次のシーンはゲーム
		mScene = EGAMESELECTION;
	}

	//2Dの描画開始
	CUtil::Start2D(-400, 400, -300, 300);
	//描画側の設定(緑色の半透明)
	glColor4f(0.0f, 1.0f, 0.0f, 1.0f);
	//文字の描画
	mText.DrawString("TITLE", -200, 0, 50, 50);
	glColor4f(0.0f, 0.0f, 0.0f, 1.0f);
	mText.DrawString("PUSH ENTER KEY", -200, -100, 16, 16);
	//2Dの描画終了
	CUtil::End2D();
}

//次のシーン取得
CScene::EScene CSceneTitle::GetNextScene(){
	return mScene;
}