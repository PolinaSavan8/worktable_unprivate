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

    // ����� ����
    int* grades;       // ��������� �� ������������ ������ ������
    int gradesCount;  // ���������� ������

public:
    // ����������� � �����������
    Student(string n, string s, int a, string g, int count = 0)
        : name(n),
        surname(s),
        age(a),
        group_number(g),
        gradesCount(count)
    {
        if (gradesCount > 0)
            grades = new int[gradesCount];  // ����������� �������� ������
        else
            grades = nullptr;

        cout << "������ ������ ��������: " << name << " " << surname << endl;
    }

    // ����������� �� ��������� (������������)
    Student()
        : Student("����������", "����������", 0, "-", 0)
    {}

    // ������� � �������
    void setName(const string& n) { name = n; }
    string getName() const { return name; }

    void setSurname(const string& s) { surname = s; }
    string getSurname() const { return surname; }

    void setAge(int a) {
        if ((a > 0) && (a < 120))
            age = a;
    }
    int getAge() const { return age; }

    void setGroupNumber(const string& g) { group_number = g; }
    string getGroupNumber() const { return group_number; }

    // ������� ����� ��� ���������� ������� ������
    void setGrades() {
        if (gradesCount <= 0) return;
        cout << "������� " << gradesCount << " ������ ��� " << name << ": ";
        for (int i = 0; i < gradesCount; i++) {
            cin >> grades[i];
        }
    }

    // ����� ������ ����������
    void printInfo() const
    {
        cout << name << " "
            << surname << ", "
            << age << " ���, ������ "
            << group_number << endl;

        if (gradesCount > 0) {
            cout << "������: ";
            for (int i = 0; i < gradesCount; i++)
                cout << grades[i] << " ";
            cout << endl;
        }
    }
    double calculateAverageGrade() {
        double result=0;
        for (int i = 0; i < gradesCount; i++) {
            result = result + grades[i];
        }
        result = result / gradesCount;
        return result;
    }
    // ����������
    ~Student() {
        delete[] grades; // ����������� ������
        cout << "������ " << name << " " << surname << " ���������." << endl;
    }
};

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    // ������ �������� � 3 ��������
    Student s1("����", "������", 18, "IT-101", 3);
    s1.setGrades();
    s1.printInfo();
    cout<<s1.calculateAverageGrade()<<endl;

    // ������ �������� �� ���������
    Student s2;
    s2.printInfo();

    // ����������� ������ ������
    Student* s3 = new Student("����", "�������", 20, "IT-202", 2);
    s3->setGrades();
    s3->printInfo();

    delete s3; // ������� ������� ������, ����� ������� ����������

}