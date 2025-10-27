#include <iostream>
#include <string>
#include <windows.h>

using namespace std;

class Student
{
private:
    string name;
    string surname;
    int age;
    string group_number;

    // Новые поля
    int* grades;       // указатель на динамический массив оценок
    int gradesCount;  // количество оценок

public:
    // Конструктор с параметрами
    Student(string n, string s, int a, string g, int count = 0)
        : name(n),
        surname(s),
        age(a),
        group_number(g),
        gradesCount(count)
    {
        if (gradesCount > 0)
            grades = new int[gradesCount];  // динамически выделяем память
        else
            grades = nullptr;

        cout << "Создан объект студента: " << name << " " << surname << endl;
    }

    // Конструктор по умолчанию (делегирующий)
    Student()
        : Student("Неизвестно", "Неизвестно", 0, "-", 0)
    {}

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

    // Добавим метод для заполнения массива оценок
    void setGrades() {
        if (gradesCount <= 0) return;
        cout << "Введите " << gradesCount << " оценок для " << name << ": ";
        for (int i = 0; i < gradesCount; i++) {
            cin >> grades[i];
        }
    }

    // Метод вывода информации
    void printInfo() const
    {
        cout << name << " "
            << surname << ", "
            << age << " лет, группа "
            << group_number << endl;

        if (gradesCount > 0) {
            cout << "Оценки: ";
            for (int i = 0; i < gradesCount; i++)
                cout << grades[i] << " ";
            cout << endl;
        }
    }
    double calculateAverageGrade() {
        double result=0;
        for (int i = 0; i < gradesCount; i++) {
            result = result + grades[i];
        }
        result = result / gradesCount;
        return result;
    }
    // Деструктор
    ~Student() {
        delete[] grades; // освобождаем память
        cout << "Объект " << name << " " << surname << " уничтожен." << endl;
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
    cout<<s1.calculateAverageGrade()<<endl;

    // Создаём студента по умолчанию
    Student s2;
    s2.printInfo();

    // Динамически создаём объект
    Student* s3 = new Student("Петр", "Сидоров", 20, "IT-202", 2);
    s3->setGrades();
    s3->printInfo();

    delete s3; // вручную удаляем объект, чтобы вызвать деструктор

}