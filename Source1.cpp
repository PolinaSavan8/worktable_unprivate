#include <iostream>
#include <string>
#include <windows.h>
#include <fstream>

using namespace std;

const int INITIAL_SIZE = 10; // Начальный размер массива
const string FILE_OF_DATA = "MyFile.txt"; //Путь к файлу
const string GENERAL_ERROR = "Некорректный ввод! Повторите действие: ";
const int LEFT_RANGE_OF_MENU = 1;
const int RIGHT_RANGE_OF_MENU = 6;

struct Student
{
    string name;
    string surname;
    int age;
};

// Прототипы функций
void showMenu(Student*& arr_of_students, int& number_of_students, int& capacity);
void inputStudents(Student*& arr_of_students, int& number_of_students, int& capacity);
void inputOneStudent(Student* arr_of_students, int position);
void addStudent(Student*& arr_of_students, int& number_of_students, int& capacity);
void delStudent(Student* arr_of_students, int& number_of_students);
void changeStudent(Student* arr_of_students, int number_of_students);
void showStudents(Student* arr_of_students, int number_of_students);
bool isArrayEmpty(int number_of_students);

// Функции для работы с динамическим массивом
Student* resizeArray(Student* arr, int& number_of_students, int new_capacity);

// Запись в файл (если что-то было в файле, то исходные данные будут удалены):
void writeFileStudents(Student* arr_of_students, int number_of_students);
// Чтение из файла в массив:
void readFileStudents(Student*& arr_of_students, int& number_of_students, int& capacity);

int inputNumber(string error_message);
int inputNumber(string error_message, int left_range, int right_range);
bool isNumberNumeric();
bool isNumberRangeCorrect(int number, int left_range, int right_range);

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    Student* arr_of_students = nullptr;
    int number_of_students = 0;
    int capacity = 0; // Физический размер массива

    // Инициализация массива начальным размером
    arr_of_students = resizeArray(arr_of_students, capacity, INITIAL_SIZE);

    readFileStudents(arr_of_students, number_of_students, capacity);

    showMenu(arr_of_students, number_of_students, capacity);

    writeFileStudents(arr_of_students, number_of_students);

    // Освобождение памяти перед выходом
    delete[] arr_of_students;

    return 0;
}

// Вывод меню и обработка выбора пользователя
void showMenu(Student*& arr_of_students, int& number_of_students, int& capacity)
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

        int item = inputNumber(GENERAL_ERROR, LEFT_RANGE_OF_MENU, RIGHT_RANGE_OF_MENU);

        cout << endl;

        if (item == 6) break;

        switch (item) {
        case 1:
            inputStudents(arr_of_students, number_of_students, capacity);
            break;
        case 2:
            addStudent(arr_of_students, number_of_students, capacity);
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
void inputStudents(Student*& arr_of_students, int& number_of_students, int& capacity)
{
    cout << "=== ЗАПОЛНЕНИЕ МАССИВА СТУДЕНТАМИ ===" << endl;
    cout << "Сколько студентов вы хотите добавить?: ";
    int count = inputNumber(GENERAL_ERROR, 1, 1000);

    // Проверяем, нужно ли увеличивать массив
    if (number_of_students + count > capacity) {
        int new_capacity = number_of_students + count;
        arr_of_students = resizeArray(arr_of_students, capacity, new_capacity);
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
    cout << "Имя: ";
    cin >> arr_of_students[position].name;
    cout << "Фамилия: ";
    cin >> arr_of_students[position].surname;
    cout << "Возраст: ";
    cin >> arr_of_students[position].age;
}

// Добавление студента в массив
void addStudent(Student*& arr_of_students, int& number_of_students, int& capacity)
{
    // Проверяем, нужно ли увеличивать массив
    if (number_of_students >= capacity) {
        int new_capacity = capacity * 2; // Увеличиваем в 2 раза
        if (new_capacity == 0) new_capacity = 1; // На случай, если capacity = 0
        arr_of_students = resizeArray(arr_of_students, capacity, new_capacity);
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

    cout << "Введите номер студента для удаления (1-" << number_of_students << "): ";
    int position = inputNumber(GENERAL_ERROR, 1, number_of_students);

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

    cout << "Введите номер студента для изменения (1-" << number_of_students << "): ";
    int position = inputNumber(GENERAL_ERROR, 1, number_of_students);

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

// Изменение размера динамического массива (по вашему примеру)
Student* resizeArray(Student* arr, int& capacity, int new_capacity)
{
    Student* arr_new;
    if (capacity < new_capacity)
    {
        arr_new = new Student[new_capacity];
        for (int i = 0; i < capacity; i++)
        {
            arr_new[i] = arr[i];
        }
        // Новые элементы инициализируются значениями по умолчанию
        // (пустые строки и 0 для возраста)
        delete[] arr;
        arr = arr_new;
        capacity = new_capacity;
    }
    return arr;
}

void readFileStudents(Student*& arr_of_students, int& number_of_students, int& capacity)
{
    ifstream fin(FILE_OF_DATA, ios::in); //Открыли файл для чтения
    if (fin.is_open())
    {
        int i = 0;
        // Сначала подсчитаем количество записей в файле
        string temp_name, temp_surname;
        int temp_age;
        int record_count = 0;

        while (fin >> temp_name >> temp_surname >> temp_age) {
            record_count++;
        }

        // Вернемся в начало файла
        fin.clear();
        fin.seekg(0);

        // Изменяем размер массива под количество записей
        if (record_count > capacity) {
            arr_of_students = resizeArray(arr_of_students, capacity, record_count);
        }

        // Теперь читаем данные
        i = 0;
        while (i < record_count && fin >> arr_of_students[i].name
            >> arr_of_students[i].surname
            >> arr_of_students[i].age) {
            i++;
        }
        number_of_students = i;

        cout << "Загружено " << number_of_students << " студентов из файла." << endl;
    }
    fin.close();  //Закрыли файл
}

void writeFileStudents(Student* arr_of_students, int number_of_students)
{
    ofstream fout(FILE_OF_DATA, ios::out);  //Открыли файл для записи
    for (int i = 0; i < number_of_students; i++)
    {
        fout << arr_of_students[i].name << " "
            << arr_of_students[i].surname << " "
            << arr_of_students[i].age;
        if (i < number_of_students - 1)
        {
            fout << endl;
        }
    }
    fout.close();
    cout << "Данные сохранены в файл." << endl;
}

int inputNumber(string error_message)
{
    int number;

    while (true)
    {
        cin >> number;
        if (isNumberNumeric())
            return number;
        else
            cout << error_message << endl;
    }
}

bool isNumberNumeric()
{
    if (cin.get() == '\n')
        return true;
    else
    {
        cin.clear();
        cin.ignore(256, '\n');
        return false;
    }
}

int inputNumber(string error_message, int left_range, int right_range)
{
    int number;

    while (true)
    {
        cin >> number;
        if (isNumberNumeric() && isNumberRangeCorrect(number, left_range, right_range))
            return number;
        else
            cout << error_message << endl;
    }
}

bool isNumberRangeCorrect(int number, int left_range, int right_range)
{
    return number >= left_range && number <= right_range;
}
