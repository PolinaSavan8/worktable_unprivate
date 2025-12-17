#include <iostream>
#include <windows.h>
#include <string>
#include <vector>

using namespace std;

class Student
{
private:
    string surname;
    string name;
    string groupNumber;
    vector<int> grades;

public:
    Student(string s, string n, string g, int count = 0)
        : name(n), surname(s), age(a), group_number(g)
    {
        grades.reserve(count);
        cout << ": " << name << " " << surname << endl;
    }


    Student()
        : Student(" ", " ", "-", 0)
    {
    }


    void setName(const string& n) { name = n; }
    string getName() const { return name; }

    void setSurname(const string& s) { surname = s; }
    string getSurname() const { return surname; }

    void setGroupNumber(const string& g) { group_number = g; }
    string getGroupNumber() const { return group_number; }


    void initGrades(int count) {
        if (count <= 0) return;
        grades.clear();
        grades.reserve(count);
    }


    void setGrades() {
        if (grades.size() <= 0) return;
        cout << " " << grades.size() << "  " << name << ": ";
        for (int i = 0; i < grades.size(); i++) {
            cin >> grades[i];
        }
    }


    void addGrade(int grade) {
        grades.push_back(grade);
    }


    void clearGrades() {
        grades.clear();
    }


    void printInfo() const {
        cout << name << " "
            << surname << ", "
            << group_number << endl;

        printGrades();
    }


    void printGrades() const {
        if (grades.empty()) {
            cout << "." << endl;
            return;
        }
        cout << ": ";
        for (const auto& grade : grades)
            cout << grade << " ";
        cout << endl;
    }


    double averageGrade() const {
        if (grades.empty())
            return 0;

        int sum = 0;
        for (int i = 0; i < grades.size(); i++)
            sum += grades[i];

        return double(sum) / grades.size();
    }

    // Конструкторы
    Student();
    Student(const string& surname,
        const string& name,
        const string& groupNumber,
        const vector<int>& grades = {});

    // Геттеры
    const string& getSurname() const;
    const string& getName() const;
    const string& getGroupNumber() const;
    const vector<int>& getGrades() const;

    // Сеттеры
    void setSurname(const string& newSurname);
    void setName(const string& newName);
    void setGroupNumber(const string& newGroupNumber);
    void setGrades(const vector<int>& newGrades);

    // Работа с оценками
    void addGrade(int grade);
    void clearGrades();

    // Бизнес-логика
    double calculateAverageGrade() const;
};

class StudentManager
{
private:
    vector<Student> students;   // композиция

public:
    // Конструкторы
    StudentManager();

    // Работа с коллекцией студентов
    void addStudent(const Student& student);
    bool removeStudent(size_t index);
    bool updateStudent(size_t index, const Student& updatedStudent);
    Student& getStudent(size_t index);

    size_t getStudentsCount() const;

    // Бизнес-операции
    void calculateAverageGrades(); // при необходимости кеширования
    vector<Student> findBySurname(const string& surname) const;
    vector<Student> filterByGroup(const string& groupNumber) const;

    // Сортировки (изменяют порядок коллекции)
    void sortBySurname();
    void sortByAverageGrade();

    // Доступ ко всей коллекции (только чтение)
    const vector<Student>& getAllStudents() const;
};

int main() {

    
    
        SetConsoleCP(1251);
        SetConsoleOutputCP(1251);

        
        Student s1(" ", " ", "IT-101", 3);
        s1.setGrades();
        s1.printInfo();

        
        Student s2;
        cout << " s2: " << endl;
        s2.printInfo();
        s2.setName(" ");
        s2.setSurname(" ");
        s2.initGrades(5);
        s2.setGrades();
        cout << " s2 : " << endl;
        s2.printInfo();

        Student s3 = s1;
        s3.printInfo();

        s3.setName(" ");
        s3.setSurname(" ");
        s3.initGrades(7);
        s3.setGrades();
        cout << " s3: " << endl;
        s3.printInfo();

        cout << " s1: " << endl;
        s1.printInfo();

        Student a("Irina", "Petrova", 16, "IT-222", 5);
        cout << " a: " << endl;
        a.printInfo();

        Student b("Mila", "Ivanova", 15, "IT-333", 4);
        cout << " b: " << endl;
        b.printInfo();

        b = a;

        cout << " a: " << endl;
        a.printInfo();

        cout << " b  : " << endl;
        b.printInfo();

        return 0;
    
}