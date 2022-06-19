/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iterator.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sna <sna@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/28 23:17:15 by sna               #+#    #+#             */
/*   Updated: 2022/06/19 18:47:33 by sna              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITERATOR_HPP
# define ITERATOR_HPP

# include <cstddef>
# include <iostream>

namespace ft {
	struct input_iterator_tag {};
	struct output_iterator_tag {};
	struct forward_iterator_tag : public input_iterator_tag {};
	struct bidirectional_iterator_tag : public forward_iterator_tag {};
	struct random_access_iterator_tag : public bidirectional_iterator_tag {};

	template <class Category, class T, class Distance = std::ptrdiff_t,
			  class Pointer = T*, class Reference = T&>
	struct iterator {
		typedef T			value_type;
		typedef Distance	difference_type;
		typedef Pointer		pointer;
		typedef Reference	reference;
		typedef Category	iterator_category;
	};

	template <class Iterator>
	struct iterator_traits {
		typedef typename Iterator::iterator_category	iterator_category;
		typedef typename Iterator::value_type			value_type;
		typedef typename Iterator::difference_type		difference_type;
		typedef typename Iterator::pointer				pointer;
		typedef typename Iterator::reference			reference;
	};

	template <class T>
	struct iterator_traits<T*> {
		typedef ft::random_access_iterator_tag				iterator_category;
		typedef T											value_type;
		typedef std::ptrdiff_t								difference_type;
		typedef T*											pointer;
		typedef T&											reference;
	};

	template <class T>
	struct iterator_traits<T* const> {
		typedef ft::random_access_iterator_tag				iterator_category;
		typedef T											value_type;
		typedef std::ptrdiff_t								difference_type;
		typedef const T*									pointer;
		typedef const T&									reference;
	};

	template <class T>
	class bidirectional_iterator : public ft::iterator<ft::bidirectional_iterator_tag, T>
	{
		typedef typename ft::iterator<ft::bidirectional_iterator_tag, T>::iterator_category	iterator_category;
		typedef typename ft::iterator<ft::bidirectional_iterator_tag, T>::value_type		value_type;
		typedef typename ft::iterator<ft::bidirectional_iterator_tag, T>::difference_type	difference_type;
		typedef typename ft::iterator<ft::bidirectional_iterator_tag, T>::pointer			pointer;
		typedef typename ft::iterator<ft::bidirectional_iterator_tag, T>::reference			reference;

		protected:
			pointer _pointer;
	};

	template <class Iterator>
	class reverse_iterator {
		public:
			typedef Iterator												iterator_type;
			typedef typename iterator_traits<Iterator>::iterator_category	iterator_category;
			typedef typename iterator_traits<Iterator>::value_type			value_type;
			typedef typename iterator_traits<Iterator>::difference_type		difference_type;
			typedef typename iterator_traits<Iterator>::pointer				pointer;
			typedef typename iterator_traits<Iterator>::reference			reference;

		protected:
			iterator_type	current;
		
		public:
			reverse_iterator() : current() {};

			explicit reverse_iterator(iterator_type it) : current(it) {};

			reverse_iterator(const reverse_iterator& it) : current(it.current) {};

			template <class Iter>
			reverse_iterator(const reverse_iterator<Iter>& rev_it) : current(rev_it.base()) {};

			template <class Iter>
			reverse_iterator& operator=(const reverse_iterator<Iter>& it)
			{
				current = it.base();
				return (*this);
			}

			virtual ~reverse_iterator() {};

			iterator_type
			base() const { return current; };

			operator reverse_iterator<const Iterator>() const { return this->current; };

			/**
			 * @brief Returns a reference to the element pointed to by the iterator.
			 */
			reference operator*() const
			{
				iterator_type temp_iter = current;
				return *(--temp_iter);
			};

			/**
			 * @brief Returns a reverse iterator pointing to the element located n positions away 
			 * from the element the iterator currently points to.
			 */
			reverse_iterator operator+(difference_type n) const
			{
				return (reverse_iterator(current - n));
			};

			/**
			 * @brief Advances the reverse_iterator by one position.(전위 증가연산자)
			 *
			 * @example ++rev_it;
			 */
			reverse_iterator& operator++()
			{
				--current;
				return (*this);
			};

			/**
			 * @brief Advances the reverse_iterator by one position.(후위 증가 연산자)
			 *
			 * @example rev_it++;
			 */
			reverse_iterator operator++(int)
			{
				reverse_iterator temp = *this;
				--current;
				return (temp);
			};

			/**
			 * @brief Advances the reverse_iterator by n element positions.
			 */
			reverse_iterator& operator+= (difference_type n)
			{
				current -= n;
				return (*this);
			};

			/**
			 * @brief Returns a reverse iterator pointing to the element located n positions
			 * before the element the iterator currently points to.
			 */
			reverse_iterator operator- (difference_type n) const
			{
				return (reverse_iterator(current + n));
			};

			/**
			 * @brief Decreases the reverse_iterator by one position.(전위 감소연산자)
			 *
			 * @example --rev_it;
			 */
			reverse_iterator& operator--()
			{
				++current;
				return (*this);
			};

			/**
			 * @brief Decreases the reverse_iterator by one position.(후위 감소연산자)
			 *
			 * @example rev_it--;
			 */
			reverse_iterator operator--(int)
			{
				reverse_iterator temp = *this;
				++current;
				return (temp);
			};

			/**
			 * @brief Descreases the reverse_iterator by n element positions.
			 */
			reverse_iterator& operator-= (difference_type n)
			{
				current += n;
				return (*this);
			};

			/**
			 * @brief Returns a pointer to the element pointed to by the iterator
			 * (in order to access one of its members).
			 */
			pointer operator->() const
			{
				return &(operator*());
			};

			/**
			 * @brief Accesses the element located n positions away
			 * from the element currently pointed to by the iterator.
			 * 
			 * If such an element does not exist, it causes undefined behavior.
			 */
			reference operator[] (difference_type n) const
			{
				return (current[-n - 1]);
			};

			bool operator==(const reverse_iterator &rhs)
			{
				return (base() == rhs.base());
			}
			
			bool operator!=(const reverse_iterator & rhs)
			{
				return (base() != rhs.base());
			}
	};

	/**
	 * @brief Relational operators== for reverse_iterator
	 */
	template <class Iterator>
	bool operator== (const reverse_iterator<Iterator>& lhs,
					const reverse_iterator<Iterator>& rhs)
	{
		return (lhs.base() == rhs.base());
	};

	/**
	 * @brief Relational operators!= for reverse_iterator
	 */
	template <class Iterator>
	bool operator!= (const reverse_iterator<Iterator>& lhs,
					const reverse_iterator<Iterator>& rhs)
	{
		return (lhs.base() != rhs.base());
	};

	/**
	 * @brief Relational operators< for reverse_iterator
	 */
	template <class Iterator>
	bool operator< (const reverse_iterator<Iterator>& lhs,
					const reverse_iterator<Iterator>& rhs)
	{
		return (lhs.base() > rhs.base());
	};

	/**
	 * @brief Relational operators<= for reverse_iterator
	 */
	template <class Iterator>
	bool operator<= (const reverse_iterator<Iterator>& lhs,
					const reverse_iterator<Iterator>& rhs)
	{
		return (lhs.base() >= rhs.base());
	};

	/**
	 * @brief Relational operators> for reverse_iterator
	 */
	template <class Iterator>
	bool operator> (const reverse_iterator<Iterator>& lhs,
					const reverse_iterator<Iterator>& rhs)
	{
		return (lhs.base() < rhs.base());
	};

	/**
	 * @brief Relational operators>= for reverse_iterator
	 */
	template <class Iterator>
	bool operator>= (const reverse_iterator<Iterator>& lhs,
					const reverse_iterator<Iterator>& rhs)
	{
		return (lhs.base() <= rhs.base());
	};

	/**
	 * @brief Returns a reverse iterator pointing to the element located n positions away
	 * from the element pointed to by rev_it.
	 * 
	 * @param n Number of elements to offset.
	 * 			Member type difference_type is an alias of Iterator's own difference type.
	 * 
	 * @param rev_it Reverse iterator.
	 */
	template <class Iterator>
	reverse_iterator<Iterator> operator+ (
		typename reverse_iterator<Iterator>::difference_type n,
		const reverse_iterator<Iterator>& rev_it)
	{
		return (rev_it + n);
	};

	/**
	 * @brief Returns the distance between lhs and rhs.
	 */
	template <class Iterator>
	typename reverse_iterator<Iterator>::difference_type operator- (
		const reverse_iterator<Iterator>& lhs,
		const reverse_iterator<Iterator>& rhs
	)
	{
		return (rhs.base() - lhs.base());
	};
}//namespace ft

#endif