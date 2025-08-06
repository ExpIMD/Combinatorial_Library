#include <iostream>
#include <vector>
#include <string>
#include <list>
#include "combinatorial_library.h"

int main(){
    std::cout << "Hello, world!" << std::endl;

    IMD::SEQUENCE::Catalan_sequence cs{};

    for(size_t i {0}; i < 10; ++i){
        std::cout << cs.current() << " ";
        cs.next();
    }

    std::cout << std::endl << std::boolalpha << cs.is_convergent();

    return 0;
}