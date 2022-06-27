/*
* ���� : �����¿�
* ���� :
	N ũ���� �� �簢���� �ִ�.
	����ڴ� 1,1�� ��ġ�� �ִ�.
	������Ʈ�� ���� U D L R �� �������� �Է��� �޴´�.
	����ڴ� U D L R�� ���� �����δ�.
	���������� ����ڰ� �ִ� ��ġ�� ����Ѵ�.

	�� �� ���簢������ ����� �Է��� ���õȴ�.
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
		cout << " ���簢�� N �Է� >> ";
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

		cout << "���� �Է� >> ";
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
				cout << "�� ���� ���Դϴ�. ������ �ٽ� �Է� ���ֽʽÿ�." << endl;
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

// buffer �ʱ�ȭ
void initBuffer(istream& istr) {
	while (istr.peek()) {				// buffer ���� ��....
		if (getchar() == '\n') 	break;	// buffer �ʱ�ȭ.
	}
}

bool InputFail(istream& istr) {
	bool isFail = false;

	if (istr.fail()) {
		cout << "�ùٸ��� ���� �������� �Է��� �߽��ϴ�. " << endl;
		cout << "�ٽ� �Է� ���ֽʽÿ�. " << endl;

		istr.clear();						// fallbit �ʱ�ȭ
		while (istr.peek()) {				// buffer ���� ��....
			if (getchar() == '\n') 	break;	// buffer �ʱ�ȭ.
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