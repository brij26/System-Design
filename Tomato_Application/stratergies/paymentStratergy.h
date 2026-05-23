#ifndef PAYMENT_STRATEGY_H
#define PAYMENT_STRATEGY_H

#include <iostream>
#include <string>

using namespace std;

class Paymentstrategy
{
public:
    virtual void pay(double amount) = 0;
    virtual ~Paymentstrategy() = default;
};

#endif // PAYMENT_STRATEGY_H