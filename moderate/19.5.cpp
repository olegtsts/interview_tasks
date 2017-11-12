#include <string>
#include <tuple>
#include <algorithm>
#include <iostream>

std::tuple<size_t, size_t, size_t, size_t> GetCounters(const std::string& answer) {
    size_t r(0),y(0),g(0),b(0);
    for (auto el: answer) {
        if (el == 'r') {
            ++r;
        } else if (el == 'y') {
            ++y;
        } else if (el == 'g') {
            ++g;
        } else if (el == 'b') {
            ++b;
        }
    }
    return std::make_tuple(r,y,g,b);
}
std::tuple<size_t, size_t> GetHitsAndPseudoHits(const std::string& correct_answer, const std::string& given_answer) {
    size_t r1,y1,g1,b1;
    std::tie(r1,y1,g1,b1) = GetCounters(correct_answer);
    size_t r2,y2,g2,b2;
    std::tie(r2,y2,g2,b2) = GetCounters(given_answer);
    size_t precise = 0;
    for (size_t i = 0; i < 4; ++i) {
        if (correct_answer[i] == given_answer[i]) {
            ++precise;
        }
    }
    return std::make_tuple(precise, std::min(r1,r2) + std::min(y1,y2) + std::min(g1,g2) + std::min(b1,b2) - precise);
}
int main() {
    std::string correct_answer, given_answer;
    std::cin >> correct_answer >> given_answer;
    size_t hits, pseudo_hits;
    std::tie(hits, pseudo_hits) = GetHitsAndPseudoHits(correct_answer, given_answer);
    std::cout << hits << " " << pseudo_hits;
    return 0;
}
