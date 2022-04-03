/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sna <sna@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/03 15:16:12 by sna               #+#    #+#             */
/*   Updated: 2022/04/03 17:30:59 by sna              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main()
{
	//Animal
	std::cout << "[ Animal ]" << std::endl;
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
	}

	std::cout << "============================================================" << std::endl;

	//WrongAnimal
	std::cout << "[ WrongAnimal ]" << std::endl;
	{
		const WrongAnimal* meta = new WrongAnimal();
		const WrongAnimal* i = new WrongCat();

		std::cout << i->getType() << " " << std::endl;//Cat 타입
		i->makeSound(); //will output the animal sound!
		meta->makeSound();
		
		delete i;
		delete meta;
	}

	return 0;
}