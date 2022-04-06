/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sna <sna@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/03 15:16:12 by sna               #+#    #+#             */
/*   Updated: 2022/04/06 15:49:51 by sna              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "Brain.hpp"

int main()
{
	{
		const Animal* j = new Dog();
		const Animal* i = new Cat();
		
		std::cout << std::endl;
		j->makeSound();
		i->makeSound();
		
		std::cout << std::endl;

		delete j;//should not create a leak
		delete i;
	}

	std::cout << "=========================================" << std::endl;
	
	{
		Animal *animal[10];

		for (int i = 0; i < 10; i++)
		{
			if (i < 5)
				animal[i] = new Dog();
			else
				animal[i] = new Cat();
		}

		std::cout << std::endl;
		for (int i = 0; i < 10; i++)
			std::cout << animal[i]->getType() << std::endl;

		std::cout << std::endl;
		Dog test(*(Dog *)animal[3]);
		std::cout << "animal[3]'s type : " << animal[3]->getType() << std::endl;
		std::cout << "animal[3]'s brain : " << ((Dog *)animal[3])->getBrain()->getIdea(1) << std::endl;
		std::cout << "test's type : " << test.getType() << std::endl;
		std::cout << "test's brain : " << test.getBrain()->getIdea(1) << std::endl;
		
		std::cout << std::endl;
		for (int i = 0; i < 10; i++)
			delete animal[i];

		std::cout << std::endl;
		std::cout << "test's type : " << test.getType() << std::endl;
		std::cout << "test's brain : " << test.getBrain()->getIdea(1) << std::endl;
	}

	return 0;
}