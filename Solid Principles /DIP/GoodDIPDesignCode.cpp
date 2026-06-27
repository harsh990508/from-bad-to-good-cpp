///GOOD Design for DIP

#include <iostream>
using namespace std;

class INotificationSender {
public:
    virtual void send(string message) = 0;
    virtual ~INotificationSender() = default;
};

class EmailSender : public INotificationSender {
public:
    void send(string message) override {
        cout << "Sending EMAIL: " << message << endl;
    }
};

class SmsSender : public INotificationSender {
public:
    void send(string message) override {
        cout << "Sending SMS: " << message << endl;
    }
};

class NotificationService {
private:
    INotificationSender* sender;   // depends on abstraction
public:
    NotificationService(INotificationSender* sender) : sender(sender) {}

    void sendNotification(string message) {
        sender->send(message);
    }
};

int main() {
    EmailSender emailSender;
    NotificationService service(&emailSender);
    service.sendNotification("Order placed successfully");
}
