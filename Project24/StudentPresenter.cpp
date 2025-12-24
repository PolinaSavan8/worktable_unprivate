#include "StudentPresenter.h"
#include <algorithm>

using namespace std;

StudentPresenter::StudentPresenter(StudentManager& manager, ConsoleView& view)
    : manager(manager), view(view)
{
}

void StudentPresenter::run()
{
    bool running = true;
    while (running)
    {
        view.showMainMenu();
        int choice = view.getMainMenuChoice();

        switch (choice)
        {
        case 1: addStudent(); break;
        case 2: removeStudent(); break;
        case 3: editStudent(); break;
        case 4: showAllStudents(); break;
        case 5: searchBySurname(); break;
        case 6: filterByGroup(); break;
        case 7: sortStudents(); break;
        case 0: running = false; break;
        default: view.showMessage("Некорректный выбор."); break;
        }
    }
}

// ===== Вспомогательный метод для форматирования вывода =====
string StudentPresenter::formatStudent(const Student& s)
{

    char buffer[20];
    sprintf_s(buffer, "%.2f", s.calculateAverageGrade()); // теперь корректно
    return s.getSurname() + " " + s.getName() +
        " | Группа: " + s.getGroupNumber() +
        " | Средний балл: " + string(buffer);
}

// ===== Методы действий =====

void StudentPresenter::addStudent()
{
    StudentInputData data = view.inputStudentData();

    // Минимальная проверка через Validator
    if (StudentValidator::isValidName(data.name) &&
        StudentValidator::isValidSurname(data.surname) &&
        StudentValidator::isValidGroupNumber(data.groupNumber) &&
        StudentValidator::areValidGrades(data.grades))
    {
        Student s(data.surname, data.name, data.groupNumber, data.grades);
        manager.addStudent(s);
        view.showMessage("Студент добавлен.");
    }
    else
    {
        view.showMessage("Ошибка: данные студента некорректны.");
    }
}

void StudentPresenter::removeStudent()
{
    size_t count = manager.getStudentsCount();
    if (count == 0)
    {
        view.showMessage("Нет студентов для удаления.");
        return;
    }

    showAllStudents();
    size_t index = view.inputStudentIndex(count);
    if (manager.removeStudent(index))
        view.showMessage("Студент удален.");
    else
        view.showMessage("Ошибка при удалении студента.");
}

void StudentPresenter::editStudent()
{
    size_t count = manager.getStudentsCount();
    if (count == 0)
    {
        view.showMessage("Нет студентов для редактирования.");
        return;
    }

    showAllStudents();
    size_t index = view.inputStudentIndex(count);
    editStudentField(index);
}

void StudentPresenter::editStudentField(size_t index)
{
    bool editing = true;
    while (editing)
    {
        view.showStudentEditMenu();
        int choice = view.getStudentEditChoice();

        Student s = manager.getStudent(index); // копия студента
        switch (choice)
        {
        case 1:
        {
            string newSurname = view.inputSurname();
            if (StudentValidator::isValidSurname(newSurname))
            {
                s.setSurname(newSurname);
                manager.updateStudent(index, s);
                view.showMessage("Фамилия изменена.");
            }
            else view.showMessage("Некорректная фамилия.");
            break;
        }
        case 2:
        {
            string newName = view.inputName();
            if (StudentValidator::isValidName(newName))
            {
                s.setName(newName);
                manager.updateStudent(index, s);
                view.showMessage("Имя изменено.");
            }
            else view.showMessage("Некорректное имя.");
            break;
        }
        case 3:
        {
            string newGroup = view.inputGroupNumber();
            if (StudentValidator::isValidGroupNumber(newGroup))
            {
                s.setGroupNumber(newGroup);
                manager.updateStudent(index, s);
                view.showMessage("Номер группы изменен.");
            }
            else view.showMessage("Некорректный номер группы.");
            break;
        }
        case 4:
        {
            vector<int> newGrades = view.inputGrades();
            if (StudentValidator::areValidGrades(newGrades))
            {
                s.setGrades(newGrades);
                manager.updateStudent(index, s);
                view.showMessage("Оценки заменены.");
            }
            else view.showMessage("Некорректные оценки.");
            break;
        }
        case 5:
            s.clearGrades();
            manager.updateStudent(index, s);
            view.showMessage("Оценки очищены.");
            break;
        case 6:
        {
            int grade = view.inputSingleGrade();
            if (StudentValidator::isValidGrade(grade))
            {
                s.addGrade(grade);
                manager.updateStudent(index, s);
                view.showMessage("Оценка добавлена.");
            }
            else view.showMessage("Некорректная оценка.");
            break;
        }
        case 0:
            editing = false;
            break;
        default:
            view.showMessage("Некорректный выбор.");
            break;
        }
    }
}

void StudentPresenter::showAllStudents()
{
    vector<Student> students = manager.getAllStudents();
    vector<string> infos;
    for (auto& s : students)
    {
        infos.push_back(formatStudent(s));
    }
    view.showStudents(infos);
}

void StudentPresenter::searchBySurname()
{
    string surname = view.inputSearchSurname();
    vector<Student> results = manager.findBySurname(surname);

    if (results.empty())
        view.showMessage("Студенты не найдены.");
    else
    {
        vector<string> infos;
        for (auto& s : results)
        {
            infos.push_back(formatStudent(s));
        }
        view.showStudents(infos);
    }
}

void StudentPresenter::filterByGroup()
{
    string group = view.inputFilterGroup();
    vector<Student> results = manager.filterByGroup(group);

    if (results.empty())
        view.showMessage("Студенты не найдены.");
    else
    {
        vector<string> infos;
        for (auto& s : results)
        {
            infos.push_back(formatStudent(s));
        }
        view.showStudents(infos);
    }
}

void StudentPresenter::sortStudents()
{
    view.showSortMenu();
    int choice = view.getSortChoice();

    switch (choice)
    {
    case 1: manager.sortBySurname(); view.showMessage("Сортировка по фамилии выполнена."); break;
    case 2: manager.sortByAverageGrade(); view.showMessage("Сортировка по среднему баллу выполнена."); break;
    case 0: break;
    default: view.showMessage("Некорректный выбор."); break;
    }
}
