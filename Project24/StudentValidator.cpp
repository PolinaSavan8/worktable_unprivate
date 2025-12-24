#include "StudentValidator.h"

// --- Имя ---
bool StudentValidator::isValidName(const string& name)
{
    return !name.empty();
}

// --- Фамилия ---
bool StudentValidator::isValidSurname(const string& surname)
{
    return !surname.empty();
}

// --- Номер группы ---
bool StudentValidator::isValidGroupNumber(const string& groupNumber)
{
    return !groupNumber.empty();
}

// --- Отдельная оценка ---
bool StudentValidator::isValidGrade(int grade)
{
    return grade >= MIN_GRADE && grade <= MAX_GRADE;
}

// --- Вектор оценок ---
bool StudentValidator::areValidGrades(const vector<int>& grades)
{
    for (int g : grades)
    {
        if (!isValidGrade(g))
            return false;
    }
    return true;
}
