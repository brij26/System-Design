#include <iostream>
#include <vector>
#include <typeinfo>

using namespace std;

class Account
{
public:
    virtual void deposit(double amount) = 0;
    virtual void withdraw(double amount) = 0;
};

class SavingAccount : public Account
{
private:
    double balance;

public:
    SavingAccount() : Account()
    {
        this->balance = 0;
    }

    void deposit(double amount) override
    {
        this->balance += amount;
        cout << "Your Saving Account Credited with " << amount << " and your final amount in your account is " << this->balance << endl;
    }

    void withdraw(double amount) override
    {
        if (amount > this->balance)
        {
            cout << "Insufficient Funds in your Saving Account" << endl;
        }
        else
        {
            this->balance -= amount;
            cout << "Your Saving Account debited with " << amount << " and your final amount in your account is " << this->balance << endl;
        }
    }
};

class CurrentAccount : public Account
{
private:
    double balance;

public:
    CurrentAccount() : Account()
    {
        this->balance = 0;
    }

    void deposit(double amount) override
    {
        this->balance += amount;
        cout << "Your Current Account credited with " << amount << " and your final amount is " << this->balance << endl;
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
            cout << "Your account debited with " << amount << " and your final amount in Your Current Account is " << this->balance << endl;
        }
    }
};

class FixedDeposit : public Account
{
private:
    double balance;

public:
    void deposit(double amount) override
    {
        this->balance += amount;
        cout << "Your Fixed Term Account Credited with " << amount << " and Your final balance in your account is " << this->balance << endl;
    }

    void withdraw(double amount) override
    {
        throw logic_error("You cannot withdraw amount from the Fixed Term Account....");
    }
};

class BankClient
{
private:
    vector<Account *> accounts;

public:
    BankClient(vector<Account *> accounts)
    {
        this->accounts = accounts;
    }

    void ProcessTransaction()
    {
        for (auto account : this->accounts)
        {
            account->deposit(1000);
            if (typeid(*account) != typeid(FixedDeposit))
            {
                try
                {
                    account->withdraw(500);
                }
                catch (const logic_error &e)
                {
                    cout << "Exception : " << e.what() << endl;
                }
            }
            else
            {
                cout << "Skipping withdraw from the Fixed Term Account...." << endl;
            }
        }
    }
};

int main()
{
    vector<Account *> accounts;
    accounts.push_back(new SavingAccount);
    accounts.push_back(new CurrentAccount);
    accounts.push_back(new FixedDeposit);

    BankClient *client = new BankClient(accounts);
    client->ProcessTransaction();

    delete client;

    return 0;
}

// by doing this your are solving the problem of LSP but you violate OCP by modifying BankClient Class
// So that This is not correct way to solve LSP problem