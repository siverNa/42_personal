/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sna <sna@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/13 15:56:33 by sna               #+#    #+#             */
/*   Updated: 2022/04/13 17:20:36 by sna              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

# include <iostream>
# include <stack>
# include <deque>

template <typename T>
class MutantStack : public std::stack<T> {
 private:
 public:
	MutantStack(void)
	{
		
	};

	MutantStack(const MutantStack& obj)
	{
		*this = obj;
	};

	virtual ~MutantStack(void)
	{

	};

	MutantStack& operator=(const MutantStack& obj)
	{
		std::stack<T>::operator=(obj);
		return (*this);
	};

	typedef typename std::stack<T>::container_type::iterator	iterator;

	iterator		begin(void)
	{
		return (this->c.begin());
	}

	iterator		end(void)
	{
		return (this->c.end());
	}
};

#endif