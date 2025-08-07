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

std::vector<unsigned int> IMD::Pascal_triangle_row(size_t row_index){
    std::vector<unsigned int> row(row_index + 1, 0);
    row[0] = 1;

    for (size_t i {1}; i <= row_index; ++i) {
        for (size_t j {i}; j > 0; --j)
            row[j] = row[j - 1] + row[j];
        row[0] = 1;
    }

    return row;           
}

unsigned int IMD::binomial_coefficient(unsigned int n, unsigned int m){ // C(n, m)
    return IMD::Pascal_triangle_row(n)[m];

}