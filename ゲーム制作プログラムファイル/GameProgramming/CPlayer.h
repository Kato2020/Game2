#ifndef CPLAYER_H
#define CPLAYER_H
//キャラクタクラスのインクルード
#include "CCharacter.h"
#include "CColliderLine.h"
#include "CText.h"
/*
プレイヤークラス
キャラクタクラスを継承
*/
class CPlayer :public CCharacter{
public:
	//更新処理
	void Update();
	CColliderLine mLine;//線分コライダ
	CColliderLine mLine2;
	CColliderLine mLine3;
	//本体衝突判定用コライダ
	CCollider mCollider; //本体用コライダ
	CPlayer();
	//衝突処理
	void Collision(CCollider*m, CCollider*o);
	//衝突処理
	void TaskCollision();
	//文字列の描画を行うCTextクラスの変数mText
	CText mText;
	//描画処理
	void Render();
};

#endif