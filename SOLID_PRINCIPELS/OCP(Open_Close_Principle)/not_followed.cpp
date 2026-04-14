// In this class is open to extend but it is close to modify
// It means we can not modify the existing class
// and if we do that than it will violate OPEN CLOSE PRINCIPLE

#include <iostream>
#include <vector>

using namespace std;

// now create one product class
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

// 1. Shopping Cart
class ShoppingCart
{
private:
    vector<Product *> products;

public:
    // write getter and setter
    // setter
    void addProduct(Product *product)
    {
        this->products.push_back(product);
    }

    // getter
    // what this code snippet means is i will return vector of references of the product but i will return the reference of the original vector and i also return vector reference in such a way that you can not change it and i also didn't change it in the function (const which is at the starting of the fucntion is ensure that this vector can not changed outside the function if we use the vector reference which is returned by this function) ( and the const which is at the end of the function ensure that this function is not modify the existing vector)
    const vector<Product *> &getProduct() const
    {
        return this->products;
    }
};

// 2. CalculateTotal
class TotalBill
{
private:
    ShoppingCart *cart;

public:
    // constructer
    TotalBill(ShoppingCart *cart)
    {
        this->cart = cart;
    }

    // method to calculate total bill
    double bill()
    {
        double total = 0;
        for (auto product : this->cart->getProduct())
        {
            total += product->price;
        }
        return total;
    }
};

// 3. PrintInvoice
class PrintInvoice
{
private:
    ShoppingCart *cart;
    TotalBill *bill;

public:
    // constructer
    PrintInvoice(ShoppingCart *cart, TotalBill *bill)
    {
        this->bill = bill;
        this->cart = cart;
    }

    // method to print invoice
    void printInvoice()
    {
        cout << "Your Invoice ........" << endl;
        for (auto product : this->cart->getProduct())
        {
            cout << product->name << " -Rs. : " << product->price << endl;
        }
        cout << "Your total bill is : " << this->bill->bill() << endl;
    }
};

// 4. Save to DB
// if we add other methods which save cart to other databases than it will violates OCP because we will modify it

class SaveToDB
{
public:
    // method to save cart to db
    void saveToDB()
    {
        cout << "Your cart is successfully saved to our database....." << endl;
    }
    void saveToMongo()
    {
        cout << "Your cart is successfully saved to our mongo Database...." << endl;
    }

    void saveToNOSQLDB()
    {
        cout << "Your cart is successfully saved to our NOSQL database....." << endl;
    }
};

// main
int main()
{
    // create one object of cart
    ShoppingCart *cart = new ShoppingCart;

    // add some product to our cart
    cart->addProduct(new Product("Milk", 60.00));
    cart->addProduct(new Product("Bread", 50.00));
    cart->addProduct(new Product("Cooking Oil", 3000.00));

    // create one object of total bill class
    TotalBill *bill = new TotalBill(cart);

    // create one object of PrintInvoice
    PrintInvoice *invoice = new PrintInvoice(cart, bill);

    invoice->printInvoice();

    // create one object of Save DB
    SaveToDB *db = new SaveToDB;
    db->saveToDB();
    db->saveToMongo();
    db->saveToNOSQLDB();

    delete db;
    delete bill;
    delete cart;
    delete invoice;

    return 0;
}