#include <iostream>
#include <vector>

using namespace std;

// In this code we will solve the Problem which was violating the Single Responsibility Principle
// Product class
class Product
{
public:
    string name;
    double price;

    // constructor
    Product(string name, double price)
    {
        this->name = name;
        this->price = price;
    }
};

// 1. write one class for shopping cart
class ShoppingCart
{
private:
    vector<Product *> products;

public:
    // getter and setter for the private attribute of the class
    // setter
    void addProduct(Product *product)
    {
        this->products.push_back(product);
    }

    // getter
    const vector<Product *> &getProduct() const
    {
        return this->products;
    }
};

// 2. write class for the totalamount
class TotalAmount
{
public:
    ShoppingCart *cart;

    TotalAmount(ShoppingCart *cart)
    {
        this->cart = cart;
    }

    double calculateTotal()
    {
        double total = 0;
        for (auto product : this->cart->getProduct())
        {
            total += product->price;
        }
        return total;
    }
};

// 3. write class for PrintInvoice
class PrintInvoice
{
public:
    ShoppingCart *cart;
    TotalAmount *amount;

    PrintInvoice(ShoppingCart *cart, TotalAmount *amount)
    {
        this->cart = cart;
        this->amount = amount;
    }

    void printInvoice()
    {
        cout << "Cart Invoice...." << endl;
        for (auto product : this->cart->getProduct())
        {
            cout << product->name << " -Rs : " << product->price << endl;
        }
        cout << "Total bill is : " << this->amount->calculateTotal() << endl;
    }
};

// 4. write class for Save To Data base
class SaveToDB
{
public:
    void save()
    {
        cout << "Your cart is successfully saved to our database....." << endl;
    }
};

int main()
{
    // create one object of the class shopping cart
    ShoppingCart *cart = new ShoppingCart;

    // add few items to our shopping cart
    cart->addProduct(new Product("Ghee", 300.00));
    cart->addProduct(new Product("Cooking Oil", 3510.00));

    // create one object of the total amount
    TotalAmount *total = new TotalAmount(cart);

    // create one object of the class PrintInvoice
    PrintInvoice *invoice = new PrintInvoice(cart, total);
    invoice->printInvoice();

    // create one object of the class SaveToDB
    SaveToDB *db = new SaveToDB;
    db->save();

    delete cart;
    delete invoice;
    delete db;

    return 0;
}