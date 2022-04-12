/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sna <sna@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 16:21:25 by sna               #+#    #+#             */
/*   Updated: 2022/04/12 20:46:32 by sna              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
# define EASYFIND_HPP

# include <iostream>
# include <algorithm>
# include <vector>

class NotFoundException : public std::exception {
	public:
		const char *what(void) const throw()
		{
			return ("Not Found Exception.");
		}
};

/*
** iterator : 반복자. 이것을 사용해서 컨테이너에 저장된 원소를 순회하고 접근할 수 있음
** 쉽게 생각하면 '배열의 요소를 가리키는 포인터'
** 템플릿을 사용했기 때문에, 지정된 STL(T)의 iterator 를 가져와서 동작하게됨!
** .end() 함수는 마지막 요소 바로 뒤의 요소를 가리키는 반복자를 반환하므로 주의.
*/
template <typename T>
typename T::iterator easyfind(T& container, int value)
{
	typename T::iterator iter;
	
	iter = std::find(container.begin(), container.end(), value);
	if (iter == container.end())
		throw NotFoundException();
	return (iter);
}

#endif