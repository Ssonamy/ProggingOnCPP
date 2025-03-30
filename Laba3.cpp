#include <iostream>
#include <windows.h>
#include <string>
#include <cmath>
using namespace std;

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

void multiplication() {
	int num;
	while (true) {
		string number;

		cout << "������� �����:" << endl;
		cin >> number;
		if (isInt(number)) {
			num = stoi(number);
			break;
		}
		else {
			cout << "������: ������� ���������� �������� ��������.\n";
		}
	}
	cout << "������� ��������� ����� " << num << ".\n";
	for (int i = 1; i <= 10; i++) {
		cout << num << " * " << i << " = " << num * i << endl;

	}
}

void sum() {
	int num;
	while (true) {
		string number;

		cout << "������� �����:" << endl;
		cin >> number;
		if (isInt(number)) {
			num = stoi(number);
			break;
		}
		else {
			cout << "������: ������� ���������� �������� ��������.\n";
		}
	}
	int s = 0;
	for (int i = 1; i <= num; i++) {
		s = s + i;
	}
	cout << "����� ����� �� 1 �� " << num << " = " << s << endl;
}

void isPrime() {
	int num;
	while (true) {
		string number;

		cout << "������� �����:" << endl;
		cin >> number;
		if (isInt(number)) {
			num = stoi(number);
			if (num > 0) {
				break;
			}
			else {
				"������� ����� ������ ����.\n";
			}
		}
		else {
			cout << "������: ������� ���������� �������� ��������.\n";
		}
	}
	switch (num) {
	case 1:
		cout << "����� �� �������� �������.\n";
	case 2:
		cout << "����� �������� �������.\n";
	case 3:
		cout << "����� �������� �������.\n";
	default:
		for (int i = 2; i < sqrt(num); i++)
		{
			if (num % i == 0) {
				cout << "����� �� �������� �������." << endl;
				break;
			}
			else {
				cout << "����� �������� �������." << endl;
				break;
			}
		}

	}
}

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

void hepl() {
	cout << "������ ������:\n1. ������� ��������� -- ��� ����� ����� �������������, ������� ������� ����� ���������� �� ����� �� 1 �� 10." << endl;
	cout << "2. ����� -- ��� ����� ����� �������������, ������� ������� ����� ���� ����� �� 1 �� N, ��� N -- ���� ������������." << endl;
	cout << "3. ������� ����� -- ��� ����� ����� �������������, ������� �������, �������� �� ����� �������." << endl;
	cout << "4. ��������� -- ��� ����� ����� �������������, ������� ������� ��������� ���������� �����." << endl;
	cout << "5. ������ -- " << endl;
}

int forSwitch(string input) {
	int num;
	if (isInt(input)) {
		return num = stoi(input);
	}
	else {
		if (input == "���������") {
			return num = 1;
		}
		else if (input == "�����") {
			return num = 2;
		}
		else if (input == "�������") {
			return num = 3;
		}
		else if (input == "���������") {
			return num = 4;
		}
		else if (input == "������") {
			return num = 5;
		}
		else if (input == "�����") {
			return num = 0;
		}
	}
}

int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	cout << "�� ��������� ������� ������� ������������ �2.\n��� ��������� � �������� �������� ���������� ����� ������ ��� ������� � ��������.\n��� ������ ������� ������� '������'.\n��� ������ ������� '�����'." << endl;
	while (true) {

		string input;
		int* newInput = new int;
		getline(cin, input);
		*newInput = forSwitch(input);

		switch (*newInput) {
		case 0:
			cout << "����� �� ���������...";
			return 0;
		case 1:
			cout << "������� ���������" << endl;
			multiplication();
			delete newInput;
			newInput = nullptr;
			cout << "��� ������ ������� �������� '������'.\n��� ������ �������� '�����'. \n";
			break;
		case 2:
			cout << "�����" << endl;
			sum();
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
			factorial();
			delete newInput;
			newInput = nullptr;
			cout << "��� ������ ������� �������� '������'.\n��� ������ �������� '�����'. \n";
			break;
		case 5:
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

	return 0;
}
