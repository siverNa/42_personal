/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sna <sna@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/10 18:18:44 by sna               #+#    #+#             */
/*   Updated: 2022/04/10 18:31:26 by sna              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"

int main(void)
{
	std::string s_arr[4] = {"Hi", "i am", "sna", "nice meet you"};
	int i_arr[5] = {1, 2, 3, 4, 5};
	char c_arr[6] = {'a', 'b', 'c', 'd', 'e', 'f'};
	double d_arr[5] = {0.1, 1.1, 2.1, 3.1, 4.2};

	//나누는 sizeof 안에 std::string, int 등으로 넣어줘도 결과 동일
	::iter(s_arr, sizeof(s_arr) / sizeof(*s_arr), print);
	std::cout << std::endl;
	::iter(i_arr, sizeof(i_arr) / sizeof(*i_arr), print);
	std::cout << std::endl;
	::iter(c_arr, sizeof(c_arr) / sizeof(*c_arr), print);
	std::cout << std::endl;
	::iter(d_arr, sizeof(d_arr) / sizeof(*d_arr), print);

	return (0);
}