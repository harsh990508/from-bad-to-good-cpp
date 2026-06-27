#include <iostream>
using namespace std;

class Singleton {
private:
    static Singleton* instance;  // just a pointer, starts null

    Singleton() {
        cout << "Lazy+Pointer: Constructor called\n";
    }
    Singleton(const Singleton&) = delete;
    Singleton& operator=(const Singleton&) = delete;

public:
    static Singleton* getInstance() {
        if(instance == nullptr) {        // first call — create it
            instance = new Singleton();  // created ON DEMAND
        }
        return instance;                 // already exists — return it
    }

    void show() {
        cout << "Lazy+Pointer: Singleton is working\n";
    }

    // must manually delete in pointer version
    static void destroy() {
        delete instance;
        instance = nullptr;
    }
};

// initialized to null — no object yet
Singleton* Singleton::instance = nullptr;

int main() {
    cout << "Main started\n";
    // object does NOT exist yet here

    Singleton* s1 = Singleton::getInstance();  // created HERE first time
    Singleton* s2 = Singleton::getInstance();  // same object returned

    s1->show();

    cout << "Same object? " << (s1 == s2 ? "YES" : "NO") << "\n";
    cout << "Address s1: " << s1 << "\n";
    cout << "Address s2: " << s2 << "\n";

    Singleton::destroy();
}


/*output is :
-----------------
Main started
Lazy+Pointer: Constructor called    ← created only when first called
Lazy+Pointer: Singleton is working
Same object? YES
Address s1: 0x...
Address s2: 0x...                   ← same address
*/
