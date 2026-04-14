// In this we will write code to solve the problem which was violating OCP
// we can solve this problem using INTERFACE(abstraction, polymorphism, inheritance)

#include <iostream>
#include <vector>

using namespace std;

class Product
{
public:
    string name;
    double price;

    Product(string name, double price)
    {
        this->name = name;
        this->price = price;
    }
};

class ShoppingCart
{
private:
    vector<Product *> products;

public:
    // getter
    const vector<Product *> &getProducts() const
    {
        return this->products;
    }

    // setter
    void addProduct(Product *product)
    {
        this->products.push_back(product);
    }
};

class TotalBill
{
private:
    ShoppingCart *cart;

public:
    TotalBill(ShoppingCart *cart)
    {
        this->cart = cart;
    }

    // calculateBill
    double calculateBill()
    {
        double total = 0;
        for (auto product : this->cart->getProducts())
        {
            total += product->price;
        }
        return total;
    }
};

class PrintInvoice
{
private:
    ShoppingCart *cart;
    TotalBill *bill;

public:
    // consturcter
    PrintInvoice(ShoppingCart *cart, TotalBill *bill)
    {
        this->cart = cart;
        this->bill = bill;
    }

    // printInvoice method
    void printInvoice()
    {
        cout << "Your cart Invoice...." << endl;
        for (auto product : this->cart->getProducts())
        {
            cout << product->name << " -Rs. :" << product->price << endl;
        }

        cout << "---------------------------" << endl;
        cout << "Your Total Bill is : " << this->bill->calculateBill() << endl;
    }
};

// now this is how we will solve this problem
// we will use abstraction for the savetodb class

class DB
{
public:
    virtual void save() = 0;
};

// now we will create one class to saveTOSQLDB
class SQLDB : public DB
{
public:
    void save() override
    {
        cout << "Your Data is stored into SQLDB....." << endl;
    }
};

// now we will create class SaveTOMONGODB
class MONGODB : public DB
{
public:
    void save() override
    {
        cout << "Your data is stored into Mongo DB...." << endl;
    }
};

// casandraDB
class CasandraDB : public DB
{
public:
    void save() override
    {
        cout << "Your data si stored into cassandra DB......" << endl;
    }
};

// main
int main()
{
    ShoppingCart *cart = new ShoppingCart;

    // add items to our cart
    cart->addProduct(new Product("Milk", 68.00));
    cart->addProduct(new Product("Bread", 50.00));

    // calculate total bill
    TotalBill *bill = new TotalBill(cart);

    // Print Invoice of the cart
    PrintInvoice *invoice = new PrintInvoice(cart, bill);

    invoice->printInvoice();

    // save to sqldb
    DB *sql = new SQLDB;

    sql->save();

    // save to Mongo
    DB *mongo = new MONGODB;
    mongo->save();

    // save to cassandra
    DB *casa = new CasandraDB;
    casa->save();

    delete casa;
    delete mongo;
    delete sql;
    delete bill;
    delete invoice;
    delete cart;

    return 0;
}