#include <iostream>
#include <windows.h>
#include <string>
#include <vector>

using namespace std;



// Пример простого менеджера студентов (без сложной логики из задания)
class SimpleStudentManager
{
private:
    vector<Student> students;

public:
    void addStudent(const Student& student)
    {
        students.push_back(student);
    }

    void printAllStudents() const
    {
        for (const auto& student : students)
        {
            student.printInfo();
            cout << "Средний балл: " << student.calculateAverageGrade() << endl;
            cout << "-------------------" << endl;
        }
    }
};

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    // Пример 1: Создание студента с оценками
    Student s1("Иванов", "Иван", "IT-101");
    s1.initGrades(3);
    s1.inputGrades();
    cout << "\nИнформация о студенте s1:" << endl;
    s1.printInfo();
    cout << "Средний балл: " << s1.calculateAverageGrade() << "\n" << endl;

    // Пример 2: Создание пустого студента и заполнение
    Student s2;
    s2.setName("Петр");
    s2.setSurname("Петров");
    s2.setGroupNumber("IT-102");
    s2.initGrades(2);
    s2.inputGrades();
    cout << "\nИнформация о студенте s2:" << endl;
    s2.printInfo();

    // Пример 3: Копирование студента
    Student s3 = s1;
    s3.setName("Мария");
    s3.setSurname("Сидорова");
    cout << "\nИнформация о студенте s3 (копия s1 с измененным именем):" << endl;
    s3.printInfo();

    // Пример 4: Присваивание
    Student a("Ирина", "Петрова", "IT-222");
    a.addGrade(5);
    a.addGrade(4);
    a.addGrade(5);

    Student b("Мила", "Иванова", "IT-333");
    b.addGrade(3);
    b.addGrade(4);

    cout << "\nДо присваивания:" << endl;
    cout << "Студент a:" << endl;
    a.printInfo();
    cout << "\nСтудент b:" << endl;
    b.printInfo();

    b = a;
    b.setName("Ольга");

    cout << "\nПосле присваивания b = a и смены имени b:" << endl;
    cout << "Студент a:" << endl;
    a.printInfo();
    cout << "\nСтудент b:" << endl;
    b.printInfo();

    // Пример использования менеджера
    SimpleStudentManager manager;
    manager.addStudent(s1);
    manager.addStudent(s2);
    manager.addStudent(s3);

    cout << "\n=== Все студенты в менеджере ===" << endl;
    manager.printAllStudents();

    return 0;
}