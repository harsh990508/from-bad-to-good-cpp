#include <iostream>
using namespace std;

class Singleton {
private:
    Singleton() {
        cout << "Lazy+Reference: Constructor called\n";
    }
    Singleton(const Singleton&) = delete;
    Singleton& operator=(const Singleton&) = delete;

public:
    static Singleton& getInstance() {
        static Singleton instance;  // created first time getInstance() called
        return instance;            // reference returned — no copy
    }

    void show() {
        cout << "Lazy+Reference: Singleton is working\n";
    }
};

int main() {
    cout << "Main started\n";
    // object does NOT exist yet here

    Singleton& s1 = Singleton::getInstance();  // created HERE first time
    Singleton& s2 = Singleton::getInstance();  // same object returned

    s1.show();

    cout << "Same object? " << (&s1 == &s2 ? "YES" : "NO") << "\n";
    cout << "Address s1: " << &s1 << "\n";
    cout << "Address s2: " << &s2 << "\n";
    // no delete needed — not on heap
}


/*Output :
----------------
Main started
Lazy+Reference: Constructor called    ← created only when first called
Lazy+Reference: Singleton is working
Same object? YES
Address s1: 0x...
Address s2: 0x...                     ← same address
*/
