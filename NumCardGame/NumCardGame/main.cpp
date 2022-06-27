/*
* 제목 : 숫자 카드 게임
* 설명 :
	2차원 행렬에서 행 끼리 비교하여 그 중에서 큰 수 선택하기
	단 ) 행에서 값을 선택하는 기준은 제일 작은 값이 기준이 된다.
* 입력 :
	row, col
* 출력 :
	result
**/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void initBuffer(istream& istr);
bool inputFail(istream& istr);

int main()
{
	vector<vector<int>> arr2D;
	int row = 0,
		col = 0;

	while (true)
	{
		cout << "행 열 >> ";
		cin >> row >> col;

		if (inputFail(cin)) {
			continue;
		}
		
		break;
	}
	initBuffer(cin);

	// 리스트에 행 추가
	arr2D.resize(row);

	for (int i = 0; i < row; i++) {
		int tVal = 0;
		for (int j = 0; j < col; j++) {
			cout << "[" << i << ", " << j << "]" << " >> ";
			cin >> tVal;
			if (inputFail(cin)) {
				j--;
				continue;
			}
			arr2D[i].push_back(tVal);
		}
		cout << endl;
	}

	cout << "값 확인 " << endl;
	for (auto& iter : arr2D) {
		for (auto& val : iter) {
			cout << val << " ";
		}
		cout << endl;
	}

	// 행의 수 만큼 리스트 할당
	vector<int> candid(row);
	// 각 행 마다 조건에 맞는 수 선택
	// 조건 : 행 중에서 가장 작은 수 선택.
	for (int i = 0; i < row; i++) {
		auto rowIter = std::min_element(begin(arr2D[i]), end(arr2D[i]));
		candid[i] = *rowIter;
	}

	auto candidMaxIter = std::max_element(begin(candid), end(candid));
	int result = *candidMaxIter;

	cout << result << endl;
}

// buffer 초기화
void initBuffer(istream& istr) {
	while (istr.peek()) {				// buffer 존재 시....
		if (getchar() == '\n') 	break;	// buffer 초기화.
	}
}

bool inputFail(istream& istr) {
	bool isFail = false;

	if (istr.fail()) {
		cout << "올바르지 않은 형식으로 입력을 했습니다. " << endl;
		cout << "다시 입력 해주십시오. " << endl;

		istr.clear();				// fallbit 초기화
		initBuffer(istr);			// buffer 초기화

		isFail = true;
	}

	return isFail;
}