/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sna <sna@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/03 16:08:47 by sna               #+#    #+#             */
/*   Updated: 2022/04/03 19:54:28 by sna              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
# define CAT_HPP

# include "Animal.hpp"
# include "Brain.hpp"

class Cat: public Animal {
 private:
	Brain *_brain;

 public:
	Cat(void);
	Cat(const Cat& obj);
	virtual ~Cat(void);
	Cat& operator=(const Cat& obj);

	void	makeSound(void) const;
	Brain	*getBrain(void) const;
};

#endif