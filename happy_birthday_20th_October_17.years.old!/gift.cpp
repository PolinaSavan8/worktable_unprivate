#include <iostream>
#include <string>
#include <windows.h>
#include <fstream>

using namespace std;

class Student
{
	//class components(fields + methods)
public://access modifier
	string name;//class fields
	string surname;//class fields
	int age;//class fields
	string group_number;

	void printInfo()
	{
	
		cout << name << " "
			<< surname << ", "
			<< age << " year, group"
			<< group_number << " " << endl;
	}

	Student()
	{
	
		name = "Noname ";
		surname = "Noname";
		age = 0;
		group_number = "-";
	}
};




int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	Student s1;
	s1.printInfo();

	s1.name = "Ivan";
	s1.surname = "Ivanov";
	s1.age = 18;
	s1.group_number = " IT-101 ";

	s1.printInfo();

}