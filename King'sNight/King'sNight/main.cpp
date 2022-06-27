#include <iostream>
#include <vector>

using namespace std;

// Knight ��ġ ����.
typedef struct Knight {
	pair<int, int> curPos;
	vector<pair<int, int>> pathList;
}Knight;

void initBuffer(istream& istr);
void calMovePath(Knight& knight, const int& mapSize);
bool movePathCheck(const int& xpos, const int& ypos, const int& mapSize);
bool checkPos(const int& pos, const int& mapSize);

int main()
{
	// map
	vector<vector<int>> chessMap;
	constexpr const int chessMapSize = 8;

	chessMap.resize(chessMapSize);
	for (auto& iter : chessMap) {
		iter.resize(chessMapSize);
	}

	Knight knight;
	int xpos = 0;
	int ypos = 0;
	cout << "x , y >> ";
	cin >> xpos >> ypos;

	knight.curPos = move(make_pair(xpos, ypos));
	initBuffer(cin);

	// Knight �̵� ��� ���
	vector<pair<int, int>> pathList;
	
	// Knight �̵� ����� �� ���.
	calMovePath(knight, chessMapSize);
	
	for (auto& iter : knight.pathList) {
		cout << "(" << iter.first << ", " << iter.second << ")" << endl;
	}
}

// �̵� ��� ���
void calMovePath(Knight& knight, const int& mapSize)
{
	const int x = knight.curPos.first;
	const int y = knight.curPos.second;
	vector<pair<int, int>>& list = knight.pathList;

	vector<pair<int, int>> moveList = {
		make_pair(-2, -1), make_pair(-2, +1), make_pair(+2, -1), make_pair(+2, +1),
		make_pair(+1, -2), make_pair(-1, -2), make_pair(-1, +2), make_pair(+1, +2)
	};

	for (int i = 0; i < 8; i++) {
		if (movePathCheck(x + moveList[i].second, y + moveList[i].first, mapSize)) {
			list.push_back(pair<int, int>(x + moveList[i].second, y + moveList[i].first));
		}
	}
}

bool movePathCheck(const int& xpos, const int& ypos, const int& mapSize)
{
	if (checkPos(xpos, mapSize) && checkPos(ypos, mapSize)) {
		return true;
	}
	else {
		return false;
	}
}

bool checkPos(const int& pos, const int& mapSize)
{
	if (0 <= pos && pos < mapSize)
		return true;
	else
		return false;
}

// buffer �ʱ�ȭ
void initBuffer(istream& istr) 
{
	while (istr.peek()) {				// buffer ���� ��....
		if (getchar() == '\n') 	break;	// buffer �ʱ�ȭ.
	}
}