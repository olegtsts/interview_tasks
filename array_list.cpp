#include <cassert>
#include <algorithm>
#include <iostream>

template <typename T>
class ArrayList {
public:
    ArrayList()
        : memory(new T[1])
        , size(0)
        , capacity(1)
    {}

    size_t GetSize() const {
        return size;
    }

    void Add(const T& value) {
        if (size == capacity) {
            T* new_memory = new T[2 * capacity];
            for (size_t i = 0; i < size; ++i) {
                new_memory[i] = memory[i];
            }
            capacity *= 2;
            std::swap(memory, new_memory);
            delete [] new_memory;
            std::cout << "Resize done\n";
        }
        assert(size < capacity);
        memory[size++] = value;
    }
    T& operator[](const size_t index) {
        return memory[index];
    }

    ~ArrayList() {
        delete [] memory;
    }
private:
    T* memory;
    size_t size;
    size_t capacity;
};

int main() {
    ArrayList<int> array_list;
    array_list.Add(1);
    array_list.Add(2);
    array_list.Add(3);
    array_list.Add(4);

    std::cout << array_list[0] << " " << array_list[1] << " " << array_list[2] << " " << array_list[3] << std::endl;
    return 0;
}
