#include <stdexcept>

constexpr long long factorial(int number) noexcept{
    if (number < 0)
        throw std::invalid_argument("number < 0");

    long long result{1};

    while(number > 0){
        result *= number;
        --number;
    }

    return result;
}

constexpr int gcd(int first, int second){
    while(second != 0){
        int temp = second;
        second = first % second;
        first = temp;
    }
    return first;
}

constexpr int lcm(int first, int second){
    return (first * second) / gcd(first, second);
}

