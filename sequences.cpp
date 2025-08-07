#include <algorithm>
#include <vector>
#include <stdexcept>
#include <cmath>
#include "sequences.h"

IMD::arithmetic_sequence::arithmetic_sequence(long long start, long long step) noexcept: _start(start), _current(start), _step(step), _index(0) {}

IMD::arithmetic_sequence::arithmetic_sequence(const arithmetic_sequence& other) noexcept : _start(other._start), _current(other._current), _step(other._step), _index(other._index) {}

IMD::arithmetic_sequence::arithmetic_sequence(arithmetic_sequence&& other) noexcept : _start(other._start), _current(other._current), _step(other._step), _index(other._index) {}

IMD::arithmetic_sequence& IMD::arithmetic_sequence::operator=(const arithmetic_sequence& other) noexcept{
    if (this != &other){
        this->_start = other._start;
        this->_current = other._current;
        this->_step = other._step;
        this->_index = other._index;
    }
    return *this;
}

IMD::arithmetic_sequence& IMD::arithmetic_sequence::operator=(arithmetic_sequence&& other) noexcept{
    this->_start = std::move(other._start);
    this->_current = std::move(other._current);
    this->_step = std::move(other._step);
    this->_index = std::move(other._index);

    return *this;
}

IMD::arithmetic_sequence::~arithmetic_sequence() noexcept = default;

long long IMD::arithmetic_sequence::current() const noexcept{
    return this->_current;
}

void IMD::arithmetic_sequence::next() noexcept {
    this->_current += this->_step;
    ++this->_index;
}

void IMD::arithmetic_sequence::previous() noexcept {
    if (this->_index == 0) return;

    this->_current -= this->_step;
    --this->_index;
}

bool IMD::arithmetic_sequence::is_convergent() const noexcept {
    return false; // Arithmetic progression doesn't converge
}

size_t IMD::arithmetic_sequence::index() const noexcept{
    return this->_index;
}

void IMD::arithmetic_sequence::advance(size_t n) noexcept{
    while(n != 0){
        this->next();
        --n;
    }
}

void IMD::arithmetic_sequence::rewind(size_t n) noexcept{
    while(n != 0){
        this->previous();
        --n;
    }
}

void IMD::arithmetic_sequence::move(size_t n) noexcept{
    if (n > _index)
        this->advance(n - _index);
    else if (n < _index)
        this->rewind(_index - n);
}

void IMD::arithmetic_sequence::reset() noexcept{
    this->_index = 0;
    this->_current = _start;
}

IMD::geometric_sequence::geometric_sequence(double start, double ratio) noexcept: _start(start), _current(start), _ratio(ratio), _index(0) {}

IMD::geometric_sequence::geometric_sequence(const geometric_sequence& other) noexcept : _start(other._start), _current(other._current), _ratio(other._ratio), _index(other._index) {}

IMD::geometric_sequence::geometric_sequence(geometric_sequence&& other) noexcept : _start(other._start), _current(other._current), _ratio(other._ratio), _index(other._index) {}

IMD::geometric_sequence& IMD::geometric_sequence::operator=(const geometric_sequence& other) noexcept{
    if (this != &other){
        this->_start = other._start;
        this->_current = other._current;
        this->_ratio = other._ratio;
        this->_index = other._index;
    }
    return *this;
}

IMD::geometric_sequence& IMD::geometric_sequence::operator=(geometric_sequence&& other) noexcept{
    this->_start = std::move(other._start);
    this->_current = std::move(other._current);
    this->_index = std::move(other._index);
    this->_ratio = std::move(other._ratio);

    return *this;
}

IMD::geometric_sequence::~geometric_sequence() noexcept = default;

double IMD::geometric_sequence::current() const noexcept{
    return this->_current;
}

void IMD::geometric_sequence::next() noexcept{
    this->_current *= this->_ratio;
    ++this->_index;
}

void IMD::geometric_sequence::previous() noexcept{
    if (this->_index == 0) return;

    this->_current /= this->_ratio;
    --this->_index;
}

bool IMD::geometric_sequence::is_convergent() const noexcept{
    return std::abs(this->_ratio) < 1 - EPSILON;
}

size_t IMD::geometric_sequence::index() const noexcept{
    return this->_index;
}

void IMD::geometric_sequence::advance(size_t n) noexcept{
    while(n != 0){
        this->next();
        --n;
    }
}

void IMD::geometric_sequence::rewind(size_t n) noexcept{
    while(n != 0){
        this->previous();
        --n;
    }
}

void IMD::geometric_sequence::move(size_t n) noexcept{
    if (n > _index)
        this->advance(n - _index);
    else if (n < _index)
        this->rewind(_index - n);
}

void IMD::geometric_sequence::reset() noexcept{
    this->_index = 0;
    this->_current = _start;
}

IMD::Fibonacci_sequence::Fibonacci_sequence() noexcept : _previous(0), _current(1), _index(0) {}

IMD::Fibonacci_sequence::Fibonacci_sequence(const Fibonacci_sequence& other) noexcept : _previous(other._previous), _current(other._current), _index(other._index) {}

IMD::Fibonacci_sequence::Fibonacci_sequence(Fibonacci_sequence&& other) noexcept : _previous(other._previous), _current(other._current), _index(other._index) {}

IMD::Fibonacci_sequence& IMD::Fibonacci_sequence::operator=(const Fibonacci_sequence& other) noexcept{
    if (this != &other){
        this->_previous = other._previous;
        this->_current = other._current;
        this->_index = other._index;
    }
    return *this;
}

IMD::Fibonacci_sequence& IMD::Fibonacci_sequence::operator=(Fibonacci_sequence&& other) noexcept{
    this->_previous = std::move(other._previous);
    this->_current = std::move(other._current);
    this->_index = std::move(other._index);

    return *this;
}

IMD::Fibonacci_sequence::~Fibonacci_sequence() noexcept = default;

long long IMD::Fibonacci_sequence::current() const noexcept {
    return this->_current;
}

void IMD::Fibonacci_sequence::next() noexcept {
    long long next = this->_previous + this->_current;
    this->_previous = this->_current;
    this->_current = next;
    ++this->_index;
}

void IMD::Fibonacci_sequence::previous() noexcept {
    if (this->_index == 0) return;
    
    long long temp = this->_current;
    this->_current = this->_previous;
    this->_previous = temp - this->_previous;
    --this->_index;
}

bool IMD::Fibonacci_sequence::is_convergent() const noexcept {
    return false; // Fibonacci sequence does not converge
}

size_t IMD::Fibonacci_sequence::index() const noexcept{
    return this->_index;
}

void IMD::Fibonacci_sequence::advance(size_t n) noexcept{
    while(n != 0){
        this->next();
        --n;
    }
}

void IMD::Fibonacci_sequence::rewind(size_t n) noexcept{
    while(n != 0){
        this->previous();
        --n;
    }
}

void IMD::Fibonacci_sequence::move(size_t n) noexcept{
    if (n > _index)
        this->advance(n - _index);
    else if (n < _index)
        this->rewind(_index - n);
}

void IMD::Fibonacci_sequence::reset() noexcept{
    this->_index = 0;
    this->_current = 1;
    this->_previous = 0;
}

IMD::Catalan_sequence::Catalan_sequence() noexcept : _index(0), _current(1) {}

IMD::Catalan_sequence::Catalan_sequence(const Catalan_sequence& other) noexcept : _current(other._current), _index(other._index) {}

IMD::Catalan_sequence::Catalan_sequence(Catalan_sequence&& other) noexcept : _current(other._current), _index(other._index) {}

IMD::Catalan_sequence& IMD::Catalan_sequence::operator=(const Catalan_sequence& other) noexcept{
    if (this != &other){
        this->_current = other._current;
        this->_index = other._index;
    }
    return *this;
}

IMD::Catalan_sequence& IMD::Catalan_sequence::operator=(Catalan_sequence&& other) noexcept{
    this->_current = std::move(other._current);
    this->_index = std::move(other._index);

    return *this;
}

IMD::Catalan_sequence::~Catalan_sequence() noexcept = default;

long long IMD::Catalan_sequence::current() const noexcept{
    return this->_current;
}

void IMD::Catalan_sequence::next() noexcept{
    this->_current = this->_current * 2 * (2 * this->_index + 1) / (this->_index + 2);
    ++this->_index;
}

void IMD::Catalan_sequence::previous() noexcept{
    if (this->_index == 0) return;

    this->_current = this->_current * (this->_index + 1) / (2 * (2 * (this->_index - 1) + 1));
    --this->_index;
}

bool IMD::Catalan_sequence::is_convergent() const noexcept{
    return false;
}

size_t IMD::Catalan_sequence::index() const noexcept{
    return this->_index;
}

void IMD::Catalan_sequence::advance(size_t n) noexcept{
    while(n != 0){
        this->next();
        --n;
    }
}

void IMD::Catalan_sequence::rewind(size_t n) noexcept{
    while(n != 0){
        this->previous();
        --n;
    }
}

void IMD::Catalan_sequence::move(size_t n) noexcept{
    if (n > _index)
        this->advance(n - _index);
    else if (n < _index)
        this->rewind(_index - n);
}

void IMD::Catalan_sequence::reset() noexcept{
    this->_index = 0;
    this->_current = 1;
}