#include <iostream>
#include <windows.h>
#include <string>
#include <vector>
using namespace std;

//����������� ��������������� �����
bool isInt(string x) {
	bool e;
	try {
		int num = stoi(x);
		return e = 1;
	}
	catch (...) {
		return e = 0;
	}

} // �������, ������������ �������� �� ���� ������ 

//������� �� ������ � �����
int INTj() {
	while (true) {
		string number;
		int num;

		cout << "������� �����:" << endl;
		cin >> number;
		if (isInt(number)) {
			return num = stoi(number);
			break;
		}
		else {
			cout << "������: ������� ���������� �������� ��������.\n";
		}
	}
}

void del(vector<int>& vec, int num) {
	for (int i = 1; i < sqrt(num); i++) {
		if (num % i == 0) {
			vec.push_back(i);
			vec.push_back(num / i);
		}
	}
}

int fibobnachi(int destination) {
	switch (destination) {
	case 0:
		return 0;
	case 1:
		return 1;
	default:
		return fibobnachi(destination - 1) + fibobnachi(destination - 2);
	}
}

//���������� ���������� �����
void factorial() {
	int num;
	while (true) {
		string number;
		cout << "������� �����:" << endl;
		cin >> number;

		if (isInt(number)) {
			num = stoi(number);
			if (num < 0) {
				cout << "������: ��������� �� �������� ��� ������������� �����.\n";
			}
			else if (num > 20) {
				cout << "������: ����� ������� ������� ��� ������� ����������.\n";
			}
			else {
				break;
			}
		}
		else {
			cout << "������: ������� ���������� �������� ��������.\n";
		}
	}

	long long s = 1;
	for (int i = 2; i <= num; i++) {
		s *= i;
	}

	cout << "��������� " << num << " = " << s << endl;
}

//���������� ����������� ������ ��������
void NOD() {
	int a, b, max = 0;
	vector<int> delA;
	vector<int> delB;

	//���� ������� �����
	a = INTj();
	//�������� ������� ��������� ������� �����
	del(delA, a);

	//���� ������� �����
	b = INTj();
	//�������� ������� ��������� ������� �����
	del(delB, b);

	for (int i : delA) {
		for (int j : delB) {
			if (i == j && max < i) {
				max = i;
			}
		}
	}

	cout << "���������� ����� �������� ����� " << a << " � " << b << " = " << max << "." << endl;
}

//�������� ����� �� ��������
void isPrime() {
	int num;
	num = INTj();
	bool isprime = 1;

	if (num > 0) {
		switch (num) {
		case 1:
			cout << "����� �� �������� �������.\n";
			break;
		case 2:
			cout << "����� �������� �������.\n";
			break;
		case 3:
			cout << "����� �������� �������.\n";
			break;
		case 4:
			cout << "����� �� �������� �������.\n";
			break;
		default:
			for (int i = 2; i < sqrt(num); i++)
			{
				if (num % i == 0) {
					isprime = 0;
					break;
				}
			}
			if (isprime) {
				cout << "����� �������� �������." << endl;
			}
			else {
				cout << "����� �� �������� �������." << endl;
			}
		}
	}
}

//�������� ������ �� ��, �������� �� ��� �����������
void palindrome() {
	string str, rts;

	cout << "������� ������:" << endl;
	cin >> str;

	//�������� ������
	for (int i = str.size() - 1; i >= 0; --i) {
		rts += str[i];
	}

	if (rts == str) {
		cout << "������ �������� �����������." << endl;
	}
	else {
		cout << "������ �� �������� ������������." << endl << "��������� ������:" << endl << str << endl << "����������� ������:" << rts << endl;
	}
}

//���������� ���� ���������
void fibonacciNumbers() {
	int destination;
	cout << "������� �� ������ ����� ����� ����������� ���" << endl;
	destination = INTj();
	cout << "������������������ ���������: ";
	for (int i = 0; i < destination; i++) {
		cout << fibobnachi(i) << " ";
	}
	cout << endl;
}

//����� �������
void hepl() {
	cout << "������ ������:" << endl;
	cout << "1. ��������� -- ����������� � ������������ �� ���� �����, ����� ���� ������� ��������� ����� �����" << endl;
	cout << "2. ���������� ����� �������� -- ����������� �� ���� ������������ ��� ����� �����, ����� ������� ���������� ����� �������� ���� ���� �����." << endl;
	cout << "3. ������� ����� -- ����������� �� ���� ����� �����, ����� ������� �������� �� ��� ����� �������." << endl;
	cout << "4. ��������� -- ����������� �� ���� ������������ ������, ����� ������� �������� �� ��� ������ �����������." << endl;
	cout << "5. ��� �������� -- ����������� � ������������ �����, ����� ������� ������� ��������� ���� ��������" << endl;
	cout << "6. ������ -- �������� ���� ������." << endl;
}

//������� ������ � �����, ��� ������ ������������� � �����
int forSwitch(string input) {
	int num;
	if (isInt(input)) {
		num = stoi(input);
		return num;
	}
	else {
		if (input == "���������") {
			return 1;
		}
		else if (input == "���" || input == "���������� ����� ��������") {
			return 2;
		}
		else if (input == "������� �����") {
			return 3;
		}
		else if (input == "���������") {
			return 4;
		}
		else if (input == "��� ��������") {
			return 5;
		}
		else if (input == "������") {
			return 6;
		}
		else if (input == "�����") {
			return 0;
		}
		else if (input == "") {
			return -1;
		}
	}

	return num = 6;
}

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	cout << "�� ��������� ������� ������� ������������ �5.\n��� ��������� � �������� �������� ���������� ����� ������ ��� ������� � ��������.\n��� ������ ������� ������� '������'.\n��� ������ ������� '�����'." << endl;

	while (true) {

		string input;
		int* newInput = new int;
		getline(cin, input);
		*newInput = forSwitch(input);

		switch (*newInput) {
		case -1:
			continue;
		case 0:
			cout << "����� �� ���������...";
			return 0;
		case 1:
			cout << "���������" << endl;
			factorial();
			delete newInput;
			newInput = nullptr;
			cout << "��� ������ ������� �������� '������'.\n��� ������ �������� '�����'. \n";
			break;
		case 2:
			cout << "���������� ����� ��������" << endl;
			NOD();
			delete newInput;
			newInput = nullptr;
			cout << "��� ������ ������� �������� '������'.\n��� ������ �������� '�����'. \n";
			break;
		case 3:
			cout << "������� �����" << endl;
			isPrime();
			delete newInput;
			newInput = nullptr;
			cout << "��� ������ ������� �������� '������'.\n��� ������ �������� '�����'. \n";
			break;
		case 4:
			cout << "���������" << endl;
			palindrome();
			delete newInput;
			newInput = nullptr;
			cout << "��� ������ ������� �������� '������'.\n��� ������ �������� '�����'. \n";
			break;
		case 5:
			cout << "��� ��������" << endl;
			fibonacciNumbers();
			delete newInput;
			newInput = nullptr;
			cout << "��� ������ ������� �������� '������'.\n��� ������ �������� '�����'. \n";
			break;
		case 6:
			cout << "������" << endl;
			hepl();
			delete newInput;
			newInput = nullptr;
			cout << "��� ������ ������� �������� '������'.\n��� ������ �������� '�����'. \n";
			break;

		default:
			cout << "������� ���������� �������.\n";
			delete newInput;
			newInput = nullptr;
			cout << "��� ������ ������� �������� '������'.\n��� ������ �������� '�����'. \n";
			break;
		}
	}
}
