#pragma once
#include <vector>

class ChessMap
{
public:
	constexpr ChessMap(const int& size);
	virtual ~ChessMap();
	constexpr const int& getMapSize();
private:
	std::vector<std::vector<int>> mChessMap;
	const int mMapSize;
};

