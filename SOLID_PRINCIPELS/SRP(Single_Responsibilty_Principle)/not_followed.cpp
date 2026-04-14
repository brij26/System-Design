#include <iostream>
#include <vector>

using namespace std;

// now we will write code in which SRP(Single Resposibility Principle is not followed)
// In this code there is only one problem which is our one class(ShoppingCart) is handling more than one Resposibility
// If we want our code to follow SRP than any particular class should only full fill one Responsibility not more than one
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

// violated SRP : ShoppingCart is handling more than one Responsibility
class ShoppingCart
{
private:
    vector<Product *> products;

public:
    // now we will write getter and setter for the private attributes of the class
    // setter
    void addProduct(Product *product)
    {
        products.push_back(product);
    }

    // getter
    const vector<Product *> &getProducts()
    {
        return this->products;
    }

    // 1. Calculate Total price in the cart
    double calculateTotalPrice()
    {
        double total = 0;
        for (auto product : this->products)
        {
            total += product->price;
        }

        return total;
    }

    // 2. Printing the Invoice of the cart
    void printInvoice()
    {
        cout << "Cart Invoice...." << endl;
        for (auto product : this->products)
        {
            cout << product->name << " - Rs. " << product->price << endl;
        }
        cout << "Total bill : " << this->calculateTotalPrice() << endl;
    }

    // 3. Save Cart to the database
    void saveToDB()
    {
        cout << "Cart is successfully saved to DB......" << endl;
    }
};

int main()
{
    vector<Product *> products;
    products.push_back(new Product("Ghee", 200.00));
    products.push_back(new Product("Book", 100.00));

    ShoppingCart *cart = new ShoppingCart;
    for (auto product : products)
    {
        cart->addProduct(product);
    }

    cart->calculateTotalPrice();
    cart->printInvoice();
    cart->saveToDB();

    delete cart;

    return 0;
}