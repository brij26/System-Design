// in this we write code which is violatign LSP(Liskov Substition Principle)
// According to this principle if we use subclass instead of it's parent class than it should work correctly

#include <iostream>
#include <vector>

using namespace std;

class Account
{
public:
    // abstract method
    virtual void deposit(double amount) = 0;
    virtual void withdraw(double amount) = 0;
};

// 1.Current Account
class CurrAccount : public Account
{
private:
    double balance;

public:
    CurrAccount()
    {
        this->balance = 0;
    }
    void deposit(double amount) override
    {
        this->balance += amount;
        cout << "After credting " << amount << " your final balance is : " << this->balance << endl;
    }

    void withdraw(double amount) override
    {
        if (this->balance <= amount)
        {
            cout << "Insufficient Funds!" << endl;
            return;
        }
        else
        {
            this->balance = this->balance - amount;
            cout << "Your final balance is : " << this->balance << endl;
        }
    }
};

// 2. Saving Account
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
        cout << "After credting " << amount << " your final balance is : " << this->balance << endl;
    }

    void withdraw(double amount) override
    {
        if (this->balance <= amount)
        {
            cout << "Insufficient Funds!" << endl;
            return;
        }
        else
        {
            this->balance = this->balance - amount;
            cout << "Your final balance is : " << this->balance << endl;
        }
    }
};

// 3. FixedDepositAccount
class FDAccount : public Account
{
private:
    double balance;

public:
    FDAccount()
    {
        this->balance = 0;
    }
    void deposit(double amount) override
    {
        this->balance += amount;
        cout << "After credting " << amount << " your final balance is : " << balance << endl;
    }

    void withdraw(double amount) override
    {
        throw logic_error("Withdraw not allowed in Fixed Deposite Account.");
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

    void processTransactions()
    {
        for (Account *acc : accounts)
        {
            acc->deposit(1000); // All accounts allow deposits

            // Assuming all accounts support withdrawal (LSP Violation)
            try
            {
                acc->withdraw(500);
            }
            catch (const logic_error &e)
            {
                cout << "Exception: " << e.what() << endl;
            }
        }
    }
};

int main()
{
    vector<Account *> accounts;
    accounts.push_back(new SavingAccount());
    accounts.push_back(new CurrAccount());
    accounts.push_back(new FDAccount());

    BankClient *client = new BankClient(accounts);
    client->processTransactions(); //  Throws exception when withdrawing from FixedTermAccount

    return 0;
}
