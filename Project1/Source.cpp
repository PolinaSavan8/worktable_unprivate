#include<iostream>
#include<string>
#include<windows.h>
#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;

// Прототипы функций 
void showMenu();

// 1. Переменные
void task1();

// 2. Типы данных
void task2_1(); // int, double
void task2_2(); // bool
void task2_3(); // char

// 3. switch-case
void task3();

// 4. if-else (камень-ножницы-бумага)
void task4();

// 5. while (симуляция накоплений)
void task5();

// 6. for (железная дорога)
void task6();

// 7. pointer
void task7();

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
		default: cout << "Invalid choice!" << endl;
		}
	}
}

void task1() {
	string name;
	cout << "Введите своё имя: ";
	cin >> name;
	int age;
	cout << "Введите свой возраст: ";
	cin >> age;
	cout << "Привет, " << name << " Через 10 лет тебе будет " << age + 10 << " и ты будешь крутым программистом!";
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
		cout << "1-налево" << endl;
		cout << "2-направо" << endl;
		cout << "3-вперёд" << endl;
		cout << "4-назад" << endl;
		cout << "0-exit" << endl;

		int item;
		cin >> item;

		switch (item)
		{
		case 1: cout << "встретил дракона" << endl;
			break;
		case 2: cout << "нашёл клад" << endl;
			break;
		case 3: cout << "вышел к реке" << endl;
			break;
		case 4: cout << "вернулся к началу" << endl;
			break;
		case 0: flag = false;
			break;

		}
	}
}

// 4. if-else (камень-ножницы-бумага)
void task4()
{
	
	string player;
	string options[3] = { "камень","ножницы","бумага" };
	srand(time(NULL));
	cout << "Введите: камень, ножницы, бумага";
	cin >> player;
	string computer = options[rand() % 3];
	cout << "Компьютер выбрал: " << computer << endl;
	if (player == computer) {
		cout << "Ничья" << endl;
	}
	else if ((player == "камень" && computer == "ножницы") || (player == "ножницы" && computer == "бумага") || (player == "бумага" && computer == "камень"))
	{
		cout << "Вы победили!" << endl;
	}
	else cout << "Компьютер победил!" << endl;
	
}


// 5. while (симуляция накоплений)
void task5()
{

	const int target = 1000;
	int total = 0;
	int months = 0;
	int deposit;
	cout << "!!!Симулятор накоплений!!!" << endl;
	cout << "!!!Цель: накопить " << target << " бел.руб.!!!" << endl;

	cout << "Сколько откладываете?" << endl;
	cin >> deposit;

	while (total < target) {
		months++;
		total = total + deposit;
	}
	cout << "через" << months << "месяцев у вас будет 1000!" << endl;
}

// 6. for (железная дорога)
void task6() 
{
	int length;
	cout << "Введите длину железной дороги: " << endl;
	cin >> length;
	for (int i = 0; i < length; i++) {
		cout << "#";
	}
	cout << endl;
}

// 7. pointer 
void task7() {
	int temp;
	cout << "Введите значение переиенной = ";
}
