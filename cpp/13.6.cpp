#include <iostream>

class BaseClass {
public:
    virtual void Func(int) const {
        std::cout << "Func1\n";
    }
    virtual void Func(int, int) const {
        std::cout << "Func2\n";
    }
};
class Derived : public BaseClass {
public:
    using BaseClass::Func;
    void Func(int) const {
        std::cout << "Derived Func1\n";
    }
};
int main() {
    Derived * derived = new Derived();
    derived->Func(1);
    derived->Func(1, 1);
    return 0;
}
