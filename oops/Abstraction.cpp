#include <iostream>

using namespace std;

// we will declare one abstract class

class Car
{
public:
    string car_name;
    string model;
    int current_speed;
    int current_gear;
    bool isEngineOn;

    Car()
    {
        this->isEngineOn = false;
        this->current_speed = 0;
        this->current_gear = 0;
    }

    virtual ~Car() {}

    virtual void getCarDetails() = 0;
    virtual void startEngine() = 0;
    virtual void offEngine() = 0;
    virtual void accelerate() = 0;
    virtual void changeGear(int gear) = 0;
    virtual void brake() = 0;
};

class ManualCar : public Car
{
public:
    void getCarDetails()
    {
        cout << "Car name is : " << this->car_name << endl;
        cout << "Car model is : " << this->model << endl;
    }
    void startEngine()
    {
        if (!this->isEngineOn)
        {
            this->isEngineOn = true;
            cout << "Car is Starting ......" << endl;
        }
    }

    void offEngine()
    {
        this->isEngineOn = false;
        cout << "Car is Turned OFF ......." << endl;
    }

    void accelerate()
    {
        if (!this->isEngineOn)
        {
            cout << "Engine is Off ......" << endl;
        }
        else
        {
            this->current_speed += 20;
            cout << "Current Speed is : " << this->current_speed << endl;
        }
    }

    void changeGear(int gear)
    {
        if (!this->isEngineOn)
        {
            cout << "Engine is Off ......" << endl;
        }
        else
        {
            this->current_gear = gear;
            cout << "Current Gear is : " << this->current_gear << endl;
        }
    }

    void brake()
    {
        if (!this->isEngineOn)
        {
            cout << "Engine is Off ......" << endl;
        }
        else
        {
            this->current_speed -= 10;
            if (this->current_speed < 0)
            {
                this->current_speed = 0;
            }
            cout << "Current speed is : " << this->current_speed << endl;
        }
    }
};

int main()
{
    Car *car = new ManualCar();
    car->car_name = "Dhano";
    car->model = "BMW";

    car->startEngine();
    car->accelerate();
    car->accelerate();
    car->brake();
    car->brake();
    car->offEngine();

    delete car;

    return 0;
}