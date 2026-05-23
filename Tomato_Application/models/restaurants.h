#ifndef RESTAURANT_H
#define RESTAURANT_H

#include <iostream>
#include <string>
#include "menuItem.h"
#include <vector>
using namespace std;

class Restaurant
{
private:
    static int nextRestaurantId;
    int restaurantId;
    string name;
    string loc;
    vector<MenuItem> menu;

public:
    Restaurant(const string &name, const string &loc)
    {
        this->name = name;
        this->loc = loc;
        this->restaurantId = ++nextRestaurantId;
    }

    ~Restaurant()
    {
        // this is optional it is just for debugging
        cout << "Destroying Restaurant" << this->name << ", and clearing its menu" << endl;
        this->menu.clear();
    }

    // Getters and Setters
    string getName() const
    {
        return this->name;
    }

    void setName(const string &n)
    {
        this->name = n;
    }

    string getLoc() const
    {
        return this->loc;
    }

    void setLoc(const string &l)
    {
        this->loc = l;
    }

    const vector<MenuItem> &getMenu() const
    {
        return this->menu;
    }

    void addMenuItem(const MenuItem &item)
    {
        this->menu.push_back(item);
    }
};

int Restaurant ::nextRestaurantId = 0;

#endif // RESTAURANT_H