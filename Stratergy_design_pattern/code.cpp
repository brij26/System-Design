#include <iostream>
using namespace std;

// In this stratergy Design Pattern rule is when there is some method or attribute which is changin very frequently or there is some dynamically changin methods than we have to separte them from the static one

// for example we have one robot class inside that we have walk, talk, fly and projection method but some robot can fly and some cannot and simillarly some can walk and some can not

// so we have to separate this method from class robot
// this rule says that the solution of inheritance method is not inheritance
// we have to use composition

class Walkable
{
public:
    virtual void walk() = 0;
    virtual ~Walkable() = default;
};

class NormalWalk : public Walkable
{
public:
    void walk() override
    {
        cout << "Walks Normally ......." << endl;
    }
};

class NoWalk : public Walkable
{
public:
    void walk() override
    {
        cout << "Can not walk ........" << endl;
    }
};

class Talkable
{
public:
    virtual void talk() = 0;
    virtual ~Talkable() = default;
};

class NoramalTalk : public Talkable
{
public:
    void talk() override
    {
        cout << "Talks Normally ........" << endl;
    }
};

class NoTalk : public Talkable
{
public:
    void talk() override
    {
        cout << "Can not talk ......." << endl;
    }
};

class Flyable
{
public:
    virtual void fly() = 0;
    virtual ~Flyable() = default;
};

class FlyWithWings : public Flyable
{
public:
    void fly() override
    {
        cout << "Flying with Wings......" << endl;
    }
};

class FlyWithJets : public Flyable
{
public:
    void fly() override
    {
        cout << "Flying using Jets........." << endl;
    }
};

class CanNotFly : public Flyable
{
public:
    void fly() override
    {
        cout << "Can not fly..........." << endl;
    }
};

// now we write code of the client
class Robot
{
private:
    Walkable *w;
    Talkable *t;
    Flyable *f;

public:
    Robot(Walkable *w, Talkable *t, Flyable *f)
    {
        this->w = w;
        this->f = f;
        this->t = t;
    }

    void walk()
    {
        this->w->walk();
    }

    void talk()
    {
        this->t->talk();
    }

    void fly()
    {
        this->f->fly();
    }

    virtual void projection() = 0;
    virtual ~Robot() = default;
};

// now we create Robot using Robot class
// 1.companion Robot
class CompanionR : public Robot
{
public:
    CompanionR(Walkable *w, Talkable *t, Flyable *f) : Robot(w, t, f) {}

    void projection() override
    {
        cout << "Displaying very friendly Companion Robot....." << endl;
    }
};

// 2. Worker Robot
class WorkerR : public Robot
{
public:
    WorkerR(Walkable *w, Talkable *t, Flyable *f) : Robot(w, t, f) {}

    void projection() override
    {
        cout << "Displying very hard Working Woker Robot ....." << endl;
    }
};

// main

int main()
{
    // Robot 1 : companion Robot
    Robot *R1 = new CompanionR(new NormalWalk(), new NoramalTalk(), new FlyWithJets());
    R1->walk();
    R1->talk();
    R1->fly();
    R1->projection();

    cout << "-----------------------------------" << endl;

    // Robot 2 : Worker Robot
    Robot *R2 = new WorkerR(new NoWalk(), new NoramalTalk(), new FlyWithWings());
    R2->walk();
    R2->talk();
    R2->fly();
    R2->projection();
}