#include <iostream>
#include <string>

using namespace std;

class Manager {
private:
    string name;

public:
    Manager(const string& name) : name(name) {}

    string getName() const
    {
        return name;
    }
};

class Teacher
{
private:
    string name;

public:
    Teacher(const string& name) : name(name) {}

    string getName() const
    {
        return name;
    }
};

class Course
{
private:
    Teacher* teacher; // агрегация
    Manager* manager;
public:
    Course(Teacher* teacher, Manager* manager) : 
        teacher(teacher), manager(manager) 
    {}

    void print() const
    {
        cout << "Course manager: " << manager->getName() << endl;
        cout << "Course teacher: " << teacher->getName() << endl;
    }


  
};

int main()
{
    Manager m1("Anna Smirnova");
    Teacher t1("Ivan Ivanov");
    Course cpp1(&t1, &m1);
   
    cpp1.print();

    Manager m2("Sumaya Pavlova");
    Teacher t2("Ivan Ivanov");
    Course cpp2(&t2, &m2);
    cpp2.print();

    // Teacher продолжает существовать
    cout << "Teacher still exists: " << t1.getName() << endl;
    cout << "Manager still exists: " << m1.getName() << endl;

    cout << "Teacher still exists: " << t2.getName() << endl;
    cout << "Manager still exists: " << m2.getName() << endl;

    return 0;
}