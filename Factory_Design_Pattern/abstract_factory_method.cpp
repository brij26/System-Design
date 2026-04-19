#include <iostream>
using namespace std;

class Burger
{
public:
    virtual void prepareBurger() = 0;
    virtual ~Burger() = default;
};

class BasicBurger : public Burger
{
public:
    void prepareBurger() override
    {
        cout << "Your Basic Burger Is Ready...." << endl;
    }
};

class StandardBurger : public Burger
{
public:
    void prepareBurger() override
    {
        cout << "Your Standard Burger is Ready...." << endl;
    }
};

class PremiumBurger : public Burger
{
public:
    void prepareBurger() override
    {
        cout << "Your Premium Burger is ready...." << endl;
    }
};

class BasicWheatBurger : public Burger
{
public:
    void prepareBurger() override
    {
        cout << "Your Basic Wheat Burger is ready...." << endl;
    }
};

class StandardWheatBurger : public Burger
{
public:
    void prepareBurger() override
    {
        cout << "Your standard Wheat Burger is ready...." << endl;
    }
};

class PremiumWheatBurger : public Burger
{
public:
    void prepareBurger() override
    {
        cout << "Your premium Wheat Burger is ready....." << endl;
    }
};

class Sandwhich
{
public:
    virtual void prepareSandwhich() = 0;
    virtual ~Sandwhich() = default;
};

class BasicSandwhich : public Sandwhich
{
public:
    void prepareSandwhich() override
    {
        cout << "Your basic sandwhich is ready....." << endl;
    }
};

class StandardSandwhich : public Sandwhich
{
public:
    void prepareSandwhich() override
    {
        cout << "Your standard Sandwhich is ready....." << endl;
    }
};

class PremiumSandwhich : public Sandwhich
{
public:
    void prepareSandwhich() override
    {
        cout << "Your premium Sandwhich is ready...." << endl;
    }
};

class BasicWheatSandwhich : public Sandwhich
{
public:
    void prepareSandwhich() override
    {
        cout << "Your Basic Wheat Sandwhich is ready..." << endl;
    }
};

class StandardWheatSandwhich : public Sandwhich
{
public:
    void prepareSandwhich() override
    {
        cout << "Your standard Wheat Sandwhich is ready....." << endl;
    }
};

class PremiumWheatSandwhich : public Sandwhich
{
public:
    void prepareSandwhich() override
    {
        cout << "Your premium Wheat Sandwhich is ready...." << endl;
    }
};

class Factory
{
public:
    virtual Burger *burger() = 0;
    virtual Sandwhich *sandwhich() = 0;
    virtual ~Factory() = default;
};

class SinghDhaba : public Factory
{
private:
    string burgerType;
    string sandwhichType;

public:
    SinghDhaba(string bt, string st)
    {
        this->burgerType = bt;
        this->sandwhichType = st;
    }

    Burger *burger() override
    {
        if (this->burgerType == "Basic")
        {
            return new BasicBurger();
        }
        else if (this->burgerType == "Standard")
        {
            return new StandardBurger();
        }
        else if (this->burgerType == "Premium")
        {
            return new PremiumBurger();
        }
        else
        {
            cout << "Invalid Burger type...." << endl;
        }
    }

    Sandwhich *sandwhich() override
    {
        if (this->sandwhichType == "Basic")
        {
            return new BasicSandwhich();
        }
        else if (this->sandwhichType == "Standard")
        {
            return new StandardSandwhich();
        }
        else if (this->sandwhichType == "Premium")
        {
            return new PremiumSandwhich();
        }
        else
        {
            cout << "Invalid Sandwhich type...." << endl;
        }
    }
};

class KingDhaba : public Factory
{
private:
    string burgerType;
    string sandwhichType;

public:
    KingDhaba(string bt, string st)
    {
        this->burgerType = bt;
        this->sandwhichType = st;
    }

    Burger *burger() override
    {
        if (this->burgerType == "Basic")
        {
            return new BasicWheatBurger();
        }
        else if (this->burgerType == "Standard")
        {
            return new StandardWheatBurger();
        }
        else if (this->burgerType == "Premium")
        {
            return new PremiumWheatBurger();
        }
        else
        {
            cout << "Invalid Burger type...." << endl;
        }
    }

    Sandwhich *sandwhich() override
    {
        if (this->sandwhichType == "Basic")
        {
            return new BasicWheatSandwhich();
        }
        else if (this->sandwhichType == "Standard")
        {
            return new StandardWheatSandwhich();
        }
        else if (this->sandwhichType == "Premium")
        {
            return new PremiumWheatSandwhich();
        }
        else
        {
            cout << "Invalid Sandwhich type...." << endl;
        }
    }
};

int main()
{
    Factory *F1 = new SinghDhaba("Basic", "Standard");
    Factory *F2 = new KingDhaba("Premium", "Basic");

    F1->burger()->prepareBurger();
    cout << "----------------------------" << endl;
    F1->sandwhich()->prepareSandwhich();
    cout << "----------------------------" << endl;
    F2->burger()->prepareBurger();
    cout << "----------------------------" << endl;
    F2->sandwhich()->prepareSandwhich();
    cout << "----------------------------" << endl;

    delete F1;
    delete F2;

    return 0;
}