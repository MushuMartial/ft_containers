/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmartial <tmartial@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 18:08:23 by tmartial          #+#    #+#             */
/*   Updated: 2022/07/18 16:45:06 by tmartial         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_HPP
# define MAP_HPP

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

namespace ft
{
	
	template < class Key, class T, class Compare = std::less<Key>, class Alloc = std::allocator<ft::pair<const Key,T> > >
	class map
	{
		public:
			// Members Types
			typedef	Key											key_type;
			typedef	T											mapped_type;
			typedef	ft::pair<const key_type, mapped_type>		value_type;
			typedef	Compare										key_compare;
			typedef	Alloc										allocator_type;
			typedef	typename allocator_type::reference			reference;
			typedef	typename allocator_type::const_reference	const_reference;
			typedef	typename allocator_type::pointer			pointer;
			typedef	typename allocator_type::const_pointer		const_pointer;
			typedef	ft::map_iterator<ft::pair<const Key, T> >		iterator;
			typedef	ft::map_iterator<const pair<const Key, T> >	const_iterator;
			typedef	ft::reverse_iterator<iterator> 				reverse_iterator;
			typedef	ft::reverse_iterator<const_iterator>		const_reverse_iterator;
			typedef typename allocator_type::size_type			size_type;

			// My Members Types
			typedef node<Key, T> *								nodePtr;
			typedef tree<Key, T>								tree;
			typedef std::allocator<node<key_type, mapped_type> > nodeAlloc;
		
		private:
			tree	_tree;
			Compare	_comp;
			Alloc	_alloc;
				
		public:
			/* ---------------------------------------------------- */
			/*                                                      */
			/*                     UTILS                            */
			/*                                                      */
			/* ---------------------------------------------------- */
			
			/* ---------------------------------------------------- */
			/*                                                      */
			/*                     CONSTRUCTORS                     */
			/*                                                      */
			/* ---------------------------------------------------- */
			//Constructor Default
			explicit map (const key_compare& comp = key_compare(),const allocator_type& alloc = allocator_type())
			:  _tree(), _comp(comp), _alloc(alloc)
			{
				
			}

			//Constructor Range
			//template <class InputIterator>
  			//map (InputIterator first, InputIterator last,const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type());

			//Constructor Copy
			map (const map& x)
			:  _tree(x._tree), _comp(x._comp), _alloc(x._alloc)
			{
				
			}

			//Destructor
			~map()
			{
				
			}

			//Operator =
			map& operator= (const map& x)
			{
				this->_tree = x._tree;
				this->_comp = x._comp;
				this->_alloc = x._alloc;
			}

			/* ---------------------------------------------------- */
			/*                                                      */
			/*                      CAPACITY                        */
			/*                                                      */
			/* ---------------------------------------------------- */
			//Empty
			bool empty() const
			{
				return (this->_tree.empty());
			}

			//size
			size_type size() const
			{
				return (this->_tree.size());
			}

			//max_size
			size_type max_size() const
			{
				return (this->_alloc->max_size());
			}
			
			/* ---------------------------------------------------- */
			/*                                                      */
			/*                      ITERATOR                        */
			/*                                                      */
			/* ---------------------------------------------------- */
			
			/*iterator begin()
			{
				iterator it;

				it->_node = this->_tree.begin();
				return (it);
			}*/

			/* ---------------------------------------------------- */
			/*                                                      */
			/*                      MODIFIERS                       */
			/*                                                      */
			/* ---------------------------------------------------- */
			//Insert
		
			
						
		
	};
}


#endif
