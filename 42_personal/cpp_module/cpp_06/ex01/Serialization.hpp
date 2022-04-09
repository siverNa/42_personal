/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serialization.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sna <sna@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/09 20:03:27 by sna               #+#    #+#             */
/*   Updated: 2022/04/09 21:03:02 by sna              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERIALIZATION_HPP
# define SERIALIZATION_HPP

# include <iostream>
# include <string>

class Serialization {
 private:
 public:
	Serialization();
	Serialization(const Serialization& obj);
	~Serialization();
	Serialization& operator=(const Serialization& obj);
};

typedef struct	s_Data
{
	std::string data;
}				Data;

uintptr_t serialize(Data* ptr);
Data* deserialize(uintptr_t raw);

#endif