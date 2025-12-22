#include "Student.h"

class Student
{
private:
    string surname;
    string name;
    string groupNumber;
    vector<int> grades;

public:
    // Конструктор с параметрами
    Student(string s, string n, string g, int count = 0)
        : surname(s), name(n), groupNumber(g)
    {
        grades.reserve(count);
        cout << "Создан студент: " << name << " " << surname << endl;
    }

    // Конструктор по умолчанию
    Student()
        : Student("", "", "-", 0)
    {
    }

    // Конструктор копирования (для s3 = s1 в main)
    Student(const Student& other)
        : surname(other.surname), name(other.name),
        groupNumber(other.groupNumber), grades(other.grades)
    {
        cout << "Скопирован студент: " << name << " " << surname << endl;
    }

    // Оператор присваивания
    Student& operator=(const Student& other)
    {
        if (this != &other)
        {
            surname = other.surname;
            name = other.name;
            groupNumber = other.groupNumber;
            grades = other.grades;
        }
        return *this;
    }

    // Геттеры
    string getName() const { return name; }
    string getSurname() const { return surname; }
    string getGroupNumber() const { return groupNumber; }
    const vector<int>& getGrades() const { return grades; }

    // Сеттеры
    void setName(const string& n) { name = n; }
    void setSurname(const string& s) { surname = s; }
    void setGroupNumber(const string& g) { groupNumber = g; }
    void setGrades(const vector<int>& newGrades) { grades = newGrades; }

    // Работа с оценками
    void initGrades(int count)
    {
        grades.clear();
        grades.resize(count);
    }

    void inputGrades()
    {
        if (grades.empty())
        {
            cout << "У студента " << name << " нет оценок для ввода." << endl;
            return;
        }

        cout << "Введите " << grades.size() << " оценок для " << name << ": ";
        for (size_t i = 0; i < grades.size(); i++)
        {
            cin >> grades[i];
        }
    }

    void addGrade(int grade)
    {
        grades.push_back(grade);
    }

    void clearGrades()
    {
        grades.clear();
    }

    // Вывод информации
    void printInfo() const
    {
        cout << name << " " << surname << ", группа " << groupNumber << endl;
        printGrades();
    }

    void printGrades() const
    {
        if (grades.empty())
        {
            cout << "Нет оценок." << endl;
            return;
        }

        cout << "Оценки: ";
        for (const auto& grade : grades)
            cout << grade << " ";
        cout << endl;
    }

    // Вычисление среднего балла
    double calculateAverageGrade() const
    {
        if (grades.empty())
            return 0.0;

        int sum = 0;
        for (int grade : grades)
            sum += grade;

        return static_cast<double>(sum) / grades.size();
    }
};
