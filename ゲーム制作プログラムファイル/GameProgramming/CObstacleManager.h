#ifndef COBSTACLEMANAGER_H
#define COBSTACLEMANAGER_H

#include <time.h>

class CObstacleManager{
public:
	//デフォルトコンストラクタ
	CObstacleManager();
	//一度だけ実行する
	void Init();
	//チュートリアル用の障害物をコースに生成する
	//Generate(コースの長さ,コースの幅, 間隔)
	void Generate(float range, float width, float spacing);
	//3種類の障害物をコースにランダムに生成する
	//GenerateRandom(コースの長さ,コースの幅, 間隔)
	void GenerateRandom(float range, float width, float spacing);
private:
	//システム時刻を保存する変数
	time_t mTime;
	//コースの横幅を3分割した中心
	float mDivisionCenter;
};

#endif