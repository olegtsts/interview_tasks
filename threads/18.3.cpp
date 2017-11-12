#include <iostream>
#include <thread>
#include <sstream>
#include <future>

template <typename Foo>
class Singleton {
public:
    static Foo& Instance() {
        static Foo instance;
        return instance;
    }
private:
    Singleton() {}
    Singleton(const Singleton&) = delete;
    Singleton& operator=(const Singleton&) = delete;
};
int main() {
    std::promise<void> p;
    std::future<void> fu = p.get_future();
    auto first_thread = std::thread([&p] () {
        Singleton<int>::Instance() = 1;
        p.set_value();
    });
    auto second_thread = std::thread([&fu] () {
        fu.wait();
        std::stringstream ss;
        ss << Singleton<int>::Instance() << "\n";
        std::cout << ss.str();
    });
    first_thread.join();
    second_thread.join();
    return 0;
}

