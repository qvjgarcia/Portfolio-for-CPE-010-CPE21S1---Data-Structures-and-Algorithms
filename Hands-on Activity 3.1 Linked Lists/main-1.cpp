#include <iostream>
#include <string>

class Fruit {
private:
    std::string name;
    double price;
    int quantity;

public:
    Fruit(std::string n = "", double p = 0, int q = 0) : name(std::move(n)), price(p), quantity(q) { std::cout 
        << "Fruit Constructor Called." << std::endl; }

    ~Fruit() { std::cout << "Fruit Destructor Called." << std::endl; }

    Fruit(const Fruit &c) : name(c.name), price(c.price), quantity(c.quantity) 
        {std::cout << "Fruit Copy Constructor Called." << std::endl; }

    Fruit& operator=(const Fruit &c) { std::cout << "Fruit Copy Assignment Called." << std::endl; if (this != &c) 
        { name = c.name; price = c.price; quantity = c.quantity; } return *this; }

    double calculateSum() { return this->price * this->quantity; }

    void printDetails() { std::cout << "Fruit: " << this->name << " PHP " 
        << this->price << " x" << this->quantity << std::endl; }
};

class Vegetable {
private:
    std::string name;
    double price;
    int quantity;

public:
    Vegetable(std::string n = "", double p = 0, int q = 0) : name(std::move(n)), price(p), quantity(q) 
        { std::cout << "Vegetable Constructor Called." << std::endl; }

    ~Vegetable() { std::cout << "Vegetable Destructor Called." << std::endl; }

    Vegetable(const Vegetable &c) : name(c.name), price(c.price), quantity(c.quantity) 
        { std::cout << "Vegetable Copy Constructor Called." << std::endl; }

    Vegetable& operator=(const Vegetable &c) { std::cout << "Vegetable Copy Assignment Called." << std::endl; if (this != &c) 
        { name = c.name; price = c.price; quantity = c.quantity; } return *this; }

    double calculateSum() { return this->price * this->quantity; }

    void printDetails() { std::cout << "Vegetable: " << this->name << " PHP " << this->price << " x" 
        << this->quantity << std::endl; }
};

//total sum
double TotalSum(Fruit* f[], int fSize, Vegetable* v[], int vSize) {
    double total = 0;
    for (int i = 0; i < fSize; i++) if (f[i]) total += f[i]->calculateSum();
    for (int i = 0; i < vSize; i++) if (v[i]) total += v[i]->calculateSum();
    return total;
}
//main driver
int main() {

    Fruit* fruitList[2] = { new Fruit("Apple", 10, 7), new Fruit("Banana", 10, 8) };
    Vegetable* vegList[2] = { new Vegetable("Broccoli", 60, 12), new Vegetable("Lettuce", 50, 10) };

    std::cout << "\n--- Jenna's Grocery List ---" << std::endl;
    for (int i = 0; i < 2; i++) if (fruitList[i]) fruitList[i]->printDetails();
    for (int i = 0; i < 2; i++) if (vegList[i]) vegList[i]->printDetails();

    //total Sum
    std::cout << "\nTotal Sum: PHP " << TotalSum(fruitList, 2, vegList, 2) << std::endl;

    std::cout << "\n--- Deleting Lettuce ---" << std::endl;
    delete vegList[1];
    vegList[1] = nullptr;

    std::cout << "Updated Total Sum: PHP " << TotalSum(fruitList, 2, vegList, 2) << std::endl << std::endl;

    // Memory Cleanup
    for (int i = 0; i < 2; i++) delete fruitList[i];
    for (int i = 0; i < 2; i++) delete vegList[i];

    return 0;
}
#include <iostream>
#include <string>


class Fruit {
private:
   std::string name;
   double price;
   int quantity;


public:
   // Constructor
   Fruit(std::string n = "", double p = 0, int q = 0) :
       name(std::move(n)), price(p), quantity(q) {
       std::cout << "Fruit Constructor Called." << std::endl; }
   // Destructor
   ~Fruit() { std::cout << "Fruit Destructor Called." << std::endl; }
   // Copy Constructor
   Fruit(const Fruit &c) : name(c.name), price(c.price), quantity(c.quantity)
       { std::cout << "Fruit Copy Constructor Called." << std::endl; }
   // Copy Assignment Operator
   Fruit& operator=(const Fruit &c) { std::cout << "Fruit Copy Assignment Called." << std::endl;
       if (this != &c)
       { name = c.name; price = c.price; quantity = c.quantity; } return *this; }
   // Calculate sum
   double calculateSum() { return this->price * this->quantity; }
   // Details
   void printDetails() {
       std::cout << "\nFruit: " << name;
       std::cout << "\nPrice: PHP " << price;
       std::cout << "\nQuantity: " << quantity;
       std::cout << "\nTotal: PHP " << calculateSum() << "\n";
   }
};


class Vegetable {
private:
   std::string name;
   double price;
   int quantity;


public:
   Vegetable(std::string n = "", double p = 0, int q = 0) : name(std::move(n)), price(p), quantity(q)
       { std::cout << "Vegetable Constructor Called." << std::endl; }


   ~Vegetable() { std::cout << "Vegetable Destructor Called." << std::endl; }


   Vegetable(const Vegetable &c) : name(c.name), price(c.price), quantity(c.quantity)
       { std::cout << "Vegetable Copy Constructor Called." << std::endl; }


   Vegetable& operator=(const Vegetable &c) { std::cout << "Vegetable Copy Assignment Called." << std::endl;
       if (this != &c)
       { name = c.name; price = c.price; quantity = c.quantity; } return *this; }


   double calculateSum() { return this->price * this->quantity; }


   void printDetails() {
       std::cout << "\nVegetable: " << name;
       std::cout << "\nPrice: PHP " << price;
       std::cout << "\nQuantity: " << quantity;
       std::cout << "\nTotal: PHP " << calculateSum() << "\n";
   }
};


//total sum
double TotalSum(Fruit* f[], int fSize, Vegetable* v[], int vSize) {
   double total = 0;
   for (int i = 0; i < fSize; i++) if (f[i]) total += f[i]->calculateSum();
   for (int i = 0; i < vSize; i++) if (v[i]) total += v[i]->calculateSum();
   return total;
}
//main driver
int main() {


   Fruit* fruitList[2] = { new Fruit("Apple", 10, 7), new Fruit("Banana", 10, 8) };
   Vegetable* vegList[2] = { new Vegetable("Broccoli", 60, 12), new Vegetable("Lettuce", 50, 10) };


   std::cout << "\n--- Jenna's Grocery List ---" << std::endl;
   for (int i = 0; i < 2; i++) if (fruitList[i]) fruitList[i]->printDetails();
   for (int i = 0; i < 2; i++) if (vegList[i]) vegList[i]->printDetails();


   // total Sum of all objects listed in Jenna’s Grocery List
   std::cout << "\nTotal Sum: PHP " << TotalSum(fruitList, 2, vegList, 2) << std::endl;


   //Deleting Lettuce
   std::cout << "\n--- Deleting Lettuce ---" << std::endl;
   delete vegList[1];
   vegList[1] = nullptr;


   std::cout << "Updated Total Sum: PHP " << TotalSum(fruitList, 2, vegList, 2) << std::endl << std::endl;


   // Memory Cleanup
   for (int i = 0; i < 2; i++) delete fruitList[i];
   for (int i = 0; i < 2; i++) delete vegList[i];


   return 0;
}
