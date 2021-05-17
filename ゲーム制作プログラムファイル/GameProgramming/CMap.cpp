#include "CMap.h"
#include "CTaskManager.h"

CMap::CMap(CModel*model, CVector position, CVector rotation, CVector scale){
	//ƒ‚ƒfƒ‹AˆÊ’uA‰ñ“]AŠgk‚ðÝ’è‚·‚é
	mpModel = model;      //ƒ‚ƒfƒ‹‚ÌÝ’è
	mPosition = position; //ˆÊ’u‚ÌÝ’è
	mRotation = rotation; //‰ñ“]‚ÌÝ’è
	mScale = scale;       //kŽÚ‚ÌÝ’è
	//—Dæ“x‚ð1‚É•ÏX‚·‚é
	mPriority = 1;
	CTaskManager::Get()->Remove(this);//íœ‚µ‚Ä
	CTaskManager::Get()->Add(this);//’Ç‰Á‚·‚é
}