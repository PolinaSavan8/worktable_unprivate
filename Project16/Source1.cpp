#include <iostream>
#include <string>
#include <vector>
#include <limits>
#include <windows.h>

using namespace std;

class Student {
private:
    string name;
    string surname;
    int age;
    string group_number;
    vector<int> grades;  // заменяем raw-указатель на std::vector

public:
    // Конструктор с параметрами
    Student(string n, string s, int a, string g, int count = 0)
        : name(move(n)),
        surname(move(s)),
        age((a > 0 && a < 120) ? a : 0),
        group_number(move(g)),
        grades(count)  // вектор автоматически создаётся нужного размера
    {
        if (count > 0) {
            cout << "Создан студент: " << name << " " << surname
                << ". Введите " << count << " оценок:\n";
            setGrades();
        }
        else {
            cout << "Создан студент: " << name << " " << surname << " (без оценок)\n";
        }
    }

    // Конструктор по умолчанию(делегирующий)
    Student()
        : Student("Неизвестно", "Неизвестно", 0, "-", 0)
        //Student(string n, string s, int a, string g, int count)
    {
    }

    // Геттеры и сеттеры
    void setName(const string& n) { name = n; }
    const string& getName() const { return name; }

    void setSurname(const string& s) { surname = s; }
    const string& getSurname() const { return surname; }

    void setAge(int a) {
        if (a > 0 && a < 120) age = a;
        else cout << "Некорректный возраст!\n";
    }
    int getAge() const { return age; }

    void setGroupNumber(const string& g) { group_number = g; }
    const string& getGroupNumber() const { return group_number; }

    // Безопасный ввод оценок с проверкой
    void setGrades() {
        if (grades.empty()) return;

        for (size_t i = 0; i < grades.size(); ++i) {
            int grade;
            while (true) {
                cout << "Оценка " << (i + 1) << ": ";
                if (cin >> grade && grade >= 1 && grade <= 10) {
                    grades[i] = grade;
                    break;
                }
                else {
                    cout << "Ошибка: введите число от 1 до 10.\n";
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(),'\n');
                }
            }
        }
    }

    // Возврат копии вектора оценок
    const vector<int>& getGrades() const { return grades; }

    // Вывод информации
    void printInfo() const {
        cout << name << " " << surname
            << ", " << age << " лет, группа " << group_number << "\n";

        if (!grades.empty()) {
            cout << "Оценки: ";
            for (int g : grades) cout << g << " ";
            cout << "\n";
        }
        cout << "-----------------------------\n";
    }

    // Деструктор (теперь не нужен, но оставлен для демонстрации)
    ~Student() {
        cout << "Студент " << name << " " << surname << " удалён.\n";
    }

    // --- Правило трёх: не требуется при использовании vector,
    // но если бы использовали raw pointers — нужно было бы реализовать:
    // Student(const Student& other) = default;
    // Student& operator=(const Student& other) = default;
    // Student(Student&& other) = default;
    // Student& operator=(Student&& other) = default;
};

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    cout << "=== Управление студентами ===\n\n";

    // Создаём студента с 3 оценками
    Student s1("Иван", "Иванов", 18, "IT-101", 3);
    s1.printInfo();

    // Студент по умолчанию
    Student s2;
    s2.printInfo();

    // Динамически создаём объект
    Student* s3 = new Student("Петр", "Сидоров", 20, "IT-202", 2);
    s3->printInfo();

    delete s3;

    return 0;
}