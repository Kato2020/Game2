#ifndef CENEMY_H
#define CENEMY_H
//キャラクタクラスのインクルード
#include "CCharacter.h"
//コライダクラスのインクルード
#include "CCollider.h"
/*
エネミークラス
キャラクタクラスを継承
*/
class CEnemy : public CCharacter{
public:
	//コンストラクタ
	//CEnemy(モデル,位置,回転,拡縮)
	CEnemy(CModel*model, CVector position, CVector rotation, CVector scale);
	//更新処理
	void Update();

	CCollider mCollider1;
	CCollider mCollider2;
	CCollider mCollider3;

	//衝突処理
	//Collision(コライダ1,コライダ2)
	void Collision(CCollider*m, CCollider*o);
	//衝突処理
	void TaskCollision();
};

#endif