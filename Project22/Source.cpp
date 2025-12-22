#include <iostream>
#include <windows.h>

#include "Student.h"
#include "StudentManager.h"

using namespace std;

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    StudentManager manager;

    manager.addStudent(Student("Иванов", "Иван", "ИТ-101", { 8, 9, 7 }));
    manager.addStudent(Student("Петров", "Пётр", "ИТ-101", { 6, 7, 8 }));
    manager.addStudent(Student("Сидоров", "Алексей", "ИТ-102", { 9, 10, 9 }));

    cout << "Всего студентов: "
        << manager.getStudentsCount() << endl << endl;

    cout << "Список студентов:" << endl;
    for (Student s : manager.getAllStudents())
    {
        cout << s.getSurname() << " "
            << s.getName()
            << " | Группа: " << s.getGroupNumber()
            << " | Средний балл: "
            << s.calculateAverageGrade()
            << endl;
    }

    cout << endl << "Сортировка по фамилии:" << endl;
    manager.sortBySurname();

    for (Student s : manager.getAllStudents())
    {
        cout << s.getSurname() << endl;
    }

    cout << endl << "Фильтр по группе ИТ-101:" << endl;
    vector<Student> group101 = manager.filterByGroup("ИТ-101");

    for (Student s : group101)
    {
        cout << s.getSurname() << " "
            << s.getName() << endl;
    }


    return 0;
}