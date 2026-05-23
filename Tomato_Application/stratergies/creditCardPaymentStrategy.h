#ifndef CREDIT_CARD_PAYMENT_STRATEGY_H
#define CREDIT_CARD_PAYMENT_STRATEGY_H

#include <iostream>
#include <string>
#include <iomanip>
#include "paymentStratergy.h"

using namespace std;

class CreditCardPaymentStrategy : public Paymentstrategy
{
private:
    string cardNum;

public:
    CreditCardPaymentStrategy(const string &cardNumber)
    {
        this->cardNum = cardNumber;
    }

    void pay(double amount) override
    {
        cout << "Paid ₹" << amount << " using Credit Card (" << this->cardNum << ")" << endl;
    }
};

#endif // CREDIT_CARD_PAYMENT_STRATEGY_H