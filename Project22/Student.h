#pragma once

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