/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sna <sna@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/08 20:13:36 by sna               #+#    #+#             */
/*   Updated: 2022/06/09 20:39:37 by sna              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTIL_HPP
# define UTIL_HPP

# include "iterator.hpp"//<cstddef>

namespace ft
{
	struct nullptr_t
	{
		private:
			void	operator&() const;
		
		public:
			// Return 0 for any class pointer
			template <class T>
			operator T*() const {
				return (0);
			};

			// Return 0 for any member pointer
			template <class T, class C>
			operator T C::*() const {
				return (0);
			};

			// Used for bool conversion
			operator void*() const
			{
				return (0);
			}

			// Comparisons with nullptr
			bool operator==(const nullptr_t&) const
			{
				return (true);
			}
			
			bool operator!=(const nullptr_t&) const
			{
				return (false);
			}
	};

	static nullptr_t u_nullptr = {};

	template <class InputIterator>
	typename ft::iterator_traits<InputIterator>::difference_type	difference(InputIterator first, InputIterator last) {
		typedef typename ft::iterator_traits<InputIterator>::difference_type	size_type;
		size_type n = 0;
		
		for (; first != last; first++)
			++n;
		return (n);
	};

	/**
	 * @brief Pair of values
	 * This class couples together a pair of values, 
	 * which may be of different types (T1 and T2).
	 * The individual values can be accessed through its public members first and second.
	 * Pairs are a particular case of tuple.
	 * 
	 * @tparam T1 Type of member first, aliased as first_type.
	 * @tparam T2 Type of member second, aliased as second_type.
	 */
	template <class T1, class T2>
	struct pair {
		public:
			typedef T1			first_type;
			typedef T2			second_type;

			first_type			first;
			second_type			second;

			/**
			 * @brief Construct pair (1) default constructor
			 * Constructs a pair object.
			 * This involves individually constructing its two component objects, 
			 * with an initialization that depends on the constructor form invoked:
			 * 
			 * Constructs a pair object with its elements value-initialized.
			 */
			pair() : first(), second() {};

			/**
			 * @brief Construct pair (2) copy / move constructor (and implicit conversion)
			 * Constructs a pair object.
			 * This involves individually constructing its two component objects, 
			 * with an initialization that depends on the constructor form invoked:
			 * 
			 * The object is initialized with the contents of the pr pair object.
			 * The corresponding member of pr is passed to the constructor of each of its members.
			 * 
			 * @param pr Another pair object.
			 */
			template<class U, class V>
			pair (const pair<U, V>& pr) : first(pr.first), second(pr.second) {};

			/**
			 * @brief Construct pair (3) initialization constructor
			 * Constructs a pair object.
			 * This involves individually constructing its two component objects, 
			 * with an initialization that depends on the constructor form invoked:
			 * 
			 * Member first is constructed with a and member second with b.
			 * 
			 * @param a An object of the type of first, or some other type implicitly convertible to it.
			 * @param b An object of the type of second, or some other type implicitly convertible to it.
			 */
			pair (const first_type& a, const second_type& b) : first(a), second(b) {};

			/**
			 * @brief Assign contents
			 * Assigns pr as the new content for the pair object.
			 * Member first is assigned pr.first, and member second is assigned pr.second.
			 */
			pair& operator= (const pair& pr)
			{
				if (*this == pr)
					return (*this);
				first = pr.first;
				second = pr.second;
				return (*this);	
			};
	};

	/**
	 * @brief Relational operators for pair
	 * Performs the appropriate comparison operation between the pair objects lhs and rhs.
	 * 
	 * Two pair objects compare equal to each other if both their first members compare equal to each other 
	 * and both their second members compare also equal to each other
	 * (in both cases using operator== for the comparison).
	 * 
	 * Similarly, operators <, >, <= and >= perform a lexicographical comparison on the sequence formed
	 * by members first and second (in all cases using operator< reflexively for the comparisons).
	 */
	template <class T1, class T2>
	bool operator== (const pair<T1, T2>& lhs, const pair<T1, T2>& rhs)
	{
		return (lhs.first == rhs.first && lhs.second == rhs.second);
	};

	template <class T1, class T2>
	bool operator!= (const pair<T1, T2>& lhs, const pair<T1, T2>& rhs)
	{
		return (!(lhs == rhs));
	};

	template <class T1, class T2>
	bool operator<  (const pair<T1, T2>& lhs, const pair<T1, T2>& rhs)
	{
		return (lhs.first < rhs.first || (!(rhs.first < lhs.first) && (lhs.second < rhs.second)));
	};

	template <class T1, class T2>
	bool operator<= (const pair<T1, T2>& lhs, const pair<T1, T2>& rhs)
	{
		return (!(rhs < lhs));
	};

	template <class T1, class T2>
	bool operator>  (const pair<T1, T2>& lhs, const pair<T1, T2>& rhs)
	{
		return (rhs < lhs);
	};

	template <class T1, class T2>
	bool operator>= (const pair<T1, T2>& lhs, const pair<T1, T2>& rhs)
	{
		return (!(lhs < rhs));
	};

	/**
	 * @brief Construct pair object
	 * Constructs a pair object with its first element set to x and its second element set to y.
	 * 
	 * The template types can be implicitly deduced from the arguments passed to make_pair.
	 * 
	 * pair objects can be constructed from other pair objects containing different types,
	 * if the respective types are implicitly convertible.
	 * 
	 * @param x Values for the members first, respectively, of the pair object being constructed.
	 * @param y Values for the members second, respectively, of the pair object being constructed.
	 * 
	 * @return A pair object whose elements first and second are set to x and y respectivelly.
	 */
	template <class T1, class T2>
	pair<T1, T2> make_pair (T1 x, T2 y)
	{
		return (pair<T1, T2>(x, y));
	};

	/**
	 * @brief Binary function object base class
	 * This is a base class for standard binary function objects.
	 * 
	 * Generically, function objects are instances of a class with member function operator() defined.
	 * This member function allows the object to be used with the same syntax as a regular function call,
	 * and therefore its type can be used as template parameter when a generic function type is expected.
	 */
	template <class Arg1, class Arg2, class Result>
	struct binary_function
	{
		//The first template parameter (Arg1)
		typedef Arg1	first_argument_type;
		//The second template parameter (Arg2)
		typedef Arg2	second_argument_type;
		//The third template parameter (Result)
		typedef Result	result_type;
	};

	/**
	 * @brief Function object class for less-than inequality comparison
	 * Binary function object class whose call returns
	 * whether the its first argument compares less than the second (as returned by operator <).
	 * 
	 * Generically, function objects are instances of a class with member function operator() defined.
	 * This member function allows the object to be used with the same syntax as a function call.
	 */
	template <class T>
	struct less : binary_function <T, T, bool>
	{
		bool operator() (const T& x, const T& y) const {return x < y;}
	};

	/**
	 * @brief Remove const qualification
	 * Obtains the type T without top-level const qualification.
	 */
	template <class T>
	struct remove_const {typedef T type; };

	template <class T>
	struct remove_const <const T> {typedef T type; };

	template <class T>
	struct BST_Node
	{
		public:
			/**
			 * @brief First template argument, the type of stocked value
			 */
			typedef T			value_type;

			value_type			value;
			BST_Node*			parent;
			BST_Node*			left;
			BST_Node*			right;

			/**
			 * @brief default construct
			 */
			BST_Node()
				: value(), parent(u_nullptr), left(u_nullptr), right(u_nullptr)
			{};

			/**
			 * @brief default construct
			 */
			BST_Node(BST_Node* parent = u_nullptr, BST_Node* left = u_nullptr, BST_Node* right = u_nullptr)
				: value(), parent(parent), left(left), right(right)
			{};

			/**
			 * @brief input construct
			 */
			BST_Node(const value_type& value, BST_Node* parent = u_nullptr,
					BST_Node* left = u_nullptr, BST_Node* right = u_nullptr)
				: value(value), parent(parent), left(left), right(right)
			{};

			/**
			 * @brief copy construct
			 */
			BST_Node(const BST_Node& copy)
				: value(copy.value), parent(copy.parent), left(copy.left), right(copy.right)
			{};

			/**
			 * @brief destructor
			 */
			virtual ~BST_Node() {};

			/**
			 * @brief copy operator
			 * Create a BST_Node that a copy of "bs".
			 * The value is initalized by a copy of "bs" value.
			 * Left and right branch point to the same than "bs" branches.
			 */
			BST_Node& operator=(const BST_Node& bs)
			{
				if (*this == bs)
					return (*this);
				
				this->value = bs.value;
				this->parent = bs.parent;
				this->left = bs.left;
				this->right = bs.right;
				
				return (*this);
			};

			/**
			 * @brief Compare BST_Node and bs
			 * if two node value is same
			 */
			bool operator==(const BST_Node& bs)
			{
				if (this->value == bs.value)
					return (true);
				return (false);
			};
	};

	template <class T>
	struct Double_Linked_Node
	{
		public:
			Double_Linked_Node*		prev;
			Double_Linked_Node*		next;
			T						data;

			/**
			 * @brief default construct
			 */
			Double_Linked_Node()
				: prev(u_nullptr), next(u_nullptr)
			{};

			/**
			 * @brief input construct
			 */
			Double_Linked_Node(const T& value)
				: prev(u_nullptr), next(u_nullptr), data(value)
			{};

			/**
			 * @brief input construct2
			 */
			Double_Linked_Node(Double_Linked_Node* prev, Double_Linked_Node* next, const T& value)
				: prev(prev), next(next), data(value)
			{};	
	};
}//namespace ft

#endif