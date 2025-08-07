#ifndef __IMD_BINOMIAL_
#define __IMD_BINOMIAL_

#include <vector>

namespace IMD {
    std::vector<std::vector<unsigned int>> Pascal_triangle(size_t rows);

    std::vector<unsigned int> Pascal_triangle_row(size_t row_index);
    
    unsigned long long binomial_coefficient(unsigned int n, unsigned int m); // C(n, m)

    unsigned long long sum_binomial_coefficient(unsigned int n);

    void print_Newton_binomial(unsigned int n, std::ostream& out = std::cout);

    unsigned long long path_to_the_grate(unsigned int n, unsigned int m);

    unsigned long long number_of_good_pairs(const std::vector<int>& vec);

}


#endif