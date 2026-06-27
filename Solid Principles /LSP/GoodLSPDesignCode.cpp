//Good design
//Write main to compile.

#include <iostream>
using namespace std;

class Bird {
public:
    virtual void eat() {
        cout << "Bird is eating\n";
    }

    virtual ~Bird() = default;
};

class FlyingBird : public Bird {
public:
    virtual void fly() = 0;
};

class Sparrow : public FlyingBird {
public:
    void fly() override {
        cout << "Sparrow is flying\n";
    }
};

class Penguin : public Bird {
public:
    void swim() {
        cout << "Penguin is swimming\n";
    }
};
