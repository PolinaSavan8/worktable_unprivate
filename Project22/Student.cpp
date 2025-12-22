#include "Student.h"

// Делегирующий конструктор по умолчанию
Student::Student()
    : Student("", "", "", {})
{
}

// Основной конструктор
Student::Student(const string& surname,
    const string& name,
    const string& groupNumber,
    const vector<int>& grades)
    : surname(surname),
    name(name),
    groupNumber(groupNumber),
    grades(grades)
{
}

// Геттеры
const string& Student::getSurname() const
{
    return surname;
}

const string& Student::getName() const
{
    return name;
}

const string& Student::getGroupNumber() const
{
    return groupNumber;
}

const vector<int>& Student::getGrades() const
{
    return grades;
}

// Сеттеры
void Student::setSurname(const string& newSurname)
{
    surname = newSurname;
}

void Student::setName(const string& newName)
{
    name = newName;
}

void Student::setGroupNumber(const string& newGroupNumber)
{
    groupNumber = newGroupNumber;
}

void Student::setGrades(const vector<int>& newGrades)
{
    grades = newGrades;
}

// Работа с оценками
void Student::addGrade(int grade)
{
    grades.push_back(grade);
}

void Student::clearGrades()
{
    grades.clear();
}

// Бизнес-логика
double Student::calculateAverageGrade() const
{
    if (grades.empty())
    {
        return 0.0;
    }

    int sum = 0;
    for (int grade : grades)
    {
        sum += grade;
    }

    return static_cast<double>(sum) / grades.size();
}
