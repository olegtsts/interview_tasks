#include <vector>
#include <iostream>

class HanoiProcessor {
private:
    std::vector<std::vector<size_t>> towers_;
public:
    HanoiProcessor(const size_t number)
        : towers_(3)
    {
        for (size_t i = 0; i < number; ++i) {
            towers_[0].push_back(static_cast<size_t>(static_cast<int>(number) - static_cast<int>(i)));
        }
    }
    friend std::ostream& operator<<(std::ostream& out, const HanoiProcessor& hanoi_processor) {
        for (auto tower_index: {0, 1, 2}) {
            out << tower_index + 1 << ": ";
            for (auto& el: hanoi_processor.towers_[tower_index]) {
                out << el << " ";
            }
            out << "\n";
        }
        out << "\n";
        return out;
    }
    void MakeMove(const size_t source_tower, const size_t target_tower) {
        auto element = towers_[source_tower].back();
        towers_[source_tower].pop_back();
        towers_[target_tower].push_back(element);
        std::cout << *this;
    }
    size_t GetThirdTower(const size_t first_tower, const size_t second_tower) const {
        return (0 ^ 1 ^ 2 ^ first_tower ^ second_tower);
    }
    void ProcessSteps(const size_t disks_count, const size_t source_tower, const size_t target_tower) {
        if (disks_count == 1) {
            MakeMove(source_tower, target_tower);
        } else {
            auto third_tower = GetThirdTower(source_tower, target_tower);
            ProcessSteps(disks_count - 1, source_tower, third_tower);
            MakeMove(source_tower, target_tower);
            ProcessSteps(disks_count - 1, third_tower, target_tower);
        }
    }
};
int main() {
    HanoiProcessor hanoi_processor(5);
    hanoi_processor.ProcessSteps(5, 0, 2);
    return 0;
}
