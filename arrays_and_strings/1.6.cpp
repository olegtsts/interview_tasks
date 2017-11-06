#include <algorithm>
#include <iostream>
#include <vector>

using Image = std::vector<std::vector<uint32_t>>;
void Rotate(Image& image) {
    int N = static_cast<int>(image.size());
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < i; ++j) {
            std::swap(image[i][j], image[j][i]);
        }
    }
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N / 2; ++j) {
            std::swap(image[i][j], image[i][(N - 1) - j]);
        }
    }
}
Image GetFromInput(std::istream& in) {
    size_t size;
    in >> size;
    Image image(size, std::vector<uint32_t>(size));
    for (size_t i = 0; i < size; ++i) {
        for (size_t j = 0; j < size; ++j) {
            in >> image[i][j];
        }
    }
    return image;
}
void PrintToOutput(std::ostream& out, const Image& image) {
    size_t size = image.size();
    for (size_t i = 0; i < size; ++i) {
        for (size_t j = 0; j < size; ++j) {
            out << image[i][j];
            if (j + 1 < size) {
                out << ' ';
            }
        }
        out << "\n";
    }
}
int main() {
    Image image = GetFromInput(std::cin);
    Rotate(image);
    PrintToOutput(std::cout, image);
    return 0;
}
