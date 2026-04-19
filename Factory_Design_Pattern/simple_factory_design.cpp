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
        cout << "Your Basic Burger is Ready....." << endl;
    }
};

class StandardBurger : public Burger
{
public:
    void prepare() override
    {
        cout << "Your Standard Burger is Ready....." << endl;
    }
};

class PremiumBurger : public Burger
{
public:
    void prepare() override
    {
        cout << "Your Premium Burger is Ready...." << endl;
    }
};

class BurgerFactory
{
private:
    string type;

public:
    BurgerFactory(string type)
    {
        this->type = type;
    }

    Burger *burger()
    {
        if (this->type == "Basic")
        {
            return new BasicBurger();
        }
        else if (this->type == "Standard")
        {
            return new StandardBurger();
        }
        else if (this->type == "Premium")
        {
            return new PremiumBurger();
        }
    }
};

int main()
{
    string type = "Basic";
    BurgerFactory *factory = new BurgerFactory(type);

    factory->burger()->prepare();

    delete factory;

    return 0;
}