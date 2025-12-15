#include <iostream>

using namespace std;

class Headlights {
private:
    int power;

public:
    Headlights(int power) : power(power)
    {
        cout << "Headlights created\n";
    }

    void start() const
    {
        cout << "Headlights started, power = " << power << endl;
    }

    ~Headlights()
    {
        cout << "Headlights destroyed\n";
    }
};
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

class Car
{
private:
    Engine engine; // композиция
    Headlights headlights;
public:
    Car(int power) : engine(power), headlights(power)
    {
        cout << "Car created\n";
    }

    void drive() const
    {
        engine.start();
        headlights.start();
        cout << "Car is driving\n";
    }

    ~Car()
    {
        cout << "Car destroyed\n";
    }
};

int main()
{
    Car car(150);
    car.drive();

}