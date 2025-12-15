#include <iostream>
#include <windows.h>
#include <string>

using namespace std;

class University
{
private:
    string universityName;

public:
    University(const string& name) : universityName(name) {}

    void print() const
    {
        cout << "University: " << universityName << endl;
    }

    // вложенный класс 
    class Department
    {
    private:
        string name;

    public:
        Department(const string& name) : name(name) {}

        void print() const
        {
            cout << "Department: " << name << endl;
        }


        class Specialization {
        private:
            string name;

        public:
            Specialization(const string& name) : name(name) {}

            void print() const {
                cout << "Specialization: " << name << endl;
            }
        };


    };
};

    
int main()
{
    University uni("Technical University");
    uni.print();

    University::Department dep1("Computer Science");
    dep1.print();
    University::Department::Specialization specialization1_1("web");
    specialization1_1.print();
    University::Department::Specialization specialization1_2("");
    specialization1_2.print();

    University::Department dep2("Gaming");
    dep2.print();
    University::Department::Specialization specialization2_1(" ");
    specialization2_1.print();

    University::Department dep3("Designing");
    dep3.print();
    University::Department::Specialization specialization3_1(" ");
    specialization3_1.print();
    
    

    return 0;
}