#ifndef PICKUP_ORDER_H
#define PICKUP_ORDER_H

#include "order.h"
using namespace std;

class PickupOrder : public Order
{
private:
    string restaurantAddress;

public:
    PickupOrder()
    {
        this->restaurantAddress = "";
    }

    string getType() const override
    {
        return "Pickup";
    }

    // Getter and Setter
    void setRestaurantAddress(const string &addr)
    {
        this->restaurantAddress = addr;
    }

    string getRestaurantAddress() const
    {
        return this->restaurantAddress;
    }
};

#endif // PICKUP_ORDER_H