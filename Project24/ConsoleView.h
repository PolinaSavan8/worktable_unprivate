#pragma once

#include <string>
#include <vector>

using namespace std;

struct StudentInputData
{
    string surname;
    string name;
    string groupNumber;
    vector<int> grades;
};

class ConsoleView
{
public:
    // ===== Главное меню =====
    void showMainMenu();
    int getMainMenuChoice();

    // ===== Меню редактирования студента =====
    void showStudentEditMenu();
    int getStudentEditChoice();

    // ===== Ввод данных =====
    StudentInputData inputStudentData();
    vector<int> inputGrades();
    int inputSingleGrade();

    string inputSurname();
    string inputName();
    string inputGroupNumber();

    // ===== Выбор =====
    size_t inputStudentIndex(size_t maxIndex);
    string inputSearchSurname();
    string inputFilterGroup();

    void showSortMenu();
    int getSortChoice();

    // ===== Вывод =====
    void showMessage(const string& message);
    void showStudent(const string& studentInfo);
    void showStudents(const vector<string>& studentsInfo);

    // ===== Служебное =====
    void pause();

private:
    // ===== Приватные методы безопасного ввода =====
    int inputInt(const string& prompt, int min = INT_MIN, int max = INT_MAX);
    string inputString(const string& prompt);
};