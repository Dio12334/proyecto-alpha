//
// Author: marvin on 5/13/20.
//


#include "funciones.h"

template <typename Numeric>
Numeric absolute(Numeric value) {
    return value >= 0 ? value : -value;
}

template <typename Container,
            template<typename> class Result = vector>
Result<Container> split_range(Container cont, int n) {
    Result<Container> result(n);
    auto range = cont.size()/n;
    auto start = begin(cont);
    for (auto &item : result) {
        auto stop = next(start, range);
        copy(start, stop, back_inserter(item));
        start = stop;
    }
    copy(start, end(cont), back_inserter(result.back()));
    return result;
}

template <typename Container>
Container suma_rango(Container cnt1, Container cnt2) {
    auto &max = cnt1.size() > cnt2.size() ? cnt1 : cnt2;
    auto &min = cnt1.size() < cnt2.size() ? cnt1 : cnt2;
    if (min.empty()) return max;
    auto current = begin(min);
    for (auto &item : max) {
        item += *(current++);
        current = current != end(min) ? current : begin(min);
    }
    return max;
}

template <typename Container, typename FilterType, typename CompareType>
Container delete_items(Container cnt, FilterType value, CompareType comparer) {
    auto current = begin(cnt);
    for (const auto& item : cnt) {
        if (comparer(item, value))
            *(current++) = item;
    }
    cnt.erase(current, end(cnt));
    return cnt;
}

template <typename T, template <typename ...> class Container>
Container<T> delete_items(Container<T> cnt, const T& value) {
    return delete_items(cnt, value, [](const T& item, const T& value){
        return item != value;
    });
}

template <typename T, template <typename ...> class Container>
Container<T> delete_items(Container<T> cnt, const initializer_list<T>& lst) {
    return delete_items(cnt, lst, [](const T& item, const initializer_list<T>& lst){
        return find(begin(lst), end(lst), item) == end(lst);
    });
}
