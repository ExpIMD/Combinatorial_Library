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
        template<typename T>
        void Heap_recursion_algorithm(std::vector<T>& permutation, std::vector<std::vector<T>>& result, size_t n){
            if (n > permutation.size())
                throw std::runtime_error("n > permutation.size()");

            if (n == 1){
                result.push_back(permutation);
                return;
            }
            
            for(size_t i{0}; i < n; ++i){
                Heap_recursion_algorithm(permutation, n - 1, result);
                if (n % 2 == 0)
                    std::swap(permutation[i], permutation[n-1]);
                else std::swap(permutation[0], permutation[n-1]);
            }
        }

        template<typename T>
        void Heap_iterative_algorithm(std::vector<T>& permutation, std::vector<std::vector<T>>& result, size_t n){
            if (n > permutation.size())
                throw std::runtime_error("n > permutation.size()");

            std::vector<size_t> c(n, 0);
            result.push_back(permutation);

            size_t i {0};
            while (i < n) {
                if (c[i] < i) {
                    if (i % 2 == 0) {
                        std::swap(permutation[0], permutation[i]);
                    } else {
                        std::swap(permutation[c[i]], permutation[i]);
                    }
                    result.push_back(permutation);
                    c[i]++;
                    i = 0;
                } else {
                    c[i] = 0;
                    i++;
                }
            }
        }

        template<typename T>
        void Johnson_Trotter_algorithm(std::vector<T>& permutation, std::vector<std::vector<T>>& result){
            std::vector<short> directions(permutation.size(), -1); // -1 ~ left, +1 ~ right
            result.push_back(permutation);

            while(true){
                int largest_mobile_index = -1;

                for (size_t i {0}; i < permutation.size(); ++i) {
                    int new_index = i + directions[i];
                    if (new_index >= 0 && new_index < permutation.size() && permutation[i] > permutation[new_index]) {
                        if (largest_mobile_index == -1 || permutation[i] > permutation[largest_mobile_index])
                            largest_mobile_index = i;
                    }
                }


                if (largest_mobile_index == -1) break;

                int move_index {largest_mobile_index + directions[largest_mobile_index]};
                std::swap(permutation[largest_mobile_index], permutation[move_index]);
                std::swap(directions[largest_mobile_index], directions[move_index]);

                // Обновляем индекс перемещенного элемента
                largest_mobile_index = move_index;

                // После обмена меняем направление у всех элементов больше перемещенного
                for (size_t i = 0; i < directions.size(); ++i) {
                    if (permutation[i] > permutation[largest_mobile_index]) {
                        directions[i] *= -1;
                    }
                }


                result.push_back(permutation);
            }
        }
    }
}