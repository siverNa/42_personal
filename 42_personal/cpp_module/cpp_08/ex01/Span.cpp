/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sna <sna@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 20:53:46 by sna               #+#    #+#             */
/*   Updated: 2022/04/13 14:53:31 by sna              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span()
{
	_size = 0;
}

Span::Span(unsigned int n)
{
	_size = n;
}

Span::Span(const Span& obj)
{
	_size = obj.getSize();
	_vector = obj.getVector();
}

Span::~Span()
{

}

Span& Span::operator=(const Span& obj)
{
	_size = obj.getSize();
	_vector = obj.getVector();

	return (*this);
}

unsigned int Span::getSize() const
{
	return (_size);
}

std::vector<int> Span::getVector() const
{
	return (_vector);
}

void Span::addNumber(int n)
{
	//벡터 최대 사이즈까지 다 찼을 경우
	if (_vector.size() >= _size)
		throw Span::FullVectorException();
	_vector.push_back(n);
}

void Span::addNumber(std::vector<int>::iterator const& begin, std::vector<int>::iterator const& end)
{
	int vec_size = std::distance(begin, end);//두 구간의 거리가 얼마나 되는지 반환
	if (vec_size > static_cast<int>(_size) - static_cast<int>(_vector.size()))
		throw Span::FullVectorException();
	//insert : 원하는 위치에서부터 begin ~ end의 값을 붙여줌
	_vector.insert(_vector.end(), begin, end);
}

unsigned int Span::shortestSpan() const
{
	if (_vector.size() < 2)
		throw Span::NotFoundException();
	
	unsigned int shortSpan;
	std::vector<int> copy = _vector;
	std::sort(copy.begin(), copy.end());
	std::vector<int>::iterator l_iter = copy.begin();
	std::vector<int>::iterator r_iter = ++copy.begin();

	shortSpan = *r_iter - *l_iter;
	while (r_iter != copy.end())
	{
		if (static_cast<unsigned int>(*r_iter - *l_iter) < shortSpan)
			shortSpan = *r_iter - *l_iter;
		l_iter = r_iter;
		r_iter++;
	}
	return (shortSpan);
}

unsigned int Span::longestSpan() const
{
	if (_vector.size() < 2)
		throw Span::NotFoundException();

	std::vector<int> copy = _vector;
	std::sort(copy.begin(), copy.end());
	return (copy.back() - copy.front());
}

const char *Span::NotFoundException::what(void) const throw()
{
	return ("Not Found Exception.");
}

const char *Span::OutOfVectorRangeException::what(void) const throw()
{
	return ("Out Of Range Exception.");
}

const char *Span::FullVectorException::what(void) const throw()
{
	return ("Full Vector Exception.");
}