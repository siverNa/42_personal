/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sna <sna@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/22 00:37:01 by sna               #+#    #+#             */
/*   Updated: 2022/06/08 21:59:34 by sna              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_HPP
# define MAP_HPP

# include <memory>
# include <cstddef>

# include "util.hpp"
# include "iterator.hpp"
# include "Red_Black_Tree.hpp"

namespace ft {
	template < class Key,										// map::key_type
			class T,											// map::mapped_type
			class Compare = ft::less<Key>,						// map::key_compare
			class Alloc = std::allocator<pair<const Key, T> >	// map::allocator_type
			> class map
	{
		public:
			typedef Key												key_type;
			typedef T												mapped_type;
			typedef pair<const Key, T>								value_type;
			typedef Compare											key_compare;
			typedef Alloc											allocator_type;
			typedef typename allocator_type::reference				reference;
			typedef typename allocator_type::const_reference		const_reference;
			typedef typename allocator_type::pointer				pointer;
			typedef typename allocator_type::const_pointer			const_pointer;
			typedef size_t											size_type;
			typedef ptrdiff_t										difference_type;
		
			class value_compare : ft::binary_function<value_type, value_type, bool>
			{
				friend class map;

				protected:
					Compare		comp;
					value_compare (Compare c) : comp(c) {};
				public:
					typedef bool				result_type;
					typedef value_type			first_argument_type;
					typedef value_type			second_argument_type;
					bool operator() (const value_type& x, const value_type& y) const
					{
						return comp(x.first, y.first);
					};
			};
			
			typedef Red_Black_Tree<value_type, value_compare, allocator_type>	tree_type;
			typedef typename tree_type::iterator								iterator;
			typedef typename tree_type::const_iterator							const_iterator;
			typedef typename tree_type::reverse_iterator						reverse_iterator;
			typedef typename tree_type::const_reverse_iterator					const_reverse_iterator;

		private:
			allocator_type	_alloc;
			tree_type		_tree;
			key_compare		_compare;
		
		public:
			/**
			 * @brief empty container constructor (default constructor)
			 * Constructs an empty container, with no elements.
			 */
			explicit map (const key_compare& comp = key_compare(),
						const allocator_type& alloc = allocator_type()) 
				: _alloc(alloc), _tree(tree_type(comp, alloc)), _compare(comp)
			{};

			/**
			 * @brief range constructor
			 * Constructs a container with as many elements as the range [first,last),
			 * with each element constructed from its corresponding element in that range.
			 */
			template <class InputIterator>
			map (InputIterator first, InputIterator last,
				const key_compare& comp = key_compare(),
				const allocator_type& alloc = allocator_type())
				: _alloc(alloc), _tree(first, last, comp, alloc), _compare(comp)
			{};

			/**
			 * @brief copy constructor
			 * Constructs a container with a copy of each of the elements in x.
			 */
			map (const map& x)
				: _alloc(x._alloc), _tree(x._tree), _compare(x._compare)
			{};

			/**
			 * @brief Insert elements
			 * Extends the container by inserting new elements,
			 * effectively increasing the container size by the number of elements inserted.
			 * 
			 * @param val Value to be copied to (or moved as) the inserted element.
			 */
			ft::pair<iterator, bool> insert(const value_type& val) {
				return (_tree.insert(val));
			};

			/**
			 * @brief Insert elements
			 * Extends the container by inserting new elements,
			 * effectively increasing the container size by the number of elements inserted.
			 * 
			 * @param position Hint for the position where the element can be inserted.
			 * @param val Value to be copied to (or moved as) the inserted element.
			 */
			iterator insert (iterator position, const value_type& val) {
				return (_tree.insert(position, val));
			};

			/**
			 * @brief Insert elements
			 * Extends the container by inserting new elements,
			 * effectively increasing the container size by the number of elements inserted.
			 * 
			 * @param first, last
			 * Iterators specifying a range of elements.
			 * Copies of the elements in the range [first,last) are inserted in the container.
			 */
			template <class InputIterator>
			void insert (typename enable_if<!is_integral<InputIt>::value, InputIterator >::type first, InputIterator last) {
				_tree.insert(first, last);
			};
			
			/**
			 * @brief Map destructor
			 * Destroys the container object.
			 */
			~map() {_tree.clear()};

			/**
			 * @brief Copy container content
			 * Assigns new contents to the container, replacing its current content.
			 */
			map& operator= (const map& x)
			{
				if (*this == x)
					return (*this);
				_tree.clear();
				_tree.insert(x.begin(), x.end());
				return (*this);
			};

			/**
			 * @brief Return iterator to beginning
			 * Returns an iterator referring to the first element in the map container.
			 * 
			 * Because map containers keep their elements ordered at all times,
			 * begin points to the element that goes first following the container's sorting criterion.
			 * 
			 * If the container is empty, the returned iterator value shall not be dereferenced.
			 */
			iterator begin() {
				return (_tree.begin());
			};
			
			/**
			 * @brief Return iterator to beginning
			 * Returns an iterator referring to the first element in the map container.
			 * 
			 * Because map containers keep their elements ordered at all times,
			 * begin points to the element that goes first following the container's sorting criterion.
			 * 
			 * If the container is empty, the returned iterator value shall not be dereferenced.
			 */
			const_iterator begin() const {
				return (_tree.begin());
			};

			/**
			 * @brief Return iterator to end
			 * Returns an iterator referring to the past-the-end element in the map container.
			 * 
			 * The past-the-end element is the theoretical element
			 * that would follow the last element in the map container.
			 * It does not point to any element, and thus shall not be dereferenced.
			 * 
			 * Because the ranges used by functions of the standard library do not include the element pointed
			 * by their closing iterator, this function is often used in combination
			 * with map::begin to specify a range including all the elements in the container.
			 * 
			 * If the container is empty, this function returns the same as map::begin.
			 */
			iterator end() {
				return (_tree.end());
			};
			
			/**
			 * @brief Return iterator to end
			 * Returns an iterator referring to the past-the-end element in the map container.
			 * 
			 * The past-the-end element is the theoretical element
			 * that would follow the last element in the map container.
			 * It does not point to any element, and thus shall not be dereferenced.
			 * 
			 * Because the ranges used by functions of the standard library do not include the element pointed
			 * by their closing iterator, this function is often used in combination
			 * with map::begin to specify a range including all the elements in the container.
			 * 
			 * If the container is empty, this function returns the same as map::begin.
			 */
			const_iterator end() const {
				return (_tree.end());
			};

			/**
			 * @brief Return reverse iterator to reverse beginning
			 * Returns a reverse iterator pointing to the last element in the container
			 * (i.e., its reverse beginning).
			 * 
			 * Reverse iterators iterate backwards:
			 * increasing them moves them towards the beginning of the container.
			 * 
			 * rbegin points to the element preceding the one that would be pointed to by member end.
			 */
			reverse_iterator rbegin() {
				return (_tree.rbegin());
			};
			
			/**
			 * @brief Return reverse iterator to reverse beginning
			 * Returns a reverse iterator pointing to the last element in the container
			 * (i.e., its reverse beginning).
			 * 
			 * Reverse iterators iterate backwards:
			 * increasing them moves them towards the beginning of the container.
			 * 
			 * rbegin points to the element preceding the one that would be pointed to by member end.
			 */
			const_reverse_iterator rbegin() const {
				return (_tree.rbegin());
			};

			/**
			 * @brief Return reverse iterator to reverse end
			 * Returns a reverse iterator pointing to the theoretical element right
			 * before the first element in the map container (which is considered its reverse end).
			 * 
			 * The range between map::rbegin and map::rend contains
			 * all the elements of the container (in reverse order).
			 */
			reverse_iterator rend() {
				return (_tree.rend());
			};
			
			/**
			 * @brief Return reverse iterator to reverse end
			 * Returns a reverse iterator pointing to the theoretical element right
			 * before the first element in the map container (which is considered its reverse end).
			 * 
			 * The range between map::rbegin and map::rend contains
			 * all the elements of the container (in reverse order).
			 */
			const_reverse_iterator rend() const {
				return (_tree.rend());
			};

			/**
			 * @brief Test whether container is empty
			 * Returns whether the map container is empty (i.e. whether its size is 0).
			 */
			bool empty() const {
				return (_tree.empty());
			};

			/**
			 * @brief Return container size
			 * Returns the number of elements in the map container.
			 */
			size_type size() const {
				return (_tree.size());
			};

			/**
			 * @brief Return maximum size
			 * Returns the maximum number of elements that the map container can hold.
			 */
			size_type max_size() const {
				return (_tree.max_size());
			};
	};
}//namespace ft

#endif