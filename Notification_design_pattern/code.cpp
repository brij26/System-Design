// In this code we will try to implement Notification Service Design Pattern

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

// Notification class
class INotification
{
public:
    virtual string getContent() const = 0;

    // destructor
    virtual ~INotification() = default;
};

class SimpleNotification : public INotification
{
private:
    string content;

public:
    SimpleNotification(const string &text)
    {
        this->content = text;
    }

    string getContent() const override
    {
        return this->content;
    }
};

// Abstract Decorator
class INotificationDecorator : public INotification
{
protected:
    INotification *notification;

public:
    INotificationDecorator(INotification *no)
    {
        this->notification = no;
    }

    virtual ~INotificationDecorator()
    {
        delete notification;
    }
};

// TimeStamp Decorator
class TimeStampDecorator : public INotificationDecorator
{
public:
    TimeStampDecorator(INotification *n) : INotificationDecorator(n) {}

    string getContent() const override
    {
        return "2026-05-26 11:54:22 : " + notification->getContent();
    }
};

// Singnature Decorator
class SignatureDecorator : public INotificationDecorator
{
private:
    string singature;

public:
    SignatureDecorator(const string &sign, INotification *n) : INotificationDecorator(n)
    {
        this->singature = sign;
    }
    string getContent() const override
    {
        return notification->getContent() + "\n--" + this->singature + "--\n\n";
    }
};

// ----------------------------
// Observer and Observable
// ----------------------------

class IObserver
{
public:
    virtual void update() = 0;

    virtual ~IObserver() = default;
};

// Observable
class IObservable
{
public:
    virtual void addObserver(IObserver *ob) = 0;
    virtual void removeObserver(IObserver *ob) = 0;
    virtual void notify() = 0;
};

// concreate Observable
class NotificationObservable : public IObservable
{
private:
    vector<IObserver *> observers;
    INotification *currentNotification;

public:
    NotificationObservable()
    {
        this->currentNotification = nullptr;
    }

    void addObserver(IObserver *ob) override
    {
        if (find(this->observers.begin(), this->observers.end(), ob) == this->observers.end())
        {
            this->observers.push_back(ob);
        }
    }

    void removeObserver(IObserver *ob) override
    {
        auto it = find(this->observers.begin(), this->observers.end(), ob);
        if (it != this->observers.end())
        {
            this->observers.erase(it);
        }
    }

    void notify() override
    {
        for (auto observer : this->observers)
        {
            observer->update();
        }
    }

    void setNotification(INotification *notification)
    {
        if (this->currentNotification)
        {
            delete this->currentNotification;
        }
        this->currentNotification = notification;
        this->notify();
    }

    INotification *getNotification()
    {
        return this->currentNotification;
    }

    string getNotificationContent()
    {
        return this->currentNotification->getContent();
    }

    ~NotificationObservable()
    {
        if (this->currentNotification)
        {
            delete this->currentNotification;
        }
    }
};

// class NotificationService
class NotificationService
{
private:
    NotificationObservable *observable;
    vector<INotification *> history;
    static NotificationService *instance;

    NotificationService()
    {
        this->observable = new NotificationObservable();
    }

public:
    static NotificationService *getInstance()
    {
        if (instance == nullptr)
        {
            instance = new NotificationService();
        }
        return instance;
    }

    // expose this observable so that observers can attach
    NotificationObservable *getObservable()
    {
        return observable;
    }

    void sendNotification(INotification *notification)
    {
        this->history.push_back(notification);
        this->observable->setNotification(notification);
    }

    ~NotificationService()
    {
        delete observable;
    }
};

// Concreate Observer
class Logger : public IObserver
{
private:
    NotificationObservable *no;

public:
    Logger()
    {
        this->no = NotificationService::getInstance()->getObservable();
        this->no->addObserver(this);
    }

    Logger(NotificationObservable *n)
    {
        this->no = n;
    }

    void update() override
    {
        cout << "Logging New Notification : \n"
             << this->no->getNotificationContent();
    }
};

// ----------------------------------
// Stratergy desing component
// ----------------------------------

class INotificationStrategy
{
public:
    virtual void sendNotification(string content) = 0;
};

class EmailStrategy : public INotificationStrategy
{
private:
    string emaiId;

public:
    EmailStrategy(const string &email)
    {
        this->emaiId = email;
    }

    void sendNotification(string content) override
    {
        cout << "Sending Email Notification to : " << this->emaiId << "\n"
             << content;
    }
};

class SMSStrategy : public INotificationStrategy
{
private:
    string mobileNumber;

public:
    SMSStrategy(string number)
    {
        this->mobileNumber = number;
    }

    void sendNotification(string content) override
    {
        cout << "Sending SMS Notification to : " << this->mobileNumber << "\n"
             << content;
    }
};

class PopUpStrategy : public INotificationStrategy
{
public:
    void sendNotification(string content) override
    {
        cout << "Sending PopUp Notification : \n"
             << content;
    }
};

// class NotificationEngine
class NotificationEngine : public IObserver
{
private:
    NotificationObservable *obsevable;
    vector<INotificationStrategy *> ns;

public:
    NotificationEngine()
    {
        // ger observable from the Notification Service
        this->obsevable = NotificationService::getInstance()->getObservable();
        this->obsevable->addObserver(this);
    }

    NotificationEngine(NotificationObservable *o)
    {
        this->obsevable = o;
    }

    void addNotificationStrategy(INotificationStrategy *s)
    {
        this->ns.push_back(s);
    }

    void update()
    {
        string notification = obsevable->getNotificationContent();
        for (const auto s : this->ns)
        {
            s->sendNotification(notification);
        }
    }
};

NotificationService *NotificationService::instance = nullptr;

int main()
{
    NotificationService *ns = NotificationService::getInstance();

    Logger *logger = new Logger();

    NotificationEngine *ne = new NotificationEngine();

    ne->addNotificationStrategy(new EmailStrategy("abc@gmail.com"));
    ne->addNotificationStrategy(new SMSStrategy("+91 9876543210"));
    ne->addNotificationStrategy(new PopUpStrategy());

    INotification *notification = new SimpleNotification("Congrats! You get selected for the job.");
    notification = new TimeStampDecorator(notification);
    notification = new SignatureDecorator("Brij Patel", notification);

    ns->sendNotification(notification);

    delete logger;
    delete ne;
    return 0;
}
