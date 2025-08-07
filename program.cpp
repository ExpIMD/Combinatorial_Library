#include <iostream>
#include <vector>
#include <string>
#include <list>
#include "sequences.h"
#include "permutations.h"

int main(){
    std::cout << "Hello, world!" << std::endl;

    IMD::Fibonacci_sequence seq{};

    for(size_t i {0}; i < 10; ++i){
        std::cout << "Index: " << seq.index() << ", Element: " << seq.current() << std::endl;
        seq.next();
    }

    std::vector<int> permutation {1, 2, 3};
    std::vector<int> current;

    IMD::backtracking_algorithm(permutation, current, 0, [](const std::vector<int>& vec){
        for(const auto& x : vec)
            std::cout << x << " ";
        std::cout << std::endl;

    });

    return 0;
}