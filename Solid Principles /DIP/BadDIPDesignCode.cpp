//Bad Dependency Inversion Principle code
#include <iostream>
using namespace std;

class EmailSender {
public:
    void send(string message) {
        cout << "Sending EMAIL: " << message << endl;
    }
};

class NotificationService {
private:
    EmailSender sender;   // concrete dependency
public:
    void sendNotification(string message) {
        sender.send(message);
    }
};

int main() {
    NotificationService service;
    service.sendNotification("Order placed successfully");
}
