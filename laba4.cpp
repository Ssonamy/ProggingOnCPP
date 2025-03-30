#include <iostream>
#include <windows.h>
#include <vector>
#include <sstream>
#include <string>
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

void arrayElements() {
	string input;
	int* arr = nullptr;
	int size = 0;

	cout << "������� ����� ����� ������:" << endl;
	getline(cin, input);

	stringstream ss(input);
	int temp;

	while (ss >> temp) {
		size++;  // ����������� ������ �������
	}
	arr = new int[size]; // �������� ������ ��� �������

	ss.clear();
	ss.str(input);

	for (int i = 0; i < size; i++) {
		ss >> arr[i]; // ��������� ������
	}

	cout << "������:" << endl;
	for (int i = 0; i < size; i++)
	{
		cout << arr[i] << " ";
	}

	delete[] arr;
	cout << endl;
}

void sum() {
	string input;
	int* arr = nullptr;
	int size = 0;
	int s = 0;

	cout << "������� ����� ����� ������:" << endl;
	getline(cin, input);

	stringstream ss(input);
	int temp;

	while (ss >> temp) {
		size++;  // ����������� ������ �������
	}
	arr = new int[size]; // �������� ������ ��� �������

	ss.clear();
	ss.str(input);

	for (int i = 0; i < size; i++) {
		ss >> arr[i]; // ��������� ������
	}

	cout << "����� ��������� �������:" << endl;
	for (int i = 0; i < size; i++)
	{
		s += arr[i];
	}

	cout << s << endl;
	delete[] arr;
}

void transposition() {
	int rows, cols;

	cout << "������� ���������� �����" << endl;
	rows = INTj();

	int** matrix = new int* [rows];

	cout << "������� ���������� ��������" << endl;
	cols = INTj();
	for (int i = 0; i < rows; i++) {
		matrix[i] = new int[cols];
	}

	// ������������� �������
	cout << "������� �������� �������:" << endl;
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			cin >> matrix[i][j];
		}
	}

	int** transMatrix = new int* [cols]; // ������� ����� ��������� ������
	for (int i = 0; i < cols; i++) {
		transMatrix[i] = new int[rows];
	}

	// ������������� �������
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			transMatrix[j][i] = matrix[i][j];
		}
	}

	// ����� ����������������� �������
	cout << "����������������� �������:" << endl;
	for (int i = 0; i < cols; i++) {
		for (int j = 0; j < rows; j++) {
			cout << transMatrix[i][j] << " ";
		}
		cout << endl;
	}

	// ����������� ������
	for (int i = 0; i < cols; i++) {
		delete[] transMatrix[i];
	}
	delete[] transMatrix;
}

void dotProduct() {
	while (true) {
		string input1, input2;
		int* arr1 = nullptr;
		int* arr2 = nullptr;
		int size1 = 0, size2 = 0;
		int s = 0;

		cout << "������ ������." << endl;
		cout << "������� ����� ����� ������:" << endl;
		getline(cin, input1);

		//���� ������� �������
		stringstream ss1(input1);
		int temp;
		while (ss1 >> temp) {
			size1++;  // ����������� ������ �������
		}
		arr1 = new int[size1]; // �������� ������ ��� �������

		ss1.clear();
		ss1.str(input1);
		for (int i = 0; i < size1; i++) {
			ss1 >> arr1[i]; // ��������� ������
		}

		//���� ������� �������
		cout << "������ ������." << endl;
		cout << "������� ����� ����� ������:" << endl;
		getline(cin, input2);

		stringstream ss2(input2);
		while (ss2 >> temp) {
			size2++;  // ����������� ������ �������
		}
		arr2 = new int[size2]; // �������� ������ ��� �������

		ss2.clear();
		ss2.str(input2);
		for (int i = 0; i < size2; i++) {
			ss2 >> arr2[i]; // ��������� ������
		}

		// ��������� ��������� �������� ��������
		if (size1 == size2) {
			// ��������� ��������� ������������
			for (int i = 0; i < size1; ++i) {
				s += arr1[i] * arr2[i];
			}
			cout << "��������� ������������ ���� �������� = " << s << "." << endl;

			// ����������� ������
			delete[] arr1;
			delete[] arr2;
			break;
		}
		else {
			cout << "���������� ��������� �������� �� �����. ������� ���������� ����������." << endl;

			// ����������� ������ ����� ��������� ������
			delete[] arr1;
			delete[] arr2;
		}
	}

}

void hepl() {
	cout << "������ ������:\n1. �������� ������� -- ����������� �� ���� ������������ ������ ����� �����, ������� ������������ ���������� � ������ � ������� ���." << endl;
	cout << "2. ����� -- ����������� �� ���� ������������ ������ ����� �����, ������� ������������ ���������� � ������ � ������� ����� ��� ���������." << endl;
	cout << "3. ���������������� -- ����������� �� ���� ���������� ����� � �������� �������, ����� ���� ������������ ������ �������� �������, ������� ������� �������������." << endl;
	cout << "4. ��������� ������������ -- ����������� �� ���� ������������ ��� ������� ����� ����� ������ �������, ����� ���� ������� ��������� ������������ ���� ��������." << endl;
	cout << "5. ������ -- " << endl;
}

int forSwitch(string input) {
	int num;
	if (isInt(input)) {
		num = stoi(input);
		return num;
	}
	else {
		if (input == "�������� �������") {
			return 1;
		}
		else if (input == "�����") {
			return 2;
		}
		else if (input == "����������������") {
			return 3;
		}
		else if (input == "��������� ������������") {
			return 4;
		}
		else if (input == "������") {
			return 5;
		}
		else if (input == "�����") {
			return 0;
		}
	}

	return num = 6;
}

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	cout << "�� ��������� ������� ������� ������������ �3.\n��� ��������� � �������� �������� ���������� ����� ������ ��� ������� � ��������.\n��� ������ ������� ������� '������'.\n��� ������ ������� '�����'." << endl;
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
			cout << "�������� �������" << endl;
			arrayElements();
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
			cout << "����������������" << endl;
			transposition();
			delete newInput;
			newInput = nullptr;
			cout << "��� ������ ������� �������� '������'.\n��� ������ �������� '�����'. \n";
			break;
		case 4:
			cout << "��������� ������������" << endl;
			dotProduct();
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
}