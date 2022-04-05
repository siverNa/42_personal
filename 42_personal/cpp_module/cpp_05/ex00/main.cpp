/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sna <sna@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 20:59:31 by sna               #+#    #+#             */
/*   Updated: 2022/04/05 21:08:55 by sna              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main(void)
{
    try
    {
        Bureaucrat employee("yohan", 10);
        std::cout << employee << std::endl;
    }
    catch(std::exception & e)
    {
        std::cerr << e.what() << '\n';
    }
    
}