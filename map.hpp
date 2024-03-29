/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmartial <tmartial@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 18:08:23 by tmartial          #+#    #+#             */
/*   Updated: 2022/08/09 17:44:56 by tmartial         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_HPP
# define MAP_HPP

# include "random_access_iterator.hpp"
# include "reverse_iterator.hpp"
# include "utils.hpp"
# include "binary_tree.hpp"
# include "map_iterator.hpp"

namespace ft
{
	
	template < class Key, class T, class Compare = std::less<Key>, class Alloc = std::allocator<ft::pair<const Key,T> > >
	class map
	{
		public:
			// Members Types
			typedef	Key												key_type;
			typedef	T												mapped_type;
			typedef	ft::pair<const key_type, mapped_type>			value_type;
			typedef	Compare											key_compare;
			typedef	Alloc											allocator_type;
			typedef	typename allocator_type::reference				reference;
			typedef	typename allocator_type::const_reference		const_reference;
			typedef	typename allocator_type::pointer				pointer;
			typedef	typename allocator_type::const_pointer			const_pointer;
			typedef	ft::map_iterator<ft::pair<const Key, T> >		iterator;
			typedef	ft::map_iterator<const pair<const Key, T> >		const_iterator;
			typedef	ft::reverse_iterator<iterator> 					reverse_iterator;
			typedef	ft::reverse_iterator<const_iterator>			const_reverse_iterator;
			typedef typename allocator_type::size_type				size_type;

			// My Members Types
			typedef node<const Key, T>*								nodePtr;
			typedef tree<const Key, T, key_compare, allocator_type>	Search_tree;
			typedef std::allocator<node<key_type, mapped_type> >	nodeAlloc;
		
		private:
			Search_tree	_tree;
			Compare	_comp;
			Alloc	_alloc;
				
		public:
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
					this->insert(*first);
					first++;
				}
			}  

			//Constructor Copy
			map (const map& x)
			:  _tree(), _comp(x._comp), _alloc(x._alloc)
			{
				this->insert(x.begin(), x.end());
			}

			//Destructor
			~map()
			{
				this->clear();
			}

			//Operator =
			map& operator= (const map& x)
			{
				this->clear();
				this->insert(x.begin(), x.end());
				return *this;
			}

			//DEBUG
			// void PrintTree()
			// {
			// 	this->_tree.printTree(this->_tree._root, NULL, false, 0);
			// }	
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
				iterator it(NULL, this->_tree.end()); 
				
				return it;
			}
			
			const_iterator end() const
			{
				const_iterator it(NULL, this->_tree.end()); 
				
				return it;
			}

			//RBegin
			reverse_iterator rbegin()
			{
				reverse_iterator it(this->end()); 
				
				return it;
			}
			
			const_reverse_iterator rbegin() const
			{
				const_reverse_iterator it(this->end()); 
				
				return it;
			}

			//REnd
			reverse_iterator rend()
			{
				reverse_iterator it(this->begin()); 
				
				return it;
			}
			
			const_reverse_iterator rend() const
			{
				const_reverse_iterator it(this->begin()); 
				
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
				iterator end(NULL, this->_tree.end());
					
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
				nodePtr tmp = this->_tree._root;
				if (!tmp)
					this->_tree._root = NULL;
				ft::pair<iterator, bool> ret = this->insert(ft::make_pair(k,mapped_type()));
				return ret.first->second;
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
				bool ret = true;
				
				if (it == this->end())
				{
					this->_tree.insert(val);
					iterator it_ret(this->find(val.first));
					return (pair<iterator,bool>(it_ret, ret));	
				}
				else
					ret = false;
				return (pair<iterator,bool>(it, ret));	
			}
			
			iterator insert (iterator position, const value_type& val)
			{
				(void)position;
				ft::pair<iterator, bool> tmp  = this->insert(val);
				
				return (tmp.first);
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
				this->_tree.erase((*position).first);
			}
			
			size_type erase (const key_type& k)
			{
				size_type ret = 0;
					if (this->_tree.erase(k))
						ret = 1;
				return (ret);
			}
			
			void erase (iterator first, iterator last)
			{
				while (first != last)
				{
					this->_tree.erase((*first).first);
					first++;
				}
			}

			//Swap
			void swap (map& x)
			{
				Search_tree	tmp_tree = this->_tree;
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
				std::allocator<pair<const Key,T> >	alloc;
				
				if (this->_tree._root)
				{
					this->_tree.delete_tree(this->_tree._root);
					this->_tree._root = NULL;
				}
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
				iterator it(NULL, this->_tree.end());
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
				const_iterator it(NULL, this->_tree.end());
				return it;
			}

			//Count
			size_type count (const key_type& k) const
			{
				size_type ret = 0;

				if (this->_tree.search(k) == NULL)
					return ret;
				return (ret + 1);
			}

			//Lower Bound
			iterator lower_bound (const key_type& k)
			{
				iterator it(this->_tree.begin());
				iterator end(NULL, this->_tree.end());

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
				const_iterator end(NULL, this->_tree.end());

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
				iterator end(NULL, this->_tree.end());

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
				const_iterator end(NULL, this->_tree.end());

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
	
	/* ---------------------------------------------------- */
	/*                                                      */
	/*                     OPERATORS                        */
	/*                                                      */
	/* ---------------------------------------------------- */
	
	template <class Key, class T, class Compare, class Alloc>
	bool operator==(const map<Key, T, Compare, Alloc>& x, const map<Key, T, Compare, Alloc>& y)
	{
		return x.size() == y.size() && ft::equal(x.begin(), x.end(), y.begin());
	}

	template <class Key, class T, class Compare, class Alloc>
	bool operator<(const map<Key, T, Compare, Alloc>& x, const map<Key, T, Compare, Alloc>& y)
	{
		return ft::lexicographical_compare(x.begin(), x.end(), y.begin(), y.end());
	}

	template <class Key, class T, class Compare, class Alloc>
	bool operator!=(const map<Key, T, Compare, Alloc>& x, const map<Key, T, Compare, Alloc>& y)
	{
		return !(x == y);
	}

	template <class Key, class T, class Compare, class Alloc>
	bool operator>(const map<Key, T, Compare, Alloc>& x, const map<Key, T, Compare, Alloc>& y)
	{
		return y < x;
	}

	template <class Key, class T, class Compare, class Alloc>
	bool operator>=(const map<Key, T, Compare, Alloc>& x, const map<Key, T, Compare, Alloc>& y)
	{
		return !(x < y);
	}

	template <class _Key, class T, class Compare, class Alloc>
	bool operator<=(const map<_Key, T, Compare, Alloc>& x, const map<_Key, T, Compare, Alloc>& y)
	{
		return !(y < x);
	}


}


#endif
