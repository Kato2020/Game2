#include "CVector.h"
#include <math.h>

void CVector::Set(float x, float y, float z){
	mX = x;
	mY = y;
	mZ = z;
}

CVector::CVector()
: mX(0.0f)
, mY(0.0f)
, mZ(0.0f)
{}


CVector::CVector(float x, float y, float z)
: mX(x)
, mY(y)
, mZ(z)
{}


CVector CVector::operator*(const CMatrix &m)
{
	//掛け算の結果をCVector型の値で返す
	return CVector(
		mX*m.mM[0][0] + mY*m.mM[1][0] + mZ*m.mM[2][0] + m.mM[3][0],
		mX*m.mM[0][1] + mY*m.mM[1][1] + mZ*m.mM[2][1] + m.mM[3][1],
		mX*m.mM[0][2] + mY*m.mM[1][2] + mZ*m.mM[2][2] + m.mM[3][2]);
}

//-演算子のオーバーロード
//CVector-CVectorの演算結果を返す
CVector CVector::operator-(const CVector &v){
	return CVector(mX - v.mX, mY - v.mY, mZ - v.mZ);
}
//+演算子のオーバーロード
//CVector+CVectorの演算結果を返す
CVector CVector::operator+(const CVector &v){
	return CVector(mX + v.mX, mY + v.mY, mZ + v.mZ);
}
//*演算子のオーバーロード
//CVector*floatの演算結果を返す
CVector CVector::operator*(const float &f){
	return CVector(mX*f, mY*f, mZ*f);
}
//ベクトルの長さを返す
float CVector::Length(){
	return sqrtf(mX*mX + mY*mY + mZ*mZ);
}
//内積
float CVector::Dot(const CVector &v){
	return mX*v.mX + mY*v.mY + mZ*v.mZ;
}
//外積
CVector CVector::Cross(const CVector &v){
	return CVector(mY*v.mZ - mZ*v.mY, mZ*v.mX - mX*v.mZ, mX*v.mY - mY*v.mX);
}
CVector CVector::Normalize(){
	//ベクトルの大きさで割ったベクトルを返す(長さ1のベクトル)
	return*this*(1.0f / Length());
}





