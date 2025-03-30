#include <iostream>
#include <windows.h>
#include <fstream> // ��� ������ � �������
#include <string>
using namespace std;

// ���������� ��������� ��� 4, 5 �������
struct Person {
	string name;  // ���������� string ������ ������� char
	int age;
	double height;
};

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

//������ �������, ���������� � ���� ���� ������������
void textToFile() {
	// ��� �����
	string filename = "output.txt";

	// ������� ������ ofstream � ��������� ���� � ������ ������ (����������� ����, ���� �� ��� ����������)
	ofstream file(filename, ios::trunc);

	// ���������, ������� �� ������� ����
	if (!file) {
		cerr << "������ ��� �������� ����� ��� ������!" << endl;
		return; // ��������� ��������� � �������
	}

	// ���� ������ �� ������������
	cout << "������� ������ ��� ������ � ���� (������� \"STOP\" ��� ���������� �����):" << endl;

	string line;
	while (true) {
		getline(cin, line); // ��������� ������ �� ������������
		if (line == "STOP") {
			break; // ��������� ����, ���� ������������ ���� "STOP"
		}
		file << line << "\n"; // ���������� ������ � ����
	}

	// ��������� ����
	file.close();

	// �������� ������������ �� �������� ������
	cout << "������ ������� �������� � ����: " << filename << endl;
}

//������ �������, ������� �� ��� ���� ��������� � ���� � ������� ������ �������
void fileToDisplay() {
	// ��� ����� (��� �� ����, ������� ������������� ��� ������)
	string filename = "output.txt";

	// ������� ������ ifstream ��� ������ �� �����
	ifstream file(filename);

	// ���������, ������� �� ������� ����
	if (!file) {
		cerr << "������: ���������� ������� ���� " << filename << " ��� ������!" << endl;
		return; // ��������� ��������� � �������
	}

	// ������ ������ �� ����� � ������� �� �� �����
	cout << "���������� ����� \"" << filename << "\":" << endl;

	string line;
	while (getline(file, line)) {
		cout << line << endl; // ������� ������ ������
	}

	// ��������� ����
	file.close();

}

//������ ������ ��������� � ���� �������������� ������, �� ������ ��������� ������
void addstrings() {
	// ��� �����
	string filename = "output.txt";

	// ������� ������ ofstream � ������ ����������
	ofstream file(filename, ios::app);

	// ���������, ������� �� ������� ����
	if (!file) {
		cerr << "������ ��� �������� ����� ��� ���������� ������!" << endl;
		return; // ��������� ��������� � �������
	}

	// ���� ������ �� ������������
	cout << "������� ������ ��� ���������� � ���� (������� \"STOP\" ��� ���������� �����):" << endl;

	string line;
	while (true) {
		getline(cin, line); // ��������� ������ �� ������������
		if (line == "STOP") {
			break; // ��������� ����, ���� ������������ ���� "STOP"
		}
		file << line << "\n"; // ��������� ������ � ����
	}

	// ��������� ����
	file.close();

	// �������� ������������ �� �������� ������
	cout << "������ ������� ��������� � ����: " << filename << endl;
}

//��������� ������, ���������� ���� ������������ � ��������� ���������
void writeToFile() {
	string filename = "data.bin";
	ofstream file(filename);
	if (!file) {
		cerr << "������ ��� �������� ����� ��� ������!" << endl;
		return;
	}

	Person person;
	cout << "������� ���: ";
	getline(cin, person.name);
	cout << "������� �������: ";
	person.age = INTj();
	cout << "������� ���� (� �����������): ";
	person.height = INTj();

	// ���������� ������ � ��������� �������
	file << person.name << "\n";
	file << person.age << "\n";
	file << person.height << "\n";

	cout << "������ ������� �������� � ����." << endl;
}

void readFromFile() {
	string filename = "data.bin";
	ifstream file(filename);
	if (!file) {
		cerr << "������ ��� �������� ����� ��� ������!" << endl;
		return;
	}

	Person person;

	// ������ ������ �� �����
	getline(file, person.name);
	file >> person.age;
	file >> person.height;

	// ������� ������
	cout << "���: " << person.name << endl;
	cout << "�������: " << person.age << endl;
	cout << "����: " << person.height << " ��" << endl;
}


void copyingToAnother() {
	//�������� ����
	string sourceFile = "output.txt";

	//���� ����������
	string destinationFile = "destinationFile.txt";

	// ��������� �������� ����
	ifstream inputFile(sourceFile);
	if (!inputFile) {
		cerr << "�� ������� ������� ���� " << sourceFile << " ��� ������!" << endl;
		return;
	}

	// ��������� ���� ����������
	ofstream outputFile(destinationFile);
	if (!outputFile) {
		cerr << "�� ������� ������� ���� " << destinationFile << " ��� ������!" << endl;
		return;
	}

	// ������ ��������� � ����������
	string line;
	while (getline(inputFile, line)) {
		outputFile << line << '\n';
	}

	cout << "���� ������� ����������." << endl;
}

//����� �������
void hepl() {
	cout << "������ ������:" << endl;
	cout << "1. ����� � ���� -- ���������� �������� ����� � ����." << endl;
	cout << "2. ����� -- ������� ����� �� �����." << endl;
	cout << "3. ���������� ����� -- ���������� �������� ����� � ����� �����." << endl;
	cout << "4. �������� ���� -- ������ ��� ������ � ��������� �������: ������ ��������� ������ � ���� � ����������� ������ �� ����." << endl;
	cout << "5. ����������� ����� � ������ -- �������� ���������� ������ ����� � ������." << endl;
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
		if (input == "����� � ����") {
			return 1;
		}
		else if (input == "�����") {
			return 2;
		}
		else if (input == "���������� �����") {
			return 3;
		}
		else if (input == "�������� ����") {
			return 4;
		}
		else if (input == "����������� ����� � ������") {
			return 5;
		}
		else if (input == "������") {
			return 6;
		}
		else if (input == "�����") {
			return 0;
		}
	}

	return num = 6;
}

int main() {
	int choice;
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	cout << "�� ��������� ������� ������� ������������ �5.\n��� ��������� � �������� �������� ���������� ����� ������ ��� ������� � ��������.\n��� ������ ������� ������� '������'.\n��� ������ ������� '�����'." << endl;
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
			cout << "����� � ����" << endl;
			textToFile();
			delete newInput;
			newInput = nullptr;
			cout << "��� ������ ������� �������� '������'.\n��� ������ �������� '�����'. \n";
			//cin.ignore(); // ������� ������� �������� �� ������
			break;
		case 2:
			cout << "�����" << endl;
			fileToDisplay();
			delete newInput;
			newInput = nullptr;
			cout << "��� ������ ������� �������� '������'.\n��� ������ �������� '�����'. \n";
			//cin.ignore(); // ������� ������� �������� �� ������
			break;
		case 3:
			cout << "���������� �����" << endl;
			while (true) {
				addstrings();
				delete newInput;
				newInput = nullptr;
				cout << "��� ������ ������� �������� '������'.\n��� ������ �������� '�����'. \n";
				//cin.ignore(); // ������� ������� �������� �� ������
				break;
		case 4:
			cout << "�������� ����" << endl;
			do {
				cout << "\n�������� ��������:\n";
				cout << "1. �������� ������ � ����\n";
				cout << "2. ��������� ������ �� �����\n";
				cout << "0. �����\n";
				cout << "��� �����: ";
				choice = INTj();
				cin.ignore(); // ������� ������� �������� �� ������

				switch (choice) {
				case 1:
					writeToFile();
					break;
				case 2:
					readFromFile();
					break;
				case 0:
					cout << "����� �� ���������." << endl;
					break;
				default:
					cout << "������������ �����! ���������� �����." << endl;
				}
			} while (choice != 0);
			delete newInput;
			newInput = nullptr;
			cout << "��� ������ ������� �������� '������'.\n��� ������ �������� '�����'. \n";
			break;
		case 5:
			cout << "����������� ����� � ������" << endl;
			copyingToAnother();
			delete newInput;
			newInput = nullptr;
			//cin.ignore(); // ������� ������� �������� �� ������
			cout << "��� ������ ������� �������� '������'.\n��� ������ �������� '�����'. \n";
			break;
		case 6:
			cout << "������" << endl;
			hepl();
			delete newInput;
			newInput = nullptr;
			//cin.ignore(); // ������� ������� �������� �� ������
			cout << "��� ������ ������� �������� '������'.\n��� ������ �������� '�����'. \n";
			break;

		default:
			cout << "������� ���������� �������.\n";
			delete newInput;
			newInput = nullptr;
			//cin.ignore(); // ������� ������� �������� �� ������
			cout << "��� ������ ������� �������� '������'.\n��� ������ �������� '�����'. \n";
			break;
			}
		}
	}
}