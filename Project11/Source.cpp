#include <iostream>
#include <string>
using namespace std;

class Student
{
	//class components(fields + methods)
public://access modifier
	string name;//class fields
	string surname;//class fields
	int age;//class fields
	
	void print() 
	{
		cout << "Name=" << name << endl;//class method
		cout << "Surname=" << surname << endl;//class method
		cout << "Age=" << age << endl;//class method
	}
	//constructor with parameters
	Student(string n, string s, int a)
	{
		name = n;
		surname = s;
		age = a;
		cout << "Object has been created!\n";

	}
	//default constructor
	Student()
	{
		name = "None";
		surname = "None";
		age = 0;
	}
};

class Book
{
public:
	string title;
	string author;
	int year;

	void printInfo()
	{
		cout << "Title=" << title << endl;
		cout << "Author=" << author << endl;
		cout << "Current year=" << year << endl;
	}

	Book(string t, string a, int y)
	{
		title= t;
		author = a;
		year = y;
		cout << "Object has been created!\n";

	}

	bool isOld()
	{
		if (year < 1970 == true)
		{
			return true;
		}
		if (year > 1970 == false);
		{
			return false;
		}
	}
};


int main() 
{
	/*Student student1("Petr", "Petrov", 14);//object
	Student student2("Alex", "Black", 15);
	Student student3("Elena", "Frolova", 13);
	Student student4;*/

	/*student.name = "Petr";
	student.surname = "Petrov";
	student.age = 14;*/

	/*student1.print();
	student2.print();
	student3.print();
	student4.print();*/

	/*Student st;
	Student* ptr = &st;
	ptr->name = "Alex";
	ptr->surname = "Black";
	ptr->age = 15;
	ptr->print();*/

	
	Book book1("Leo Tolstoy", "War and Peace", 1865);
		book1.printInfo();
		if (book1.isOld()) {
			cout << "book is Old";
		}
		Book book2("J.K.Rowling", "Harry Potter", 1997);
		book2.printInfo();
		if (book2.isOld()) {
			cout << "book is Old";
		}
		Book book3("John Ronald Reuel", "The Lord of the Rings", 1954);
		book3.printInfo();
		if (book3.isOld()) {
			cout << "book is Old";
		}
	return 0;
	
}