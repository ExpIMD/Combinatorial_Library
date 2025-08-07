#include <vector>
#include "binomial.h"


std::vector<std::vector<unsigned int>> IMD::Pascal_triangle(size_t rows){
    std::vector<std::vector<unsigned int>> result;
    for(size_t i {0}; i < rows; ++i){
        std::vector<unsigned int> row(i + 1, 1);
        for(size_t j {1}; j < i; ++j)
            row[j] = result[i - 1][j - 1] + result[i - 1][j];
        result.push_back(row);
    }
    return result;
}