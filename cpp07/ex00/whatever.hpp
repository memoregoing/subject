//
// Created by namhyung kim on 2020/11/28.
//

#ifndef CPP_WHATEVER_HPP
#define CPP_WHATEVER_HPP

#include <iostream>
//template <typename T> 와 template <class T>
// 는 정확히 같은 의미를 같지만 되도록이면 typename 키워드를 사용하기를 권장합니다.

template<typename T>
void swap(T &a, T &b)
{
    T tmp = a;
    a = b;
    b = tmp;
}

template<typename T>
T &min(T &a, T &b)
{
    if (b > a)
        return (a);
    return (b);
}

template<typename T>
T &max(T &a, T &b)
{
    if (a > b)
        return (a);
    return (b);
}

#endif //CPP_WHATEVER_HPP
