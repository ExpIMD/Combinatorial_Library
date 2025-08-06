#include <algorithm>
#include <vector>
#include <stdexcept>
#include <cmath>
#include "combinatorial_library.h"

IMD::SEQUENCE::arithmetic_sequence::arithmetic_sequence(long long start, long long step) noexcept: _start(start), _current(start), _step(step), _index(0) {}

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
    ++this->_index;
}

void IMD::SEQUENCE::arithmetic_sequence::previous() noexcept {
    if (this->_index == 0) return;

    this->_current -= this->_step;
    --this->_index;
}

bool IMD::SEQUENCE::arithmetic_sequence::is_convergent() const noexcept {
    return false; // Arithmetic progression doesn't converge
}

size_t IMD::SEQUENCE::arithmetic_sequence::index() const noexcept{
    return this->_index;
}

void IMD::SEQUENCE::arithmetic_sequence::advance(size_t n) noexcept{
    while(n != 0){
        this->next();
        --n;
    }
}

void IMD::SEQUENCE::arithmetic_sequence::rewind(size_t n) noexcept{
    while(n != 0){
        this->previous();
        --n;
    }
}

void IMD::SEQUENCE::arithmetic_sequence::move(size_t n) noexcept{
    if (n > _index)
        this->advance(n - _index);
    else if (n < _index)
        this->rewind(_index - n);
}

void IMD::SEQUENCE::arithmetic_sequence::reset() noexcept{
    this->_index = 0;
    this->_current = _start;
}

IMD::SEQUENCE::geometric_sequence::geometric_sequence(double start, double ratio) noexcept: _start(start), _current(start), _ratio(ratio), _index(0) {}

double IMD::SEQUENCE::geometric_sequence::current() const noexcept{
    return this->_current;
}

void IMD::SEQUENCE::geometric_sequence::next() noexcept{
    this->_current *= this->_ratio;
    ++this->_index;
}

void IMD::SEQUENCE::geometric_sequence::previous() noexcept{
    if (this->_index == 0) return;

    this->_current /= this->_ratio;
    --this->_index;
}

bool IMD::SEQUENCE::geometric_sequence::is_convergent() const noexcept{
    return std::abs(this->_ratio) < 1 - EPSILON;
}

size_t IMD::SEQUENCE::geometric_sequence::index() const noexcept{
    return this->_index;
}

void IMD::SEQUENCE::geometric_sequence::advance(size_t n) noexcept{
    while(n != 0){
        this->next();
        --n;
    }
}

void IMD::SEQUENCE::geometric_sequence::rewind(size_t n) noexcept{
    while(n != 0){
        this->previous();
        --n;
    }
}

void IMD::SEQUENCE::geometric_sequence::move(size_t n) noexcept{
    if (n > _index)
        this->advance(n - _index);
    else if (n < _index)
        this->rewind(_index - n);
}

void IMD::SEQUENCE::geometric_sequence::reset() noexcept{
    this->_index = 0;
    this->_current = _start;
}

IMD::SEQUENCE::Fibonacci_sequence::Fibonacci_sequence() noexcept : _previous(0), _current(1), _index(0) {}

long long IMD::SEQUENCE::Fibonacci_sequence::current() const noexcept {
    return this->_current;
}

void IMD::SEQUENCE::Fibonacci_sequence::next() noexcept {
    long long next = this->_previous + this->_current;
    this->_previous = this->_current;
    this->_current = next;
    ++this->_index;
}

void IMD::SEQUENCE::Fibonacci_sequence::previous() noexcept {
    if (this->_index == 0) return;
    
    long long temp = this->_current;
    this->_current = this->_previous;
    this->_previous = temp - this->_previous;
    --this->_index;
}

bool IMD::SEQUENCE::Fibonacci_sequence::is_convergent() const noexcept {
    return false; // Fibonacci sequence does not converge
}

size_t IMD::SEQUENCE::Fibonacci_sequence::index() const noexcept{
    return this->_index;
}

void IMD::SEQUENCE::Fibonacci_sequence::advance(size_t n) noexcept{
    while(n != 0){
        this->next();
        --n;
    }
}

void IMD::SEQUENCE::Fibonacci_sequence::rewind(size_t n) noexcept{
    while(n != 0){
        this->previous();
        --n;
    }
}

void IMD::SEQUENCE::Fibonacci_sequence::move(size_t n) noexcept{
    if (n > _index)
        this->advance(n - _index);
    else if (n < _index)
        this->rewind(_index - n);
}

void IMD::SEQUENCE::Fibonacci_sequence::reset() noexcept{
    this->_index = 0;
    this->_current = 1;
    this->_previous = 0;
}

IMD::SEQUENCE::Catalan_sequence::Catalan_sequence() noexcept : _index(0), _current(1) {}

long long IMD::SEQUENCE::Catalan_sequence::current() const noexcept{
    return this->_current;
}

void IMD::SEQUENCE::Catalan_sequence::next() noexcept{
    this->_current = this->_current * 2 * (2 * this->_index + 1) / (this->_index + 2);
    ++this->_index;
}

void IMD::SEQUENCE::Catalan_sequence::previous() noexcept{
    if (this->_index == 0) return;

    this->_current = this->_current * (this->_index + 1) / (2 * (2 * (this->_index - 1) + 1));
    --this->_index;
}

bool IMD::SEQUENCE::Catalan_sequence::is_convergent() const noexcept{
    return false;
}

size_t IMD::SEQUENCE::Catalan_sequence::index() const noexcept{
    return this->_index;
}

void IMD::SEQUENCE::Catalan_sequence::advance(size_t n) noexcept{
    while(n != 0){
        this->next();
        --n;
    }
}

void IMD::SEQUENCE::Catalan_sequence::rewind(size_t n) noexcept{
    while(n != 0){
        this->previous();
        --n;
    }
}

void IMD::SEQUENCE::Catalan_sequence::move(size_t n) noexcept{
    if (n > _index)
        this->advance(n - _index);
    else if (n < _index)
        this->rewind(_index - n);
}

void IMD::SEQUENCE::Catalan_sequence::reset() noexcept{
    this->_index = 0;
    this->_current = 1;
}