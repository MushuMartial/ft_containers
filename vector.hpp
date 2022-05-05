/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmartial <tmartial@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 15:54:04 by tmartial          #+#    #+#             */
/*   Updated: 2022/05/05 17:29:31 by tmartial         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_HPP
# define VECTOR_HPP

#include <iostream>

namespace ft
{
	template<class T, class Allocator = std::allocator<T> >
	class vector
	{
		public:
			typedef				T												value_type;
			typedef				Alloc											allocator_type;
			typedef typename	allocator_type::reference						reference;
			typedef typename	allocator_type::const_reference					const_reference;
			typedef typename	allocator_type::pointer							pointer;
			typedef typename	allocator_type::const_pointer					const_pointer;
			typedef typename	ft::random_access_iterator<value_type>			iterator;
			typedef typename	ft::random_access_iterator<const value_type>	const_iterator;
			typedef typename	ft::reverse_iterator<iterator>					reverse_iterator;
			typedef typename	ft::reverse_iterator<const_iterator>			const_reverse_iterator;
			typedef typename	ft::iterator_traits<iterator>::difference_type	difference_type;
			typedef 			std::size_t										size_type;
		private:
			
		
		public:
			//Constructor Default
			explicit vector ()
		
	};
}


#endif