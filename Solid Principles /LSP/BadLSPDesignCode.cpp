//BadDesign -LSP

#include <iostream>
using namespace std;

class Bird {
public:
    virtual void fly() {
        cout << "Bird is flying\n";
    }
};

class Sparrow : public Bird {
public:
    void fly() override {
        cout << "Sparrow is flying\n";
    }
};

class Penguin : public Bird {
public:
    void fly() override {
        throw runtime_error("Penguin cannot fly");
    }
};

void makeBirdFly(Bird& b) {
    b.fly();
}

int main() {
    Sparrow s;
    Penguin p;

    makeBirdFly(s);   // fine
    makeBirdFly(p);   // problem
}
