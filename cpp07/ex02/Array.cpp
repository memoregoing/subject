//
// Created by namhyung kim on 2020/11/29.
//

#include "Array.hpp"

template<typename T>
Array<T>::Array():
	length(0), elts(nullptr)
{
}

template<typename T>
Array<T>::Array(size_t n):
	length(n), elts(nullptr)
{
	this->elts = new T[n]();
}

template<typename T>
Array<T>::Array(Array const &other):
	length(0), elts(nullptr)
{
	if (other.length > 0)
	{
		this->elts = new T[other.length]();
		for (size_t i = 0; i < other.length; i++)
			this->elts[i] = other.elts[i];
	}
	this->length = other.length;
}

template<typename T>
Array<T>::~Array()
{
	if (this->length > 0)
		delete[] this->elts;
}

template<typename T>
const char* Array<T>::OutOfBoundsException::what() const throw()
{
	return "ArrayException: index out of bounds";
}

// 대입 연산자의 의미를 생각 할 때 void형을 반환 해두 되지만 if ((i = array[i]) < y) 같은 문장을 사용하기 때문에
// 리턴 값을 주는게 인터페이스 차원에서 더 좋기 때문 입니다.
template<typename T>
Array<T> &Array<T>::operator=(Array<T> const &other)
{
	if (this->length > 0)
		delete[] this->elts;
	this->elts = nullptr;
	if (other.length > 0)
	{
		this->elts = new T[other.length]();
		for (size_t i = 0; i < other.length; i++)
			this->elts[i] = other.elts[i];
	}
	this->length = other.length;
	return (*this);
}

template<typename T>
T &Array<T>::operator[](size_t index)
{
	if (index >= this->length)
		throw Array::OutOfBoundsException();
	return (this->elts[index]);
}

template<typename T>
T const &Array<T>::operator[](size_t index) const
{
	return (operator[](index));
}

template<typename T>
size_t Array<T>::size(void) const
{
	return (this->length);
}
