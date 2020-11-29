//
// Created by namhyung kim on 2020/11/28.
//

#ifndef CPP_ITER_HPP
#define CPP_ITER_HPP

#include <iostream>
#include <cctype>

// void 반환형이 없는 함수 포인터이며 매개변수로는 템플릿 const 타입의 래퍼런스 변수를 받습니다.
template<typename T>
void iter(T *arr, size_t length, void (*f)(T const &elt))
{
    for (size_t i = 0; i < length; i++)
        (*f)(arr[i]);
}
// for을 순환하면서 매개변수로 받은 함수에 arr[i]의 요소를 차례대로 넣습니다.

template<typename T>
void display(T const &value)
{
    std::cout << value << " 반복중! ";
}

#endif //CPP_ITER_HPP
