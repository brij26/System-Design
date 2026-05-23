#ifndef ORDER_MANAGER_H
#define ORDER_MANAGER_H

#include <vector>
#include <iostream>
#include "../models/order.h"
using namespace std;

class OrderManager
{
private:
    vector<Order *> orders;
    static OrderManager *instance;

    // managers follows singleton patterns
    // becuase of that we will create private constructor of this
    OrderManager()
    {
        // private Constructor
    }

public:
    static OrderManager *getInstance()
    {
        if (!instance)
        {
            instance = new OrderManager();
        }
        return instance;
    }

    void addOrder(Order *order)
    {
        orders.push_back(order);
    }

    void listOrders()
    {
        cout << "\n--- All Orders ---" << endl;
        for (auto order : orders)
        {
            cout << order->getType() << " order for " << order->getUser()->getName() << " | Total: ₹" << order->getTotal() << " | At: " << order->getScheduled() << endl;
        }
    }
};

OrderManager *OrderManager ::instance = nullptr;

#endif // ORDER_MANAGER_H