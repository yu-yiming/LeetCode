#include <vector>

#include "tools/format.hpp"

void reverseString(std::vector<char>& s) {
    size_t low = 0, high = s.size() - 1;
    while (low < high) {
        std::swap(s[low++], s[high--]);
    }
}

int main() {
    std::vector<char> v1 = { 'a', 'b', 'c' };
    reverseString(v1);
    print_elems(v1);
    return 0;
}