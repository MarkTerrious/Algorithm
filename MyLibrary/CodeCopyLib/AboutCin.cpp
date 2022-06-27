// 숫자 입력 할 때 사용......

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