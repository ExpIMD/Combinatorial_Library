#include <vector>
#include <iostream>
#include <unordered_map>
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

unsigned long long IMD::binomial_coefficient(unsigned int n, unsigned int m){ // C(n, m)
    return IMD::Pascal_triangle_row(n)[m];
}

unsigned long long IMD::sum_binomial_coefficient(unsigned int n){
    return 1ULL << n;
}

void IMD::print_Newton_binomial(unsigned int n, std::ostream& out) {
    for (unsigned int k {0}; k <= n; ++k) {
        unsigned long long coefficient {binomial_coefficient(n, k)};

        if (coefficient != 1)
            out << coefficient;

        if (n - k > 0) {
            out << "a";
            if (n - k > 1)
                out << "^" << (n - k);
        }

        if (k > 0) {
            out << "b";
            if (k > 1)
                out << "^" << k;
        }

        if (k != n)
            out << " + ";
    }
    out << std::endl;
}

unsigned long long IMD::path_to_the_grate(unsigned int n, unsigned int m){
    return binomial_coefficient(n + m, n);
}

unsigned long long IMD::number_of_good_pairs(const std::vector<int>& vec){
    std::unordered_map<int, unsigned int> alphabet;
    int result{0};

    for (const auto& x : vec) alphabet[x]++;

    for (const auto& entry : alphabet)
        result += (entry.second * (entry.second - 1)) / 2; // C(count, 2)

    return result;

}

