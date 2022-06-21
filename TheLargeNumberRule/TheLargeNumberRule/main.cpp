#include <iostream>
#include <queue>
#include <vector>

using namespace std;

/*
* 제목 : 큰 수의 법칙
* 설명 :
*	배열의 크기 : N
*	더해지는 횟수 : M
*	연속으로 더할 수 있는 횟수 : K
*	
*	M >= K : M은 K보다 반드시 크거나 같아야 한다.
*	이 때 위 조건을 부합시키면서 N의 원소를 조합해서 만든 제일 큰 수 구하기
* 입력 :
*	N, M, K
* 출력 :
*	result (조합해서 만들어진 제일 큰 수) 
*/

bool inputFail(istream& istr);

int main()
{
	int N = 0,
		M = 0,
		K = 0;
	
	
	// N, M, K 입력
	while (true) 
	{
		cout << "크기, 총 횟수, 원소 중복 횟수 >> ";
		cin >> N >> M >> K;

		if (inputFail(cin)) {
			continue;
		}

		if (!(2 <= N && N <= 1000)) {
			cout << "조건 : 2 <= N <= 1000 " << endl;
			cout << "N : " << N << endl;
			continue;
		}
		else if (
			(!(1 <= M && M <= 10000)) || 
			(!(1 <= K && K <= 10000))
		) {
			cout << "조건 : 1 <= K and M <= 10000 " << endl;
			cout << "M : " << M << endl;
			cout << "K : " << K << endl;
			continue;
		}
		else if (!(M >= K)) {
			cout << "M은 K보다 크거나 같아야 합니다. " << endl << endl;
			cout 
				<< "M : " << M << endl
				<< "K : " << K << endl;
			continue;
		}
		
		break;
	}

	// N만큼 배열 입력
	priority_queue<int> pq;
	for (int i=0; i<N; i++)
	{
		int arrData = 0;
		cout << i+1 << "번째 숫자 입력 >> ";
		cin >> arrData;
		
		if (inputFail(cin)) {
			i--;
			continue;
		}
		
		pq.push(arrData);
	}

	cout << endl;

	size_t listLen = pq.size();	// 총 원소 개수
	int result = 0;				// 결과 변수

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
	*	총 더하는 횟수 == 연속되는 수
	*	총 더하는 횟수 > 연속되는 수
	*/
	if (M == K) {
		result += (topList[0] * K);
	}
	else {
		// max 값 곱하는 횟수.
		int maxTNum =  K * (M / (K + 1));
		// second max값 곱하는 횟수.
		int secMaxTNum = M - maxTNum;

		result += topList[0] * maxTNum;
		result += topList[1] * secMaxTNum;
	}
	
	cout << "결과 : " << result << endl;
	
	return 0;
}

bool inputFail(istream& istr)
{
	bool status = false;

	if (cin.fail()) {
		status = true;
		cout << "올바르지 않은 형식으로 입력을 했습니다. " << endl;
		cout << "다시 입력 해주십시오. " << endl;

		cin.clear();						// fallbit 초기화
		while (cin.peek()) {				// buffer 존재 시....
			if (getchar() == '\n') 	break;	// buffer 초기화.
		}
	}

	return status;
}