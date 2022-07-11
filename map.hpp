/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmartial <tmartial@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 18:08:23 by tmartial          #+#    #+#             */
/*   Updated: 2022/07/05 17:01:44 by tmartial         ###   ########.fr       */
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
			typedef	Key											key_type;
			typedef	T											mapped_type;
			typedef	std::pair<const key_type, mapped_type>		value_type;
			typedef	Compare										key_compare;
			typedef	Alloc										allocator_type;
			typedef	typename allocator_type::reference			reference;
			typedef	typename allocator_type::const_reference	const_reference;
			typedef	typename allocator_type::pointer			pointer;
			typedef	typename allocator_type::const_pointer		const_pointer;
			//typedef	ft::map_iterator<pair<const Key, T> >		iterator;
			//typedef	ft::map_iterator<const pair<const Key, T> >	const_iterator;
			//typedef	ft::reverse_iterator<iterator> 				reverse_iterator;
			//typedef	ft::reverse_iterator<const_iterator>		const_reverse_iterator;
			typedef typename allocator_type::size_type			size_type;

			typedef node<Key, T> *								nodePtr;
			typedef std::allocator<node<key_type, mapped_type> > nodeAlloc;
		
		private:
			nodePtr		_root;
			Compare		_comp;
			Alloc		_alloc;
				
		public:
			/* ---------------------------------------------------- */
			/*                                                      */
			/*                     UTILS                            */
			/*                                                      */
			/* ---------------------------------------------------- */
			/* return a empty node */
			nodePtr	new_node()
			{
				nodeAlloc	alloc;
				nodePtr		node_ptr;
				
				node_ptr = alloc.allocate(1);
				alloc.construct(node_ptr, node<Key, T>());
				return (node_ptr);
			}

			/*node* newNode(value_type val)
			{
				NodePtr	node = this->nodeAlloc.allocate(1);
				this->nodeAlloc.construct(node, val);
				node->left = this->TreeNull;
				node->right = this->TreeNull;
				node->parent = NULL;
				node->color = RED;
				return (node);
			}*/
			
			//void insert (const value_type& val)
			void insert (const std::pair<const Key, T>& val)
			{
				this->_root->data = val;
			}
			/* ---------------------------------------------------- */
			/*                                                      */
			/*                     CONSTRUCTORS                     */
			/*                                                      */
			/* ---------------------------------------------------- */
			//Constructor Default
			explicit map (const key_compare& comp = key_compare(),const allocator_type& alloc = allocator_type())
			:  _root(), _comp(comp), _alloc(alloc)
			{
				this->_root = new_node();
				//this->_root
			}

			//Constructor Range
			//template <class InputIterator>
  			//map (InputIterator first, InputIterator last,const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type());

			//Constructor Copy
			map (const map& x);

			//Destructor
			~map()
			{
				printTree(this->_root, nullptr, false, 0);
			}

			//Operator =
			map& operator= (const map& x);

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
			/*                      DEBUG		                    */
			/*                                                      */
			/* ---------------------------------------------------- */
			// printTree(this->_root, nullptr, false, 0);
			struct Trunk
			{
				Trunk *prev;
				std::string str;

				Trunk(Trunk *prev, std::string str)
				{
					this->prev = prev;
					this->str = str;
				}
			};

			void showTrunks(Trunk *p)
			{
				if (p == NULL) {
					return;
				}

				showTrunks(p->prev);
				std::cout << p->str;
			}

			void printTree(node<Key, T>* root, Trunk *prev, bool isLeft, bool type)
			{
				if (root == NULL) {
					return;
				}

				std::string prev_str = "    ";
				Trunk *trunk = new Trunk(prev, prev_str);

				printTree(root->right, trunk, true, type);
				if (!prev) {
					trunk->str = "———";
				}
				else if (isLeft)
				{
					trunk->str = "/———";
					prev_str = "   |";
				}
				else {
					trunk->str = "\\———";
					prev->str = prev_str;
				}
				showTrunks(trunk);
				std::cout << " " << root->data.first << "( ): " << root->data.second << std::endl;
				if (prev) {
					prev->str = prev_str;
				}
				trunk->str = "   |";
				printTree(root->left, trunk, false, type);
			}
			/*
			public :
			typedef Key													key_type;
			typedef T													mapped_type;
			typedef ft::pair<const Key,T>								value_type;
			typedef Compare												key_compare;
			typedef std::allocator<ft::pair<const Key,T> >				allocator_type;
			typedef std::allocator<ft::Node<const Key,T> >				allocator_type_node;
			typedef int													difference_type;
			typedef size_t												size_type;
			typedef ft::map_iterator<value_type, Node>					iterator;
			typedef ft::map_iterator<const value_type, Node>			const_iterator;
			typedef ft::map_reverse_iterator<value_type, Node>			reverse_iterator;
			typedef ft::map_reverse_iterator<const value_type, Node>	const_reverse_iterator;
			
			private:
			Node *					_root;
			Node *					_null;
			key_compare				_comp;
			allocator_type			_alloc_pair;
			allocator_type_node		_alloc_node;*/
		
	};
}


#endif
