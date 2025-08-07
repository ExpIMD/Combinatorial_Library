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

    std::vector<int> permutation {1, 3, 2};
    size_t index{0};
    return 0;
}