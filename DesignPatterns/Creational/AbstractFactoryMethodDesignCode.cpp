#include<iostream>
using namespace std;

///Product Interfaces
//=======================//
class Car
{
public:
    virtual void drive() = 0;
    virtual ~Car(){}
};

class Engine
{
public:
    virtual void start() = 0;
    virtual ~Engine(){}
};

class Seat
{
public:
    virtual void comfort() = 0;
    virtual ~Seat(){}
};

class Dashboard
{
public:
    virtual void display() = 0;
    virtual ~Dashboard(){}
};


/*Concrete Products -> BMWProducts
======================================*/


class BMWCar : public Car
{
public:
    void drive() override
    {
        cout<<"Driving BMW\n";
    }
};

class BMWEngine : public Engine
{
public:
    void start() override
    {
        cout<<"BMW Engine Started\n";
    }
};

class BMWSeat : public Seat
{
public:
    void comfort() override
    {
        cout<<"BMW Luxury Seat\n";
    }
};

class BMWDashboard : public Dashboard
{
public:
    void display() override
    {
        cout<<"BMW Digital Dashboard\n";
    }
};


/*Concrete Products -> AudiProducts
======================================*/

class AudiCar : public Car
{
public:
    void drive() override
    {
        cout<<"Driving Audi\n";
    }
};

class AudiEngine : public Engine
{
public:
    void start() override
    {
        cout<<"Audi Engine Started\n";
    }
};

class AudiSeat : public Seat
{
public:
    void comfort() override
    {
        cout<<"Audi Sports Seat\n";
    }
};

class AudiDashboard : public Dashboard
{
public:
    void display() override
    {
        cout<<"Audi Virtual Cockpit\n";
    }
};

/*Abstract Factory -> 
==============================*/

class VehicleFactory
{
public:

    virtual Car* createCar() = 0;

    virtual Engine* createEngine() = 0;

    virtual Seat* createSeat() = 0;

    virtual Dashboard* createDashboard() = 0;

    virtual ~VehicleFactory(){}
};


/* Concrete Factory -> BMWFactory
======================================*/

class BMWFactory : public VehicleFactory
{
public:

    Car* createCar() override
    {
        return new BMWCar();
    }

    Engine* createEngine() override
    {
        return new BMWEngine();
    }

    Seat* createSeat() override
    {
        return new BMWSeat();
    }

    Dashboard* createDashboard() override
    {
        return new BMWDashboard();
    }
};


/* Concrete Factory -> AudiFactory
======================================*/

class AudiFactory : public VehicleFactory
{
public:

    Car* createCar() override
    {
        return new AudiCar();
    }

    Engine* createEngine() override
    {
        return new AudiEngine();
    }

    Seat* createSeat() override
    {
        return new AudiSeat();
    }

    Dashboard* createDashboard() override
    {
        return new AudiDashboard();
    }
};


int main()
{
    string choice;
    cout<<"Enter you choice\n";
    cin>>choice;
    
    VehicleFactory* factory = nullptr;

    if(choice == "BMW")
        factory = new BMWFactory();
    else if(choice == "Audi")
        factory = new AudiFactory();
    else {
        cout << "Invalid choice\n";
        return 1;
    }
    
    //VehicleFactory* factory = new BMWFactory();

    Car* car = factory->createCar();

    Engine* engine = factory->createEngine();

    Seat* seat = factory->createSeat();

    Dashboard* dashboard = factory->createDashboard();

    engine->start();

    dashboard->display();

    seat->comfort();

    car->drive();
    
    // cleanup
    delete car;
    delete engine;
    delete seat;
    delete dashboard;
    delete factory;

    return 0;
}
