#include <iostream>
#include <string>
#include <windows.h>

using namespace std;

const int SIZE_OF_STUDENTS = 100;

struct Student
{
    string name;
    string surname;
    int age;
};

// Прототипы функций
void showMenu(Student* arr_of_students, int& number_of_students);
void inputStudents(Student* arr_of_students, int& number_of_students);
void inputOneStudent(Student* arr_of_students, int position);
void addStudent(Student* arr_of_students, int& number_of_students);
void delStudent(Student* arr_of_students, int& number_of_students);
void changeStudent(Student* arr_of_students, int number_of_students);
void showStudents(Student* arr_of_students, int number_of_students);
bool isArrayEmpty(int number_of_students);

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    Student students[SIZE_OF_STUDENTS];
    int number_of_students = 0;

    showMenu(students, number_of_students);

    return 0;
}

// Вывод меню и обработка выбора пользователя
void showMenu(Student* arr_of_students, int& number_of_students)
{
    while (true)
    {
        cout << "=== МЕНЮ УПРАВЛЕНИЯ СТУДЕНТАМИ ===" << endl;
        cout << "1. Заполнить массив студентами" << endl;
        cout << "2. Добавить студента" << endl;
        cout << "3. Удалить студента" << endl;
        cout << "4. Изменить данные студента" << endl;
        cout << "5. Показать всех студентов" << endl;
        cout << "6. Выход" << endl;
        cout << "Выберите действие: " << endl;

        int item;
        cin >> item;
        cout << endl;

        if (item == 0) break;

        switch (item) {
        case 1:
            inputStudents(arr_of_students, number_of_students);
            break;
        case 2:
            addStudent(arr_of_students, number_of_students);
            break;
        case 3:
            if (!isArrayEmpty(number_of_students))
            {
                delStudent(arr_of_students, number_of_students);
            }
            break;
        case 4:
            if (!isArrayEmpty(number_of_students))
            {
                changeStudent(arr_of_students, number_of_students);
            }
            break;
        case 5:
            if (!isArrayEmpty(number_of_students))
            {
                showStudents(arr_of_students, number_of_students);
            }
            break;
        case 6:
            cout << "Выход из программы" << endl;
            break;
        default:
            cout << "Неверный выбор! Попробуйте снова" << endl;
        }

        cout << endl;

    }
}

// Заполнение массива студентами
void inputStudents(Student* arr_of_students, int& number_of_students)
{
    cout << "=== ЗАПОЛНЕНИЕ МАССИВА СТУДЕНТАМИ ===" << endl;
    cout << "Сколько студентов вы хотите добавить? (максимум " << SIZE_OF_STUDENTS << "): ";
    int count;
    cin >> count;

    if (count < 0 || count > SIZE_OF_STUDENTS) {
        cout << "Некорректное количество студентов!" << endl;
        return;
    }

    if (number_of_students + count > SIZE_OF_STUDENTS) {
        cout << "Недостаточно места в массиве! Доступно мест: " << SIZE_OF_STUDENTS - number_of_students << endl;
        return;
    }

    for (int i = 0; i < count; i++) {
        cout << "Студент " << i + 1 << ":" << endl;
        inputOneStudent(arr_of_students, number_of_students);

        number_of_students++;
    }

    cout << "Добавлено " << count << " студентов!" << endl;
}

void inputOneStudent(Student* arr_of_students, int position)
{
    if (position < SIZE_OF_STUDENTS)
    {
        cout << "Имя: ";
        cin >> arr_of_students[position].name;
        cout << "Фамилия: ";
        cin >> arr_of_students[position].surname;
        cout << "Возраст: ";
        cin >> arr_of_students[position].age;
    }
}

// Добавление студента в массив
void addStudent(Student* arr_of_students, int& number_of_students)
{
    if (number_of_students >= SIZE_OF_STUDENTS) {
        cout << "Массив заполнен! Невозможно добавить нового студента.\n";
        return;
    }

    cout << "=== ДОБАВЛЕНИЕ НОВОГО СТУДЕНТА ===" << endl;
    inputOneStudent(arr_of_students, number_of_students);

    number_of_students++;
    cout << "Студент успешно добавлен!" << endl;
}

// Удаление студента из массива
void delStudent(Student* arr_of_students, int& number_of_students)
{
    cout << "=== УДАЛЕНИЕ СТУДЕНТА ===" << endl;
    showStudents(arr_of_students, number_of_students);

    int position;
    cout << "Введите номер студента для удаления (1-" << number_of_students << "): ";
    cin >> position;

    if (position < 1 || position > number_of_students) {
        cout << "Неверный номер студента!" << endl;
        return;
    }

    // Сдвигаем элементы массива
    for (int i = position - 1; i < number_of_students - 1; i++) {
        arr_of_students[i] = arr_of_students[i + 1];
    }

    number_of_students--;
    cout << "Студент успешно удален!" << endl;
}

// Изменение данных о студенте
void changeStudent(Student* arr_of_students, int number_of_students)
{
    cout << "=== ИЗМЕНЕНИЕ ДАННЫХ СТУДЕНТА ===" << endl;
    showStudents(arr_of_students, number_of_students);

    int position;
    cout << "Введите номер студента для изменения (1-" << number_of_students << "): ";
    cin >> position;

    if (position < 1 || position > number_of_students) {
        cout << "Неверный номер студента!" << endl;
        return;
    }

    cout << "Текущие данные студента #" << position << ":" << endl;
    cout << "Имя: " << arr_of_students[position - 1].name << endl;
    cout << "Фамилия: " << arr_of_students[position - 1].surname << endl;
    cout << "Возраст: " << arr_of_students[position - 1].age << endl;

    cout << "Введите новые данные: ";
    inputOneStudent(arr_of_students, position - 1);

    cout << "Данные студента успешно изменены!" << endl;
}

// Вывод содержимого массива на экран
void showStudents(Student* arr_of_students, int number_of_students)
{
    cout << "=== СПИСОК СТУДЕНТОВ ===" << endl;
    for (int i = 0; i < number_of_students; i++) {
        cout << i + 1 << ". " << arr_of_students[i].surname << " "
            << arr_of_students[i].name << ", возраст: "
            << arr_of_students[i].age << " лет" << endl;
    }
    cout << "Всего студентов: " << number_of_students << endl;
}

bool isArrayEmpty(int number_of_students)
{
    if (number_of_students == 0) {
        cout << "Массив пуст!" << endl;
        return true;
    }
    else return false;
}
