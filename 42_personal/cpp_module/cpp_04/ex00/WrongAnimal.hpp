/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sna <sna@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/03 17:00:34 by sna               #+#    #+#             */
/*   Updated: 2022/04/03 17:27:59 by sna              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGANIMAL_HPP
# define WRONGANIMAL_HPP

# include <iostream>
# include <string>

/*
** makeSound에 virtual 키워드가 없어서
** 생성된 객체의 함수가 아닌 WrongAnimal 의 함수만 호출됨
*/
class WrongAnimal {
 private:

 protected:
	std::string _type;
 public:
	WrongAnimal(void);
	WrongAnimal(const WrongAnimal& obj);
	virtual ~WrongAnimal(void);
	WrongAnimal& operator=(const WrongAnimal& obj);

	void makeSound(void) const;//Animal 과 달리 virtual 키워드가 없음
	std::string getType(void) const;
	void		setType(const std::string& type);
};

#endif