#include <iostream>
using namespace std;

struct Student 
{
	string name;
	string surname;
	int age;
};
const int SIZE_OF_STUDENTS = 10;

void showMenu(Student* arr, int number_of_students);
void showStudents(Student* arr, int number_of_students);

void inputStudents(Student* arr, int number_of_students);

int main()
{
	Student arr[SIZE_OF_STUDENTS];
	int number_of_students;
	cout << "Введите кол-во студентов(не более "<<SIZE_OF_STUDENTS<<") = ";
	cin >> number_of_students;
	if (number_of_students > SIZE_OF_STUDENTS) {
		cout << "Некор.ввод";
		return 1;
	}
	showMenu(arr,number_of_students);
	return 0;
}

void showMenu(Student* arr, int number_of_students)
{
	bool flag = true;
	while (flag)
	{
		cout << "1 - ввести студентов" << endl;
		cout << "2 - изменить студента" << endl;
		cout << "3 - удалить студента" << endl;
		cout << "4 - добавть студента" << endl;
		cout << "5 - вывести всех студентов" << endl;
		cout << "0 - выход" << endl;
	}
	int item;
	cin >> item;
	switch (item)
	{
	case 1: inputStudents(arr, number_of_students);
		break;
	case 0: flag = false;
		break;
	default: cout << "Некор.ввод";
	}
}

void inputStudents(Student* arr, int number_of_students) {
	for (int i = 0; i < number_of_students; i++) {
		cout << "name= ";
		cin >> arr[i].name;
		cout << "surname= ";
		cin >> arr[i].surname;
		cout << "age= ";
		cin >> arr[i].age;
	}
}
void changeStudent(Student* arr, int number_of_students) {
	int position;
	cout << "Введите N";
	cin >> position;
	position--;
	if (position<0 || position > number_of_students-1)cout << "Некор.ввод!";
	else {
		cout << "New name= ";
		cin >> arr[position].name;
		cout << "New surname= ";
		cin >> arr[position].surname;
		cout << "New age= ";
		cin >> arr[position].age;
	}
}

void showStudents(Student* arr, int number_of_students) {
	for (int i = 0; i < number_of_students; i++) {
		cout << i + 1 << " " << arr[i].name << " " << arr[i].surname << " " << arr[i].age << endl;
	}
}

void deleteStudent(Student* arr, int& number_of_students) {
	int position;
	cout << "Введите N";
	cin >> position;
	position--;
	if (position<0 || position > number_of_students - 1)cout << "Ошибка!";
	else {
		for (int i = position; i < number_of_students - 1; i++) {
			arr[position] = arr[position + 1];
		}
		number_of_students--;
	}
}