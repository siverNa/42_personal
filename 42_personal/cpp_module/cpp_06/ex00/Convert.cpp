/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Convert.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sna <sna@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/08 20:09:03 by sna               #+#    #+#             */
/*   Updated: 2022/04/09 19:18:22 by sna              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Convert.hpp"

Convert::Convert()
{

}

Convert::Convert(char* input)
{
	_cInput = input;
	_sInput = static_cast<std::string>(input);
	char	*ptr = NULL;
	try
	{
		_dValue = strtod(input, &ptr);
	}
	catch(...)
	{
		_isImpossible = true;
	}
	
}

Convert::Convert(const Convert& obj)
{
	_cInput = obj._cInput;
	_sInput = obj._sInput;
	_dValue = obj._dValue;
	_isImpossible = obj._isImpossible;
}

Convert::~Convert()
{

}

Convert& Convert::operator=(const Convert& obj)
{
	_cInput = obj._cInput;
	_sInput = obj._sInput;
	_dValue = obj._dValue;
	_isImpossible = obj._isImpossible;
	return (*this);
}

void	Convert::toChar()
{
	std::cout << "char: ";
	if (_isImpossible || std::isnan(_dValue) || std::isinf(_dValue))
		std::cout << "Impossible";
	else if (isprint(_dValue) == false)
		std::cout << "Non displayable";
	else
		std::cout << "'" << static_cast<char>(_dValue) << "'";
	std::cout << std::endl;
}

void	Convert::toInt()
{
	std::cout << "int: ";
	if (_isImpossible || std::isnan(_dValue) || _dValue > std::numeric_limits<int>::max() || std::isinf(_dValue))
		std::cout << "Impossible";
	else
		std::cout << static_cast<int>(_dValue);
	std::cout << std::endl;
}

void	Convert::toFloat()
{
	std::cout << "float: ";
	if (_isImpossible || std::isnan(_dValue) || std::isinf(_dValue) ||_dValue > std::numeric_limits<float>::max())
		std::cout << std::showpos << static_cast<float>(_dValue) << "f";
	else
		std::cout << static_cast<float>(_dValue) << 'f';
	std::cout << std::endl;
}

void	Convert::toDouble()
{
	std::cout << "double: ";
	if (_isImpossible || std::isnan(_dValue) || std::isinf(_dValue) ||_dValue > std::numeric_limits<float>::max())
		std::cout << std::showpos << static_cast<float>(_dValue);
	else
		std::cout << static_cast<double>(_dValue);
	std::cout << std::endl;
}