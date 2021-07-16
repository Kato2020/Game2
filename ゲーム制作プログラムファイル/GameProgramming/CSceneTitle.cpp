#include "CSceneTitle.h"

#include "CText.h"
#include "CKey.h"

void CSceneTitle::Init(){
	//テクスチャファイルを読み込む
	//フォントの設定
	//CText::mFont.Load("font.tga");
	//シーンの設定
	mScene = ETITLE;
}

void CSceneTitle::Update(){
	//文字の描画
	//CText::DrawString("TITLE", -200, 0, 50, 50);
	//CText::DrawString("Push ENTER Key", -200, -100, 16, 16);
	if (CKey::Once(VK_RETURN)){
		//次のシーンはゲーム
		mScene = EGAME;
	}
}

//次のシーン取得
CScene::EScene CSceneTitle::GetNextScene(){
	return mScene;
}