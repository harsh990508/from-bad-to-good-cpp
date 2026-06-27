//Improved SRP.

#include <iostream>
#include <string>
using namespace std;

// Responsibility 1: Billing
class BillCalculator {
public:
    int calculateBill(int itemPrice, int quantity) {
        return itemPrice * quantity;
    }
};

// Responsibility 2: Payment
class PaymentService {
public:
    void processPayment(const string& method, int amount) {
        cout << "Processing payment of " << amount
             << " using " << method << endl;
    }
};

// Responsibility 3: Notification
class NotificationService {
public:
    void sendNotification(const string& message) {
        cout << "Sending notification: " << message << endl;
    }
};

// Responsibility 4: Persistence
class OrderRepository {
public:
    void saveOrder() {
        cout << "Saving order to database" << endl;
    }
};

// Coordinator class
class OrderService {
private:
    BillCalculator billCalculator;
    PaymentService paymentService;
    NotificationService notificationService;
    OrderRepository repository;

public:
    void placeOrder(int itemPrice, int quantity, const string& paymentMethod) {
        int total = billCalculator.calculateBill(itemPrice, quantity);
        paymentService.processPayment(paymentMethod, total);
        repository.saveOrder();
        notificationService.sendNotification("Order placed successfully");
    }
};

int main() {
    OrderService orderService;
    orderService.placeOrder(200, 2, "UPI");
}
