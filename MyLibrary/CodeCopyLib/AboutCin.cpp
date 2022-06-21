// 숫자 입력 할 때 사용......

if (cin.fail()) {
	cout << "올바르지 않은 형식으로 입력을 했습니다. " << endl;
	cout << "다시 입력 해주십시오. " << endl;

	cin.clear();						// fallbit 초기화
	while (cin.peek()) {				// buffer 존재 시....
		if (getchar() == '\n') 	break;	// buffer 초기화.
	}

	continue;
}