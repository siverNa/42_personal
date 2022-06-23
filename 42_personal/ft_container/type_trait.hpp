/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_trait.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sna <sna@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/15 17:57:08 by sna               #+#    #+#             */
/*   Updated: 2022/06/23 21:17:36 by sna              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TYPE_TRAIT_HPP
# define TYPE_TRAIT_HPP

namespace ft {

	/**
	 * @brief The type T is enabled as member type enable_if::type if Cond is true.
	 * 
	 * Otherwise, enable_if::type is not defined.
	 * 
	 * This is useful to hide signatures on compile time when a particular condition is not met, 
	 * since in this case, the member enable_if::type will not be defined 
	 * and attempting to compile using it should fail.
	 * 
	 * @param Cond A compile-time constant of type bool
	 * @param T A type.
	 */
	template <bool Cond, class T = void>
	struct enable_if {};

	template <class T>
	struct enable_if<true, T> {typedef T type; };

	template <class T>
	struct is_integral {static const bool value = false; };
	template <>
	struct is_integral<bool> {static const bool value = true; };
	template <>
	struct is_integral<char> {static const bool value = true; };
	template <>
	struct is_integral<char16_t> {static const bool value = true; };
	template <>
	struct is_integral<char32_t> {static const bool value = true; };
	template <>
	struct is_integral<wchar_t> {static const bool value = true; };
	template <>
	struct is_integral<signed char> {static const bool value = true; };
	template <>
	struct is_integral<short int> {static const bool value = true; };
	template <>
	struct is_integral<int> {static const bool value = true; };
	template <>
	struct is_integral<long int> {static const bool value = true; };
	template <>
	struct is_integral<long long int> {static const bool value = true; };
	template <>
	struct is_integral<unsigned char> {static const bool value = true; };
	template <>
	struct is_integral<unsigned short int> {static const bool value = true; };
	template <>
	struct is_integral<unsigned int> {static const bool value = true; };
	template <>
	struct is_integral<unsigned long int> {static const bool value = true; };
	template <>
	struct is_integral<unsigned long long int> {static const bool value = true; };

	template <typename T, typename U>
	struct is_equal {static const bool value = false; };

	template <typename T, typename Enable = void>
	struct is_iter {static const bool value = false; };

	template <typename T>
	struct remove_volatile {typedef T type; };

	template <typename T>
	struct remove_volatile<volatile T>{typedef T type; };

	template <typename T>
	struct remove_cv : remove_const<typename remove_volatile<T>::type> {};

	template <typename T>
	struct is_unqualified_pointer{enum { value = false }; };

	template <typename T>
	struct is_unqualified_pointer<T*> {enum { value = true }; };

	template <typename T>
	struct is_pointer: is_unqualified_pointer<typename remove_cv<T>::type> {};

	template <typename T>
	struct is_iter<T, typename ft::enable_if<ft::is_equal<typename T::value_type, typename ft::iterator_traits<T>::value_type>::value>::type>
	{
		static const bool value = true;
	};

	template <typename T>
	struct is_iter<T, typename ft::enable_if<ft::is_pointer<T>::value>::type>
	{
		static const bool value = true;
	};

}//namespace ft

#endif