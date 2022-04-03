/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sna <sna@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/03 17:13:36 by sna               #+#    #+#             */
/*   Updated: 2022/04/03 17:17:19 by sna              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGCAT_HPP
# define WRONGCAT_HPP

# include "WrongAnimal.hpp"

class WrongCat: public WrongAnimal {
 private:
 public:
	WrongCat(void);
	WrongCat(const WrongCat& obj);
	virtual ~WrongCat(void);
	WrongCat& operator=(const WrongCat& obj);

	void makeSound(void) const;//부모 클래스의 함수에 virtual이 없어서 overriding이 안됨
};

#endif