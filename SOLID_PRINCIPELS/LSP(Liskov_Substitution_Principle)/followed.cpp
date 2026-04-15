#include <iostream>
#include <vector>
#include <typeinfo>

using namespace std;

// create one Account class which can only depsit amount from the Account
class DepositOnlyAccount
{
public:
    virtual void deposit(double amount) = 0;
};

// Fixed Term Deposit Account will inherent the Deposit Only Account
class FixedTermAccount : public DepositOnlyAccount
{
private:
    double balance;

public:
    FixedTermAccount()
    {
        this->balance = 0;
    }

    void deposit(double amount) override
    {
        this->balance += amount;
        cout << "Your FD account credited with " << amount << " and your final balance in your account is " << this->balance << endl;
    }
};

// Normal Account will also inherite the Deposite Only Account
class Account : public DepositOnlyAccount
{
public:
    virtual void withdraw(double amount) = 0;
};

// now our Current Account and Saving Account will also inherites from the Account
class CurrentAccount : public Account
{
private:
    double balance;

public:
    CurrentAccount()
    {
        this->balance = 0;
    }

    void deposit(double amount) override
    {
        this->balance += amount;
        cout << "Your Current Account is credited with " << amount << " and Your total balance in Your account is " << this->balance << endl;
    }

    void withdraw(double amount) override
    {
        if (amount > this->balance)
        {
            cout << "Your Current account have Insufficient Funds!" << endl;
        }
        else
        {
            this->balance -= amount;
            cout << "Your Current Account debited with " << amount << " and Your total balance is " << this->balance << endl;
        }
    }
};

class SavingAccount : public Account
{
private:
    double balance;

public:
    SavingAccount()
    {
        this->balance = 0;
    }

    void deposit(double amount) override
    {
        this->balance += amount;
        cout << "Your Saving Account is credited with " << amount << " and your final balance is " << this->balance << endl;
    }

    void withdraw(double amount) override
    {
        if (amount > this->balance)
        {
            cout << "Your Saving Accout has Insufficient Funds!" << endl;
        }
        else
        {
            this->balance -= amount;
            cout << "Your Saving accoutn debited with " << amount << " and your final balance is " << this->balance << endl;
        }
    }
};

class BankClient
{
private:
    vector<Account *> accounts;
    vector<DepositOnlyAccount *> depositOnlyAccounts;

public:
    BankClient(vector<Account *> accounts, vector<DepositOnlyAccount *> depositOnlyAccounts)
    {
        this->accounts = accounts;
        this->depositOnlyAccounts = depositOnlyAccounts;
    }

    void proccessTransaction()
    {
        for (auto acc : accounts)
        {
            acc->deposit(1000);
            acc->withdraw(500);
        }
        for (auto acc : depositOnlyAccounts)
        {
            acc->deposit(1000);
        }
    }
};

int main()
{
    vector<Account *> accounts;

    accounts.push_back(new SavingAccount);
    accounts.push_back(new CurrentAccount);

    vector<DepositOnlyAccount *> DOA;

    DOA.push_back(new FixedTermAccount);

    BankClient *client = new BankClient(accounts, DOA);

    client->proccessTransaction();

    delete client;

    return 0;
}