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
    int gradesCount;   // количество оценок

public:
    // Конструктор с параметрами по умолчанию
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
    {
    }

    // Конструктор копирования (глубокое копирование)
    Student(const Student& other)
        : name(other.name),
        surname(other.surname),
        age(other.age),
        group_number(other.group_number),
        gradesCount(other.gradesCount)
    {
        if (gradesCount > 0) {
            grades = new int[gradesCount];
            for (int i = 0; i < gradesCount; i++)
                grades[i] = other.grades[i];
        }
        else {
            grades = nullptr;
        }
    }

    // перегрузка оператора присваивания
    Student& operator=(const Student& other)
    {
        if (this == &other)
            return *this;   // самоприсваивание

        // Копируем простые поля
        name = other.name;
        surname = other.surname;
        age = other.age;
        group_number = other.group_number;

        // Удаляем старый массив оценок
        delete[] grades;

        gradesCount = other.gradesCount;

        if (gradesCount > 0) {
            grades = new int[gradesCount];
            for (int i = 0; i < gradesCount; i++)
                grades[i] = other.grades[i];
        }
        else {
            grades = nullptr;
        }

        return *this;
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

    void initGrades(int count) {
        if (count <= 0) return;
        delete[] grades;   // освобождаем старую память, если была
        gradesCount = count;
        grades = new int[count];
    }

    // Добавим метод для заполнения массива оценок
    void setGrades() {
        if (gradesCount <= 0) return;
        cout << "Введите " << gradesCount << " оценок для " << name << ": ";
        for (int i = 0; i < gradesCount; i++) {
            cin >> grades[i];
        }
    }

    // Добавить одну оценку
    void addGrade(int grade)
    {
        int* newArr = new int[gradesCount + 1];
        // копируем старые оценки
        for (int i = 0; i < gradesCount; i++)
            newArr[i] = grades[i];
        // добавляем новую оценку
        newArr[gradesCount] = grade;
        // освобождаем старую память
        delete[] grades;
        grades = newArr;
        gradesCount++;
    }

    // Полная очистка массива оценок
    void clearGrades()
    {
        delete[] grades;
        grades = nullptr;
        gradesCount = 0;
    }

    // Метод вывода информации
    void printInfo()
    {
        cout << name << " "
            << surname << ", "
            << age << " лет, группа "
            << group_number << endl;

        printGrades();
    }

    // Печать всех оценок
    void printGrades()
    {
        if (gradesCount == 0) {
            cout << "Оценок нет." << endl;
            return;
        }cout << "Оценки: ";
        for (int i = 0; i < gradesCount; i++)
            cout << grades[i] << " ";
        cout << endl;
    }

    // Средний балл студента
    double averageGrade()
    {
        if (gradesCount == 0)
            return 0;

        int sum = 0;
        for (int i = 0; i < gradesCount; i++)
            sum += sum + grades[i];

        return double(sum) / gradesCount;
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
}