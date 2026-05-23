#ifndef UPI_PAYMENT_STRATEGY_H
#define UPI_PAYMENT_STRATEGY_H

#include <iostream>
#include <string>
#include <iomanip>
#include "paymentStratergy.h"

using namespace std;

class UpiPaymentStrategy : public Paymentstrategy
{
private:
    string mobile;

public:
    UpiPaymentStrategy(const string &mob)
    {
        this->mobile = mob;
    }

    void pay(double amount) override
    {
        cout << "Paid ₹" << amount << " using UPI (" << mobile << ")" << endl;
    }
};

#endif // UPI_PAYMENT_STRATEGY