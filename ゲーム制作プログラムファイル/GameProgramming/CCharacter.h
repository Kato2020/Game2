#ifndef CCHARACTER_H
#define CCHARACTER_H
//変換行列クラスのインクルード
#include "CTransform.h"
//モデルクラスのインクルード
#include "CModel.h"
//タスククラスのインクルード
#include "CTask.h"
/*
キャラクタークラス
ゲームキャラクターの基本的な機能を定義する
*/
//コライダクラスの宣言
class CCollider;

class CCharacter :public CTransform,public CTask{
public:
	CModel*mpModel; //モデルのポインタ
	//描画処理
	void Render();
	//デストラクタ
	~CCharacter();
	//コンストラクタ
	CCharacter();
	//衝突処理
	virtual void Collision(CCollider*m, CCollider*o){}
	enum ETag
	{
		EZERO,         //初期値
		EPLAYER,       //プレイヤー
		EENEMY,        //敵
		EBULLETPLAYER, //プレイヤー弾
		EBULLETENEMY,  //敵弾
		EMAP,          //コースの壁
		EBLOCK,        //障害物
		EGOAL,         //ゴール
	};
	ETag mTag;
};

#endif