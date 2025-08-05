#include <algorithm>
#include <iterator>

template<typename Iterator>
bool narayana_algorithm(Iterator begin, Iterator end) {
    auto j = std::prev(end);

    while(j != begin){
        if (*std::prev(j) < *j) break;
        --j;
    }

    if (j == begin)
        return false;

    auto l = std::prev(end);

    while(l != begin){
        if (*std::prev(j) < *l) break;
        --l;
    }

    std::iter_swap(l, std::prev(j));

    std::reverse(j, end);
    return true;
}
