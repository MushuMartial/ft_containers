/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmartial <tmartial@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 18:08:23 by tmartial          #+#    #+#             */
/*   Updated: 2022/07/20 18:54:31 by tmartial         ###   ########.fr       */
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
			typedef	ft::map_iterator<ft::pair<const Key, T> >	iterator;
			typedef	ft::map_iterator<const pair<const Key, T> >	const_iterator;
			typedef	ft::reverse_iterator<iterator> 				reverse_iterator;
			typedef	ft::reverse_iterator<const_iterator>		const_reverse_iterator;
			typedef typename allocator_type::size_type			size_type;

			// My Members Types
			typedef node<const Key, T>*								nodePtr;
			typedef tree<const Key, T>								tree;
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
			void insert (const ft::pair<const Key, T>& val)
			{
				this->_tree.insert(val);
			}
			
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
			template <class InputIterator>
  			map (InputIterator first, InputIterator last,const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type())
			: _tree(), _comp(comp), _alloc(alloc)
			{
				while (first != last)
				{
					this->_tree.insert(*first);
					first++;
				}
				
			}  

			//Constructor Copy
			map (const map& x)
			:  _tree(x._tree), _comp(x._comp), _alloc(x._alloc)
			{
				
			}

			//Destructor
			~map()
			{
				this->_tree.printTree(this->_tree._root, nullptr, false, 0);
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
			/*                     ITERATORS                        */
			/*                                                      */
			/* ---------------------------------------------------- */
			//Begin
			iterator begin()
			{
				iterator it; 
				
				it._node = this->_tree.begin();
				return it;
			}
			
			const_iterator begin() const
			{
				const_iterator it; 
				
				it._node = this->_tree.begin();
				return it;
			}

			//End
			iterator end()
			{
				iterator it; 
				
				it._node = this->_tree.end();
				return it;
			}
			
			const_iterator end() const
			{
				const_iterator it; 
				
				it._node = this->_tree.end();
				return it;
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
			/*                   ELEMENT ACCESS                     */
			/*                                                      */
			/* ---------------------------------------------------- */
			mapped_type& operator[] (const key_type& k);
			
			/* ---------------------------------------------------- */
			/*                                                      */
			/*                      MODIFIERS                       */
			/*                                                      */
			/* ---------------------------------------------------- */
			//Insert
			//pair<iterator,bool> insert (const value_type& val);
			//iterator insert (iterator position, const value_type& val);
			//template <class InputIterator>
  			//void insert (InputIterator first, InputIterator last);

			//Erase
			//void erase (iterator position);
			//size_type erase (const key_type& k);
			//void erase (iterator first, iterator last);

			//Swap
			//void swap (map& x);
			//void clear();

			/* ---------------------------------------------------- */
			/*                                                      */
			/*                     OBSERVERS                        */
			/*                                                      */
			/* ---------------------------------------------------- */
			/*key_compare key_comp() const
			{
				return (this->_comp);
			}

			class value_compare
			{
				friend class map;
				protected:

					Compare comp;
					value_compare (Compare c) : comp(c) {}

				public:

					typedef bool result_type;
					typedef value_type first_argument_type;
					typedef value_type second_argument_type;
					bool operator() (const value_type& x, const value_type& y) const
					{
						return comp(x.first, y.first);
					}
			};

			value_compare value_comp() const
			{
				return (value_compare(_comp));
			}*/

			/* ---------------------------------------------------- */
			/*                                                      */
			/*                     OPERATORS                        */
			/*                                                      */
			/*  --------------------------------------------------- */
			//Find
			//iterator find (const key_type& k);
			//const_iterator find (const key_type& k) const;

			//Count
			//size_type count (const key_type& k) const;

			//Lower Bound
			//iterator lower_bound (const key_type& k);
			//const_iterator lower_bound (const key_type& k) const;

			//Upper Bound
			//iterator upper_bound (const key_type& k);
			//const_iterator upper_bound (const key_type& k) const;
		
			//Equal Range
			//pair<const_iterator,const_iterator> equal_range (const key_type& k) const;
			//pair<iterator,iterator>             equal_range (const key_type& k);
			
						
		
	};
}


#endif
