// let's understand Command design pattern
#include <iostream>
#include <string>
#include <vector>
using namespace std;

// class for the Command
class ICommand
{
public:
    virtual void excecute() = 0;
    virtual void undo() = 0;
    virtual ~ICommand() = default;
};

class Light
{
public:
    void on()
    {
        cout << "Light On...." << endl;
    }

    void off()
    {
        cout << "Light Off...." << endl;
    }
};

class Fan
{
public:
    void on()
    {
        cout << "Fan On...." << endl;
    }

    void off()
    {
        cout << "Fan Off...." << endl;
    }
};

class AC
{
public:
    void on()
    {
        cout << "AC On...." << endl;
    }

    void off()
    {
        cout << "AC Off..." << endl;
    }
};

class LightCommand : public ICommand
{
private:
    Light *light;

public:
    LightCommand(Light *l)
    {
        this->light = l;
    }

    void excecute() override
    {
        light->on();
    }

    void undo() override
    {
        light->off();
    }
};

class FanCommand : public ICommand
{
private:
    Fan *fan;

public:
    FanCommand(Fan *f)
    {
        this->fan = f;
    }

    void excecute() override
    {
        fan->on();
    }

    void undo() override
    {
        fan->off();
    }
};

class ACCOmmand : public ICommand
{
private:
    AC *ac;

public:
    ACCOmmand(AC *a)
    {
        this->ac = a;
    }

    void excecute() override
    {
        ac->on();
    }

    void undo() override
    {
        ac->off();
    }
};

class RemoteControl
{
private:
    static const int numberOfButtons = 4;
    ICommand *buttons[numberOfButtons];
    bool buttonPressed[numberOfButtons];

public:
    RemoteControl()
    {
        for (int i = 0; i < numberOfButtons; i++)
        {
            this->buttons[i] = nullptr;
            this->buttonPressed[i] = false;
        }
    }

    void setCommand(ICommand *command, int i)
    {
        if (i >= 0 && i < numberOfButtons)
        {
            if (this->buttons[i] != nullptr)
            {
                delete this->buttons[i];
            }
            this->buttons[i] = command;
        }
    }

    void pressButton(int idx)
    {
        if (idx >= 0 && idx < numberOfButtons)
        {
            if (this->buttons[idx] != nullptr)
            {
                if (this->buttonPressed[idx])
                {
                    this->buttons[idx]->undo();
                }
                else
                {
                    this->buttons[idx]->excecute();
                }
                this->buttonPressed[idx] = !this->buttonPressed[idx];
            }
            else
            {
                cout << "No command assigned at this button " << idx << endl;
            }
        }
    }

    ~RemoteControl()
    {
        for (int i = 0; i < numberOfButtons; i++)
        {
            delete this->buttons[i];
        }
    }
};

int main()
{
    RemoteControl *remote = new RemoteControl();

    Light *light = new Light();
    Fan *fan = new Fan();
    AC *ac = new AC();

    remote->setCommand(new FanCommand(fan), 0);
    remote->setCommand(new LightCommand(light), 2);
    remote->setCommand(new ACCOmmand(ac), 1);

    cout << "---------------Pressing Assigned buttons------------" << endl;
    remote->pressButton(0);
    remote->pressButton(2);
    remote->pressButton(0);
    remote->pressButton(1);
    remote->pressButton(1);
    remote->pressButton(2);

    cout << "-------------Pressing Not Assigned Buttons------------" << endl;
    remote->pressButton(3);

    delete light;
    delete fan;
    delete ac;
    delete remote;

    return 0;
}