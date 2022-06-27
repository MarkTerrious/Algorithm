/*
* 제목 : 상하좌우
* 설명 :
	N 크기의 정 사각형이 있다.
	사용자는 1,1에 위치해 있다.
	프롬프트로 부터 U D L R 을 연속으로 입력을 받는다.
	사용자는 U D L R에 따라 움직인다.
	최종적으로 사용자가 있는 위치를 출력한다.

	이 때 정사각형안을 벗어나는 입력은 무시된다.
*/


#include <iostream>
#include <vector>
#include <string>
#include <regex>

using namespace std;

void initBuffer(istream& istr);
bool InputFail(istream& istr);
int moveCheckInSquare(const int& move, const int& sqSize);

int main()
{
	int N = 0;
	string direction;

	while (true) {
		cout << " 정사각형 N 입력 >> ";
		cin >> N;
		if (InputFail(cin))	continue;
		else break;
	}
	initBuffer(cin);

	// Square N x N
	vector<vector<int>> square(N);
	for (int i = 0; i < square.size(); i++) {
		square[i].resize(N);
	}


	vector<string> userInput;

	// user input U(UP), D(DOWN), L(LEFT), R(RIGHT)
	while (true) {
		bool escape = true;

		cout << "방향 입력 >> ";
		getline(cin, direction);

		regex tokenReg("\\s+");
		regex regUDLR("[UDLR]");
		sregex_token_iterator end;
		for (
			auto iter = sregex_token_iterator(cbegin(direction), cend(direction), tokenReg, -1);
			iter != end; ++iter
			) {
			cout << *iter << " ";
			if (!regex_match(iter->str(), regUDLR)) {
				cout << "잘 못된 값입니다. 방향을 다시 입력 해주십시오." << endl;
				vector<string>().swap(userInput);
				escape = false;
			}
			userInput.push_back(iter->str());
		}

		if (escape) break;
	}


	
	cout << " end .. " << endl;

	int row = 0;
	int col = 0;
	const int sqLen = static_cast<int>(square.size());
	for (auto& iter : userInput) {
		switch (iter[0])
		{
		case 'U':
			row = moveCheckInSquare(row - 1, sqLen);
			break;
		case 'D':
			row = moveCheckInSquare(row + 1, sqLen);
			break;
		case 'L':
			col = moveCheckInSquare(col - 1, sqLen);
			break;
		case 'R':
			col = moveCheckInSquare(col + 1, sqLen);
			break;
		}
	}

	cout << row + 1 << " " << col + 1 << endl;
	
	return 0;
}

// buffer 초기화
void initBuffer(istream& istr) {
	while (istr.peek()) {				// buffer 존재 시....
		if (getchar() == '\n') 	break;	// buffer 초기화.
	}
}

bool InputFail(istream& istr) {
	bool isFail = false;

	if (istr.fail()) {
		cout << "올바르지 않은 형식으로 입력을 했습니다. " << endl;
		cout << "다시 입력 해주십시오. " << endl;

		istr.clear();						// fallbit 초기화
		while (istr.peek()) {				// buffer 존재 시....
			if (getchar() == '\n') 	break;	// buffer 초기화.
		}

		isFail = true;
	}

	return isFail;
}

int moveCheckInSquare(const int& move, const int& sqSize)
{
	int correctMove = move;

	if (move < 0) {
		correctMove = 0;
	}
	else if (move > sqSize - 1) {
		correctMove = sqSize - 1;
	}

	return correctMove;
}