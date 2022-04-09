/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Convert.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sna <sna@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/08 20:09:06 by sna               #+#    #+#             */
/*   Updated: 2022/04/09 17:26:21 by sna              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONVERT_HPP
# define CONVERT_HPP

# include <iostream>
# include <string>
# include <cmath>
# include <cfloat>
# include <limits>

class Convert {
 private:
	char* 			_cInput;
	std::string 	_sInput;
	double 			_dValue;
	bool			_isImpossible;
 public:
	Convert();
	Convert(char* input);
	Convert(const Convert& obj);
	~Convert();
	Convert& operator=(const Convert& obj);

	void	toChar();
	void	toInt();
	void	toFloat();
	void	toDouble();

	class ImpossibleException : public std::exception
	{
		public:
			const char *what(void) const throw();
	};

	class NonDisplayableException : public std::exception
	{
		public:
			const char *what(void) const throw();
	};
};

#endif