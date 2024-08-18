/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smarty <smarty@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 16:51:11 by smarty            #+#    #+#             */
/*   Updated: 2024/04/29 21:55:50 by smarty           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
#define SPAN_HPP

#include <iostream>
#include <exception>
#include <vector>
#include <cstdlib> // Pour la fonction rand()
#include <ctime>
#include <unistd.h> 


class Span
{
private:
    std::vector<int> containers;
    int size;
public :
    Span(uintptr_t n);
    Span(const Span &src);
    ~Span();
    void addNumber(int value);
    int shortestSpan();
    int longestSpan();
    uintptr_t getLen();
    int getValue();
    void addMoreNumbers();
    void printSpan();
    Span &operator=(Span &src);
    class isFull : public std::exception
    {
    public:
        virtual const char* what() const throw();
    };
    class isEmpty : public std::exception
    {
    public:
        virtual const char* what() const throw();
    };
};


#endif