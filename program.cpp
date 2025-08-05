#include <iostream>
#include <vector>
#include <string>
#include <list>
#include "combinatorial_library.h"

int main(){
    std::cout << "Hello, world!" << std::endl;

    std::list<int> vec{1, 2, 3};
    do{
        for(auto x : vec)
            std::cout << x << " ";
        std::cout << std::endl;
    }while(narayana_algorithm(vec.begin(), vec.end()));
    
    return 0;
}