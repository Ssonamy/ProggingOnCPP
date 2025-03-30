#include <windows.h>						//��� ��������� ���������
#include <iostream>							//��� ����� ������
#include <string>							//��� getline'�
#include <vector>							//��� ������ ������ ��������
#include <sstream>							//��� ����� � ������
#include <numeric>							//��� ���������� ����� ������
using namespace std;						//����� �� ������ "std::"

//���������� ��� ������ ������� (�� ForSwitch)
string first = "�������";
string second = "����������";
string help = "������";
string EXIT = "�����";

class Student {
private:
	string name;							// ��� ��������
	int age;								// ������� ��������
	double averageGrade;					// ������� ����
	vector<int> grades;						// ������ ��� �������� ������

	// ����� ��� ���������� �������� �����
	void calculateAverage() {
		if (!grades.empty()) {
			averageGrade = static_cast<double>(
				accumulate(grades.begin(), grades.end(), 0)) / grades.size();
		}
		else {
			averageGrade = 0.0;
		}
	}

public:

	// ����������� ��� ������������� ����� � ��������
	Student(const string& studentName, int studentAge) {
		name = studentName;
		age = studentAge;
		averageGrade = 0.0;					//������� ���� �� ���������
	}

	// ����� ��� ���������� ������
	void addGrades(const vector<int>& newGrades) {
		for (int grade : newGrades) {
			grades.push_back(grade);
		}
		calculateAverage();					// ������������� ������� ����
	}

	// ����� ��� ������ ���������� � ��������
	void displayInfo() const {
		cout << "���: " << name << endl;
		cout << "�������: " << age << endl;
		cout << "������: " << endl;
		for (int grade : grades) {
			cout << grade << " ";
		}
		cout << endl;
		cout << "������� ����: " << averageGrade << endl;
	}

	string getName() const {
		return name;
	}
};

class Book {

private:
	string title;
	string author;
	int year;

public:
	// ����������� �� ���������
	Book() : title("����������"), author("����������"), year(0) {}

	// ����������� � �����������	
	Book(const string& bookTitle, const string& bookAuthor, int bookYear)
		: title(bookTitle), author(bookAuthor), year(bookYear) {
	}

	// ����� ��� ������ ���������� � �����
	void displayInfo() const {
		cout << "��������: " << title << endl;
		cout << "�����: " << author << endl;
		cout << "��� �������: " << year << endl;
	}

	string getTitle() const { return title; }
	string getAuthor() const { return author; }
	int getYear() const { return year; }

};

class Library {
private:
	vector<Book> books;

public:

	void addBook(const string& title, const string& author, int year) {
		books.emplace_back(title, author, year);
	}

	void displayBooks() const {
		if (books.empty()) {
			cout << "���������� �����." << endl;
			return;
		}

		cout << "����� � ����������:" << endl;
		for (const auto& book : books) {
			book.displayInfo();
			cout << "--------------------" << endl;
		}
	}

	void findBookByTitle(const string& searchTitle) const {
		for (const auto& book : books) {
			if (book.getTitle() == searchTitle) {
				cout << "����� �������:" << endl;
				book.displayInfo();
				return;
			}
		}
		cout << "����� � ��������� \"" << searchTitle << "\" �� �������." << endl;
	}

	void removeBookByTitle(const string& title) {
		auto it = remove_if(books.begin(), books.end(),
			[&title](const Book& book) { return book.getTitle() == title; });

		if (it != books.end()) {
			books.erase(it, books.end());
			cout << "����� � ��������� \"" << title << "\" �������." << endl;
		}
		else {
			cout << "����� � ��������� \"" << title << "\" �� �������." << endl;
		}
	}
};

//�������� �������� �� ������ ������
bool isInt(string input) {
	try {
		int n = stoi(input);
		return true;
	}
	catch (...) {
		return false;
	}
}

//������� �� ������ � �����
int toInt(string input = "") {
	//���� ������� �� �������� ������ �� ����
	if (input == "") {
		cout << "������� �����: ";
		do {
			cin >> input;
			try {
				return stoi(input);
			}
			catch (...) {
				cout << "������� ���������� ��������: ";
			}
		} while (true);
	}
	//���� �������� ������ �� ����
	else {
		try {
			return stoi(input);
		}
		catch (...) {}
	}
}

void student(vector<Student>& students) {
	int input;
	do {
		cout << "\n�������� ��������\n";
		cout << "1. �������� ��������\n";
		cout << "2. �������� ������ ��������\n";
		cout << "3. �������� ���� ���������\n";
		cout << "0. �����\n";
		cout << "��� �����: ";
		input = toInt();
		cin.ignore();

		switch (input) {
		case 0:
			cout << "����� �� �������." << endl;
			return;

		case 1:
			while (true) {
				cout << "\n������� ��� �������� (��� 'Stop' ��� ����������):\n";
				string name;
				cin >> name;

				if (name == "Stop") { // ��������� ������� ������
					break;
				}

				cout << "������� ������� ��������: ";
				int age = toInt();

				if (age <= 0) {
					cout << "������� ������ ���� ������������� ������. ���������� ��� ���." << endl;
					continue;
				}

				students.emplace_back(name, age);
				cout << "������� ��������!" << endl;
			}
			break;

		case 2: {
			cout << endl << "������� ��� ��������: ";
			string forVec, name;
			vector<int> vec;
			int num;
			cin >> name;

			cin.ignore();
			bool found = false;
			for (auto& student : students) {
				if (student.getName() == name) {
					found = true;

					cout << endl << "������� ������ ����� ������" << endl;
					getline(cin, forVec);

					istringstream ss(forVec);
					while (ss >> num) {
						vec.push_back(num);
					}

					student.addGrades(vec);
					cout << "������ ���������!" << endl;
					break;
				}
			}

			if (!found) {
				cout << "������� � ������ " << name << " �� ������." << endl;
			}
			break;
		}
		case 3:
			if (students.empty()) {
				cout << "������ ��������� ����." << endl;
				break;
			}

			cout << endl << "������ ���������:" << endl;
			for (const auto& student : students) {
				student.displayInfo();
				cout << "-----------------" << endl;
			}
			break;

		default:
			cout << "�������� ����. ���������� ��� ���." << endl;
		}
	} while (input != 0);
}

void library() {
	int input;
	Library library;

	do {

		cout << "\n�������� ��������\n";
		cout << "1. �������� �����\n";
		cout << "2. ����� �����\n";
		cout << "3. �������� ��� �����\n";
		cout << "4. ������� �����\n";
		cout << "0. �����\n";
		cout << "��� �����: ";
		input = toInt();
		cin.ignore();

		switch (input) {
		case 1: {
			string title, author;
			int year;

			do {
				cout << "\n������� �������� ����� (������� Stop ��� ���������� �����, ���� ���������� ���� ��� ��������� ����� �������� �� �������):";
				getline(cin, title);

				if (title != "Stop") {

					cout << "\n������� ������:";
					getline(cin, author);

					cout << "\n������� ��� �������:";
					year = toInt();
					cin.ignore();

					library.addBook(title, author, year);
					cout << "����� ������� ���������!" << endl;
					continue;
				}
				cout << "������� ��� �������� �����!";
			} while (title != "Stop");
			break;
		}

		case 2: {
			string input;
			cout << endl;
			cout << "����� �� ��������.\n";
			cout << "������� �������� �����: ";
			getline(cin, input);
			library.findBookByTitle(input);
			break;
		}

		case 3:
			cout << endl;
			library.displayBooks();
			break;

		case 4: {
			string title;

			cout << endl;
			cout << "�������� �����" << endl;
			cout << "������� �������� �����:" << endl << endl;

			getline(cin, title);
			library.removeBookByTitle(title);
		}
		}
	} while (input != 0);
}

//������� �������� ������ � �����
int forSwitch(string input) {
	if (isInt(input)) {
		return toInt(input);
	}
	else {
		if (input == first) {
			return 1;
		}
		else if (input == second) {
			return 2;
		}
		else if (input == help) {
			return 3;
		}
		else if (input == EXIT) {
			return 0;
		}
	}
}

//������ ������
void list() {
	cout << "__________________________________________________________________________________\n";
	cout << "1. �������: ���������� � �������� ���������� � ���������." << endl;
	cout << "2. ����������: ����������, ��������, ����� ���� ����." << endl;
	cout << "__________________________________________________________________________________\n";
}

//������� �������
int main() {
	vector<Student> students;
	//��������� ��������� �� ���� � �����
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	//�����������?
	cout << "__________________________________________________________________________________\n";
	cout << "�� ��������� ������� ������� ������������ �7.\n";
	cout << "��� ��������� � �������� �������� ���������� ����� ������ ��� ������� � ��������.\n";
	cout << "��� ������ ������� ������� '������'.\n��� ������ ������� '�����'.\n";
	cout << "__________________________________________________________________________________\n";

	//����������� ���� ��� ������ ������
	while (true) {
		cout << "��� �����: ";
		string input;
		cin >> input;
		cout << endl;

		switch (forSwitch(input)) {

		case 0:
			cout << "����� �� ���������.";
			return 0;
		case 1:
			cout << "������ �� ����������." << endl;
			student(students);
			break;
		case 2:
			cout << "����������." << endl;
			library();
			break;
		case 3:
			list();
			break;
		default:
			cout << "������� ���������� ��������. ��� ������ ������� ������� '������'." << endl;
		}
	}

	return 0;
}