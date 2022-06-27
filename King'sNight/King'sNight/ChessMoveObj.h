#pragma once

#include <vector>

class ChessMoveObj
{
public:
	constexpr ChessMoveObj(
		const int& mapSize, 
		const int& numOfPath,
		const int& xpos,
		const int& ypos
	);
	virtual ~ChessMoveObj();

private:
	constexpr bool moveCheck(const int& x, const int& y);
private:
	const int mMapSize;
	std::pair<int, int> mCurPos;
	std::vector<std::pair<int, int>> mPathList;
};

