// This written code is not thread safe
// so to make this thread safe we have to use locking and unlocking

#include <iostream>
using namespace std;

// now we try to create one singleton class
class Singleton
{
private:
    // this is static Singleton pointer
    static Singleton *instance;
    // constructor
    Singleton()
    {
        cout << "Creating new object of the class Singleton...." << endl;
    }

public:
    static Singleton *getInstance()
    {
        if (instance == nullptr)
        {
            instance = new Singleton();
        }
        return instance;
    }
};

Singleton *Singleton::instance = nullptr;

int main()
{
    Singleton *s1 = Singleton::getInstance();
    Singleton *s2 = Singleton::getInstance();

    cout << (s1 == s2) << endl;

    return 0;
}