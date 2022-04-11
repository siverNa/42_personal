/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Convert.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sna <sna@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/08 20:09:03 by sna               #+#    #+#             */
/*   Updated: 2022/04/11 18:51:15 by sna              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Convert.hpp"

Convert::Convert()
{

}

Convert::Convert(std::string input)
{
	_sInput = input;
	_error = false;
	_dValue = 0.0;
	try
	{
		char	*ptr = NULL;
		_dValue = std::strtod(input.c_str(), &ptr);
		if (_dValue == 0.0 && (input[0] != '-' && input[0] != '+' && !std::isdigit(input[0])))
			throw (std::bad_alloc());
		if (*ptr && std::strcmp(ptr, "f"))
			throw (std::bad_alloc());
	}
	catch(std::exception &)
	{
		_error = true;
	}
	
}

Convert::Convert(const Convert& obj)
{
	_sInput = obj._sInput;
	_dValue = obj._dValue;
	_error = obj._error;
}

Convert::~Convert()
{

}

Convert& Convert::operator=(const Convert& obj)
{
	_sInput = obj._sInput;
	_dValue = obj._dValue;
	_error = obj._error;
	return (*this);
}

void	Convert::toChar()
{
	std::cout << "char: ";
	if (std::isnan(_dValue) || std::isinf(_dValue))
		std::cout << "Impossible";
	else if (std::isprint(static_cast<char>(_dValue)))
		std::cout << "'" << static_cast<char>(_dValue) << "'";
	else
		std::cout << "Non displayable";
	std::cout << std::endl;
}

void	Convert::toInt()
{
	std::cout << "int: ";
	if (std::isnan(_dValue) || std::isinf(_dValue) || _dValue > std::numeric_limits<int>::max())
		std::cout << "Impossible";
	else
		std::cout << static_cast<int>(_dValue);
	std::cout << std::endl;
}

void	Convert::toFloat()
{
	float f = static_cast<float>(_dValue);

	std::cout << "float: ";
	if (std::isnan(_dValue) || std::isinf(_dValue) || _dValue > std::numeric_limits<float>::max())
		std::cout << std::showpos << f << "f";
	else if (f == static_cast<int64_t>(f))
		std::cout << f << ".0f";
	else
		std::cout << std::setprecision(std::numeric_limits<float>::digits10) << f << 'f';
	std::cout << std::endl;
}

void	Convert::toDouble()
{
	double d = static_cast<double>(_dValue);

	std::cout << "double: ";
	if (std::isnan(_dValue) || std::isinf(_dValue))
		std::cout << std::showpos << d;
	else if (d == static_cast<int64_t>(d))
		std::cout << d << ".0";
	else
		std::cout << std::setprecision(std::numeric_limits<double>::digits10) << d;
	std::cout << std::endl;
}

bool	Convert::getError() const
{
	return (_error);
}