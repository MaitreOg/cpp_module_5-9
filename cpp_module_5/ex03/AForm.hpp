/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smarty <smarty@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 23:18:44 by smarty            #+#    #+#             */
/*   Updated: 2024/04/20 21:30:10 by smarty           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
#define AFORM_HPP

#include <iostream>
#include <exception>
#include <string>
#include <fstream>
#include "Bureaucrat.hpp"


class   AForm
{
protected:
    std::string name;
    bool sign;
    const int required_s;
    const int required_e;
    AForm &operator=(AForm &src);
    AForm(const AForm&);
public:
    AForm(const std::string name, const int rS, const int rE);
    virtual ~AForm(void);
    const int getRequiredS() const;
    const int getRequiredE() const;
    const std::string getName() const;
    bool getSigned() const;
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

};

#endif