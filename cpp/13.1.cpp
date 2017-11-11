#include <fstream>
#include <string>
#include <iostream>
#include <deque>

int main() {
    std::deque<std::string> lines_queue;
    std::ifstream in("input");
    size_t k = 3;
    while (true) {
        std::string input_string;
        std::getline(in, input_string);
        if (in.eof()) {
            break;
        }
        lines_queue.push_back(input_string);
        if (lines_queue.size() > k) {
            lines_queue.pop_front();
        }
    }
    for (auto& line: lines_queue) {
        std::cout << line << "\n";
    }
    return 0;
}
