#pragma once

#include <string>
#include <vector>

using namespace std;

class StudentValidator
{
public:
    static const int MIN_GRADE = 1;
    static const int MAX_GRADE = 10;

    static bool isValidName(const string& name);
    static bool isValidSurname(const string& surname);
    static bool isValidGroupNumber(const string& groupNumber);
    static bool isValidGrade(int grade);
    static bool areValidGrades(const vector<int>& grades);
};