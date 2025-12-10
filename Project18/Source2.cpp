#include <iostream>
#include <string>
#include <vector>
#include <windows.h>

using namespace std;

class Student
{
private:
    string name;
    string surname;
    int age;
    string group_number;
    vector<int> grades;  // коллекция оценок
    int studentID;       // уникальный идентификатор студента

    static int nextID;   // статическое поле для подсчета студентов

public:

    // Конструктор по умолчанию
    Student()
        : name("Неизвестно"), surname("Неизвестно"), age(0), group_number("-")
    {
        nextID = nextID + 1;
        studentID = nextID;
        //studentID = ++nextID;
        cout << "Создан объект студента: " << name << " " << surname
            << ", ID = " << studentID << endl;
    }


    // Конструктор с параметрами без оценок
    Student(const string& n, const string& s, int a, const string& g)
        : name(n), surname(s), age(a), group_number(g)
    {
        studentID = ++nextID;
        cout << "Создан объект студента: " << name << " " << surname
            << ", ID = " << studentID << endl;
    }

    // Конструктор с параметрами и готовыми оценками
    Student(const string& n, const string& s, int a, const string& g, const vector<int>& initialGrades)
        : name(n), surname(s), age(a), group_number(g), grades(initialGrades)
    {
        studentID = ++nextID;
        cout << "Создан объект студента: " << name << " " << surname
            << ", ID = " << studentID << endl;
    }

    // Статический метод для общего числа студентов
    static int getTotalStudents()
    {
        return nextID;
    }

    // Сеттеры и геттеры
    void setName(const string& n) { name = n; }
    string getName() const { return name; }

    void setSurname(const string& s) { surname = s; }
    string getSurname() const { return surname; }

    void setAge(int a) { if (a > 0 && a < 120) age = a; }
    int getAge() const { return age; }

    void setGroupNumber(const string& g) { group_number = g; }
    string getGroupNumber() const { return group_number; }

    int getStudentID() const { return studentID; }

    // Работа с оценками
    void addGrade(int g)
    {
        if (g >= 1 && g <= 10)
            grades.push_back(g);
        else
            cout << "Недопустимая оценка: " << g << endl;
    }

    void setGrades(const vector<int>& newGrades)
    {
        grades = newGrades;
    }

    void clearGrades()
    {
        grades.clear();
    }

    // Вывод информации
    void printInfo() const
    {
        cout << "ID " << studentID << ": " << name << " " << surname
            << ", " << age << " лет, группа " << group_number << endl;

        if (grades.empty())
        {
            cout << "Оценок нет." << endl;
        }
        else
        {
            cout << "Оценки: ";
            for (int g : grades)
                cout << g << " ";
            cout << endl;
        }
    }

    double averageGrade() const
    {
        if (grades.empty())
            return 0;

        int sum = 0;
        for (int g : grades)
            sum += g;
        return double(sum) / grades.size();
    }
};

// Инициализация статического поля
int Student::nextID = 0;

// ----------------------------
// Пример работы
// ----------------------------
int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    // ----------------------------
    // Создание студентов
    // ----------------------------
    Student s1("Иван", "Иванов", 18, "IT-101");
    s1.addGrade(8);
    s1.addGrade(9);
    s1.printInfo();

    Student s2("Анастасия", "Ромашина", 18, "IT-102", { 10, 9, 8, 10 });
    s2.printInfo();

    Student s3("Пётр", "Петров", 19, "IT-103");
    s3.addGrade(7);
    s3.addGrade(8);
    s3.addGrade(11); // тест недопустимой оценки
    s3.printInfo();

    Student s4; // конструктор по умолчанию
    s4.setName("Ольга");
    s4.setSurname("Латышова");
    s4.setAge(17);
    s4.setGroupNumber("IT-104");
    s4.setGrades({ 9, 7, 8 });
    s4.printInfo();
    // ----------------------------
    // Изменение оценок
    // ----------------------------
    cout << "\nОчистка оценок студента s1 и добавление новых:" << endl;
    s1.clearGrades();
    s1.addGrade(10);
    s1.addGrade(9);
    s1.printInfo();

    // ----------------------------
    // Проверка среднего балла
    // ----------------------------
    cout << "\nСредний балл " << s2.getName() << " = " << s2.averageGrade() << endl;
    cout << "Средний балл " << s4.getName() << " = " << s4.averageGrade() << endl;

    // ----------------------------
    // Создание еще нескольких студентов
    // ----------------------------
    Student s5("Алексей", "Кутиков", 16, "IT-105", { 8, 7, 9 });
    Student s6("Марина", "Соколова", 18, "IT-106", { 10, 10, 9, 10 });
    Student s7("Дмитрий", "Иванов", 20, "IT-107");

    // ----------------------------
    // Вывод информации всех студентов
    // ----------------------------
    cout << "\nИнформация по всем студентам:" << endl;
    s1.printInfo();
    s2.printInfo();
    s3.printInfo();
    s4.printInfo();
    s5.printInfo();
    s6.printInfo();
    s7.printInfo();

    // ----------------------------
    // Проверка статического метода
    // ----------------------------
    cout << "\nОбщее количество студентов: "
        << Student::getTotalStudents() << endl;

    return 0;
}