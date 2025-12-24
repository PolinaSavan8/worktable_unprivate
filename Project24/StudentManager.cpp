#include "StudentManager.h"
#include <algorithm>

// --- Конструктор ---
StudentManager::StudentManager() {
    students.reserve(BASIC_CAPACITY);
}

// --- Работа с коллекцией ---
bool StudentManager::addStudent(const Student& student)
{
    if (!StudentValidator::isValidName(student.getName()) ||
        !StudentValidator::isValidSurname(student.getSurname()) ||
        !StudentValidator::isValidGroupNumber(student.getGroupNumber()) ||
        !StudentValidator::areValidGrades(student.getGrades()))
    {
        return false; // данные невалидные
    }

    students.push_back(student);
    return true;
}

// --- Удаление студента ---
bool StudentManager::removeStudent(size_t index)
{
    if (index >= students.size())
        return false;

    students.erase(students.begin() + index);
    return true;
}

// --- Обновление студента ---
bool StudentManager::updateStudent(size_t index, const Student& student)
{
    if (index >= students.size())
        return false;

    if (!StudentValidator::isValidName(student.getName()) ||
        !StudentValidator::isValidSurname(student.getSurname()) ||
        !StudentValidator::isValidGroupNumber(student.getGroupNumber()) ||
        !StudentValidator::areValidGrades(student.getGrades()))
    {
        return false; // данные невалидные
    }

    students[index] = student;
    return true;
}

// --- Получение студента ---
Student& StudentManager::getStudent(size_t index)
{
    return students.at(index); // выброс std::out_of_range при неверном индексе
}

// --- Количество студентов ---
size_t StudentManager::getStudentsCount() const
{
    return students.size();
}

// --- Поиск по фамилии ---
vector<Student> StudentManager::findBySurname(const string& surname) const
{
    vector<Student> result;
    for (const auto& s : students)
    {
        if (s.getSurname() == surname)
            result.push_back(s);
    }
    return result;
}

// --- Фильтрация по группе ---
vector<Student> StudentManager::filterByGroup(const string& groupNumber) const
{
    vector<Student> result;
    for (const auto& s : students)
    {
        if (s.getGroupNumber() == groupNumber)
            result.push_back(s);
    }
    return result;
}

// --- Сортировка ---
void StudentManager::sortBySurname()
{
    sort(students.begin(), students.end(),
        [](const Student& a, const Student& b) {
            return a.getSurname() < b.getSurname();
        });
}

void StudentManager::sortByAverageGrade()
{
    sort(students.begin(), students.end(),
        [](const Student& a, const Student& b) {
            return a.calculateAverageGrade() < b.calculateAverageGrade();
        });
}

// --- Доступ ко всей коллекции ---
const vector<Student>& StudentManager::getAllStudents() const
{
    return students;
}
