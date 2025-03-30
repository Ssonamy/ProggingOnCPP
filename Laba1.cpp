#include <iostream>
#include <vector>
#include <windows.h>
#include <sstream>
#include <string>
using namespace std;

// �������� ����� �� ������� �����
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

// ���� ������ �����
int INTj() {
	while (true) {
		string number;
		int num;

		std::cout << "������� �����:" << endl;
		cin >> number;
		if (isInt(number)) {
			return num = stoi(number);
			break;
		}
		else {
			std::cout << "������: ������� ���������� �������� ��������.\n";
		}
	}
}

// ������� �����
void simpleSearch() {
	string forVec;
	vector<int> vec;
	int num, target, i = 1;
	bool found = 0;

	// ���� ������� 
	std::cout << "������� ����� ������� ����� ������" << endl;
	getline(cin, forVec);

	istringstream ss(forVec); // �������� ������ ��� ��������� ������

	while (ss >> num) { // ������ ����� �� ������ ���� ��������
		vec.push_back(num);
	}

	std::cout << "������� ������� �����" << endl;
	cin >> target;

	for (int val : vec) {

		if (val == target) {
			std::cout << "������� ����� " << target << " ���� � ������� � �������� " << i << "." << endl;
			found = 1;
			break;
		}
		else {
			i++;
		}
	}
	if (!found) {
		std::cout << "����� �� �������." << endl;
	}

}

int binSearch(vector<int> vec, int target) {
	int left = 0;
	int right = vec.size();

	while (left <= right) {
		int mid = left + (right - left) / 2;

		if (vec[mid] == target) {
			return mid;
		}
		else if (vec[mid] < target) {
			left = mid + 1; // ������ ����� � ������ ��������
		}
		else {
			right = mid - 1; // ������ ����� � ����� ��������
		}
	}
	return -1;
}

// ���������� ���������
void bubbleSort() {
	string forVec;
	vector<int> vec;
	int num;

	// ���� ������� 
	std::cout << "������� ����� ������� ����� ������" << endl;
	getline(cin, forVec);

	istringstream ss(forVec); // �������� ������ ��� ��������� ������

	while (ss >> num) { // ������ ����� �� ������ ���� ��������
		vec.push_back(num);
	}

	// ����� �� ���������������� �������
	std::cout << "�� ����� �����:" << endl;
	for (int val : vec) {
		std::cout << val << " ";
	}

	int n = vec.size();
	bool swapped;
	// ����� ���������������� �������
	std::cout << endl << "��������������� ��������:" << endl;

	for (int i = 0; i < n - 1; ++i) {
		swapped = false;

		for (int j = 0; j < n - i - 1; ++j) {

			if (vec[j] > vec[j + 1]) {
				// ������ ������� ��������
				swap(vec[j], vec[j + 1]);
				swapped = true; // ���������, ��� ���� ������������
			}
		}

		// ���� �� ���� ������ �� ���� ������������, �������
		if (!swapped) break;
	}

	for (int val : vec) {
		std::cout << val << " ";
	}
	std::cout << endl;
}

// �������, �������������� �������
void merge(vector<int>& arr, int left, int mid, int right) {
	int n1 = mid - left + 1; // ������ ������ ����������
	int n2 = right - mid;    // ������ ������� ����������

	// ������� ��������� �������
	vector<int> leftArr(n1), rightArr(n2);

	// �������� ������ � ��������� �������
	for (int i = 0; i < n1; ++i) {
		leftArr[i] = arr[left + i];
	}
	for (int j = 0; j < n2; ++j) {
		rightArr[j] = arr[mid + 1 + j];
	}

	// ������� ��������� �������� ������� � arr
	int i = 0, j = 0, k = left;

	while (i < n1 && j < n2) {
		if (leftArr[i] <= rightArr[j]) {
			arr[k++] = leftArr[i++];
		}
		else {
			arr[k++] = rightArr[j++];
		}
	}

	// �������� ���������� ��������
	while (i < n1) {
		arr[k++] = leftArr[i++];
	}
	while (j < n2) {
		arr[k++] = rightArr[j++];
	}
}

// ����������� ������� ���������� ��������
void mergeSor(vector<int>& arr, int left, int right) {
	if (left < right) {
		int mid = left + (right - left) / 2; // ������� ��������

		// ��������� ������ � ������ ��������
		mergeSor(arr, left, mid);
		mergeSor(arr, mid + 1, right);

		// ������� ��������������� ��������
		merge(arr, left, mid, right);
	}
}

// �������, ���� �������, ����������
void mergeSort() {

	string forVec;
	vector<int> vec;
	int num;

	// ���� ������� 
	std::cout << "������� ����� ������� ����� ������" << endl;
	getline(cin, forVec);

	istringstream ss(forVec); // �������� ������ ��� ��������� ������

	while (ss >> num) { // ������ ����� �� ������ ���� ��������
		vec.push_back(num);
	}

	mergeSor(vec, 0, vec.size() - 1);

	cout << "��������������� ������: ";
	for (int num : vec) {
		cout << num << " ";
	}
	cout << endl;

}

// �������� �����
void binSearc() {
	string forVec;
	vector<int> vec;
	int num, target, res, i = 1;
	bool found = 0;

	// ���� ������� 
	std::cout << "������� ����� ������� ����� ������" << endl;
	getline(cin, forVec);

	istringstream ss(forVec); // �������� ������ ��� ��������� ������

	while (ss >> num) { // ������ ����� �� ������ ���� ��������
		vec.push_back(num);
	}

	mergeSor(vec, 0, vec.size() - 1);

	std::cout << "������� ������� �����" << endl;
	cin >> target;

	res = binSearch(vec, target);
	if (res != -1) {
		cout << "������� ������ �� �������: " << res + 1 << endl;
	}
	else {
		cout << "������� �� ������." << endl;
	}
}

// ������ �������
void hepl() {
	std::cout << "������ ������:";
	std::cout << "1. ������� ����� -- ������������ ������ ������ �����, ����� ������ ������� �����." << endl;
	std::cout << "2. �������� ������ -- ������������ ������ ������ �����, ����� ������ ������� �����." << endl;
	std::cout << "3. ���������� ��������� -- ������������ ������ ������ �����, ������� ��������� ������, ������� ���������������." << endl;
	std::cout << "4. ���������� �������� -- ������������ ������ ������ �����, ������� ��������� ������, ������� ���������������." << endl;
	std::cout << "5. ������ -- �������� ������ ������ (�� �����)." << endl;
}

// �������������� �������� ������� � �������.
int forSwitch(string input) {
	int num;
	if (isInt(input)) {
		num = stoi(input);
		return num;
	}
	else {
		if (input == "������� �����") {
			return 1;
		}
		else if (input == "�������� �����") {
			return 2;
		}
		else if (input == "���������� ���������") {
			return 3;
		}
		else if (input == "���������� ��������") {
			return 4;
		}
		else if (input == "������") {
			return 5;
		}
		else if (input == "�����") {
			return 0;
		}
		else if (input == "") {
			return -1;
		}
	}

	return 6;
}


int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);


	std::cout << "�� ��������� ������� ������� ������������ �1.\n��� ��������� � �������� �������� ���������� ����� ������ ��� ������� � ��������.\n��� ������ ������� ������� '������'.\n��� ������ ������� '�����'." << endl;
	while (true) {

		string input;
		int* newInput = new int;
		getline(cin, input);
		*newInput = forSwitch(input);

		switch (*newInput) {
		case -1:
			continue; // �������� ������� �������� 0_0
		case 0:
			std::cout << "����� �� ���������...";
			return 0;
		case 1:
			std::cout << "������� �����" << endl;
			simpleSearch();
			delete newInput;
			newInput = nullptr;
			std::cout << "��� ������ ������� �������� '������'.\n��� ������ �������� '�����'. \n";
			break;
		case 2:
			std::cout << "�������� �����" << endl;
			binSearc();
			delete newInput;
			newInput = nullptr;
			std::cout << "��� ������ ������� �������� '������'.\n��� ������ �������� '�����'. \n";
			break;
		case 3:
			std::cout << "���������� ���������" << endl;
			bubbleSort();
			delete newInput;
			newInput = nullptr;
			std::cout << "��� ������ ������� �������� '������'.\n��� ������ �������� '�����'. \n";
			break;
		case 4:
			std::cout << "���������� ��������" << endl;
			mergeSort();
			delete newInput;
			newInput = nullptr;
			std::cout << "��� ������ ������� �������� '������'.\n��� ������ �������� '�����'. \n";
			break;
		case 5:
			std::cout << "������" << endl;
			hepl();
			delete newInput;
			newInput = nullptr;
			std::cout << "��� ������ ������� �������� '������'.\n��� ������ �������� '�����'. \n";
			break;

		default:
			std::cout << "������� ���������� �������.\n";
			delete newInput;
			newInput = nullptr;
			std::cout << "��� ������ ������� �������� '������'.\n��� ������ �������� '�����'. \n";
			break;
		}
	}

}