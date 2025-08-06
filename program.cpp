#include <iostream>
#include <vector>
#include <string>
#include <list>
#include "combinatorial_library.h"

int main(){
    std::cout << "Hello, world!" << std::endl;

    auto result = IMD::BINOMIAL::Pascal_triangle(5);

    for(auto x : result){
        for(auto y : x)
            std::cout << y << " ";
        std::cout << std::endl;
    }

    return 0;
}