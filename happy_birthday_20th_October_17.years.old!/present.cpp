#include <iostream>
#include <string>
#include <windows.h>
#include <time.h>

using namespace std;

int getCurrentYear();


class Book
{
public:
	string title;
	string author;
	int year;

	//a method for displaying information
	void printInfo()
	{
		cout << "Title=" << title << endl
		     << "Author=" << author << endl
		     << "Current year=" << year << endl;
	}

	//a method for checking whether a book is older than 50 years
	bool isOld(int currentYear)
	{
		return(currentYear - year) > 50;

	}

	//constructor with parameters
	Book(string t, string a, int y)
	{
		title = t;
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

	Book() 
	{
		title = "Unknown";
		author = "Unknown";
		year = 0;
	}

	
	
};


int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	string title_temp;
	string author_temp;
	int year_temp;

	Book book1("Leo Tolstoy", "War and Peace", 1865);
	book1.printInfo();
	if (book1.isOld()) {
		cout << "book is Old\n";
	}

	Book book2;
	book2.printInfo();
	cout << "Enter the name of the book: ";
	getline(cin, book2.title);

	cout << "Enter surname: ";
	getline(cin, book2.author);

	cout << "Enter year: ";
	cin >> book2.year;
	cin.ignore();

	if (book2.isOld()) {
		cout << "book is Old\n";
	}

	
	Book book3;
	book3.printInfo();
	cout << "Enter the name of the book: ";
	getline(cin, title_temp);

	cout << "Enter surname: ";
	getline(cin, author_temp);

	cout << "Enter year: ";
	cin >> year_temp;

	if (book3.isOld()) {
		cout << "book is Old\n";
	}

	
	return 0;
}

int getCurrentYear()
{
	SYSTEMTIME tm;
	GetLocalTime(&tm);
	return tm.wYear;
}