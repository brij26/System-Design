#ifndef SCHEDULED_ORDER_FACTORY_H
#define SCHEDULED_ORDER_FACTORY_H

#include "OrderFactory.h"
#include "../models/deliveryOrder.h"
#include "../models/pickupOrder.h"
#include "../utils/TimeUtils.h"
using namespace std;

class ScheduledOrderFactory : public OrderFactory
{
private:
    string scheduleTime;

public:
    ScheduledOrderFactory(string scheduleTime)
    {
        this->scheduleTime = scheduleTime;
    }

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
        }
        order->setUser(user);
        order->setRestaurant(restaurant);
        order->setItems(menuItems);
        order->setPaymentStrategy(paymentStrategy);
        order->setScheduled(scheduleTime);
        order->setTotal(totalCost);
        return order;
    }
};

#endif // SCHEDULED_ORDER_FACTORY_H