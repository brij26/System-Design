#ifndef MENUITEM_H
#define MENUITEM_H

#include <string>
using namespace std;

class MenuItem
{
private:
    string code;
    string name;
    int price;

public:
    MenuItem(const string &name, const string &code, int price)
    {
        this->code = code;
        this->name = name;
        this->price = price;
    }

    // Getters and Setters
    string getCode() const
    {
        return this->code;
    }

    void setCode(const string &c)
    {
        this->code = c;
    }

    string getName() const
    {
        return this->name;
    }

    void getName(const string &name)
    {
        this->name = name;
    }

    int getPrice() const
    {
        return this->price;
    }

    void setPrice(int price)
    {
        this->price = price;
    }
};

#endif // MENUITEM_H