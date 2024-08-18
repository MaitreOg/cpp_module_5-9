/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smarty <smarty@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 23:13:14 by smarty            #+#    #+#             */
/*   Updated: 2024/05/04 19:15:08 by smarty           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
#define RPN_HPP

#include <iostream>
#include <exception>
#include <list>
#include <algorithm>
#include <string>
#include <sstream>
class Rpn
{
private:
    std::list<std::string> rpn;
public :
    Rpn(std::list<std::string> rpn);
    Rpn(Rpn &src);
    ~Rpn();
    Rpn &operator=(Rpn &src);
    int lunch(void);
    int calcul(int v1, int v2, int op);
    class tooLarge : public std::exception
    {
    public:
        virtual const char* what() const throw();
    };
};


#endif