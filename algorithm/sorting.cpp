#include "../std.hpp"

namespace sorting {

template<typename It>
void bubble_sort(It first, It last) {
    if (first == last) {
        return;
    }

    int n = std::distance(first, last);
    for (int i = 0; i < 1; ++i) {
        It prev = first, curr = first;
        ++curr;
        while (curr != last) {
            prev = curr++;
            if (*curr < *prev) {
                std::swap(*curr, *prev);
            }
        }
    }
}

/**
 * Bubble sort.
 * Traverse the container an swap any adjacent pairs that are in wrong order.
 */
template<typename It, typename Comp>
void bubble_sort(It first, It last, Comp cmp) {
    if (first == last) {
        return;
    }

    int n = std::distance(first, last);
    for (int i = 0; i < n; ++i) {
        It prev = first, curr = first;
        ++curr;
        while (curr != last) {
            prev = curr++;
            if (cmp(*curr, *prev)) {
                std::swap(*curr, *prev);
            }
        }
    }
}

/**
 * Bubble sort.
 * Do the bubble sort on a container and put the results into another containers.
 * Note that the two containers should be different or it's a UB.
 */
template<typename InputIt, typename OutputIt, typename Comp>
void bubble_sort(InputIt first, InputIt last, OutputIt out, int n, Comp cmp) {
    std::copy(first, last, out);
    bubble_sort(first, last, n, cmp);
}


}

/**
 * Command line sorting test.
 * Usage: ./sort [alg-name] n1 n2 ...
 */
void sort_test(int argc, char* argv[]) {
    std::string sort_type(argv[1]);
    std::vector<int> nums(argc - 2);
    for (int i = 2; i < argc; ++i) {
        nums[i - 2] = static_cast<int>(std::strtol(argv[i], nullptr, 10));
    }
    if (sort_type == "bubble") {
        sorting::bubble_sort(nums.begin(), nums.end());
    }

    for (auto elem : nums) {
        std::cout << elem << ' ';
    }
    std::cout << '\n';
}