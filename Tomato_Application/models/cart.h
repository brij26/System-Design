#ifndef CART_H
#define CART_H

#include <iostream>
#include <string>
#include <vector>
#include "menuItem.h"
#include "restaurants.h"

using namespace std;

class Cart
{
private:
    Restaurant *restuarant;
    vector<MenuItem> items;

public:
    Cart()
    {
        restuarant = nullptr;
    }

    void addItem(const MenuItem &item)
    {
        if (!restuarant)
        {
            cerr << "Cart: Set a Restaurant before adding items." << endl;
            return;
        }
        items.push_back(item);
    }

    double getTotalCost() const
    {
        double sum = 0;
        for (const auto &item : items)
        {
            sum += item.getPrice();
        }
        return sum;
    }

    bool isEmpty()
    {
        return (!restuarant || items.empty());
    }

    void clear()
    {
        items.clear();
        restuarant = nullptr;
    }

    // getter and setter
    void setRestaurant(Restaurant *r)
    {
        this->restuarant = r;
    }

    Restaurant *getRestuarant() const
    {
        return this->restuarant;
    }

    const vector<MenuItem> &getitems() const
    {
        return this->items;
    }
};

#endif // CART_H