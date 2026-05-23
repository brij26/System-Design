#ifndef ORDER_H
#define ORDER_H

#include <iostream>
#include <vector>
#include <string>
#include "user.h"
#include "restaurants.h"
#include "menuItem.h"
#include "../stratergies/paymentStratergy.h"
#include "../utils/TimeUtils.h"
using namespace std;

class Order
{
protected:
    static int nextOrderId;
    int orderId;
    User *user;
    Restaurant *restaurant;
    vector<MenuItem> items;
    Paymentstrategy *paymentstrategy;
    double total;
    string scheduled;

public:
    Order()
    {
        this->user = nullptr;
        this->restaurant = nullptr;
        this->paymentstrategy = nullptr;
        this->total = 0.0;
        this->scheduled = "";
        this->orderId = ++nextOrderId;
    }

    virtual ~Order()
    {
        delete paymentstrategy;
    }

    bool processPayment()
    {
        if (paymentstrategy)
        {
            paymentstrategy->pay(total);
            return true;
        }
        else
        {
            cout << "Please Choose a payment Mode first" << endl;
            return false;
        }
    }

    virtual string getType() const = 0;

    // Getter and Setter
    int getOrderId() const
    {
        return orderId;
    }

    void setUser(User *u)
    {
        this->user = u;
    }

    User *getUser()
    {
        return this->user;
    }

    void setRestaurant(Restaurant *r)
    {
        this->restaurant = r;
    }

    Restaurant *getRestaurant()
    {
        return this->restaurant;
    }

    void setItems(const vector<MenuItem> &its)
    {
        this->items = its;
        total = 0;
        for (auto &i : this->items)
        {
            total += i.getPrice();
        }
    }

    const vector<MenuItem> &getItems() const
    {
        return this->items;
    }

    void setPaymentStrategy(Paymentstrategy *p)
    {
        this->paymentstrategy = p;
    }

    void setScheduled(const string &s)
    {
        this->scheduled = s;
    }

    string getScheduled() const
    {
        return scheduled;
    }

    double getTotal() const
    {
        return this->total;
    }

    void setTotal(int total)
    {
        this->total = total;
    }
};

int Order::nextOrderId = 0;

#endif // ORDER_H