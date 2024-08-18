/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smarty <smarty@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 15:04:17 by smarty            #+#    #+#             */
/*   Updated: 2024/08/18 23:23:06 by smarty           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <iostream>
#include <exception>


template<typename T>
class Array
{
private:
    T* array;
    uintptr_t len;
public :
    Array();
    Array(uintptr_t n);
    Array(const Array &src);
    ~Array();
    uintptr_t size() const;
    T getTab(uintptr_t n) const;
    Array &operator=(Array &src);
    T &operator[](uintptr_t n) const;
    class outBound : public std::exception
    {
    public:
        virtual const char* what() const throw();
    };

};

template<typename T>
Array<T>::Array() : array(nullptr), len(0)
{
}

template<typename T>
Array<T>::Array(uintptr_t n) : len(n)
{
    this->array = new T[n];
for (uintptr_t i = 0; i < n; ++i)
        this->array[i] = 0; // Initialisation des éléments à zéro
}

template<typename T>
Array<T>::Array(const Array<T> &src) : len(src.size())
{
    this->array = new T[src.size()];
    for (int i = 0; i < src.size(); i++)
        this->array[i] = src.getTab(i);
}

template<typename T>
Array<T>::~Array()
{
    delete[] this->array;
}

template<typename T>
uintptr_t Array<T>::size() const
{
    return this->len;
}

template<typename T>
T Array<T>::getTab(uintptr_t n) const
{
    if (n >= this->size())
        throw outBound();
    return (this->array[n]);
}

template<typename T>
Array<T> &Array<T>::operator=(Array<T> &src)
{
    if (this->array[0])
        delete[] this->array;
    this->array = new T[src.size()];
    for (int i = 0; i < src.size(); i++)
        this->array[i] = src.getTab(i);
    return  *this;
}

template<typename T>
T &Array<T>::operator[](uintptr_t n) const
{
    if (n >= this->size())
    {
        throw outBound();
    }
    return this->array[n]; 
}

template<typename T>
const char* Array<T>::outBound::what() const throw()
{
    return "out of bounds";
}
#endif