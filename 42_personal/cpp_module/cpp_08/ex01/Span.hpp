/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sna <sna@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 20:53:36 by sna               #+#    #+#             */
/*   Updated: 2022/04/13 21:06:36 by sna              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_CPP
# define SPAN_CPP

# include <iostream>
# include <vector>
# include <algorithm>
# include <exception>

class Span {
 private:
	std::vector<int> 	_vector;
	unsigned int		_size;

 public:
	Span();
	Span(unsigned int n);
	Span(const Span& obj);
	~Span();
	Span& operator=(const Span& obj);

	unsigned int getSize() const;
	std::vector<int> getVector() const;

	void addNumber(int n);
	
	template <typename T>
	void addNumber(T const& begin, T const& end)
	{
		int vec_size = std::distance(begin, end);//두 구간의 거리가 얼마나 되는지 반환
		if (vec_size > static_cast<int>(_size) - static_cast<int>(_vector.size()))
			throw Span::FullVectorException();
		
		T temp = begin;
		while (temp != end)
		{
			_vector.push_back(*temp);
			temp++;
		}
	}

	unsigned int shortestSpan() const;
	unsigned int longestSpan() const;

	class NotFoundException : public std::exception {
		public:
			const char *what(void) const throw();
	};

	class FullVectorException : public std::exception {
		public:
			const char *what(void) const throw();
	};
};

#endif