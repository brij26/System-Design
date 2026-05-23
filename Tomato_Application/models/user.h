#ifndef USER_H
#define USER_H

#include <iostream>
#include <vector>
#include <string>
#include "cart.h"

using namespace std;

class User
{
private:
    static int nextUserId;
    int userId;
    string name;
    string address;
    Cart *cart;

public:
    User(const string &name, const string &addr)
    {
        this->name = name;
        this->address = addr;
        this->userId = ++nextUserId;
        this->cart = new Cart();
    }

    ~User()
    {
        delete cart;
    }

    // Getter and Setter
    string getName() const
    {
        return this->name;
    }

    void setName(const string &name)
    {
        this->name = name;
    }

    string getAddress() const
    {
        return this->address;
    }

    void setAddress(const string &address)
    {
        this->address = address;
    }

    Cart *getCart() const
    {
        return this->cart;
    }
};

int User ::nextUserId = 0;

#endif // USER_H