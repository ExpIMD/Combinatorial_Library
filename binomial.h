#ifndef __IMD_BINOMIAL_
#define __IMD_BINOMIAL_

#include <vector>

namespace IMD {
    std::vector<std::vector<unsigned int>> Pascal_triangle(size_t rows);

    std::vector<unsigned int> Pascal_triangle_row(size_t row_index);
    
    unsigned int binomial_coefficient(unsigned int n, unsigned int m); // C(n, m)

    unsigned int sum_binomial_coefficient(int n);

    void Newton_binomial(unsigned int n);

    unsigned int path_to_the_grate(int n, int m);

    unsigned int number_of_good_pairs(const std::vector<int>& vec);

}


#endif