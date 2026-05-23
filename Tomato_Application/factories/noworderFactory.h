#ifndef NOW_ORDER_FACTORY_H
#define NOW_ORDER_FACTORY_H

#include "orderFactory.h"
#include "../models/deliveryOrder.h"
#include "../models/pickupOrder.h"
#include "../utils/TimeUtils.h"
using namespace std;

class NowOrderFactory : public OrderFactory
{
public:
    Order *createOrder(User *user, Cart *cart, Restaurant *restaurant, const vector<MenuItem> &menuItems,
                       Paymentstrategy *paymentStrategy, double totalCost, const string &orderType) override
    {
        Order *order = nullptr;
        if (orderType == "Delivery")
        {
            auto deliveryOrder = new DeliveryOrder();
            deliveryOrder->setUserAddress(user->getAddress());
            order = deliveryOrder;
        }
        else
        {
            auto pickupOrder = new PickupOrder();
            pickupOrder->setRestaurantAddress(restaurant->getLoc());
            order = pickupOrder;
        }
        order->setUser(user);
        order->setRestaurant(restaurant);
        order->setItems(menuItems);
        order->setPaymentStrategy(paymentStrategy);
        order->setScheduled(TimeUtils::getCurrentTime());
        order->setTotal(totalCost);
        return order;
    }
};

#endif // NOW_ORDER_FACTORY_H