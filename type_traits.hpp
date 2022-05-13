/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_traits.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmartial <tmartial@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 15:06:25 by tmartial          #+#    #+#             */
/*   Updated: 2022/05/13 15:14:26 by tmartial         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TYPE_TRAITS_HPP
# define TYPE_TRAITS_HPP

namespace ft
{
	template <typename T, T val>
	struct integral_constant
	{
		static const	T							value = val;
		typedef			T							value_type;
		typedef			integral_constant<T, val>	type;
	};

	template<typename T, T val>
	const T integral_constant<T, val>::value;

	typedef integral_constant<bool, true>	true_type;
	typedef integral_constant<bool, false>	false_type;

	template <typename>
	struct is_integral : public false_type {};

	template <>
	struct is_integral<bool> : public true_type {};
	template <>
	struct is_integral<char> : public true_type {};
	template <>
	struct is_integral<signed char> : public true_type {};
	template <>
	struct is_integral<unsigned char> : public true_type {};
	template <>
	struct is_integral<wchar_t> : public true_type {};
	template <>
	struct is_integral<char16_t> : public true_type {};
	template <>
	struct is_integral<char32_t> : public true_type {};
	template <>
	struct is_integral<short> : public true_type {};
	template <>
	struct is_integral<unsigned short> : public true_type {};
	template <>
	struct is_integral<int> : public true_type {};
	template <>
	struct is_integral<unsigned int> : public true_type {};
	template <>
	struct is_integral<long> : public true_type {};
	template <>
	struct is_integral<unsigned long> : public true_type {};

	template <bool, typename T = void>
	struct enable_if {};

	template <typename T>
	struct enable_if<true, T> { typedef T type; };
}

#endif