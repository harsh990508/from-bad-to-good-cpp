#include <iostream>
using namespace std;

//==============================
// Product
//==============================
class Car
{
public:
    virtual void drive() = 0;

    virtual ~Car() {}
};

//==============================
// Concrete Products
//==============================
class BMW : public Car
{
public:
    void drive() override
    {
        cout << "Driving BMW" << endl;
    }
};

class Audi : public Car
{
public:
    void drive() override
    {
        cout << "Driving Audi" << endl;
    }
};

//==============================
// Creator
//==============================
class CarFactory
{
public:
    virtual Car* createCar() = 0;

    virtual ~CarFactory() {}
};

//==============================
// Concrete Creators
//==============================
class BMWFactory : public CarFactory
{
public:
    Car* createCar() override
    {
        return new BMW();
    }
};

class AudiFactory : public CarFactory
{
public:
    Car* createCar() override
    {
        return new Audi();
    }
};

//==============================
// Client
//==============================
int main()
{
    string choice;
    cout<<"Enter your choice\n";
    cin>>choice;
    
    CarFactory* factory = nullptr;
    Car* car = nullptr;
    
    if(choice =="BMW")
    {
        factory = new BMWFactory();
    }
    else
    {
        factory = new AudiFactory();
    }
    
    car = factory->createCar();
    car->drive();

    delete car;
    delete factory;

    return 0;
}
