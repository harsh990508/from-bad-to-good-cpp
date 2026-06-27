#include <iostream>
using namespace std;

// Split into small focused interfaces
class IWorkable {
public:
    virtual void work() = 0;
    virtual ~IWorkable() {}
};

class IEatable {
public:
    virtual void eat() = 0;
    virtual ~IEatable() {}
};

class ISleepable {
public:
    virtual void sleep() = 0;
    virtual ~ISleepable() {}
};

// Human needs all three — implement all three
class HumanWorker : public IWorkable, public IEatable, public ISleepable {
public:
    void work() override {
        cout << "Human is working\n";
    }
    void eat() override {
        cout << "Human is eating\n";
    }
    void sleep() override {
        cout << "Human is sleeping\n";
    }
};

// Robot needs only work — implement only work ✅
class RobotWorker : public IWorkable {
public:
    void work() override {
        cout << "Robot is working\n";
    }
};

int main() {
    HumanWorker human;
    RobotWorker robot;

    human.work();
    human.eat();
    human.sleep();

    robot.work();
    // robot.eat()  — does not exist, cannot even call ✅
    // robot.sleep() — does not exist, cannot even call ✅

    return 0;
}
