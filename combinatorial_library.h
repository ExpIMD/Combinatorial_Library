#ifndef __COMBINATORIAL_LIBRARY_
#define __COMBINATORIAL_LIBRARY_

#include <algorithm>
#include <iterator>
#include <stdexcept>

namespace IMD{

    namespace PERMUTATIONS{

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
        void Heap_recursion_algorithm(std::vector<T>& permutation, Func f, size_t n){
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
        void Heap_iterative_algorithm(std::vector<T>& permutation, Func f, size_t n){
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
    }
    

    namespace BINOMIAL {
        std::vector<std::vector<unsigned int>> Pascal_triangle(size_t rows);
    }

    namespace SEQUENCE{

        const double EPSILON{1e-8};

        class arithmetic_sequence{
        private:
            long long _current;
            long long _step;
        public:
            arithmetic_sequence(long long start, long long step) noexcept;
    
            long long current() const noexcept;
    
            void next() noexcept;
                
            void previous() noexcept;
    
            bool is_convergent() const noexcept;        
        };

        class geometric_sequence{
        private:
            double _current;
            double _ratio;
        public:
            geometric_sequence(double start, double ratio) noexcept;

            double current() const noexcept;
        
            void next() noexcept;
        
            void previous() noexcept;
        
            bool is_convergent() const noexcept;
        };

        class Fibonacci_sequence {
        public:
            Fibonacci_sequence() noexcept;
            
            long long current() const noexcept;
            
            void next() noexcept;
            
            void previous() noexcept;
            
            bool is_convergent() const noexcept;
            
        private:
            long long _previous;
            long long _current;
        };
    }
    
}

#endif