#include "CObstacleManager.h"
#include <stdlib.h>

//デフォルトコンストラクタ
CObstacleManager::CObstacleManager()
:randomSeed(0), mObstacleType(0)
{}

//一度だけ実行する
void CObstacleManager::Init(){
	srand(randomSeed);
}

//通常の障害物をコース上に生成する
void Generate(float range,float spacing){
	//間隔を開けてゴールまで障害物を生成
	for (int i = 0; i < range / spacing; i++){
		//普通サイズの障害物を生成する
		new CObstacle(CVector(0.0f, 0.0f, spacing*1), CVector(), CVector(1.0f, 1.0f, 1.0f));
	}
}

//3種類の障害物をコース上にランダムに生成する
void GenerateRandom(float renge, float spacing){
	//間隔を開けてゴールまで障害物を生成
	for (int i = 0; i < renge / spacing; i++){
		//ランダムな値を生成
		int mObstacleType = rand();
		mObstacleType %= 3;
		switch (mObstacleType){
			case 0:
				//普通サイズの障害物を生成する
				new CObstacle(CVector(0.0f, 0.0f, spacing*1), CVector(), CVector(1.0f, 1.0f, 1.0f));
			case 1:
				//大きいサイズの障害物を生成
			case 2:
				//左右に動く障害物を生成
		default:
			break;
		}
	}
}