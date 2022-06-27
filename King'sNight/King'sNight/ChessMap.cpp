#include "ChessMap.h"

ChessMap::ChessMap(const int& size)
	:mMapSize(size)
{
	mChessMap.resize(size);
	for (auto& iter : mChessMap) {
		iter.resize(size);
	}
}

ChessMap::~ChessMap() {}

const int& ChessMap::getMapSize()
{
	return mMapSize;
}