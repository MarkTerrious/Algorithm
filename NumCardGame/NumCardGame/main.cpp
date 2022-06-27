/*
* ���� : ���� ī�� ����
* ���� :
	2���� ��Ŀ��� �� ���� ���Ͽ� �� �߿��� ū �� �����ϱ�
	�� ) �࿡�� ���� �����ϴ� ������ ���� ���� ���� ������ �ȴ�.
* �Է� :
	row, col
* ��� :
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
		cout << "�� �� >> ";
		cin >> row >> col;

		if (inputFail(cin)) {
			continue;
		}
		
		break;
	}
	initBuffer(cin);

	// ����Ʈ�� �� �߰�
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

	cout << "�� Ȯ�� " << endl;
	for (auto& iter : arr2D) {
		for (auto& val : iter) {
			cout << val << " ";
		}
		cout << endl;
	}

	// ���� �� ��ŭ ����Ʈ �Ҵ�
	vector<int> candid(row);
	// �� �� ���� ���ǿ� �´� �� ����
	// ���� : �� �߿��� ���� ���� �� ����.
	for (int i = 0; i < row; i++) {
		auto rowIter = std::min_element(begin(arr2D[i]), end(arr2D[i]));
		candid[i] = *rowIter;
	}

	auto candidMaxIter = std::max_element(begin(candid), end(candid));
	int result = *candidMaxIter;

	cout << result << endl;
}

// buffer �ʱ�ȭ
void initBuffer(istream& istr) {
	while (istr.peek()) {				// buffer ���� ��....
		if (getchar() == '\n') 	break;	// buffer �ʱ�ȭ.
	}
}

bool inputFail(istream& istr) {
	bool isFail = false;

	if (istr.fail()) {
		cout << "�ùٸ��� ���� �������� �Է��� �߽��ϴ�. " << endl;
		cout << "�ٽ� �Է� ���ֽʽÿ�. " << endl;

		istr.clear();				// fallbit �ʱ�ȭ
		initBuffer(istr);			// buffer �ʱ�ȭ

		isFail = true;
	}

	return isFail;
}