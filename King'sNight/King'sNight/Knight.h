#pragma once
#include "ChessMoveObj.h"

class Knight : public ChessMoveObj
{
public:
	Knight(const int& mapSize);
	virtual ~Knight();
	
private:
	void movePath();
	bool movePathCheck(const int& x, const int& y);
private:
	const int mDefaultMaxMovePath = 8;
};

