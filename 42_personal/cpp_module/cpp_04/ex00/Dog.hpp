/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sna <sna@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/03 15:59:30 by sna               #+#    #+#             */
/*   Updated: 2022/04/03 16:52:19 by sna              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
# define DOG_HPP

# include "Animal.hpp"

class Dog: public Animal {
 private:

 public:
	Dog(void);
	Dog(const Dog& obj);
	virtual ~Dog(void);
	Dog& operator=(const Dog& obj);

	void	makeSound(void) const;
};

#endif