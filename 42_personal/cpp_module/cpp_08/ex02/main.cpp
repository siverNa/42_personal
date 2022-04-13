/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sna <sna@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 16:12:58 by sna               #+#    #+#             */
/*   Updated: 2022/04/13 18:30:40 by sna              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"

int main(void)
{
	std::cout << "=================== normal iterator ======================" << std::endl;
	{
		MutantStack<int> mstack;

		mstack.push(5);
		mstack.push(17);

		std::cout << mstack.top() << std::endl;

		mstack.pop();

		std::cout << mstack.size() << std::endl;

		mstack.push(3);
		mstack.push(5);
		mstack.push(737);
		//[...]
		mstack.push(0);

		MutantStack<int>::iterator it = mstack.begin();
		MutantStack<int>::iterator ite = mstack.end();

		++it;
		--it;
		while (it != ite)
		{
			std::cout << *it << std::endl;
			++it;
		}
		std::stack<int> s(mstack);
	}

	std::cout << "=================== reverse iterator ======================" << std::endl;
	{
		MutantStack<double> mstack;

		mstack.push(1.0);
		mstack.push(2.0);
		mstack.push(3.0);
		mstack.push(4.0);
		mstack.push(5.0);
		
		MutantStack<double>::reverse_iterator rit = mstack.rbegin();
		MutantStack<double>::reverse_iterator rite = mstack.rend();
		++rit;
		--rit;
		while (rit != rite) {
			std::cout << *rit << std::endl;
			++rit;
		}
	}
	return 0;
}