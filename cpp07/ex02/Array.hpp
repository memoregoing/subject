//
// Created by namhyung kim on 2020/11/29.
//

#ifndef ARRAY_HPP
# define ARRAY_HPP

#include <iostream>
#include <string>
# include <exception>
# include <cctype>

template<typename T>
class Array
{
private:
	size_t length;
	T *elts;
public:
	Array();  //매개변수가 없는 빈 배열을 만드는 생성자 - Construction with no parameter: creates an empty array
	Array(size_t n); // size_t가 unsgined int의 typedef 입니다. Construction with an unsigned int n as a parameter:
	Array(Array<T> const &other);
	virtual ~Array();

    // exeception을 상속 받아 이 클레스의 고유의 애러처리를 위해 이렇게 합니다
	class OutOfBoundsException: public std::exception {
		virtual const char* what() const throw();
	};

	Array &operator=(Array const &other); // 할당 연산자에 관한 연산자 오버로딩 이를 통해 사용자가 정의한 클레스에 할당 연산자 사용 가능
	// 왜 같은 연산자가 두번 있는가?
	// 클레스에 첨자 연산자가 있으면 일반적으로 보통의 참조자를 반환 하는 것과 const맴버이면서 const에 대한 참조를 반환 하는 것 두 버전을 둘다 정의한다.
	T &operator[](size_t index); // []연산자 오버로
	T const &operator[](size_t index) const; //[]연산자 오버로딩

	size_t size(void) const;
};

# include "Array.cpp"

#endif
