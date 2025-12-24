#include <iostream>
#include <windows.h>

#include "Student.h"
#include "StudentManager.h"
#include "ConsoleView.h"
#include "StudentPresenter.h"

using namespace std;

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    // Создаем менеджер студентов
    StudentManager manager;

    // Создаем консольное представление
    ConsoleView view;

    // Создаем презентер
    StudentPresenter presenter(manager, view);

    // Запуск программы
    presenter.run();

    return 0;
}