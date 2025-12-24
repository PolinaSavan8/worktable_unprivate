#pragma once

#include "ConsoleView.h"

#include "StudentManager.h"
#include "StudentValidator.h"

class StudentPresenter
{
public:
    StudentPresenter(StudentManager& manager, ConsoleView& view);

    void run(); // основной цикл программы

private:
    StudentManager& manager;
    ConsoleView& view;

    // Методы действий
    void addStudent();
    void removeStudent();
    void editStudent();
    void showAllStudents();
    void searchBySurname();
    void filterByGroup();
    void sortStudents();

    void editStudentField(size_t index);

    // Вспомогательный метод для форматирования вывода студента
    string formatStudent(const Student& s);
};