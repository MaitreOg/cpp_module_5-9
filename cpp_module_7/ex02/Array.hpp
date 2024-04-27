/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smarty <smarty@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 15:04:17 by smarty            #+#    #+#             */
/*   Updated: 2024/04/27 17:48:35 by smarty           ###   ########.fr       */
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


#endif