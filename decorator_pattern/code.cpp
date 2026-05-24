// In this we will implement Decorator pattern using mario example

#include <iostream>
#include <string>
using namespace std;

// create one abstract class for the character
class ICharacter
{
public:
    virtual string ability() const = 0;
    virtual ~ICharacter() = default;
};

// create class mario which inherites from the ICharacter class
class Mario : public ICharacter
{
public:
    string ability() const override
    {
        return "Mario";
    }
};

// create abstract class of the decorator which inherites from the ICharacter but also have composition reslation with it

class Decorator : public ICharacter
{
protected:
    ICharacter *character;

public:
    Decorator(ICharacter *character)
    {
        this->character = character;
    }
};

// now create a class which will inherites from the Decorator class
class HeightBoost : public Decorator
{
public:
    HeightBoost(ICharacter *c) : Decorator(c) {}
    string ability() const override
    {
        return character->ability() + " With Height Boost";
    }
};

class Gunup : public Decorator
{
public:
    Gunup(ICharacter *c) : Decorator(c) {}

    string ability() const override
    {
        return character->ability() + " With Gun Power up";
    }
};

class StarPowerUp : public Decorator
{
public:
    StarPowerUp(ICharacter *c) : Decorator(c) {}

    string ability() const override
    {
        return character->ability() + " With Star Power Up(For Limited Time Only)";
    }

    ~StarPowerUp()
    {
        cout << "Destroying StarPowerUp Decorator" << endl;
    }
};

int main()
{
    ICharacter *mario = new Mario();
    cout << "Simple Mario: " << mario->ability() << endl;

    mario = new HeightBoost(mario);
    cout << "After Height Up: " << mario->ability() << endl;

    mario = new Gunup(mario);
    cout << "After Gun Up: " << mario->ability() << endl;

    mario = new StarPowerUp(mario);
    cout << "After StartPower Up : " << mario->ability() << endl;

    delete mario;

    return 0;
}
