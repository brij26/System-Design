#include <iostream>
using namespace std;

class Car
{
private:
    int currentSpeed;

protected:
    string CarName;
    string CarModel;
    bool isEngineON;

public:
    // constructer
    Car()
    {
        this->currentSpeed = 0;
    }

    // getter and setter for the private attributes of the class
    // getter for current speed
    int getCurrentSpeed()
    {
        return this->currentSpeed;
    }

    // setter for current speed
    void setCurrentSpeed(int speed)
    {
        if (this->isEngineON && speed < 150)
        {
            this->currentSpeed = speed;
        }
    }

    // write virtual functions
    virtual void startEngine() = 0;
    virtual void stopEngine() = 0;
    virtual void accelerate() = 0;
    // write one function of the method overloading
    virtual void accelerate(int acc) = 0;
    virtual void brake() = 0;
    virtual void getCarDetails() = 0;

    // destructor
    virtual ~Car() {}
};

class GearCar : public Car
{

protected:
    int currentGear;

public:
    // constructor
    GearCar() : Car()
    {
        this->currentGear = 0;
    }

    // getter and setter for the current gear
    // getter
    int getCurrentGear()
    {
        return this->currentGear;
    }

    // setter
    void setCurrentGear(int gear)
    {
        this->currentGear = gear;
    }
    // virtual methods
    virtual void shiftGear(int gear) = 0;

    // destructor
    virtual ~GearCar() {}
};

class ManualCar : public GearCar
{
public:
    // consturcter
    ManualCar(string name, string model) : GearCar()
    {
        this->CarName = name;
        this->CarModel = model;
    }

    // define all the virtual function of the parent class into this child class
    void startEngine() override
    {
        this->isEngineON = true;
        cout << "Engine is START....." << endl;
    }

    void stopEngine() override
    {
        this->currentGear = 0;
        this->setCurrentSpeed(0);
        this->isEngineON = false;
        cout << "Engine is OFF...." << endl;
    }

    void accelerate() override
    {
        if (!this->isEngineON)
        {
            cout << "Engine is OFF...." << endl;
        }
        else
        {
            int speed = this->getCurrentSpeed();
            speed += 20;
            this->setCurrentSpeed(speed);
            cout << "Your current speed is " << speed << endl;
        }
    }

    void accelerate(int acc) override
    {
        if (!this->isEngineON)
        {
            cout << "Engine is OFF..." << endl;
        }
        else
        {
            int speed = this->getCurrentSpeed();
            speed += acc;
            this->setCurrentSpeed(speed);
            cout << "Your current speed is " << speed << endl;
        }
    }

    void brake() override
    {
        if (!this->isEngineON)
        {
            cout << "Engine is OFF..." << endl;
        }

        else
        {
            int speed = this->getCurrentSpeed();
            speed -= 10;
            if (speed < 0)
            {
                speed = 0;
            }
            this->setCurrentSpeed(speed);
            cout << "Your current speed is " << speed << endl;
        }
    }

    void shiftGear(int gear) override
    {
        if (!this->isEngineON)
        {
            cout << "Your Engine is OFF...." << endl;
        }

        else
        {
            int prev = this->getCurrentGear();
            this->setCurrentGear(gear);
            cout << "You shift gear from " << prev << " to " << gear << endl;
        }
    }

    void getCarDetails() override
    {
        cout << "This is a Manual Car and it's model is " << this->CarModel << " and it's Name is " << this->CarName << endl;
    }
};

class AutoCar : public Car
{
protected:
    int batteryPercentage;

public:
    // constructer
    AutoCar() : Car()
    {
        this->batteryPercentage = 100;
    }

    // write getter and setter for the battery percentage
    // getter
    int getBatteryPercentage()
    {
        return this->batteryPercentage;
    }

    // setter
    void setBatteryPercentage(int percentage)
    {
        if (percentage <= 100)
        {
            this->batteryPercentage = percentage;
        }
        else
        {
            this->batteryPercentage = 100;
        }
    }

    // write one virtual method for the charge a battery
    virtual void chargeBattery() = 0;

    // destructor
    virtual ~AutoCar() {}
};

class ElectricalCar : public AutoCar
{
public:
    // constructor
    ElectricalCar(string name, string model) : AutoCar()
    {
        this->CarName = name;
        this->CarModel = model;
    }

    // define all the virtual methods of the parent class over here
    void startEngine() override
    {
        this->isEngineON = true;
        cout << "Engine is START silently ......" << endl;
    }

    void stopEngine() override
    {
        this->setCurrentSpeed(0);
        this->isEngineON = false;
        cout << "Engine is OFF...." << endl;
    }

    void accelerate() override
    {
        if (!this->isEngineON)
        {
            cout << "Your Engine is OFF..." << endl;
        }
        else
        {
            int speed = this->getCurrentSpeed();
            int currentbattery = this->getBatteryPercentage();
            speed += 15;
            currentbattery -= 5;
            if (currentbattery < 0)
            {
                currentbattery = 0;
            }
            this->setCurrentSpeed(speed);
            this->setBatteryPercentage(currentbattery);
            cout << "Your current speed is " << speed << " and your current battery percentage is " << currentbattery << endl;
        }
    }

    void accelerate(int acc) override
    {
        if (!this->isEngineON)
        {
            cout << "Your Engine is OFF..." << endl;
        }
        else
        {
            int speed = this->getCurrentSpeed();
            int currentBattery = this->getBatteryPercentage();
            speed += acc;
            currentBattery -= 10;
            if (currentBattery < 0)
            {
                currentBattery = 0;
            }
            this->setCurrentSpeed(speed);
            this->setBatteryPercentage(currentBattery);
            cout << "Your current speed is " << speed << " and your current battery percentage is " << currentBattery << endl;
        }
    }

    void brake() override
    {
        if (!this->isEngineON)
        {
            cout << "Your Engine is OFF...." << endl;
        }
        else
        {
            int speed = this->getCurrentSpeed();
            int currentBattery = this->getBatteryPercentage();
            speed -= 10;
            if (speed < 0)
            {
                speed = 0;
            }
            currentBattery -= 5;
            if (currentBattery < 0)
            {
                currentBattery = 0;
            }
            this->setCurrentSpeed(speed);
            this->setBatteryPercentage(currentBattery);
            cout << "Your current speed is " << speed << " and your current battery percentage is " << currentBattery << endl;
        }
    }

    void getCarDetails() override
    {
        cout << "This is an Electrical Car and it's model is " << this->CarModel << " and it's Name is " << this->CarName << " and current battery percentage is " << this->getBatteryPercentage() << endl;
    }

    void chargeBattery() override
    {
        this->setBatteryPercentage(100);
        cout << "Your Car is Fully charged and it's battery percentage is " << this->getBatteryPercentage() << endl;
    }
};

int main()
{
    GearCar *car = new ManualCar("DHANO", "BMW");
    AutoCar *autocar = new ElectricalCar("BASANTI", "TATA");

    cout << "This is Manual Car" << endl;
    cout << "-------------------" << endl;
    car->startEngine();
    car->accelerate();
    car->shiftGear(2);
    car->accelerate(10);
    car->shiftGear(3);
    car->brake();
    car->shiftGear(2);
    car->brake();
    car->stopEngine();
    cout << "------------------" << endl;

    cout << "This is Auto Car" << endl;
    cout << "-------------------" << endl;
    autocar->startEngine();
    autocar->accelerate();
    autocar->accelerate(40);
    autocar->brake();
    autocar->brake();
    autocar->brake();
    autocar->stopEngine();
    cout << "--------------------" << endl;

    delete car;
    delete autocar;

    return 0;
}