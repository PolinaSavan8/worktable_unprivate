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
    vector<int> grades;  // Вектор для хранения оценок

public:
    // Конструктор с параметрами по умолчанию
    Student(string n, string s, int a, string g, int count = 0)
        : name(n), surname(s), age(a), group_number(g)
    {
        grades.reserve(count);  // Резервируем память для вектора, если количество оценок задано
        cout << "Создан объект студента: " << name << " " << surname << endl;
    }

    // Конструктор по умолчанию (делегирующий)
    Student()
        : Student("Неизвестно", "Неизвестно", 0, "-", 0)
    {
    }

    // Сеттеры и геттеры
    void setName(const string& n) { name = n; }
    string getName() const { return name; }

    void setSurname(const string& s) { surname = s; }
    string getSurname() const { return surname; }

    void setAge(int a) {
        if ((a > 0) && (a < 120))
            age = a;
    }
    int getAge() const { return age; }

    void setGroupNumber(const string& g) { group_number = g; }
    string getGroupNumber() const { return group_number; }

    // Инициализация вектора оценок
    void initGrades(int count) {
        if (count <= 0) return;
        grades.clear();  // Очищаем вектор перед добавлением новых элементов
        grades.reserve(count);  // Резервируем память для вектора
    }

    // Заполнение оценок
    void setGrades() {
        if (grades.size() <= 0) return;
        cout << "Введите " << grades.size() << " оценок для " << name << ": ";
        for (int i = 0; i < grades.size(); i++) {
            cin >> grades[i];
        }
    }

    // Добавление одной оценки
    void addGrade(int grade) {
        grades.push_back(grade);  // Добавляем оценку в конец вектора
    }

    // Полная очистка массива оценок
    void clearGrades() {
        grades.clear();  // Очищаем вектор
    }

    // Метод вывода информации
    void printInfo() const {
        cout << name << " "
            << surname << ", "
            << age << " лет, группа "
            << group_number << endl;

        printGrades();
    }

    // Печать всех оценок
    void printGrades() const {
        if (grades.empty()) {
            cout << "Оценок нет." << endl;
            return;
        }
        cout << "Оценки: ";
        for (const auto& grade : grades)
            cout << grade << " ";
        cout << endl;
    }

    // Средний балл студента
    double averageGrade() const {
        if (grades.empty())
            return 0;

        int sum = 0;
        for (int i = 0; i < grades.size(); i++)
            sum += grades[i];

        return double(sum) / grades.size();
    }
};

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    // Создаём студента с 3 оценками
    Student s1("Иван", "Иванов", 18, "IT-101", 3);
    s1.setGrades();
    s1.printInfo();

    // Создаём студента по умолчанию
    Student s2;
    cout << "Объект s2: " << endl;
    s2.printInfo();
    s2.setName("Анастасия");
    s2.setSurname("Ромашина");
    s2.initGrades(5);
    s2.setGrades();
    cout << "Объект s2 после изменений: " << endl;
    s2.printInfo();

    Student s3 = s1;
    s3.printInfo();

    s3.setName("Петр");
    s3.setSurname("Петров");
    s3.initGrades(7);
    s3.setGrades();
    cout << "Объект s3: " << endl;
    s3.printInfo();

    cout << "Объект s1: " << endl;
    s1.printInfo();

    Student a("Алексей", "Кутиков", 16, "IT-222", 5);
    cout << "Объект a: " << endl;
    a.printInfo();

    Student b("Ольга", "Латышова", 15, "IT-333", 4);
    cout << "Объект b: " << endl;
    b.printInfo();

    b = a;

    cout << "Объект a: " << endl;
    a.printInfo();

    cout << "Объект b после присваивания объекта а: " << endl;
    b.printInfo();

    return 0;
}
