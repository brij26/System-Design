#ifndef DELIVERY_ORDER_H
#define DELIVERY_ORDER_H

#include "order.h"
using namespace std;

class DeliveryOrder : public Order
{
private:
    string userAddress;

public:
    DeliveryOrder()
    {
        this->userAddress = "";
    }

    string getType() const override
    {
        return "Delivery";
    }

    // Getter and Setter
    void setUserAddress(const string &Addr)
    {
        this->userAddress = Addr;
    }

    string getUserAddress() const
    {
        return this->userAddress;
    }
};

#endif // DELIVERY_ORDER_H
