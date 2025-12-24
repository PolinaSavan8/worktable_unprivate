#pragma once

#include <string>
#include <vector>
#include "StudentValidator.h" // обновление после реализации StudentValidator

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
    Student();  // делегирующий конструктор
    Student(const string& surname,
        const string& name,
        const string& groupNumber,
        const vector<int>& grades = {});

    // Геттеры
    const string& getSurname() const;
    const string& getName() const;
    const string& getGroupNumber() const;
    const vector<int>& getGrades() const;

    // Сеттеры (возвращают true, если данные корректны)
    bool setSurname(const string& newSurname);
    bool setName(const string& newName);
    bool setGroupNumber(const string& newGroupNumber);
    bool setGrades(const vector<int>& newGrades);

    // Работа с оценками
    bool addGrade(int grade);
    void clearGrades();

    // Бизнес-логика
    double calculateAverageGrade() const;
};