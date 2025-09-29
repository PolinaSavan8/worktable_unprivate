#include <iostream>
#include <string>
#include <windows.h>

using namespace std;

const int SIZE_OF_STUDENTS = 100;

struct Student
{
    string name;
    string surname;
    int age;
};

// ��������� �������
void showMenu(Student* arr_of_students, int& number_of_students);
void inputStudents(Student* arr_of_students, int& number_of_students);
void inputOneStudent(Student* arr_of_students, int position);
void addStudent(Student* arr_of_students, int& number_of_students);
void delStudent(Student* arr_of_students, int& number_of_students);
void changeStudent(Student* arr_of_students, int number_of_students);
void showStudents(Student* arr_of_students, int number_of_students);
bool isArrayEmpty(int number_of_students);

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    Student students[SIZE_OF_STUDENTS];
    int number_of_students = 0;

    showMenu(students, number_of_students);

    return 0;
}

// ����� ���� � ��������� ������ ������������
void showMenu(Student* arr_of_students, int& number_of_students)
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

        int item;
        cin >> item;
        cout << endl;

        if (item == 0) break;

        switch (item) {
        case 1:
            inputStudents(arr_of_students, number_of_students);
            break;
        case 2:
            addStudent(arr_of_students, number_of_students);
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
void inputStudents(Student* arr_of_students, int& number_of_students)
{
    cout << "=== ���������� ������� ���������� ===" << endl;
    cout << "������� ��������� �� ������ ��������? (�������� " << SIZE_OF_STUDENTS << "): ";
    int count;
    cin >> count;

    if (count < 0 || count > SIZE_OF_STUDENTS) {
        cout << "������������ ���������� ���������!" << endl;
        return;
    }

    if (number_of_students + count > SIZE_OF_STUDENTS) {
        cout << "������������ ����� � �������! �������� ����: " << SIZE_OF_STUDENTS - number_of_students << endl;
        return;
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
    if (position < SIZE_OF_STUDENTS)
    {
        cout << "���: ";
        cin >> arr_of_students[position].name;
        cout << "�������: ";
        cin >> arr_of_students[position].surname;
        cout << "�������: ";
        cin >> arr_of_students[position].age;
    }
}

// ���������� �������� � ������
void addStudent(Student* arr_of_students, int& number_of_students)
{
    if (number_of_students >= SIZE_OF_STUDENTS) {
        cout << "������ ��������! ���������� �������� ������ ��������.\n";
        return;
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

    int position;
    cout << "������� ����� �������� ��� �������� (1-" << number_of_students << "): ";
    cin >> position;

    if (position < 1 || position > number_of_students) {
        cout << "�������� ����� ��������!" << endl;
        return;
    }

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

    int position;
    cout << "������� ����� �������� ��� ��������� (1-" << number_of_students << "): ";
    cin >> position;

    if (position < 1 || position > number_of_students) {
        cout << "�������� ����� ��������!" << endl;
        return;
    }

    cout << "������� ������ �������� #" << position << ":" << endl;
    cout << "���: " << arr_of_students[position - 1].name << endl;
    cout << "�������: " << arr_of_students[position - 1].surname << endl;
    cout << "�������: " << arr_of_students[position - 1].age << endl;

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
            << arr_of_students[i].age << " ���" << endl;
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
