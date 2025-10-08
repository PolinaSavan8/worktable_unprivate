#include <iostream>
#include <vector>
#include <algorithm>//��� sort
using namespace std;

#include <iostream>
#include <string>
#include <windows.h>
#include <fstream>

using namespace std;

const int INITIAL_SIZE = 10; // ��������� ������ �������
const string FILE_OF_DATA = "MyFile.txt"; //���� � �����
const string GENERAL_ERROR = "������������ ����! ��������� ��������: ";
const int LEFT_RANGE_OF_MENU = 1;
const int RIGHT_RANGE_OF_MENU = 6;

struct Student
{
    string name;
    string surname;
    int age;
    string group;//class 10
    double average_mark;
};

struct Catalog
{
    string setting;
    string menu;
};

// ��������� �������
void showMenu_1(Catalog*& arr_of_menu);
void showMenu(Student*& arr_of_students, int& number_of_students, int& capacity);
void inputStudents(Student*& arr_of_students, int& number_of_students, int& capacity);
void inputOneStudent(Student* arr_of_students, int position);
void addStudent(Student*& arr_of_students, int& number_of_students, int& capacity);
void delStudent(Student* arr_of_students, int& number_of_students);
void changeStudent(Student* arr_of_students, int number_of_students);
void showStudents(Student* arr_of_students, int number_of_students);
bool isArrayEmpty(int number_of_students);

// ������� ��� ������ � ������������ ��������
Student* resizeArray(Student* arr, int& number_of_students, int new_capacity);

// ������ � ���� (���� ���-�� ���� � �����, �� �������� ������ ����� �������):
void writeFileStudents(Student* arr_of_students, int number_of_students);
// ������ �� ����� � ������:
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
    int capacity = 0; // ���������� ������ �������

    Catalog* arr_of_menu = nullptr;
    int installation = 0;


    // ������������� ������� ��������� ��������
    arr_of_students = resizeArray(arr_of_students, capacity, INITIAL_SIZE);

    readFileStudents(arr_of_students, number_of_students, capacity);

    //showMenu_1(arr_of_menu);

    showMenu(arr_of_students, number_of_students, capacity);

    writeFileStudents(arr_of_students, number_of_students);

    // ������������ ������ ����� �������
    delete[] arr_of_students;

    return 0;
}

// ����� � ��������� ���� �����
void showMenu_1(Catalog*& arr_of_menu)
{
    while (true)
    {
        cout << "### ��������� ###" << endl;
        cout << "=== M��� ���������� ���������� ==" << endl;
        cout << "=== ������������� ===" << endl;
        cout << "=== ������� ===" << endl;
        cout << "=== �������� ===" << endl;
        cout << "=== �������� ===" << endl;
        cout << "=== � ��� ===" << endl;
        cout << "=== �������! ===" << endl;
        cout << "=== ������ ===" << endl;
        cout << "=== ����� ===" << endl;
        cout << "=== ����������� �� ���������� ����! ===" << endl;
        cout << "=== ���� ���� ===" << endl;

        int item = inputNumber(GENERAL_ERROR, LEFT_RANGE_OF_MENU, RIGHT_RANGE_OF_MENU);

        cout << endl;

        if (item == 6) break;

        switch (item) {
        case 7:
            
            
        case 8:
            
            
        case 9:
            
            
        case 10:
            

        case 11:


        case 12:
            cout << "����� �� ���������" << endl;
            break;
        default:
            cout << "�������� �����! ���������� �����" << endl;
        }

        cout << endl;

    }
}
// ����� ���� � ��������� ������ ������������
void showMenu(Student*& arr_of_students, int& number_of_students, int& capacity)
{
    while (true)
    {
        cout << "=== ���� ���������� ���������� ===" << endl;
        cout << "1. ��������� ������ ����������" << endl;
        cout << "2. �������� ��������" << endl;
        cout << "3. ������� ��������" << endl;
        cout << "4. �������� ������ ��������" << endl;
        cout << "5. �������� ���� ���������" << endl;
        cout << "6. �����" << endl;
        cout << "�������� ��������: " << endl;

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
            cout << "����� �� ���������" << endl;
            break;
        default:
            cout << "�������� �����! ���������� �����" << endl;
        }

        cout << endl;

    }
}

// ���������� ������� ����������
void inputStudents(Student*& arr_of_students, int& number_of_students, int& capacity)
{
    cout << "=== ���������� ������� ���������� ===" << endl;
    cout << "������� ��������� �� ������ ��������?: ";
    int count = inputNumber(GENERAL_ERROR, 1, 1000);

    // ���������, ����� �� ����������� ������
    if (number_of_students + count > capacity) {
        int new_capacity = number_of_students + count;
        arr_of_students = resizeArray(arr_of_students, capacity, new_capacity);
    }

    for (int i = 0; i < count; i++) {
        cout << "������� " << i + 1 << ":" << endl;
        inputOneStudent(arr_of_students, number_of_students);

        number_of_students++;
    }

    cout << "��������� " << count << " ���������!" << endl;
}

void inputOneStudent(Student* arr_of_students, int position)
{
    cout << "���: ";
    cin >> arr_of_students[position].name;
    cout << "�������: ";
    cin >> arr_of_students[position].surname;
    cout << "�������: ";
    cin >> arr_of_students[position].age;
    cout << "������: ";
    cin >> arr_of_students[position].group;
    cout << "������� ����: ";
    cin >> arr_of_students[position].average_mark;
}

// ���������� �������� � ������
void addStudent(Student*& arr_of_students, int& number_of_students, int& capacity)
{
    // ���������, ����� �� ����������� ������
    if (number_of_students >= capacity) {
        int new_capacity = capacity * 2; // ����������� � 2 ����
        if (new_capacity == 0) new_capacity = 1; // �� ������, ���� capacity = 0
        arr_of_students = resizeArray(arr_of_students, capacity, new_capacity);
    }

    cout << "=== ���������� ������ �������� ===" << endl;
    inputOneStudent(arr_of_students, number_of_students);

    number_of_students++;
    cout << "������� ������� ��������!" << endl;
}

// �������� �������� �� �������
void delStudent(Student* arr_of_students, int& number_of_students)
{
    cout << "=== �������� �������� ===" << endl;
    showStudents(arr_of_students, number_of_students);

    cout << "������� ����� �������� ��� �������� (1-" << number_of_students << "): ";
    int position = inputNumber(GENERAL_ERROR, 1, number_of_students);

    // �������� �������� �������
    for (int i = position - 1; i < number_of_students - 1; i++) {
        arr_of_students[i] = arr_of_students[i + 1];
    }

    number_of_students--;
    cout << "������� ������� ������!" << endl;
}

// ��������� ������ � ��������
void changeStudent(Student* arr_of_students, int number_of_students)
{
    cout << "=== ��������� ������ �������� ===" << endl;
    showStudents(arr_of_students, number_of_students);

    cout << "������� ����� �������� ��� ��������� (1-" << number_of_students << "): ";
    int position = inputNumber(GENERAL_ERROR, 1, number_of_students);

    cout << "������� ������ �������� #" << position << ":" << endl;
    cout << "���: " << arr_of_students[position - 1].name << endl;
    cout << "�������: " << arr_of_students[position - 1].surname << endl;
    cout << "�������: " << arr_of_students[position - 1].age << endl;
    cout << "������: " << arr_of_students[position - 1].group << endl;
    cout << "������� ����: " << arr_of_students[position - 1].average_mark << endl;

    cout << "������� ����� ������: ";
    inputOneStudent(arr_of_students, position - 1);

    cout << "������ �������� ������� ��������!" << endl;
}

// ����� ����������� ������� �� �����
void showStudents(Student* arr_of_students, int number_of_students)
{
    cout << "=== ������ ��������� ===" << endl;
    for (int i = 0; i < number_of_students; i++) {
        cout << i + 1 << ". " << arr_of_students[i].surname << " "
            << arr_of_students[i].name << ", �������: "
            << arr_of_students[i].age << " ���"
            << arr_of_students[i].group
            << arr_of_students[i].average_mark << endl;
    }
    cout << "����� ���������: " << number_of_students << endl;
}

bool isArrayEmpty(int number_of_students)
{
    if (number_of_students == 0) {
        cout << "������ ����!" << endl;
        return true;
    }
    else return false;
}

// ��������� ������� ������������� ������� (�� ������ �������)
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
        // ����� �������� ���������������� ���������� �� ���������
        // (������ ������ � 0 ��� ��������)
        delete[] arr;
        arr = arr_new;
        capacity = new_capacity;
    }
    return arr;
}

void readFileStudents(Student*& arr_of_students, int& number_of_students, int& capacity)
{
    ifstream fin(FILE_OF_DATA, ios::in); //������� ���� ��� ������
    if (fin.is_open())
    {
        int i = 0;
        // ������� ���������� ���������� ������� � �����
        string temp_name, temp_surname;
        int temp_age;
        int temp_group;
        int temp_average_mark;
        int record_count = 0;

        while (fin >> temp_name >> temp_surname >> temp_age >> temp_group >> temp_average_mark) {
            record_count++;
        }

        // �������� � ������ �����
        fin.clear();
        fin.seekg(0);

        // �������� ������ ������� ��� ���������� �������
        if (record_count > capacity) {
            arr_of_students = resizeArray(arr_of_students, capacity, record_count);
        }

        // ������ ������ ������
        i = 0;
        while (i < record_count && fin >> arr_of_students[i].name
            >> arr_of_students[i].surname
            >> arr_of_students[i].age
            >> arr_of_students[i].group
            >> arr_of_students[i].average_mark) {
            i++;
        }
        number_of_students = i;

        cout << "��������� " << number_of_students << " ��������� �� �����." << endl;
    }
    fin.close();  //������� ����
}

void writeFileStudents(Student* arr_of_students, int number_of_students)
{
    ofstream fout(FILE_OF_DATA, ios::out);  //������� ���� ��� ������
    for (int i = 0; i < number_of_students; i++)
    {
        fout << arr_of_students[i].name << " "
            << arr_of_students[i].surname << " "
            << arr_of_students[i].age
            << arr_of_students[i].group
            << arr_of_students[i].average_mark;
        if (i < number_of_students - 1)
        {
            fout << endl;
        }
    }
    fout.close();
    cout << "������ ��������� � ����." << endl;
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


