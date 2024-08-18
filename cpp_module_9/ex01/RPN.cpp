/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smarty <smarty@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 23:13:17 by smarty            #+#    #+#             */
/*   Updated: 2024/05/14 16:14:49 by smarty           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

Rpn::Rpn(std::list<std::string> rpn) : rpn(rpn)
{
}
Rpn::Rpn(Rpn &src)
{
    *this = src;
}
Rpn::~Rpn()
{

}
Rpn &Rpn::operator=(Rpn &src)
{
    *this = src;
    return *this;
}

int Rpn::calcul(int v1, int v2, int op)
{
    if (op == '-')
        return (v2 - v1);
    if (op == '+')
        return (v2 + v1);
    if (op == '*')
        return (v2 * v1);
    if (op == '/')
        return (v2 / v1);
}


int Rpn::lunch(void)
{
    std::list<int> pile;
    std::list<std::string>::iterator it;
    for (it = this->rpn.begin(); it != this->rpn.end(); ++it)
    {
        int ok = 0;
        if ((*it)[0] >= '0' && (*it)[0] <= '9')
        {   
            pile.push_back(std::stoi(*it));
        }
        else if ((*it)[0] == '+' || (*it)[0] == '-' || (*it)[0] == '/' || (*it)[0] == '*')
        {   
            if (pile.size() < 2)
                return -100000;
            int value1 = pile.back();
            pile.pop_back();
            int value2 = pile.back();
            pile.pop_back();
            int tmp_result = calcul(value1, value2, (*it)[0]);
            pile.push_back(tmp_result)  ;       
        }
        else
            return -100000;
        //std::cout << value1 << "  " << value2 << "  " << op << std::endl;

    }
    if (pile.size() != 1)
    {
        return -100000;
    }

    return  pile.back();
}
