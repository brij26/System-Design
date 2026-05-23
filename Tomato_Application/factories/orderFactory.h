#ifndef ORDER_FACTORY_H
#define ORDER_FACTORY_H

#include "../models/order.h"
#include "../models/cart.h"
#include "../models/restaurants.h"
#include "../stratergies/paymentStratergy.h"
#include <vector>
#include <string>
using namespace std;

class OrderFactory
{
public:
    virtual Order *createOrder(User *user, Cart *cart, Restaurant *restaurant, const vector<MenuItem> &menuItems,
                               Paymentstrategy *paymentStrategy, double totalCost, const string &orderType) = 0;
    virtual ~OrderFactory() {}
};

#endif // ORDER_FACTORY_H