#pragma once

#include <vector>
#include <string>
#include "Student.h"

using namespace std;

class StudentManager
{
private:
    vector<Student> students;   // композиция

public:
    // Конструктор
    StudentManager();

    // Работа с коллекцией студентов
    void addStudent(const Student& student);
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