#pragma once

#include <vector>
#include <string>
#include "Student.h"
#include "StudentValidator.h" // обновление после реализации StudentValidator

using namespace std;

class StudentManager
{
private:
    vector<Student> students;   // композиция

    static const size_t BASIC_CAPACITY = 10;

public:
    // Конструктор
    StudentManager();

    // Работа с коллекцией студентов
    bool addStudent(const Student& student); // обновление после реализации StudentValidator
    bool removeStudent(size_t index);
    bool updateStudent(size_t index, const Student& updatedStudent);
    Student& getStudent(size_t index);

    size_t getStudentsCount() const;

    // Бизнес-операции
    vector<Student> findBySurname(const string& surname) const;
    vector<Student> filterByGroup(const string& groupNumber) const;

    // Сортировки
    void sortBySurname();
    void sortByAverageGrade();

    // Доступ ко всей коллекции (только чтение)
    const vector<Student>& getAllStudents() const;
};