#include "CSceneGame.h"
#include "CVector.h"
#include "CTriangle.h"
#include "CKey.h"
#include "CTransform.h"
#include "CTaskManager.h"
//OPenGL
#include "glut.h"
#include "CCollisionManager.h"
#include "CBillBoard.h"
#include "CCamera.h"
#include "CColliderMesh.h"
#include "CMap.h"

//四角形モデル
CModel mModelcubeL;
CModel mModelcubeR;
//三角コライダの作成
CColliderTriangle mColliderTriangle;
CColliderTriangle mColliderTriangle2;
//モデルからコライダを生成
CColliderMesh mColliderMesh;

void CSceneGame::Init() {
	mEye = CVector(1.0f, 2.0f, 3.0f);

	//モデルファイルの入力
	mModel.Load("cube.obj", "cube.mtl");

	mPlayer.mpModel = &mModel;
	mPlayer.mScale = CVector(0.1f, 0.1f, 0.1f);
	mPlayer.mPosition = CVector(0.0f, 0.0f, -3.0f)*mBackGroundMatrix;
	mPlayer.mRotation = CVector(0.0f, 180.0f, 0.0f);

	//四角形モデルの読み込み
	mModelcubeL.Load("cube.obj", "cube.mtl");
	mModelcubeR.Load("cube.obj", "cube.mtl");

	//左壁のインスタンス作成
	new CMap(&mModelcubeL, CVector(50.0f, 30.0f, 0.0f)
		*mBackGroundMatrix, CVector(), CVector(1.0f, 1.0f, 1.0f));
	//右壁のインスタンス作成
	new CMap(&mModelcubeR, CVector(-50.0f, 30.0f, 0.0f)
		*mBackGroundMatrix, CVector(), CVector(1.0f, 1.0f, 1.0f));

	//三角コライダの確認
	mColliderTriangle.Set(NULL, NULL
		, CVector(-5.0f, 0.0f, -100.0f)
		, CVector(-5.0f, 0.0f, 0.0f)
		, CVector(5.0f, 0.0f, 0.0f));
	mColliderTriangle2.Set(NULL, NULL
		, CVector(5.0f, 0.0f, -100.0f)
		, CVector(-5.0f, 0.0f, -100.0f)
		, CVector(5.0f, 0.0f, 0.0f));


}

void CSceneGame::Update() {

	//タスクマネージャの更新
	CTaskManager::Get()->Update();
	//コリジョンマネージャの衝突処理
	//削除　CCollisionManager::Get()->Collision();
	CTaskManager::Get()->TaskCollision();

	//頂点1,頂点2,頂点3,法線データの作成
	CVector v0, v1, v2, n;

	//法線を上向きで設定する
	n.mX = 0.0f; n.mY = 1.0f; n.mZ = 0.0f;
	//頂点1の座標を設定する
	v0.mX = 0.0f; v0.mY = 0.0f; v0.mZ = 0.5f;
	//頂点2の座標を設定する
	v1.mX = 1.0f; v1.mY = 0.0f; v1.mZ = 0.0f;
	//頂点3の座標を設定する
	v2.mX = 0.0f; v2.mY = 0.0f; v2.mZ = -0.5f;
	//カメラの移動の入力処理
	if (CKey::Push('J'))
	{
		mEye.mX -= 0.1f;
	}
	if (CKey::Push('L'))
	{
		mEye.mX += 0.1f;
	}
	if (CKey::Push('I'))
	{
		mEye.mZ -= 0.1f;
	}
	if (CKey::Push('K'))
	{
		mEye.mZ += 0.1f;
	}
	if (CKey::Push('M'))
	{
		mEye.mY -= 0.1f;
	}
	if (CKey::Push('O'))
	{
		mEye.mY += 0.1f;
	}

	//mPlayer.Update();

	//カメラのパラメータを作成する
	CVector e, c, u;//視点、中心点、上方向
	//視点を求める
	    e = CVector(-2.0f, 10.0f, -30.0f)*mPlayer.mMatrix;
		//注視点を求める
		c = mPlayer.mPosition;
	//上方向を求める
		u = CVector(0.0f, 1.0f, 0.0f)*mPlayer.mMatrixRotate;
	//カメラの設定
	//gluLookAt(e.mX, e.mY, e.mZ, c.mX, c.mY, c.mZ, u.mX, u.mY, u.mZ);


	//カメラクラスの設定
	Camera.Set(e, c, u);
	Camera.Render();

	//mPlayer.Render();

	//タスクリストの削除
	CTaskManager::Get()->Delete();
	//タスクマネージャの描画
	CTaskManager::Get()->Render();
	//コライダの描画
	CCollisionManager::Get()->Render();
}

