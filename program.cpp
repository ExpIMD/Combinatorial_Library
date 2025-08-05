#include <iostream>
#include <vector>
#include <string>
#include <list>
#include "combinatorial_library.h"

int main(){
    std::cout << "Hello, world!" << std::endl;

    std::vector<int> vec{1, 2, 3, 4};
    size_t index{0};
    std::vector<std::vector<int>> result{};
    IMD::PERMUTATIONS::Johnson_Trotter_algorithm(vec, result);

    for(auto x : result){
        std::cout << "INDEX: " << index << ": ";
        for(auto y : x)
            std::cout << y << " ";
        std::cout << std::endl;
        ++index;
    }

    return 0;
}