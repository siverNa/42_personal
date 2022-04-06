/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sna <sna@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/03 18:04:22 by sna               #+#    #+#             */
/*   Updated: 2022/04/06 15:45:29 by sna              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
# define BRAIN_HPP

# include <iostream>
# include <string>

class Brain {
 private:
	std::string _idea[100];
 public:
	Brain();
	Brain(const Brain& obj);
	~Brain();
	Brain& operator=(const Brain& obj);

	std::string getIdea(const int& i) const;
	void		setIdea(const int& i, const std::string& idea);
};

#endif