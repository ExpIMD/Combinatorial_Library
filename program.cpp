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

    std::vector<int> permutation {1, 2, 3, 4, 5};
    std::vector<int> current = permutation;

    for(size_t i{0}; i < 120; ++i){

        IMD::factorial_number_system_permutation_bitmask(permutation, i, [i](const std::vector<int>& vec){
            std::cout << "Index: " << i << ", Permutation: ";
            for(const auto& x : vec)
                std::cout << x << " ";
            std::cout << std::endl;
        });
    }

    return 0;
}