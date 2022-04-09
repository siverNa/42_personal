/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sna <sna@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/09 21:17:15 by sna               #+#    #+#             */
/*   Updated: 2022/04/09 21:29:51 by sna              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BASE_HPP
# define BASE_HPP

# include <iostream>
# include <string>
# include <cstdlib>
# include <ctime>
# include <exception>

class Base {
 public:
	virtual ~Base() {};
};

class A : public Base {

};

class B : public Base {

};

class C : public Base {

};

Base * generate(void);
void identify(Base* p);
void identify(Base& p);

#endif