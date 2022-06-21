#include <iostream>
#include <queue>
#include <vector>

using namespace std;

/*
* ���� : ū ���� ��Ģ
* ���� :
*	�迭�� ũ�� : N
*	�������� Ƚ�� : M
*	�������� ���� �� �ִ� Ƚ�� : K
*	
*	M >= K : M�� K���� �ݵ�� ũ�ų� ���ƾ� �Ѵ�.
*	�� �� �� ������ ���ս�Ű�鼭 N�� ���Ҹ� �����ؼ� ���� ���� ū �� ���ϱ�
* �Է� :
*	N, M, K
* ��� :
*	result (�����ؼ� ������� ���� ū ��) 
*/

bool inputFail(istream& istr);

int main()
{
	int N = 0,
		M = 0,
		K = 0;
	
	
	// N, M, K �Է�
	while (true) 
	{
		cout << "ũ��, �� Ƚ��, ���� �ߺ� Ƚ�� >> ";
		cin >> N >> M >> K;

		if (inputFail(cin)) {
			continue;
		}

		if (!(2 <= N && N <= 1000)) {
			cout << "���� : 2 <= N <= 1000 " << endl;
			cout << "N : " << N << endl;
			continue;
		}
		else if (
			(!(1 <= M && M <= 10000)) || 
			(!(1 <= K && K <= 10000))
		) {
			cout << "���� : 1 <= K and M <= 10000 " << endl;
			cout << "M : " << M << endl;
			cout << "K : " << K << endl;
			continue;
		}
		else if (!(M >= K)) {
			cout << "M�� K���� ũ�ų� ���ƾ� �մϴ�. " << endl << endl;
			cout 
				<< "M : " << M << endl
				<< "K : " << K << endl;
			continue;
		}
		
		break;
	}

	// N��ŭ �迭 �Է�
	priority_queue<int> pq;
	for (int i=0; i<N; i++)
	{
		int arrData = 0;
		cout << i+1 << "��° ���� �Է� >> ";
		cin >> arrData;
		
		if (inputFail(cin)) {
			i--;
			continue;
		}
		
		pq.push(arrData);
	}

	cout << endl;

	size_t listLen = pq.size();	// �� ���� ����
	int result = 0;				// ��� ����

	vector<int> topList;		// container for max, second max
	const int repeatNum = 2;
	for (int i = 0; i < repeatNum; i++) {
		topList.push_back(pq.top());
		pq.pop();
	}

	for (auto& val : topList) {
		cout << val << endl;
	}
	/*
	* case
	*	�� ���ϴ� Ƚ�� == ���ӵǴ� ��
	*	�� ���ϴ� Ƚ�� > ���ӵǴ� ��
	*/
	if (M == K) {
		result += (topList[0] * K);
	}
	else {
		// max �� ���ϴ� Ƚ��.
		int maxTNum =  K * (M / (K + 1));
		// second max�� ���ϴ� Ƚ��.
		int secMaxTNum = M - maxTNum;

		result += topList[0] * maxTNum;
		result += topList[1] * secMaxTNum;
	}
	
	cout << "��� : " << result << endl;
	
	return 0;
}

bool inputFail(istream& istr)
{
	bool status = false;

	if (cin.fail()) {
		status = true;
		cout << "�ùٸ��� ���� �������� �Է��� �߽��ϴ�. " << endl;
		cout << "�ٽ� �Է� ���ֽʽÿ�. " << endl;

		cin.clear();						// fallbit �ʱ�ȭ
		while (cin.peek()) {				// buffer ���� ��....
			if (getchar() == '\n') 	break;	// buffer �ʱ�ȭ.
		}
	}

	return status;
}