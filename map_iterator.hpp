/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_iterator.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmartial <tmartial@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/02 11:52:03 by tmartial          #+#    #+#             */
/*   Updated: 2022/07/12 16:11:03 by tmartial         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef MAP_ITERATOR_HPP
# define MAP_ITERATOR_HPP

# include <iostream>
# include <algorithm>
# include <memory>
# include <vector>
# include <iterator>
# include <map>
# include "iterator_traits.hpp"
# include "type_traits.hpp"
# include "random_access_iterator.hpp"
# include "reverse_iterator.hpp"
# include "utils.hpp"
# include "pair.hpp"
# include "binary_tree.hpp"
# include "map_iterator.hpp"

namespace	ft
{
	template <class T>
	class map_iterator
	{
		public:
			// Members Types
			typedef	typename T::first_type				key_type;
			typedef	typename T::second_type				mapped_type;
			typedef typename ft::iterator<map_iterator, T>::iterator_category	iterator_category;
			typedef typename ft::iterator<map_iterator, T>::value_type			value_type;
			typedef typename ft::iterator<map_iterator, T>::difference_type		difference_type;
			typedef typename ft::iterator<map_iterator, T>::pointer				pointer;
			typedef typename ft::iterator<map_iterator, T>::reference			reference;
		
		map_iterator()
		{
			
		}
		
	};
}


#endif