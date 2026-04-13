#include <iostream>

using namespace std;

// In this code we will implement ABSTRACTION and ENCAPSULATION in one code

class Car
{
private:
    int currentSpeed;

protected:
    string Name;
    string Model;
    int currentGear;
    bool isEngineOn;

public:
    // constructer
    Car()
    {
        this->Name = "";
        this->Model = "";
        this->currentGear = 0;
        this->currentSpeed = 0;
        this->isEngineOn = false;
    }

    // getter and setter for car name
    string getCarName()
    {
        return this->Name;
    }
    void setCarName(string name)
    {
        this->Name = name;
    }

    // getter and setter for car model
    string getCarModel()
    {
        return this->Model;
    }

    void setCarModel(string model)
    {
        this->Model = model;
    }

    // getter for gear
    int getCurrentGear()
    {
        return this->currentGear;
    }

    // setter for the gear
    void setCurrentGear(int gear)
    {
        this->currentGear = gear;
        cout << "Shift the gear to " << this->currentGear << endl;
    }

    // abstract methods
    virtual void startEngine() = 0;
    virtual void stopEngine() = 0;
    virtual void accelerate() = 0;
    virtual void changeGear(int gear) = 0;
    virtual void brake() = 0;
    virtual void getCarDetails() = 0;

    // getter for the speed
    int getSpeed()
    {
        if (!this->isEngineOn)
        {
            cout << "Engine is off so that current speed is : " << this->currentSpeed << endl;
        }
        return this->currentSpeed;
    }

    // setter for the speed
    void setSpeed(int speed)
    {
        if (!this->isEngineOn)
        {
            cout << "Engine is Off" << endl;
        }
        else
        {
            this->currentSpeed = speed;
            cout << "Your speed is : " << this->currentSpeed << endl;
        }
    }

    // desturcter
    virtual ~Car() {}
};

// now we will inhert the Car class
class ManualCar : public Car
{
public:
    // now we write the code of the abstract methods of the parent class
    void startEngine() override
    {
        this->isEngineOn = true;
        cout << "Engine is starting ......." << endl;
    }

    void stopEngine() override
    {
        this->setCurrentGear(0);
        this->setSpeed(0);
        this->isEngineOn = false;
        cout << "Engine is Off ...." << endl;
        }

    void accelerate() override
    {
        if (!this->isEngineOn)
        {
            cout << "Engine is Off" << endl;
        }
        else
        {
            int speed = this->getSpeed();
            speed += 20;
            this->setSpeed(speed);
        }
    }

    void brake() override
    {
        if (!this->isEngineOn)
        {
            cout << "Engine is off" << endl;
        }
        else
        {
            int speed = this->getSpeed();
            speed -= 15;
            if (speed < 0)
            {
                speed = 0;
            }
            this->setSpeed(speed);
        }
    }

    void changeGear(int gear) override
    {
        if (!this->isEngineOn)
        {
            cout << "Engine is off" << endl;
        }
        else
        {
            this->setCurrentGear(gear);
        }
    }

    void getCarDetails() override
    {
        string name = this->getCarName();
        string model = this->getCarModel();
        cout << "Car name is : " << name << " and car model is : " << model << endl;
    }
};

int main()
{
    Car *car = new ManualCar;

    // set car name and car model
    car->setCarName("Dhano");
    car->setCarModel("BMW");

    car->getCarDetails();
    car->startEngine();
    car->accelerate();
    car->changeGear(2);
    car->accelerate();
    car->changeGear(4);
    car->brake();
    car->changeGear(3);
    car->brake();
    car->changeGear(2);
    car->brake();
    car->stopEngine();

    delete car;

    return 0;
}