#include <iostream>

class Singleton {
public:
    static Singleton& Instance() {
        static Singleton s;
        return s;
    }
private:
    Singleton() {
        std::cout << "Initialized\n";
    }
    Singleton(const Singleton&) = delete;
    Singleton& operator=(const Singleton&);
};
int main() {
    Singleton::Instance();
    Singleton::Instance();
    return 0;
}
