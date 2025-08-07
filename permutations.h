#ifndef __PERMUTATIONS_
#define __PERMUTATIONS_

#include <algorithm>
#include <iterator>
#include <stdexcept>
#include <unordered_set>

namespace IMD{
    template<typename T>
    bool Narayana_algorithm(std::vector<T>& permutation) {
        size_t j{permutation.size() - 1};
    
        while(j > 0){
            if (permutation[j-1] < permutation[j]) break;
            --j;
        }
    
        if (j == 0)
            return false;
    
        size_t l {permutation.size() - 1};
    
        while(l > 0){
            if (permutation[j - 1] < permutation[l]) break;
            --l;
        }
    
        std::swap(permutation[l], permutation[j-1]);
    
        std::reverse(permutation.begin() + j, permutation.end());
        return true;
    }
    template<typename T, typename Func>
    void Heap_algorithm(std::vector<T>& permutation, Func f, size_t n){
        if (n > permutation.size())
            throw std::runtime_error("n > permutation.size()");

        if (n == 1){
            f(permutation);
            return;
        }
        
        for(size_t i{0}; i < n; ++i){
            Heap_recursion_algorithm(permutation, f, n - 1);
            if (n % 2 == 0)
                std::swap(permutation[i], permutation[n-1]);
            else std::swap(permutation[0], permutation[n-1]);
        }
    }

    template<typename T, typename Func>
    void Algorithm_L(std::vector<T>& permutation, Func f, size_t n){
        if (n > permutation.size())
            throw std::runtime_error("n > permutation.size()");

        std::vector<size_t> counter(n, 0);
        f(permutation);

        size_t i {0};
        while (i < n) {
            if (counter[i] < i) {
                if (i % 2 == 0)
                    std::swap(permutation[0], permutation[i]);
                else std::swap(permutation[counter[i]], permutation[i]);
                
                f(permutation);
                ++counter[i];
                i = {0};
            } else {
                counter[i] = {0};
                ++i;
            }
        }
    }

    template<typename T, typename Func>
    void Johnson_Trotter_algorithm(std::vector<T>& permutation, Func f){
        std::vector<short> directions(permutation.size(), -1); // -1 ~ left, +1 ~ right
        f(permutation);

        while(true){
            long largest_mobile_index {-1};

            for (size_t i {0}; i < permutation.size(); ++i) {
                long new_index = i + directions[i];
                if (new_index >= 0 && new_index < permutation.size() && permutation[i] > permutation[new_index]) {
                    if (largest_mobile_index == -1 || permutation[i] > permutation[largest_mobile_index])
                        largest_mobile_index = i;
                }
            }

            if (largest_mobile_index == -1) break;

            long move_index {largest_mobile_index + directions[largest_mobile_index]};

            std::swap(permutation[largest_mobile_index], permutation[move_index]);
            std::swap(directions[largest_mobile_index], directions[move_index]);

            largest_mobile_index ={move_index};

            for (size_t i {0}; i < directions.size(); ++i)
                if (permutation[i] > permutation[largest_mobile_index])
                    directions[i] *= -1;

            f(permutation);
        }
    }

    template<typename T, typename Func>
    void backtracking_algorithm(const std::vector<T>& source, std::vector<T>& current, size_t used_mask, Func f) {
        if (current.size() == source.size()) {
            f(current);
            return;
        }
    
        for (size_t i {0}; i < source.size(); ++i) {
            if ((used_mask & (1ULL << i)) == 0) {
                current.push_back(source[i]);
                backtracking_algorithm(source, current, used_mask | (1ULL << i), f);
                current.pop_back();
            }
        }
    }

    template<typename T, typename Func>
    void factorial_number_system_permutation_bitmask(const std::vector<T>& source, size_t index, Func f) {
        size_t n {source.size()};
        if (n > 64)
            throw std::invalid_argument("Bitmask implementation supports up to 64 elements.");

        std::vector<T> permutation;
        permutation.reserve(n);

        std::vector<size_t> factorials(n);
        factorials[0] = 1;
        for (size_t i {1}; i < n; ++i)
            factorials[i] = factorials[i - 1] * i;

        if (index >= factorials[n - 1] * n)
            throw std::out_of_range("Index exceeds total number of permutations");

        unsigned long long used_mask {0};

        for (size_t i {0}; i < n; ++i) {
            size_t factorial = factorials[n - 1 - i];
            size_t position = index / factorial;
            index %= factorial;

            size_t count {0};
            size_t element_index {0};
            for (; element_index < n; ++element_index) {
                if ((used_mask & (1ULL << element_index)) == 0) {
                    if (count == position) break;
                    ++count;
                }
            }

            permutation.push_back(source[element_index]);
            used_mask |= (1ULL << element_index);
        }

        f(permutation);
    }

}

#endif