#include "ConsoleView.h"
#include <iostream>

using namespace std;

// ===== Приватные методы =====
int ConsoleView::inputInt(const string& prompt, int min, int max)
{
    int value;
    while (true)
    {
        cout << prompt;
        if (cin >> value)
        {
            if (value >= min && value <= max)
            {
                cin.ignore(256, '\n');
                return value;
            }
            else
            {
                cout << "Число должно быть в диапазоне [" << min << ".." << max << "]\n";
            }
        }
        else
        {
            cout << "Некорректный ввод. Попробуйте снова.\n";
            cin.clear();
            cin.ignore(256, '\n');
        }
    }
}

string ConsoleView::inputString(const string& prompt)
{
    string s;
    cout << prompt;
    getline(cin, s);

    // Очистка консоли для предотвращения мусора в буфере (WinAPI)
    // SetConsoleCP / SetConsoleOutputCP можно настроить отдельно, если нужно
    if (s.empty())
        getline(cin, s); // безопасный повтор

    return s;
}

// ===== Главное меню =====
void ConsoleView::showMainMenu()
{
    cout << "\n===== Главное меню =====\n";
    cout << "1. Добавить студента\n";
    cout << "2. Удалить студента\n";
    cout << "3. Изменить данные студента\n";
    cout << "4. Показать всех студентов\n";
    cout << "5. Поиск студента по фамилии\n";
    cout << "6. Фильтр по группе\n";
    cout << "7. Сортировка\n";
    cout << "0. Выход\n";
}

int ConsoleView::getMainMenuChoice()
{
    return inputInt("Выберите пункт меню: ", 0, 7);
}

// ===== Меню редактирования студента =====
void ConsoleView::showStudentEditMenu()
{
    cout << "\n=== Меню редактирования студента ===\n";
    cout << "1. Изменить фамилию\n";
    cout << "2. Изменить имя\n";
    cout << "3. Изменить номер группы\n";
    cout << "4. Заменить вектор оценок\n";
    cout << "5. Очистить вектор оценок\n";
    cout << "6. Добавить новую оценку\n";
    cout << "0. Назад\n";
}

int ConsoleView::getStudentEditChoice()
{
    return inputInt("Выберите действие: ", 0, 6);
}

// ===== Ввод данных =====
StudentInputData ConsoleView::inputStudentData()
{
    StudentInputData data;
    data.surname = inputString("Фамилия: ");
    data.name = inputString("Имя: ");
    data.groupNumber = inputString("Номер группы: ");

    int count;
    cout << "Введите кол-во оценок: ";
    cin >> count;
    int grade;
    for (int i = 0; i < count; i++)
    {
        cout << "Введите оценку: ";
        cin >> grade;
        data.grades.push_back(grade);
    }
    cin.clear();
    cin.ignore(256, '\n');

    return data;
}

vector<int> ConsoleView::inputGrades()
{
    vector<int> grades;
    int count;
    cout << "Введите кол-во оценок: ";
    cin >> count;
    int grade;
    for (int i = 0; i < count; i++)
    {
        cout << "Введите оценку: ";
        cin >> grade;
        grades.push_back(grade);
    }
    cin.clear();
    cin.ignore(256, '\n');
    return grades;
}

int ConsoleView::inputSingleGrade()
{
    return inputInt("Введите оценку: ");
}

string ConsoleView::inputSurname()
{
    return inputString("Введите фамилию: ");
}

string ConsoleView::inputName()
{
    return inputString("Введите имя: ");
}

string ConsoleView::inputGroupNumber()
{
    return inputString("Введите номер группы: ");
}

// ===== Выбор =====
size_t ConsoleView::inputStudentIndex(size_t maxIndex)
{
    return static_cast<int>(inputInt("Введите индекс студента (0.." + to_string(maxIndex - 1) + "): ", 0, maxIndex - 1));
}

string ConsoleView::inputSearchSurname()
{
    return inputString("Введите фамилию для поиска: ");
}

string ConsoleView::inputFilterGroup()
{
    return inputString("Введите номер группы для фильтрации: ");
}

void ConsoleView::showSortMenu()
{
    cout << "\n=== Меню сортировки ===\n";
    cout << "1. По фамилии (алфавит)\n";
    cout << "2. По среднему баллу\n";
    cout << "0. Назад\n";
}

int ConsoleView::getSortChoice()
{
    return inputInt("Выберите сортировку: ", 0, 2);
}

// ===== Вывод =====
void ConsoleView::showMessage(const string& message)
{
    cout << message << endl;
}

void ConsoleView::showStudent(const string& studentInfo)
{
    cout << studentInfo << endl;
}
void ConsoleView::showStudents(const vector<string>& studentsInfo)
{
    for (const auto& s : studentsInfo)
        cout << s << endl;
}

// ===== Служебное =====
void ConsoleView::pause()
{
    cout << "\nНажмите Enter для продолжения...";
    cin.ignore(256, '\n');
}