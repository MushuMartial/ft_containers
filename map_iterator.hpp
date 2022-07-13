/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_iterator.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmartial <tmartial@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/02 11:52:03 by tmartial          #+#    #+#             */
/*   Updated: 2022/07/13 17:20:37 by tmartial         ###   ########.fr       */
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
# include "node.hpp"
# include "binary_tree.hpp"
# include "map_iterator.hpp"

#define EMPTY 0
#define LEFT 1
#define RIGHT 2
#define ROOT 3

template<class Key, class T, class Compare = std::less<Key>,
		class Alloc = std::allocator<ft::pair<const Key,T> >  >
	struct node;

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

			typedef node<typename T::first_type, typename T::second_type>* nodePtr;
		
			//Attributes
			nodePtr	_node;
			int		_next;
			
			map_iterator() : _node()
			{
				
			}

			~map_iterator() {}
			
			T&	operator*() const
			{
				return ((this->_node->data));
			}
			
			map_iterator &	operator++()
			{
				nodePtr tmp = this->_node;
				
				if (tmp->parent == NULL)//node == root
				{
					this->_node = smallest_right();
					return *this;
				}
				else if (!tmp->left && !tmp->right)//node == leaf 
				{
					this->_node = tmp->parent;
					return *this;
				}
				else if ()
				{
						
				}
				return *this;
			}
			
			T*		operator->() const 
			{
				return (&this->_node->data);
			}
			/* ---------------------------------------------------- */
			/*                                                      */
			/*                     UTILS                            */
			/*                                                      */
			/* ---------------------------------------------------- */
			//Return smallest node on right starting from the root
			nodePtr smallest_right()
			{
				nodePtr tmp = this->_node;
				
				if (!tmp->right)
					return (tmp);
				tmp = tmp->right;
				while (tmp->left)
					tmp = tmp->left;
				return (tmp);
			}
	
	};
}


#endif