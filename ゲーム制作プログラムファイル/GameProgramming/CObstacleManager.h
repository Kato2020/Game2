#ifndef COBSTACLEMANAGER_H
#define COBSTACLEMANAGER_H

#include "CObstacle.h"

class CObstacleManager{
public:
	//デフォルトコンストラクタ
	CObstacleManager();
	//一度だけ実行する
	void Init();
	//通常の障害物をコース上に生成する
	//Generate(マップの長さ,間隔)
	void Generate(float range, float spacing);
	//3種類の障害物をコースにランダムに生成する
	//GenerateRandom(マップの長さ,間隔)
	void GenerateRandom(float range, float spacing);
private:
	//シード値
	unsigned int  randomSeed;
	//生成する障害物の種類
	int mObstacleType;
};

#endif