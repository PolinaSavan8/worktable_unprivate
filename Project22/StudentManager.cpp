#include "StudentManager.h"
#include <algorithm>

// --- Конструктор ---
StudentManager::StudentManager() {}

// --- Работа с коллекцией ---
void StudentManager::addStudent(const Student& student)
{
    students.push_back(student);
}

bool StudentManager::removeStudent(size_t index)
{
    if (index >= students.size())
        return false;

    students.erase(students.begin() + index);
    return true;
}

bool StudentManager::updateStudent(size_t index, const Student& updatedStudent)
{
    if (index >= students.size())
        return false;

    students[index] = updatedStudent;
    return true;
}

Student& StudentManager::getStudent(size_t index)
{
    return students.at(index); // безопасно: бросает исключение
}

size_t StudentManager::getStudentsCount() const
{
    return students.size();
}

// --- Бизнес-операции ---
vector<Student> StudentManager::findBySurname(const string& surname) const
{
    vector<Student> result;

    for (const auto& s : students)
    {
        if (s.getSurname() == surname)
        {
            result.push_back(s);
        }
    }
    return result;
}

vector<Student> StudentManager::filterByGroup(const string& groupNumber) const
{
    vector<Student> result;

    for (const auto& s : students)
    {
        if (s.getGroupNumber() == groupNumber)
        {
            result.push_back(s);
        }
    }
    return result;
}

// --- Сортировки ---
void StudentManager::sortBySurname()
{
    sort(students.begin(), students.end(),
        [](const Student& a, const Student& b)
        {
            return a.getSurname() < b.getSurname();
        });
}

void StudentManager::sortByAverageGrade()
{
    sort(students.begin(), students.end(),
        [](const Student& a, const Student& b)
        {
            return a.calculateAverageGrade() < b.calculateAverageGrade();
        });
}

// --- Доступ ко всей коллекции ---
const vector<Student>& StudentManager::getAllStudents() const
{
    return students;
}
