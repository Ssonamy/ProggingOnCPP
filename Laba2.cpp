#include <iostream>
#include <string>
#include <windows.h>

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
//1
void evenOrOdd() {
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
	if (num % 2 == 0) {
		cout << "��������� ����� ������." << endl;
	}
	else {
		cout << "��������� ����� ��������." << endl;
	}

}
//2
void leapYear() {
	int num;
	while (true) {
		string number;
		cout << "������� ���:" << endl;
		cin >> number;
		if (isInt(number)) {
			num = stoi(number);
			break;
		}
		else {
			cout << "������: ������� ���������� �������� ��������.\n";
		}
	}
	if (((num % 4 == 0) and !(num % 100 == 0)) || (num % 400 == 0)) {
		cout << "��� ����������." << endl;
	}
	else if ((num % 100 == 0) and !(num % 400 == 0)) {
		cout << "��� �� ����������." << endl;
	}
	else {
		cout << "��� �� ����������." << endl;
	}
}
//3
void maxOfThree() {
	int a;
	while (true) { // ������ �����
		string a1;
		cout << "������� ������ �����:" << endl;
		cin >> a1;
		if (isInt(a1)) {
			a = stoi(a1);
			break;
		}
		else {
			cout << "������: ������� ���������� �������� ��������.\n";
		}
	}

	int b;
	while (true) { // ������ �����
		string b2;
		cout << "������� ������ �����:" << endl;
		cin >> b2;
		if (isInt(b2)) {
			b = stoi(b2);
			break;
		}
		else {
			cout << "������: ������� ���������� �������� ��������.\n";
		}
	}

	int c;
	while (true) { // ������ ����� 
		string c3;
		cout << "������� ������ �����:" << endl;
		cin >> c3;
		if (isInt(c3)) {
			c = stoi(c3);
			break;
		}
		else {
			cout << "������: ������� ���������� �������� ��������.\n";
		}
	}

	if ((a == b) and (a == c)) {
		cout << "��� ����� ���������. ������������ ��� " << a << "!" << endl;
	}
	else {
		int max = a;
		if (b >= max) {
			max = b;
		}
		if (c >= max) {
			max = c;
		}
		cout << "������������ �������� ��� - " << max << "!" << endl;
	}
}
//4
void vowelOrConsonant() {
	string vowel = "������������������AEIOU"; // ������ �� ��������
	string consonant = "����������������������������������������������QWRTYPSDFGHJKLZXCVBNM"; // ������ � ����������
	char letter, upLetter;
	while (true) {
		cout << "������� �����" << endl;
		cin >> letter;
		upLetter = toupper(letter);
		if (vowel.find(upLetter) != string::npos) {
			cout << "����� " << letter << " �������" << endl;
			break;
		}
		else if (consonant.find(upLetter) != string::npos) {
			cout << "����� " << letter << " ���������" << endl;
			break;
		}
		else {
			cout << letter << " �� �����!\n���������� ��� ���. \n" << endl;
		}
	}
}
//5
void hepl() {
	cout << "������ ������:\n1. ������ ��� �������� -- ��� ����� ����� �������������, ������� ������ � ����� �������� �� ��������.\n";
	cout << "2. ���������� ��� -- ��� ����� ����, ������� �������� �� ������ ���������� ��� ��� ���.\n3. ������������ �� ���� -- ������� ������� ������������ �� �������� ������������� �����.\n4. ������� ��� ��������� -- ������� �������� �������� �� ������, ������� ����� ��� ���.\n5. ������ -- �������� ������ ������ (�� �����).\n";
}

int forSwitch(string input) {
	int num;
	if (isInt(input)) {
		return num = stoi(input);
	}
	else {
		if (input == "������ ��� ��������") {
			return num = 1;
		}
		else if (input == "���������� ���") {
			return num = 2;
		}
		else if (input == "������������ �� ����") {
			return num = 3;
		}
		else if (input == "������� ��� ���������") {
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
	cout << "�� ��������� ������� ������� ������������ �2.\n��� ��������� � �������� �������� ���������� ����� ������ ��� ������� � ��������.\n";
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
			cout << "������ ��� ��������" << endl;
			evenOrOdd();
			delete newInput;
			newInput = nullptr;
			cout << "��� ������ ������� �������� '������'.\n��� ������ �������� '�����'. \n";
			break;
		case 2:
			cout << "���������� ���" << endl;
			leapYear();
			delete newInput;
			newInput = nullptr;
			cout << "��� ������ ������� �������� '������'.\n��� ������ �������� '�����'. \n";
			break;
		case 3:
			cout << "������������ �� ����" << endl;
			maxOfThree();
			delete newInput;
			newInput = nullptr;
			cout << "��� ������ ������� �������� '������'.\n��� ������ �������� '�����'. \n";
			break;
		case 4:
			cout << "������� ��� ���������" << endl;
			vowelOrConsonant();
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