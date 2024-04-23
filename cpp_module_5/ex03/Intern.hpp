/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smarty <smarty@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/21 00:53:01 by smarty            #+#    #+#             */
/*   Updated: 2024/04/23 17:57:20 by smarty           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
#define INTERN_HPP

#include <iostream>
#include <string>
#include <map>
class AForm;

class   Intern
{
private:

public:
    Intern();
    Intern(const std::string name, int grade);
    Intern(Intern &src);
    ~Intern(void);
    Intern &operator=(Intern &src);

    AForm* makeForm(std::string nameForm, std::string target);
};

#endif