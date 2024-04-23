/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smarty <smarty@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 23:18:44 by smarty            #+#    #+#             */
/*   Updated: 2024/04/19 23:47:36 by smarty           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>
#include <exception>
#include <string>
#include "Bureaucrat.hpp"


class   Form
{
private:
    const std::string name;
    bool sign;
    const int required_s;
    const int required_e;

public:
    Form(const std::string name, const int rS, const int rE);
    Form(const Form &src);
    ~Form(void);
    const int getRequiredS() const;
    const int getRequiredE() const;
    const std::string getName() const;
    bool getSigned() const;
    void BeSigned(Bureaucrat &B);
    friend std::ostream &operator<<(std::ostream & os,Form &B);
    
    class GradeTooHighException : public std::exception
    {
    public:
        virtual const char* what() const throw();
    };

    class GradeTooLowException : public std::exception 
    {
    public:
        virtual const char* what() const throw();
    };

};

#endif