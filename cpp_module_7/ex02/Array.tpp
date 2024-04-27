/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.tpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smarty <smarty@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 15:20:02 by smarty            #+#    #+#             */
/*   Updated: 2024/04/27 17:52:39 by smarty           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_TPP
#define ARRAY_TPP

template<typename T>
Array<T>::Array() : array(nullptr), len(0)
{
    std::cout << "constructor called" << std::endl;
}

template<typename T>
Array<T>::Array(uintptr_t n) : len(n)
{
    std::cout << "uintptr constructor called" << std::endl;
    this->array = new T[n];
for (uintptr_t i = 0; i < n; ++i)
        this->array[i] = 0; // Initialisation des éléments à zéro
}

template<typename T>
Array<T>::Array(const Array<T> &src) : len(src.size())
{
    std::cout << "copy constructor called" << std::endl;
    this->array = new T[src.size()];
    for (int i = 0; i < src.size(); i++)
        this->array[i] = src.getTab(i);
}

template<typename T>
Array<T>::~Array()
{
    std::cout << "destructor called" << std::endl;
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
    return (*this)[n];
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
