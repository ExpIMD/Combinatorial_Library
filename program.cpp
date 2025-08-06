#include <iostream>
#include <vector>
#include <string>
#include <list>
#include "combinatorial_library.h"

int main(){
    std::cout << "Hello, world!" << std::endl;

    IMD::SEQUENCE::arithmetic_sequence as{3, 5};

    for(size_t i {0}; i < 10; ++i){
        std::cout << as.current() << " ";
        as.next();
    }

    return 0;
}