#include <algorithm>
#include <vector>
#include <stdexcept>
#include <cmath>
#include "combinatorial_library.h"

std::vector<std::vector<unsigned int>> IMD::BINOMIAL::Pascal_triangle(size_t rows){
    std::vector<std::vector<unsigned int>> result;
    for(size_t i {0}; i < rows; ++i){
        std::vector<unsigned int> row(i + 1, 1);
        for(size_t j {1}; j < i; ++j)
            row[j] = result[i - 1][j - 1] + result[i - 1][j];
        result.push_back(row);
    }
    return result;
}
long long IMD::SEQUENCE::arithmetic_sequence::current() const noexcept{
    return this->_current;
}

void IMD::SEQUENCE::arithmetic_sequence::next() noexcept {
    this->_current += this->_step;
}

void IMD::SEQUENCE::arithmetic_sequence::previous() noexcept {
    this->_current -= this->_step;
}

bool IMD::SEQUENCE::arithmetic_sequence::is_convergent() const noexcept {
    return false; // Arithmetic progression doesn't converge
}            

double IMD::SEQUENCE::geometric_sequence::current() const noexcept{
    return this->_current;
}

void IMD::SEQUENCE::geometric_sequence::next() noexcept{
    this->_current *= this->_ratio;
}

void IMD::SEQUENCE::geometric_sequence::previous() noexcept{
    this->_current /= this->_ratio;
}

bool IMD::SEQUENCE::geometric_sequence::is_convergent() const noexcept{
    return std::abs(this->_ratio) < 1 - EPSILON;
}