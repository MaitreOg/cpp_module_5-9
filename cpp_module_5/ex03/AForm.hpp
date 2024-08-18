/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smarty <smarty@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 23:18:44 by smarty            #+#    #+#             */
/*   Updated: 2024/08/18 05:09:37 by smarty           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
#define AFORM_HPP

#include <iostream>
#include <exception>
#include <string>
#include <fstream>
#include "Bureaucrat.hpp"

class Bureaucrat;
class   AForm
{
protected:
    std::string name;
    bool sign;
    const int required_s;
    const int required_e;
    AForm &operator=(const AForm &src);
    AForm(const AForm&);
public:
    AForm(const std::string name, const int rS, const int rE);
    virtual ~AForm(void) = 0;
    
    
    const int getRequiredS() const;
    const int getRequiredE() const;
    const std::string getName() const;
    bool getSigned() const;
    
    void setName(const std::string name);
    void setRequiredE(const int e);
    void setRequiredS(const int s);
    void setSigned(bool sign);

    
    void BeSigned(Bureaucrat &B);
    virtual void action() const = 0;
    void execute(Bureaucrat const & executor) const;
    friend std::ostream &operator<<(std::ostream & os,AForm &B);
    
    class GradeTooHighException : public std::exception
    {
    public:
        virtual const char* what() const throw();
    };

    class NotSign : public std::exception
    {
        virtual const char* what() const throw();
    };

    class GradeTooLowException : public std::exception 
    {
    public:
        virtual const char* what() const throw();
    };

    class isAlreadySigned : public std::exception 
    {
    public:
        virtual const char* what() const throw();
    };
};

#endif