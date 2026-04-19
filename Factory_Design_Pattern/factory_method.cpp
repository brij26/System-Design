#include <iostream>
using namespace std;

class Burger
{
public:
    virtual void prepare() = 0;
    virtual ~Burger() = default;
};

class BasicBurger : public Burger
{
public:
    void prepare() override
    {
        cout << "Preparing Basic Burger For You....." << endl;
        cout << "After Few minutes....." << endl;
        cout << "Your Basic Burger is Ready...." << endl;
    }
};

class StandardBurger : public Burger
{
public:
    void prepare() override
    {
        cout << "Preparing Standard Burger For You...." << endl;
        cout << "After Few Minutes......" << endl;
        cout << "Your Standard Burger is Ready...." << endl;
    }
};

class PremiumBurger : public Burger
{
public:
    void prepare() override
    {
        cout << "Preparing Premium Burger For You...." << endl;
        cout << "After Few Minutes..." << endl;
        cout << "Your Premium Burger is Ready...." << endl;
    }
};

class BasicWheatBurger : public Burger
{
public:
    void prepare() override
    {
        cout << "Preparing Basic Wheat Burger For You......" << endl;
        cout << "After Few Minutes..." << endl;
        cout << "Your Basic Wheat Burger is Ready...." << endl;
    }
};

class StandardWheatBurger : public Burger
{
public:
    void prepare() override
    {
        cout << "Preparing Standard Wheat Burger For You....." << endl;
        cout << "After Few Minutes..." << endl;
        cout << "Your Standard Wheat Burger is Ready...." << endl;
    }
};

class PremiumWheatBurger : public Burger
{
public:
    void prepare() override
    {
        cout << "Preparing Premium Wheat Burger For You...." << endl;
        cout << "After Few Minutes..." << endl;
        cout << "Your Premium Wheat Burger is Ready..." << endl;
    }
};

class Factory
{
public:
    virtual Burger *cook() = 0;
    virtual ~Factory() = default;
};

class SinghBurger : public Factory
{
private:
    string type;

public:
    SinghBurger(string type)
    {
        this->type = type;
    }

    Burger *cook() override
    {
        if (this->type == "basic")
        {
            return new BasicBurger();
        }

        else if (this->type == "standard")
        {
            return new StandardBurger();
        }

        else if (this->type == "premium")
        {
            return new PremiumBurger();
        }

        else
        {
            cout << "Invalid Burger type...." << endl;
        }
    }
};

class KingBurger : public Factory
{
private:
    string type;

public:
    KingBurger(string type)
    {
        this->type = type;
    }

    Burger *cook() override
    {
        if (this->type == "basic")
        {
            return new BasicWheatBurger();
        }
        else if (this->type == "standard")
        {
            return new StandardWheatBurger();
        }
        else if (this->type == "premium")
        {
            return new PremiumWheatBurger();
        }
        else
        {
            cout << "Invalid Burger Type....." << endl;
        }
    }
};

int main()
{
    string type = "basic";
    Factory *F1 = new SinghBurger(type);
    Factory *F2 = new KingBurger("standard");

    F1->cook()->prepare();
    cout << "-------------------------------" << endl;
    F2->cook()->prepare();

    delete F1;
    delete F2;

    return 0;
}