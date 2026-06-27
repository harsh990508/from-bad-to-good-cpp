#include <iostream>
using namespace std;

// One fat interface forcing everything on everyone
class IWorker {
public:
    virtual void work() = 0;
    virtual void eat() = 0;      // robots don't eat ❌
    virtual void sleep() = 0;    // robots don't sleep ❌
    virtual ~IWorker() {}
};

// Human worker — fine, needs all three
class HumanWorker : public IWorker {
public:
    void work() override {
        cout << "Human is working\n";
    }
    void eat() override {
        cout << "Human is eating\n";
    }
    void sleep()
