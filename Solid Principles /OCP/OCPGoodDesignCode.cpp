//Good OCP design
#include <iostream>
using namespace std;

// Abstraction
//PaymentMethod is the abstraction : It defines the contract.
//It says : Any payment method must know how to pay(amount).”
class PaymentMethod {
public:
    virtual void pay(int amount) = 0;
    virtual ~PaymentMethod() = default;
};

/// Each payment type implements the contract
================================================

// Extension 1
class UpiPayment : public PaymentMethod {
public:
    void pay(int amount) override {
        cout << "Processing UPI payment of Rs. " << amount << endl;
    }
};

// Extension 2
class CardPayment : public PaymentMethod {
public:
    void pay(int amount) override {
        cout << "Processing Card payment of Rs. " << amount << endl;
    }
};

// Extension 3
class CashPayment : public PaymentMethod {
public:
    void pay(int amount) override {
        cout << "Processing Cash payment of Rs. " << amount << endl;
    }
};

// PaymentProcessor no longer contains branching logic.
//It simply relies on polymorphism.

// Stable class
class PaymentProcessor {
public:
    void processPayment(PaymentMethod& paymentMethod, int amount) {
        paymentMethod.pay(amount);
    }
};

int main() {
    PaymentProcessor processor;

    UpiPayment upi;
    CardPayment card;
    CashPayment cash;

    processor.processPayment(upi, 500);
    processor.processPayment(card, 1200);
    processor.processPayment(cash, 300);
}
