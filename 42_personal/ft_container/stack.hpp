/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sna <sna@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/21 00:06:56 by sna               #+#    #+#             */
/*   Updated: 2022/05/22 00:16:49 by sna              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_HPP
# define STACK_HPP

# include "vector.hpp"

namespace ft {

	template <class T, class Container = ft::vector<T> >
	class stack {
		public:
			/**
			 * @brief value_type
			 * The first template parameter (T)
			 */
			typedef T					value_type;
			/**
			 * @brief container_type
			 * The second template parameter (Container)	
			 */
			typedef Container			container_type;
			/**
			 * @brief size_type	
			 * an unsigned integral type
			 */
			typedef unsigned int		size_type;

		protected:
			container_type				_c_t;

		public:
			/**
			 * @brief Construct stack
			 * Constructs a stack container adaptor object.
			 */
			explicit stack (const container_type& ctnr = container_type())
			{
				_c_t = ctnr;
			};

			/**
			 * @brief Test whether container is empty
			 * Returns whether the stack is empty: i.e. whether its size is zero.
			 * This member function effectively calls member empty of the underlying container object.
			 * 
			 * @return true if the underlying container's size is 0, false otherwise.
			 */
			bool empty() const {return (_c_t.empty()); };

			/**
			 * @brief Return size
			 * Returns the number of elements in the stack.
			 * This member function effectively calls member size of the underlying container object.
			 * 
			 * @return The number of elements in the underlying container.
			 */
			size_type size() const {return (_c_t.size()); };

			/**
			 * @brief Access next element
			 * Returns a reference to the top element in the stack.
			 * Since stacks are last-in first-out containers,
			 * the top element is the last element inserted into the stack.
			 * This member function effectively calls member back of the underlying container object.
			 * 
			 * @return A reference to the top element in the stack.
			 */
			value_type& top() {return (_c_t.back()); };

			/**
			 * @brief Access next element
			 * Returns a contst reference to the top element in the stack.
			 * Since stacks are last-in first-out containers,
			 * the top element is the last element inserted into the stack.
			 * This member function effectively calls member back of the underlying container object.
			 * 
			 * @return A reference to the top element in the stack.
			 */
			const value_type& top() const {return (_c_t.back()); };

			/**
			 * @brief Insert element
			 * Inserts a new element at the top of the stack,
			 * above its current top element. The content of this new element is initialized to a copy of val.
			 * This member function effectively calls the member function push_back
			 * of the underlying container object.
			 * 
			 * @param val Value to which the inserted element is initialized.
			 */
			void push (const value_type& val) {_c_t.push_back(val); };

			/**
			 * @brief Remove top element
			 * Removes the element on top of the stack, effectively reducing its size by one.
			 * 
			 * The element removed is the latest element inserted into the stack,
			 * whose value can be retrieved by calling member stack::top.
			 * 
			 * This calls the removed element's destructor.
			 * 
			 * This member function effectively calls the member function pop_back of the underlying container object.
			 */
			void pop() {_c_t.pop_back(); };
	};

};//namespace ft


#endif