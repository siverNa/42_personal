/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sna <sna@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 20:53:36 by sna               #+#    #+#             */
/*   Updated: 2022/04/13 15:51:14 by sna              ###   ########.fr       */
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
	void addNumber(std::vector<int>::iterator const& begin, std::vector<int>::iterator const& end);

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