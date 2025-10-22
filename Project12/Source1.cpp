#include <iostream>
#include <string>
#include <windows.h>

using namespace std;

class Student
{
private:
    string name;
    string surname;
    int age;
    string group_number;

public:
    Student(string n, string s, int a, string g)
        : name(n),
        surname(s),
        age(a),
        group_number(g)
    {
    }

    Student()
        : name("Неизвестно"),
        surname("Неизвестно"),
        age(0),
        group_number("-")
    {
    }

    void setName(const string& n)
    {
        name = n;
    }

    string getName() const
    {
        return name;
    }

    void setSurname(const string& s)
    {
        surname = s;
    }

    string getSurname() const
    {
        return surname;
    }

    void setAge(int a)
    {
        if (a > 0 && a < 120) age = a;
    }

    int getAge() const
    {
        return age;
    }

    void setGroupNumber(const string& g)
    {
        group_number = g;
    }

    string getGroupNumber() const
    {
        return group_number;
    }


    void printInfo()
    {
        cout << name << " "
            << surname << ", "
            << age << " лет, группа "
            << group_number << endl;
    }
};

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    Student s1("Иван", "Иванов", 18, "IT-101");
    s1.printInfo();


    Student s2;
    s2.printInfo();

    string name, surname, group_number;
    int age;

    cout << "Введите имя: ";
    cin >> name; // нельзя: cin >> s2.name;
    s2.setName(name);

    cout << "Введите фамилию: ";
    cin >> surname;
    s2.setSurname(surname);

    cout << "Введите возраст: ";
    cin >> age;
    s2.setAge(age);

    cout << "Введите номер группы: ";
    cin >> group_number;
    s2.setGroupNumber(group_number);

    s2.printInfo();

    Student s3(name, surname, age, group_number);
    s3.printInfo();

    cout << s3.getName() << " "
        << s3.getSurname() << ", "
        << s3.getAge() << " лет, группа "
        << s3.getGroupNumber() << endl;

}