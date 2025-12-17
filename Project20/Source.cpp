#include <iostream>

using namespace std;

class Engine
{
private:
    int power;

public:
    Engine(int power) : power(power)
    {
        cout << "Engine created\n";
    }

    void start() const
    {
        cout << "Engine started, power = " << power << endl;
    }

    ~Engine()
    {
        cout << "Engine destroyed\n";
    }
};

class Electronics
{
private:
    string serial_number;

public:
    Electronics(string serial_number) : serial_number(serial_number)
    {
        cout << "Electronics has been added\n";
    }

    void start() const
    {
        cout << "Electronics has been started, serial_number = " << serial_number << endl;
    }

    ~Electronics()
    {
        cout << "Electronics destroyed\n";
    }
};

class Car
{
private:
    Engine engine; // композиция
    Electronics electronics; // композиция

public:
    Car(int power, string serial_number) : engine(power), electronics(serial_number)
    {
        cout << "Car created\n";
    }

    void drive() const
    {
        engine.start();
        electronics.start();
        cout << "Car is driving\n";
    }

    ~Car()
    {
        cout << "Car destroyed\n";
    }
};

int main()
{
    Car car(150, "jhv232");
    car.drive();

}