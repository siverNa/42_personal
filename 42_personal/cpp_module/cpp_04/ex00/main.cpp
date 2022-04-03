/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sna <sna@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/03 15:16:12 by sna               #+#    #+#             */
/*   Updated: 2022/04/03 16:53:58 by sna              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

int main()
{
    const Animal* meta = new Animal();
    const Animal* j = new Dog();
    const Animal* i = new Cat();

    std::cout << j->getType() << " " << std::endl;//Dog 타입
    std::cout << i->getType() << " " << std::endl;//Cat 타입
    i->makeSound(); //will output the cat sound!
    j->makeSound();
    meta->makeSound();
    
    delete j;
    delete i;
    delete meta;

    return 0;
}