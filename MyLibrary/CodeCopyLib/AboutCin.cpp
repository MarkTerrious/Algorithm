// ���� �Է� �� �� ���......

if (cin.fail()) {
	cout << "�ùٸ��� ���� �������� �Է��� �߽��ϴ�. " << endl;
	cout << "�ٽ� �Է� ���ֽʽÿ�. " << endl;

	cin.clear();						// fallbit �ʱ�ȭ
	while (cin.peek()) {				// buffer ���� ��....
		if (getchar() == '\n') 	break;	// buffer �ʱ�ȭ.
	}

	continue;
}