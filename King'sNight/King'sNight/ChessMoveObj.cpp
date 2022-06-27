#include "ChessMoveObj.h"

ChessMoveObj::ChessMoveObj(
	const int& mapSize, const int& numOfPath
)
	: mMapSize(mapSize), mPathList(numOfPath)
{}

ChessMoveObj::~ChessMoveObj() {}
bool ChessMoveObj::moveCheck(const int& x, const int& y)
{
	if (mMapSize <= x || mMapSize <= y)
		return false;
	else if (x < 0 || y < 0)
		return false;
	else
		return true;
}