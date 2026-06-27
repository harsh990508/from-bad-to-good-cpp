#include <iostream>
using namespace std;

class Singleton {
private:
    // object created immediately at program start
    static Singleton* instance;

    Singleton() {
        cout << "Eager+Pointer: Constructor called\n";
    }
    Singleton(const Singleton&) = delete;
    Singleton& operator=(const Singleton&) = delete;

public:
    static Singleton* getInstance() {
        return instance;   // already exists — just return it
    }

    void show() {
        cout << "Eager+Pointer: Singleton is working\n";
    }

    static void destroy() {
        delete instance;
        instance = nullptr;
    }
};

// object created HERE — before main() starts
Singleton* Singleton::instance = new Singleton();

int main() {
    cout << "Main started\n";
    // object ALREADY EXISTS here

    Singleton* s1 = Singleton::getInstance();  // just retrieves it
    Singleton* s2 = Singleton::getInstance();  // same object

    s1->show();

    cout << "Same object? " << (s1 == s2 ? "YES" : "NO") << "\n";
    cout << "Address s1: " << s1 << "\n";
    cout << "Address s2: " << s2 << "\n";

    Singleton::destroy();
}

/*Output :
---------------
Eager+Pointer: Constructor called    ← created BEFORE main
Main started
Eager+Pointer: Singleton is working
Same object? YES
Address s1: 0x...
Address s2: 0x...                    ← same address
*/
