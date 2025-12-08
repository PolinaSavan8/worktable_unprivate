#include <iostream>
#include <string>
#include <windows.h>

using namespace std;

class Reader 
{

private:
	string name;
    string surname; 
	int booksCount; 
	string* books; 

public:
    Reader(string n, string s, int bc, string* b = 0)
        : name(n),
        surname(s),
        booksCount(bc),
        books(b)
    {
        if (booksCount > 0)
            books = new string[booksCount];  
        else
            books = nullptr;

        cout << "Создан объект студента: " << name << " " << surname << endl;
    }

    Reader()
        : Reader("Неизвестно", "Неизвестно", 0)
    {

    }

    Reader(const Reader& other)
        : name(other.name),
        surname(other.surname),
        booksCount(other.booksCount)
    {
        if (booksCount > 0) {
            books = new string[booksCount];
            for (int i = 0; i < booksCount; i++)
                books[i] = other.books[i];
        }
        else {
            books = nullptr;
        }
    }

    Reader& operator=(const Reader& other)
    {
        if (this == &other)
            return *this;   

        
        name = other.name;
        surname = other.surname;

        delete[] books;

        booksCount = other.booksCount;

        if (booksCount > 0) {
            books = new string[booksCount];
            for (int i = 0; i < booksCount; i++)
                books[i] = other.books[i];
        }
        else {
            books = nullptr;
        }

        return *this;
    }

    void setName(const string& n) { name = n; }
    string getName() const { return name; }

    void setSurname(const string& s) { surname = s; }
    string getSurname() const { return surname; }

    void getbooksCount(const int& bc) { booksCount = bc; }
    int getbooksCount() const { return booksCount; }

    void setbooksCount(int count) { 
        booksCount=count; 
        if (booksCount > 0) {
            delete[] books;
            books = new string[booksCount];
        }
        else {
            books = nullptr;
        }
    
    
    }

    void setBooks() {
        if (booksCount <= 0)return;
        cout << "Введите " << booksCount
        << " книг(и) для читателя " << name << ": \n";

        for (int i = 0; i < booksCount; i++) {
            cout << "Книга " << i + 1 << ": ";
            getline(cin, books[i]);
        }
    }
    

    void addBook(const string& bookTitle) {
        string* newArr = new string[booksCount + 1];
       
        for (int i = 0; i < booksCount; i++)
            newArr[i] = books[i];
        
        newArr[booksCount] = bookTitle;
        
        delete[] books;
        books = newArr;
        booksCount++;

    }

    void clearBooks() {
        delete[] books;
        books = nullptr;
        booksCount = 0;
    }

    void printInfo() const {
        cout << name << " "
            << surname << ", "
            << booksCount << ""
            << endl;

        
    }
        
    ~Reader() {
        delete[] books; 
        cout << "Объект " << name << " " << surname << " уничтожен." << endl;
    }
};

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    Reader r1("Иван", "Иванов", 4);
    r1.printInfo();
 
    Reader r2;
    cout << "Объект s2: " << endl;
    r2.printInfo();
    r2.setName("Анастасия");
    r2.setSurname("Ромашина");
    r2.setbooksCount(4);
    r2.setBooks();
    cout << "Объект s2 после изменений: " << endl;
    r2.printInfo();

    Reader r3 = r1;
    r3.printInfo();

    r3.setName("Петр");
    r3.setSurname("Петров");
    r3.setbooksCount(4);
    r3.setBooks();
    cout << "Объект s3: " << endl;
    r3.printInfo();

    cout << "Объект s1: " << endl;
    r1.printInfo();

    Reader a("Алексей", "Кутиков", 4);
    cout << "Объект a: " << endl;
    a.printInfo();

    Reader b("Ольга", "Латышова", 4);
    cout << "Объект b: " << endl;
    b.printInfo();

    b = a;

    cout << "Объект a: " << endl;
    a.printInfo();

    cout << "Объект b после присваивания объекта а: " << endl;
    b.printInfo();
}