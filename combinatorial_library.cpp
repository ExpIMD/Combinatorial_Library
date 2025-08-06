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

IMD::SEQUENCE::geometric_sequence::geometric_sequence(double start, double ratio) noexcept: _current(start), _ratio(ratio) {}

double IMD::SEQUENCE::geometric_sequence::current() const noexcept{
    return this->_current;
}

void IMD::SEQUENCE::geometric_sequence::next() noexcept{
    this->_current *= this->_ratio;
}

IMD::SEQUENCE::arithmetic_sequence::arithmetic_sequence(long long start, long long step) noexcept: _current(start), _step(step) {}

void IMD::SEQUENCE::geometric_sequence::previous() noexcept{
    this->_current /= this->_ratio;
}

bool IMD::SEQUENCE::geometric_sequence::is_convergent() const noexcept{
    return std::abs(this->_ratio) < 1 - EPSILON;
}

long long IMD::SEQUENCE::Fibonacci_sequence::current() const noexcept {
    return this->_current;
}

void IMD::SEQUENCE::Fibonacci_sequence::next() noexcept {
    long long next = this->_previous + this->_current;
    this->_previous = this->_current;
    this->_current = next;
}

void IMD::SEQUENCE::Fibonacci_sequence::previous() noexcept {
    if (this->_current == 0) return;
    
    long long temp = this->_current;
    this->_current = this->_previous;
    this->_previous = temp - this->_previous;
}

bool IMD::SEQUENCE::Fibonacci_sequence::is_convergent() const noexcept {
    return false; // Fibonacci sequence does not converge
}

IMD::SEQUENCE::Fibonacci_sequence::Fibonacci_sequence() noexcept : _previous(0), _current(1) {}

IMD::SEQUENCE::Catalan_sequence::Catalan_sequence() noexcept : _current_index(0), _current_value(1) {}

long long IMD::SEQUENCE::Catalan_sequence::current() const noexcept{
    return this->_current_value;
}

void IMD::SEQUENCE::Catalan_sequence::next() noexcept{
    this->_current_value = this->_current_value * 2 * (2 * this->_current_index + 1) / (this->_current_index + 2);
    ++this->_current_index;
}

void IMD::SEQUENCE::Catalan_sequence::previous() noexcept{
    if (this->_current_index == 0) return;

    this->_current_value = this->_current_value * (this->_current_index + 1) / (2 * (2 * (this->_current_index - 1) + 1));
    --this->_current_index;
}

bool IMD::SEQUENCE::Catalan_sequence::is_convergent() const noexcept{
    return false;
}