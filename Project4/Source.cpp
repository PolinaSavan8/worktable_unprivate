#include<iostream>
#include<string>
#include<windows.h>
#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;

const int MY_SIZE = 5;
const int SIZE_OF_PLAYERS = 3;

struct Player {
	string name;
	int level;
	int health;
};

// ��������� ������� 
void showMenu();

// 1. ����������
void task1();

// 2. ���� ������
void task2_1(); // int, double
void task2_2(); // bool
void task2_3(); // char

// 3. switch-case
void task3();

// 4. if-else (������-�������-������)
void task4();

// 5. while (��������� ����������)
void task5();

// 6. for (�������� ������)
void task6();

// 7. pointer(���������)
void task7();

// 8. link(������)
void task8();

// 9. array(������/������� ����)
void task9();

// 10. function(�������:��� ������� ��������)
void task10();

// 11. array+function
void task11();

// 12.struct(����)
void task12();

double calculateAverageMark(int* arr, int size);

double findMin(int* arr, int size);

double findMax(int* arr, int size);

void printPlayers(Player* arr, int size);

void levelUpByValue(int number, int add);

void levelUpByPointer(int* number, int add);

void levelUpByReverence(int& number, int add);

int CountValue(int* arr, int length, int value);

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	showMenu();

	return 0;
}

void showMenu()
{
	while (true)
	{
		cout << "\n=== MENU ===\n";
		cout << "1  - Variables" << endl;
		cout << "2  - Data types" << endl;
		cout << "3  - switch-case (mini game)" << endl;
		cout << "4  - if-else (rock/paper/scissors)" << endl;
		cout << "5  - while (simulation)" << endl;
		cout << "6  - for (railway)" << endl;
		cout << "7  - pointer" << endl;
		cout << "8  - link" << endl;
		cout << "9  - array(GPA)" << endl;
		cout << "10 - function" << endl;
		cout << "11 - array+functuion"<<endl;
		cout << "12 - struct(game)" << endl;
		cout << "0  - Exit" << endl;

		int item;
		cin >> item;

		if (item == 0) break;

		switch (item)
		{
		case 1: task1();
			break;
		case 2: task2_1();
			task2_2();
			task2_3();
			break;
		case 3: task3();
			break;
		case 4: task4();
			break;
		case 5: task5();
			break;
		case 6: task6();
			break;
		case 7: task7();
			break;
		case 8: task8();
			break;
		case 9: task9();
			break;
		case 10: task10();
			break;
		case 11: task11();
			break;
		case 12: task12();
			break;
		default: cout << "Invalid choice!" << endl;
		}
	}
}

void task1() {
	string name;
	cout << "������� ��� ���: ";
	cin >> name;
	int age;
	cout << "������� ���� �������: ";
	cin >> age;
	cout << "������, " << name << " ����� 10 ��� ���� ����� " << age + 10 << " � �� ������ ������ �������������!";
}
void task2_1() // int, double
{
	double result;
	double a;
	double b;
	double c;
	double d;
	double f;

	cin >> a >> b >> c >> d >> f;
	cout << (a + b + c + d + f) / 5;



}

void task2_2() // bool
{

}

void task2_3() // char
{
	char symb;
	cout << "Enter symbol= ";
	cin >> symb;
	cout << (int)symb;

	int code;
	cin >> code;
	cout << (char)code;
}

// 3. switch-case
void task3()
{
	bool flag = true;
	while (flag == true) {
		cout << "1-������" << endl;
		cout << "2-�������" << endl;
		cout << "3-�����" << endl;
		cout << "4-�����" << endl;
		cout << "0-exit" << endl;

		int item;
		cin >> item;

		switch (item)
		{
		case 1: cout << "�������� �������" << endl;
			break;
		case 2: cout << "����� ����" << endl;
			break;
		case 3: cout << "����� � ����" << endl;
			break;
		case 4: cout << "�������� � ������" << endl;
			break;
		case 0: flag = false;
			break;

		}
	}
}

// 4. if-else (������-�������-������)
void task4()
{

	string player;
	string options[3] = { "������","�������","������" };
	srand(time(NULL));
	cout << "�������: ������, �������, ������";
	cin >> player;
	string computer = options[rand() % 3];
	cout << "��������� ������: " << computer << endl;
	if (player == computer) {
		cout << "�����" << endl;
	}
	else if ((player == "������" && computer == "�������") || (player == "�������" && computer == "������") || (player == "������" && computer == "������"))
	{
		cout << "�� ��������!" << endl;
	}
	else cout << "��������� �������!" << endl;

}


// 5. while (��������� ����������)
void task5()
{

	const int target = 1000;
	int total = 0;
	int months = 0;
	int deposit;
	cout << "!!!��������� ����������!!!" << endl;
	cout << "!!!����: �������� " << target << " ���.���.!!!" << endl;

	cout << "������� ������������?" << endl;
	cin >> deposit;

	while (total < target) {
		months++;
		total = total + deposit;
	}
	cout << "�����" << months << "������� � ��� ����� 1000!" << endl;
}

// 6. for (�������� ������)
void task6()
{
	int length;
	cout << "������� ����� �������� ������: " << endl;
	cin >> length;
	for (int i = 0; i < length; i++) {
		cout << "#";
	}
	cout << endl;
}

// 7. pointer(���������)
void task7() {
	int x = 10;
	int* ukazatel = &x;
	*ukazatel = *ukazatel + 10;
	cout << &x << endl;
	cout << ukazatel << endl;
	cout << x << endl;
	cout << *ukazatel << endl;
}

// 8. link(������)
void task8() {
	int x = 10;
	int& ref = x;
	ref = ref + 50;
	cout << x << endl;
	cout << ref << endl;
}

// 9. array(������/������� ����)
void task9() {

	int marks[MY_SIZE];
	for (int i = 0; i < MY_SIZE; i++) {
		cout << "marks[" << i << "]=";
		cin >> marks[i];
	}
	cout << calculateAverageMark(marks, MY_SIZE) << endl;
	cout << findMin(marks, MY_SIZE) << endl;
	cout << findMax(marks, MY_SIZE) << endl;
}
double calculateAverageMark(int* arr, int size)
{
	int sum = 0;
	for (int i = 0; i < size; i++) {
		sum += arr[i];

	}

	return (double)sum / size;
}
double findMin(int* arr, int size)
{

	int min = arr[0];
	for (int i = 1; i < size; i++) {
		if (arr[i] < min) {
			min = arr[i];
		}
	}

	return min;
}
double findMax(int* arr, int size)
{

	int max = arr[0];
	for (int i = 1; i < size; i++) {
		if (arr[i] > max) {
			max = arr[i];
		}

		return max;

	}
}

// 10.function(�������:��� ������� ��������)
	void task10() {
		int level;
		int add;
		cout << "level= ";
		cin >> level;
		cout << "add= ";
		cin >> add;

		levelUpByValue(level, add);
		cout << level;

		levelUpByPointer(&level, add);
		cout << level;

		levelUpByReverence(level, add);
		cout << level;
		
	}
	void levelUpByValue(int number, int add) {
		number += add;
		cout << number;
	}	
	void levelUpByPointer(int* number, int add) {
		*number += add;
		cout << *number;
	}	
	void levelUpByReverence(int& number, int add) {
		number += add;
		cout << number;
	}

// 11. array+function
void task11() {
		int length;
		cout << "������� ������ �������: ";
		cin >> length;
		int* arr = new int[length];//��������� ������
		cout << "������� " << length << " ��������� �������: " << endl;
		for (int i = 0; i < length; i++) {
			cout << "�������" << i + 1 << ":";
			cin >> arr[i];
		}
		int value;
		cout << "������� �������� ��� ������: ";
		cin >> value;
		int result = CountValue(arr, length, value);
		cout << "��������" << value << "meet" << result << "times";
		delete[] arr;
}
int CountValue(int* arr, int length, int value) {
	int count = 0;
	for (int i = 0; i < length; i++) {
		if (arr[i] == value){
			count++;
		}
	}
	return count;
}
// 12. struct(����)
void task12() {

		
  Player players[SIZE_OF_PLAYERS];
  for (int i = 0; i < SIZE_OF_PLAYERS; i++) {
				cout << "name= ";
				cin >> players[i].name;
				cout << "level= ";
				cin >> players[i].level;
				cout << "health= ";
				cin >> players[i].health;
  }
			printPlayers(players, SIZE_OF_PLAYERS);
}
void printPlayers(Player * player, int size) {
			for (int i = 0; i < size - 1; i++) {
				for (int j = 0; j < size - i - 1; j++) {
					if (player[j].health < player[j + 1].health) {
						swap(player[j], player[j + 1]);
					}
				}
			}
			for (int i = 0; i < size; i++) {
				cout << player[i].name << " " << player[i].level << " " << player[i].health << endl;
			}
}
	