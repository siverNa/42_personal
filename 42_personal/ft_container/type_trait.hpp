/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_trait.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sna <sna@student.42seoul.kr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/15 17:57:08 by sna               #+#    #+#             */
/*   Updated: 2022/05/15 18:30:21 by sna              ###   ########.fr       */
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
	struct enable_if<true, T> {typedef T type};

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

}//namespace ft

#endif