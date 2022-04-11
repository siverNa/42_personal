/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Convert.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sna <sna@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/08 20:09:03 by sna               #+#    #+#             */
/*   Updated: 2022/04/11 18:14:58 by sna              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Convert.hpp"

Convert::Convert()
{

}

Convert::Convert(std::string input)
{
	_sInput = input;
	try
	{
		char	*ptr = NULL;
		_dValue = std::strtod(input.c_str(), &ptr);
		if (_dValue == 0.0 && (input[0] != '-' && input[0] != '+' && !std::isdigit(input[0])))
			throw (std::bad_alloc());
		if (*ptr && std::strcmp(ptr, "f"))
			throw (std::bad_alloc());
	}
	catch(...)
	{
		_isImpossible = true;
	}
	
}

Convert::Convert(const Convert& obj)
{
	_sInput = obj._sInput;
	_dValue = obj._dValue;
	_isImpossible = obj._isImpossible;
}

Convert::~Convert()
{

}

Convert& Convert::operator=(const Convert& obj)
{
	_sInput = obj._sInput;
	_dValue = obj._dValue;
	_isImpossible = obj._isImpossible;
	return (*this);
}

void	Convert::toChar()
{
	std::cout << "char: ";
	if (std::isnan(_dValue) || std::isinf(_dValue))
		std::cout << "Impossible";
	else if (std::isprint(_dValue) == false)
		std::cout << "Non displayable";
	else
		std::cout << "'" << static_cast<char>(_dValue) << "'";
	std::cout << std::endl;
}

void	Convert::toInt()
{
	std::cout << "int: ";
	if (std::isnan(_dValue) || _dValue > std::numeric_limits<int>::max() || std::isinf(_dValue))
		std::cout << "Impossible";
	else
		std::cout << static_cast<int>(_dValue);
	std::cout << std::endl;
}

void	Convert::toFloat()
{
	std::cout << "float: ";
	if (std::isnan(_dValue) || std::isinf(_dValue) ||_dValue > std::numeric_limits<float>::max())
		std::cout << std::showpos << static_cast<float>(_dValue) << "f";
	else
		std::cout << static_cast<float>(_dValue) << 'f';
	std::cout << std::endl;
}

void	Convert::toDouble()
{
	std::cout << "double: ";
	if (std::isnan(_dValue) || std::isinf(_dValue))
		std::cout << std::showpos << static_cast<float>(_dValue);
	else
		std::cout << static_cast<double>(_dValue);
	std::cout << std::endl;
}