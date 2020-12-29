//
// Author: marvin on 5/13/20.
//

#ifndef FUNCIONES_H
#define FUNCIONES_H

#include "lib.h"
//parametros del template
// type parameter   T
// non type parameter  int n = 10
//template of template T
template <typename Numeric>
Numeric absolute(Numeric value);

template <typename Container,
        template<typename> class Result = vector>
Result<Container> split_range(Container cont, int n);

template <typename Container>
Container suma_rango(Container cnt1, Container cnt2);


/* delete_range */

template <typename Container, typename FilterType, typename CompareType>
Container delete_items(Container cnt, FilterType value, CompareType comparer);

template <typename T, template <typename ...> class Container>
Container<T> delete_items(Container<T> cnt, const T& value);

template <typename T, template <typename ...> class Container>
Container<T> delete_items(Container<T> cnt, const initializer_list<T>& lst);

/* -- */


#endif //FUNCIONES_H
