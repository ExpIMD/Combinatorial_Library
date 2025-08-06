#include <iostream>
#include <vector>
#include <string>
#include <list>
#include "combinatorial_library.h"

int main(){
    std::cout << "Hello, world!" << std::endl;

    IMD::SEQUENCE::Fibonacci_sequence gs{};

    for(size_t i {0}; i < 10; ++i){
        std::cout << gs.current() << " ";
        gs.next();
    }

    std::cout << std::endl << std::boolalpha << gs.is_convergent();

    return 0;
}