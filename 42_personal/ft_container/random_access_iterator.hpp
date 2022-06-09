/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   random_access_iterator.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sna <sna@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/08 18:33:52 by sna               #+#    #+#             */
/*   Updated: 2022/06/09 20:41:46 by sna              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RANDOM_ACCESS_ITERATOR_HPP
# define RANDOM_ACCESS_ITERATOR_HPP

# include "iterator.hpp"
# include "util.hpp"

namespace ft
{
	template <class T>
	class random_access_iterator : public ft::iterator<ft::random_access_iterator_tag, T> {
		public:
			typedef typename ft::iterator<ft::random_access_iterator_tag, T>::iterator_category	iterator_category;
			typedef typename ft::iterator<ft::random_access_iterator_tag, T>::value_type		value_type;
			typedef typename ft::iterator<ft::random_access_iterator_tag, T>::difference_type	difference_type;
			typedef typename ft::iterator<ft::random_access_iterator_tag, T>::pointer			pointer;
			typedef typename ft::iterator<ft::random_access_iterator_tag, T>::reference			reference;
		
		protected:
			pointer	_pointer;
		
		public:
			/**
			 * @brief default constructor
			 */
			random_access_iterator(pointer _pointer = ft::u_nullptr) : _pointer(_pointer)
			{};

			/**
			 * @brief copy constructor
			 */
			random_access_iterator(const random_access_iterator<T>& obj) : _pointer(obj._pointer)
			{};

			pointer const& base() const
			{
				return (this->_pointer);
			};

			/**
			 * @brief random_access_iterator<const T> operator cast
			 * @return random_access_iterator<const T>
			 */
			operator random_access_iterator<const T>() const
			{
				return (this->_pointer);
			};

			/**
			 * @brief Returns a reference to the element pointed to by the iterator.
			 */
			reference operator*() const
			{
				return (*_pointer);
			};

			/**
			 * @brief Returns a pointer to the element pointed
			 * (in order to access one of its members).
			 */
			pointer operator->() const
			{
				return (&(operator*()));
			};

			/**
			 * @brief Advances the random_access_iterator by one position.(전위 증가연산자)
			 * @example ++_pointer;
			 */
			random_access_iterator& operator++()
			{
				++_pointer;
				return (*this);
			};

			/**
			 * @brief Advances the random_access_iterator by one position.(후위 증가연산자)
			 * @example ++_pointer;
			 */
			random_access_iterator operator++(int)
			{
				random_access_iterator temp = *this;
				++(*this);
				return (temp);
			};

			/**
			 * @brief Returns a iterator pointing to the _pointer located n positions away 
			 * from the _pointer the iterator currently points to.
			 */
			random_access_iterator operator+(difference_type n) const
			{
				return (random_access_iterator(this->_pointer + n));
			};

			/**
			 * @brief Advances the random_access_iteratorr by n _pointer positions.
			 */
			random_access_iterator& operator+= (difference_type n)
			{
				this->_pointer += n;
				return (*this);
			};

			/**
			 * @brief Decreases the random_access_iterator by one position.(전위 감소연산자)
			 * @example --_pointer;
			 */
			random_access_iterator& operator--()
			{
				--_pointer;
				return (*this);
			};

			/**
			 * @brief Decreases the random_access_iterator by one position.(후위 감소연산자)
			 * @example _pointer--;
			 */
			random_access_iterator operator--(int)
			{
				random_access_iterator temp = *this;
				--(*this);
				return (temp);
			};

			/**
			 * @brief Returns a iterator pointing to the _pointer located n positions
			 * before the _pointer the iterator currently points to.
			 */
			random_access_iterator operator- (difference_type n) const
			{
				return (random_access_iterator(this->_pointer - n));
			};

			/**
			 * @brief Advances the random_access_iterator by n _pointer positions.
			 */
			random_access_iterator& operator-= (difference_type n)
			{
				this->_pointer -= n;
				return (*this);
			};

			reference operator[] (difference_type n) const
			{
				return (this->_pointer[n]);
			};
	};

	/**
	 * @brief Relational operators== for random_access_iterator
	 */
	template <class Iterator>
	bool operator== (const random_access_iterator<Iterator>& lhs,
					const random_access_iterator<Iterator>& rhs)
	{
		return (lhs.base() == rhs.base());
	};

	/**
	 * @brief Relational operators!= for random_access_iterator
	 */
	template <class Iterator>
	bool operator!= (const random_access_iterator<Iterator>& lhs,
					const random_access_iterator<Iterator>& rhs)
	{
		return (lhs.base() != rhs.base());
	};

	/**
	 * @brief Relational operators< for random_access_iterator
	 */
	template <class Iterator>
	bool operator< (const random_access_iterator<Iterator>& lhs,
					const random_access_iterator<Iterator>& rhs)
	{
		return (lhs.base() < rhs.base());
	};

	/**
	 * @brief Relational operators<= for random_access_iterator
	 */
	template <class Iterator>
	bool operator<= (const random_access_iterator<Iterator>& lhs,
					const random_access_iterator<Iterator>& rhs)
	{
		return (lhs.base() <= rhs.base());
	};

	/**
	 * @brief Relational operators> for random_access_iterator
	 */
	template <class Iterator>
	bool operator> (const random_access_iterator<Iterator>& lhs,
					const random_access_iterator<Iterator>& rhs)
	{
		return (lhs.base() > rhs.base());
	};

	/**
	 * @brief Relational operators>= for random_access_iterator
	 */
	template <class Iterator>
	bool operator>= (const random_access_iterator<Iterator>& lhs,
					const random_access_iterator<Iterator>& rhs)
	{
		return (lhs.base() >= rhs.base());
	};

	/**
	 * @brief Returns a random_access_iterator pointing to the _pointer located n positions away
	 * from the _pointer pointed to by ran_it.
	 * 
	 * @param n Number of _pointer to offset.
	 * 			Member type difference_type is an alias of Iterator's own difference type.
	 * 
	 * @param ran_it random_access_iterator.
	 */
	template <class Iterator>
	random_access_iterator<Iterator> operator+ (
		typename random_access_iterator<Iterator>::difference_type n,
		const random_access_iterator<Iterator>& ran_it)
	{
		return (ran_it + n);
	};

	/**
	 * @brief Returns the distance between lhs and rhs.
	 */
	template <class Iterator>
	typename random_access_iterator<Iterator>::difference_type operator- (
		const random_access_iterator<Iterator>& lhs,
		const random_access_iterator<Iterator>& rhs
	)
	{
		return (rhs.base() - lhs.base());
	};

}//namespace ft

#endif