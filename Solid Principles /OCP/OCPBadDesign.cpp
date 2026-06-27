//Bad OCP Design
#include <iostream>
#include <string>
using namespace std;

class PaymentProcessor {
public:
    void processPayment(const string& method, int amount) {
        if (method == "UPI") {
            cout << "Processing UPI payment of Rs. " << amount << endl;
        }
        else if (method == "CARD") {
            cout << "Processing Card payment of Rs. " << amount << endl;
        }
        else if (method == "CASH") {
            cout << "Processing Cash payment of Rs. " << amount << endl;
        }
        else {
            cout << "Invalid payment method" << endl;
        }
    }
};

int main() {
    PaymentProcessor p;
    p.processPayment("UPI", 500);
}
