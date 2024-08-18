/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Mutantstack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smarty <smarty@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 15:06:29 by smarty            #+#    #+#             */
/*   Updated: 2024/05/03 01:03:02 by smarty           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <iostream>
#include <exception>
#include <stack>
#include <algorithm>

template<typename T>
class MutantStack : public std::stack<T>
{
public :
    typedef typename std::stack<T>::container_type::iterator iterator;
    typedef typename std::stack<T>::container_type::const_iterator const_iterator;

    MutantStack(void){

    }
    MutantStack(const MutantStack &src)
    {
        *this = *src;
        return *this;
    }
    ~MutantStack()
    {

    }
    MutantStack &operator=(MutantStack &src)
    {
        return  *src;
    }
    iterator begin() 
    {
        return this->c.begin(); 
    }
    iterator end() 
    { 
        return this->c.end();
    }
    const_iterator begin() const
    {
        return this->c.begin();
    }
    const_iterator end() const 
    {
        return this->c.end();
    }
};


#endif