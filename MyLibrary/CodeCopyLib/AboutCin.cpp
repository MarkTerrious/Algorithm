// ���� �Է� �� �� ���......

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