/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iterator.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sna <sna@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/28 23:17:15 by sna               #+#    #+#             */
/*   Updated: 2022/04/29 23:42:55 by sna              ###   ########.fr       */
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

	template <class Category, class T, class Distance = ptrdiff_t,
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
		typedef typename Iterator::valuie_type			value_type;
		typedef typename Iterator::difference_type		difference_type;
		typedef typename Iterator::pointer				pointer;
		typedef typename Iterator::reference			reference;
	};

	template <class T>
	struct iterator_traits<T*> {
		typedef random_access_iterator_tag				iterator_category;
		typedef T										value_type;
		typedef ptrdiff_t								difference_type;
		typedef T*										pointer;
		typedef T&										reference;
	};

	template <class T>
	struct iterator_traits<T* const> {
		typedef random_access_iterator_tag				iterator_category;
		typedef T										value_type;
		typedef ptrdiff_t								difference_type;
		typedef const T*								pointer;
		typedef const T&								reference;
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

			explicit reverse_iterator(iterator_type _x) : current(_x) {};

			reverse_iterator(const reverse_iterator& _x) : current(_x.current) {};

			template <class Iter>
			reverse_iterator(const reverse_iterator<Iter>& _x) : current(_x.base()) {};

			virtual ~reverse_iterator() {};

			iterator_type
			base() const { return current; };

			operator reverse_iterator<const Iterator>() const { return this->current; };
	};
}

#endif