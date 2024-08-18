/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smarty <smarty@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 17:02:55 by smarty            #+#    #+#             */
/*   Updated: 2024/08/18 05:03:02 by smarty           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include <exception>
#include <string>
#include "AForm.hpp"
class AForm;

class   Bureaucrat
{
private:
    const std::string name;
    int grade;
public:
    Bureaucrat(const std::string name, int grade);
    Bureaucrat(const Bureaucrat &src);
    ~Bureaucrat(void);
    
    
    friend std::ostream &operator<<(std::ostream & os,Bureaucrat &B);
    Bureaucrat &operator=(const Bureaucrat &src);
    
    void setName(const std::string str);
    int getGrade() const;
    const std::string getName() const;
    
    void    promote();
    void    regress();
    void    signForm(AForm &form);
    void    executeForm(AForm const & form) const;
   
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