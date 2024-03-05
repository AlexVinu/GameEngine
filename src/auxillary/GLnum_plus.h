#pragma once
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>


template<typename T>
class num_plus {
	T* num;
public:
	num_plus();/*void constructor*/
	num_plus(T num);/*constructor with num*/

	/*special operators*/
	num_plus& operator = (const T& num); /*makes num from simple or OpenGL type*/
	friend std::ostream& operator << (std::ostream& os, const num_plus<T>& obj) { return os << *obj.num; }; /*ostream operator, it works only if defined in class, must be friendly because it is free from class(overloaded << and >> operators must free from class, but may be defined in class)*/
	/*--------------*/
	/*special constructors*/
	num_plus(num_plus&& obj) noexcept; /*move constructor*/
	/*------------*/
};

template<typename T>
inline num_plus<T>::num_plus()
{
	this->num = new T;
}

template<typename T>
inline num_plus<T>::num_plus(T num)
{
	this->num = new T;
	*this->num = num;
}

template<typename T>
num_plus<T>& num_plus<T>::operator=(const T& num)
{
	this->num = new T;
	*this->num = num;
	return *this;
}

template<typename T>
num_plus<T>::num_plus(num_plus&& obj) noexcept
{
	this->num = new T;
	*this->num = *obj.num;
	delete obj.num;
}
