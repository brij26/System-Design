// In this code snippet i will write the code of the inheritance , abstarction and encapsulation.

#include <iostream>
using namespace std;

// parent class

class Car
{
private:
    int currentSpeed;

protected:
    string CarName;
    string CarModel;
    bool IsEngineOn;

public:
    // constructer
    Car()
    {
        this->currentSpeed = 0;
        this->IsEngineOn = false;
    }

    // getter and setter for the CurrentSpeed
    int getCurrentSpeed()
    {
        return this->currentSpeed;
    }

    void setCurrentSpeed(int speed)
    {
        if (this->IsEngineOn && speed < 150)
        {
            this->currentSpeed = speed;
        }
    }

    // getter and setter for the Car Name
    string getCarName()
    {
        return this->CarName;
    }

    void setCarName(string name)
    {
        this->CarName = name;
    }

    // getter and setter for the Car Model
    string getCarModel()
    {
        return this->CarModel;
    }

    void setCarModel(string model)
    {
        this->CarModel = model;
    }

    // abstract methods
    virtual void startEngine() = 0;
    virtual void stopEngine() = 0;
    virtual void accelerate() = 0;
    virtual void brake() = 0;
    virtual void CarDetails() = 0;

    // destructer
    virtual ~Car() {}
};

class GearCar : public Car
{

public:
    GearCar() : Car() {}
    virtual void changeGear(int gear) = 0;

    virtual ~GearCar() {}
};

// now we will create two child class of the Car parent class

// 1. Manual car
class ManualCar : public GearCar
{
private:
    int currentGear;

public:
    // constructer
    ManualCar(string name, string model) : GearCar()
    {
        this->currentGear = 0;
        this->setCarName(name);
        this->setCarModel(model);
    }

    // getter and setter for the currentGear
    // getter
    int getCurrentGear()
    {
        return this->currentGear;
    }

    // setter
    void setCurrentGear(int gear)
    {
        if (this->IsEngineOn && gear > 0 && gear < 7)
        {
            this->currentGear = gear;
        }
    }

    // we will define the abstract method of the parent class over here
    void startEngine() override
    {
        this->IsEngineOn = true;
        cout << "Engine is Started....." << endl;
    }

    void stopEngine() override
    {
        this->setCurrentGear(0);
        this->setCurrentSpeed(0);
        this->IsEngineOn = false;
        cout << "Engine is OFF..." << endl;
    }

    void accelerate() override
    {
        if (!this->IsEngineOn)
        {
            cout << "Engine is Off..." << endl;
        }
        else
        {
            int speed = this->getCurrentSpeed();
            speed += 20;
            this->setCurrentSpeed(speed);
            cout << "Your current speed is : " << speed << endl;
        }
    }

    void brake() override
    {
        if (!this->IsEngineOn)
        {
            cout << "Engine is Off.." << endl;
        }

        else
        {
            int speed = this->getCurrentSpeed();
            speed -= 15;
            if (speed < 0)
            {
                speed = 0;
            }
            this->setCurrentSpeed(speed);
            cout << "Your current speed is : " << speed << endl;
        }
    }

    void CarDetails() override
    {
        cout << "This is the Manual car which name is " << this->getCarName() << " and car model is " << this->getCarModel() << endl;
    }

    void changeGear(int gear) override
    {
        if (!this->IsEngineOn)
        {
            cout << "Engine is Off..." << endl;
        }

        else
        {
            this->setCurrentGear(gear);
            cout << "Your gear is now shifted to " << gear << endl;
        }
    }
};

// 2. Electric Car
class ElectricCar : public Car
{
private:
    int batteryPercentage;

public:
    ElectricCar(string name, string model)
    {
        this->setCarName(name);
        this->setCarModel(model);
        this->batteryPercentage = 100;
    }

    // now write getter and setter methods for the private attributes of the class
    // getter and setter for the battery Percentage of the car
    // getter
    int getCarBetteryPercentage()
    {
        return this->batteryPercentage;
    }

    // setter
    void setCarBetteryPercentage(int pr)
    {
        if (pr <= 100)
        {
            this->batteryPercentage = pr;
        }
        else
        {
            this->batteryPercentage = 100;
        }
    }

    // now we will write all the abstract methods of the parent class from which this child class is inherited
    void startEngine() override
    {
        this->IsEngineOn = true;
        cout << "Engine started silently....." << endl;
    }

    void stopEngine() override
    {
        this->setCurrentSpeed(0);
        this->IsEngineOn = false;
        cout << "Engine is Off...." << endl;
    }

    void accelerate() override
    {
        if (!this->IsEngineOn)
        {
            cout << "Engine is Off.." << endl;
        }
        else
        {
            int speed = this->getCurrentSpeed();
            speed += 15;
            int batteryCharge = this->getCarBetteryPercentage();
            batteryCharge -= 5;
            this->setCarBetteryPercentage(batteryCharge);
            this->setCurrentSpeed(speed);
            cout << "Your current speed is " << speed << " and your current battery is " << batteryCharge << endl;
        }
    }

    void brake() override
    {
        if (!this->IsEngineOn)
        {
            cout << "Engine is Off..." << endl;
        }
        else
        {
            int speed = this->getCurrentSpeed();
            speed -= 10;
            if (speed < 0)
            {
                speed = 0;
            }
            int battery = this->getCarBetteryPercentage();
            battery -= 5;
            if (battery < 0)
            {
                battery = 0;
            }
            this->setCurrentSpeed(speed);
            this->setCarBetteryPercentage(battery);
            cout << "Your current speed is " << speed << " and your current battery is " << battery << endl;
        }
    }

    void CarDetails() override
    {
        cout << "This is and Electric car and it's Name is :" << this->getCarName() << " and it's Model Name is " << this->getCarModel() << " and current battery percentage is " << this->getCarBetteryPercentage() << "%." << endl;
    }
};

int main()
{
    // create one pointer of manual car object
    GearCar *car = new ManualCar("DHANO", "BMW");
    Car *AutoCar = new ElectricCar("BASANTI", "TATA");

    // this is of Manual Car
    cout << "This is manual Car" << endl;
    cout << "----------------------------" << endl;
    car->CarDetails();
    car->startEngine();
    car->accelerate();
    car->changeGear(2);
    car->accelerate();
    car->changeGear(4);
    car->brake();
    car->changeGear(3);
    car->brake();
    car->changeGear(2);
    car->stopEngine();
    cout << "---------------------------" << endl;

    // this is for electric car
    cout << "This is Auto Car" << endl;
    cout << "---------------------------" << endl;
    AutoCar->CarDetails();
    AutoCar->startEngine();
    AutoCar->accelerate();
    AutoCar->brake();
    AutoCar->brake();
    AutoCar->stopEngine();
    cout << "----------------------------" << endl;

    delete car;
    delete AutoCar;

    return 0;
}