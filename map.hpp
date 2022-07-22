/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmartial <tmartial@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 18:08:23 by tmartial          #+#    #+#             */
/*   Updated: 2022/07/22 12:10:43 by tmartial         ###   ########.fr       */
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
				//this->_tree.printTree(this->_tree._root, nullptr, false, 0);
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
				iterator it(this->_tree.begin()); 
				
				return it;
			}
			
			const_iterator begin() const
			{
				const_iterator it(this->_tree.begin()); 
				
				return it;
			}

			//End
			iterator end()
			{
				iterator it(this->_tree.end()); 
				
				return it;
			}
			
			const_iterator end() const
			{
				const_iterator it(this->_tree.end()); 
				
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
				size_type ret = 0;
				iterator it(this->_tree.begin()); 
				iterator end(this->_tree.end());
				
				while (it != end)
				{
					it++;
					ret++;
				}
				return (ret);
			}

			//max_size
			size_type max_size() const
			{
				return (this->_alloc.max_size());
			}
			
			/* ---------------------------------------------------- */
			/*                                                      */
			/*                   ELEMENT ACCESS                     */
			/*                                                      */
			/* ---------------------------------------------------- */
			mapped_type& operator[] (const key_type& k)
			{
				return (*((this->insert(make_pair(k,mapped_type()))).first)).second;
			}
			
			/* ---------------------------------------------------- */
			/*                                                      */
			/*                      MODIFIERS                       */
			/*                                                      */
			/* ---------------------------------------------------- */
			//Insert
			pair<iterator,bool> insert (const value_type& val)
			{
				iterator it(this->find(val.first));
				bool ret;
				
				if (!it._node || val.first != it->first)
				{
					this->_tree.insert(val);
					iterator it(this->find(val.first));
					ret = true;
				}
				else
					ret = false;
				return (pair<iterator,bool>(it, ret));	
			}
			
			iterator insert (iterator position, const value_type& val)
			{
				(void)position;
				ft::pair<iterator, bool> tmp  = this->insert(val);
				
				return (tmp->first);
			}
			
			template <class InputIterator>
  			void insert (InputIterator first, InputIterator last)
			{
				while (first != last)
				{
					this->insert(*first);
					first++;
				}
				
			}

			//Erase
			void erase (iterator position)
			{
				this->_tree.erase(*position);
			}
			
			size_type erase (const key_type& k) //remove worked = 1 else 0
			{
				(void)k;
				size_type ret = 0;
				return (0);
			}
			
			void erase (iterator first, iterator last)
			{
				while (first != last)
				{
					this->_tree.erase(*first);
					first++;
				}
				
			}

			//Swap
			void swap (map& x)
			{
				tree	tmp_tree = this->_tree;
				Compare	tmp_comp = this->_comp;
				Alloc	tmp_alloc = this->_alloc;

				this->_tree = x._tree;
				this->_comp = x._comp;
				this->_alloc = x._alloc;

				x._tree = tmp_tree;
				x._comp = tmp_comp;
				x._alloc = tmp_alloc;
			}

			//Clear
			void clear()
			{
				
			}

			/* ---------------------------------------------------- */
			/*                                                      */
			/*                     OBSERVERS                        */
			/*                                                      */
			/* ---------------------------------------------------- */
			key_compare key_comp() const
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
			}

			/* ---------------------------------------------------- */
			/*                                                      */
			/*                     ALLOCATOR                        */
			/*                                                      */
			/* ---------------------------------------------------- */
			allocator_type get_allocator() const
			{
				return (this->_alloc);
			}
			
			/* ---------------------------------------------------- */
			/*                                                      */
			/*                     OPERATORS                        */
			/*                                                      */
			/*  --------------------------------------------------- */
			//Find
			iterator find (const key_type& k)
			{
				nodePtr tmp = this->_tree.search(k);

				if (tmp)
				{
					iterator it(tmp);
					return it;
				}
				iterator it(this->_tree.end());
				return it;
			}
			
			const_iterator find (const key_type& k) const
			{
				nodePtr tmp = this->_tree.search(k);

				if (tmp)
				{
					const_iterator it(tmp);
					return it;
				}
				const_iterator it(this->_tree.end());
				return it;
			}

			//Count
			size_type count (const key_type& k) const
			{
				size_type ret = 0;

				if (this->search(k) == nullptr)
					return ret;
				return (ret + 1);
			}

			//Lower Bound
			iterator lower_bound (const key_type& k)
			{
				iterator it(this->_tree.begin());
				iterator end(this->_tree.end());

				while (it != end)
				{
					if (!(this->_comp((*it).first, k)))
						return (it);
					it++;
				}
				return (end);
			}
			
			const_iterator lower_bound (const key_type& k) const
			{
				const_iterator it(this->_tree.begin());
				const_iterator end(this->_tree.end());

				while (it != end)
				{
					if (!(this->_comp((*it).first, k)))
						return (it);
					it++;
				}
				return (end);
			}

			//Upper Bound
			iterator upper_bound (const key_type& k)
			{
				iterator it(this->_tree.begin());
				iterator end(this->_tree.end());

				while (it != end)
				{
					if ((this->_comp(k, (*it).first)))
						return (it);
					it++;
				}
				return (end);
			}
			
			const_iterator upper_bound (const key_type& k) const
			{
				const_iterator it(this->_tree.begin());
				const_iterator end(this->_tree.end());

				while (it != end)
				{
					if ((this->_comp(k, (*it).first)))
						return (it);
					it++;
				}
				return (end);
			}
		
			//Equal Range
			pair<const_iterator,const_iterator> equal_range (const key_type& k) const
			{
				return (pair<const_iterator, const_iterator>(this->lower_bound(k), this->upper_bound(k)));
			}
			
			pair<iterator,iterator>             equal_range (const key_type& k)
			{
				return (pair<iterator, iterator>(this->lower_bound(k), this->upper_bound(k)));
			}

	};
}


#endif
