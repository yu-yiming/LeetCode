#pragma once
#include <iostream>

template<typename Cont>
void print_elems(Cont const& cont) {
    for (auto const& elem : cont) {
        std::cout << elem << ' ';
    }
}