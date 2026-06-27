//SOLID Principle
//Bad design for S->SRP

#include <iostream>
#include <string>
using namespace std;

class OrderProcessor {
public:
    void calculateBill(int itemPrice, int quantity) {
        int total = itemPrice * quantity;
        cout << "Total bill = " << total << endl;
    }

    void processPayment(const string& method) {
        cout << "Processing payment using " << method << endl;
    }

    void sendNotification(const string& message) {
        cout << "Sending notification: " << message << endl;
    }

    void saveToDatabase() {
        cout << "Saving order to database" << endl;
    }
};

int main() {
    OrderProcessor op;
    op.calculateBill(200, 2);
    op.processPayment("UPI");
    op.sendNotification("Order placed successfully");
    op.saveToDatabase();
}
