#include "CSceneGameSelection.h"
#include <stdio.h>
#include "CText.h"
#include "CKey.h"
#include "CUtil.h"
#include "glut.h"

CSceneGameSelection::CSceneGameSelection()
:mNextGame(0)
{}

void CSceneGameSelection::Init(){
	//テクスチャファイルの読み込み(1行64列)
	mText.LoadTexture("FontWhite.tga", 1, 64);
	//シーンの設定
	mScene = EGAMESELECTION;
}

void CSceneGameSelection::Update(){
	//ゲームシーンを選択
	if (CKey::Once('A')){
		mNextGame = 0;
	}
	//チュートリアルシーンを選択
	if (CKey::Once('D')){
		mNextGame = 1;
	}
	if (CKey::Push(VK_RETURN) && mNextGame == 0){
		//次のシーンはゲーム
		mScene = EGAME;
	}
	if (CKey::Push(VK_RETURN) && mNextGame == 1){
		//次のシーンはチュートリアル
		mScene = ETUTORIAL;
	}
	
	//2Dの描画開始
	CUtil::Start2D(-400, 400, -300, 300);
	//選択したゲームボタンの背景色を変更
	if (mNextGame == 0){
		//描画色の設定(青色の半透明)
		glColor4f(0.0f, 1.0f, 0.0f, 0.4f);
		glBegin(GL_TRIANGLES);
		glVertex2f(-300.0f, 200.0f);
		glVertex2f(-300.0f, -100.0f);
		glVertex2f(0.0f, 200.0f);
		glEnd();
		glBegin(GL_TRIANGLES);
		glVertex2f(-300.0f, -100.0f);
		glVertex2f(0.0f, -100.0f);
		glVertex2f(0.0f, 200.0f);
		glEnd();
	}
	if (mNextGame == 1){
		//描画色の設定(青色の半透明)
		glColor4f(0.0f, 0.0f, 1.0f, 0.4f);
		glBegin(GL_TRIANGLES);
		glVertex2f(0.0f, 200.0f);
		glVertex2f(0.0f, -100.0f);
		glVertex2f(300.0f, 200.0f);
		glEnd();
		glBegin(GL_TRIANGLES);
		glVertex2f(0.0f, -100.0f);
		glVertex2f(300.0f, -100.0f);
		glVertex2f(300.0f, 200.0f);
		glEnd();
	}
	//描画側の設定(黒色)
	glColor4f(0.0f, 0.0f, 0.0f, 1.0f);
	//文字の描画
	mText.DrawString("TUTORIAL", 40, 40, 16, 16);
	mText.DrawString("GAME", -200, 40, 16, 16);
	mText.DrawString("PUSH ENTER KEY", -200, -150, 16, 16);
	//2Dの描画終了
	CUtil::End2D();
}

//次のシーン取得
CScene::EScene CSceneGameSelection::GetNextScene(){
	return mScene;
}