#include "CObstacleManager.h"
//
#include <stdlib.h>
//
#include "CObstacle.h"
#include "CObstacleBig.h"
#include "CObstacleMoving.h"

#define CATEGORY 3 //障害物の種類


//デフォルトコンストラクタ
CObstacleManager::CObstacleManager()
:mTime(0), mDivisionCenter(0)
{}

//一度だけ実行する
void CObstacleManager::Init(){
	//時間をシード値として疑似乱数の引数に設定
	srand((unsigned)time(&mTime));
}

//チュートリアル用コース
void CObstacleManager::Generate(float range,float width,float spacing){
	//コースの横幅を3分割した中心
	mDivisionCenter = width / 3 / 2;
	//間隔を開けてゴールまで
	for (int i = 0; i < range / spacing; i++){
		//コースの左端から障害物の横の位置をランダムに決める
		float x = -width / 2 + mDivisionCenter + rand() % 3 * mDivisionCenter * 2;

		switch ((i+CATEGORY) % CATEGORY)
		{
		case 0:
			//普通サイズの障害物を生成する
			new CObstacle(CVector(x, 0.0f, spacing * i*-1.0f - 10.0f), CVector(), CVector(1.0f, 1.0f, 1.0f));
			break;
		case 1:
			//大きいサイズの障害物を生成
			new CObstacleBig(CVector(x, 0.0f, spacing * i*-1.0f - 10.0f), CVector(), CVector(2.0f, 2.0f, 2.0f));
			break;
		case 2:
			//左右に動く障害物を生成
			new CObstacleMoving(CVector(x, 0.0f, spacing * i*-1.0f - 10.0f), CVector(), CVector(0.8f, 1.8f, 0.8f));
			break;
		default:
			break;
		}
	}
}

//3種類の障害物をコース上にランダムに生成する
void CObstacleManager::GenerateRandom(float renge, float width, float spacing){
	//コースの横幅を3分割した中心
	mDivisionCenter = width / 3 / 2;
	//間隔を開けてゴールまで
	for (int i = 0; i < renge / spacing; i++){
		//コースの左端から障害物の横の位置をランダムに決める
		float x = -width / 2 + mDivisionCenter + rand() % 3 * mDivisionCenter * 2;
		//疑似乱数を生成
		unsigned int mObstacleRandom = rand();
		printf("mObstacleRandom:%d\n,mObstacleRandom");
		int mObstacleType = mObstacleRandom % CATEGORY;
		printf("mObstacleType:%d\n,mObstacleType");
		switch (mObstacleType){
			case 0:
				//普通サイズの障害物を生成する
				new CObstacle(CVector(x, 0.0f, spacing * i*-1.0f - 10.0f), CVector(), CVector(1.0f, 1.0f, 1.0f));
				break;
			case 1:
				//大きいサイズの障害物を生成
				new CObstacleBig(CVector(x, 0.0f, spacing * i*-1.0f - 10.0f), CVector(), CVector(2.0f, 1.0f, 2.0f));
				break;
			case 2:
				//左右に動く障害物を生成
				new CObstacleMoving(CVector(x, 0.0f, spacing * i*-1.0f - 10.0f), CVector(), CVector(0.8f, 1.8f, 0.8f));
				break;
		default:
			break;
		}
	}
}