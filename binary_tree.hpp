/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   binary_tree.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmartial <tmartial@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/02 11:52:33 by tmartial          #+#    #+#             */
/*   Updated: 2022/07/21 15:34:42 by tmartial         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef BINARY_TREE_HPP
# define BINARY_TREE_HPP

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
# include "node.hpp"

namespace ft
{
	
	template < class Key, class T, class Compare = std::less<Key>, class Alloc = std::allocator<ft::pair<const Key,T> > >
	class tree
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
			typedef	ft::map_iterator<pair<const Key, T> >		iterator;
			typedef	ft::map_iterator<const pair<const Key, T> >	const_iterator;
			typedef	ft::reverse_iterator<iterator> 				reverse_iterator;
			typedef	ft::reverse_iterator<const_iterator>		const_reverse_iterator;
			typedef typename allocator_type::size_type			size_type;
			
			// My Members Types
			typedef node<const Key, T> *								nodePtr;
			typedef std::allocator<node<const key_type, mapped_type> > nodeAlloc;
		
		public:
			nodePtr		_root;
			Compare		_comp;
			Alloc		_alloc;
				
		public:
			/* ---------------------------------------------------- */
			/*                                                      */
			/*                     UTILS                            */
			/*                                                      */
			/* ---------------------------------------------------- */
			//Return a empty node NOT USED
			nodePtr	new_node()
			{
				nodeAlloc	alloc;
				nodePtr		node_ptr;
				
				node_ptr = alloc.allocate(1);
				alloc.construct(node_ptr, node<const Key, T>());
				return (node_ptr);
			}

			//New node with pair param
			nodePtr	new_node(const ft::pair<const Key, T>& val)
			{
				nodeAlloc	alloc;
				nodePtr		node_ptr;
				ft::node<const Key, T>    node(val);
				
				node_ptr = alloc.allocate(1);
				alloc.construct(node_ptr, node);
				return (node_ptr);
			}
			
			//void insert (const value_type& val)
			void insert (const ft::pair<const Key, T>& val)
			{
				if (!this->_root)
				{
					this->_root = new_node(val);
				}
				else
				{
					nodePtr tmp = this->_root;
					
					while (true)
					{
						if (this->_comp(tmp->data->first, val.first))
						{
							if (!tmp->right)
							{
								tmp->right = new_node(val);
								tmp->right->parent = tmp;
								break;
							}
							else
								tmp = tmp->right;
						}
						else
						{
							if (!tmp->left)
							{
								tmp->left = new_node(val);
								tmp->left->parent = tmp;
								break;
							}
							else
							tmp = tmp->left;
						}
					}
				}
			}
			
			bool erase (const value_type& val)
			{
				(void)val;
				//nodePtr tmp = this->search(val.first);
				
				// if (!this->_root || !tmp)
				// 	return false;
				
				// if (tmp == this->_root)
				// {
				// 	this->_root = nullptr;
				// 	return true;
				// }

				// side = this->side(); //false = right
				// if (!tmp->left && !tmp->right) //leaf
				// {
				// 	if (!side)
				// 		tmp->parent->right = nullptr;
				// 	else
				// 		tmp->parent->left = nullptr;
				// 	return true;
				// }

				// if (!tmp->left || !tmp->right)
				// {
				// 	if (!tmp->left)
				// 	{
				// 		if (side == false)
				// 		{
				// 			tmp->parent->right = tmp;
				// 		}
				// 		else
				// 		{
							
				// 		}
				// 	}
						
				// }
				// if (!tmp->left->right)
				// {
				// 	tmp 
				// }
				// if (!tmp->right->left)
				// {
					
				// }
				return true;
			}

			bool erase (const key_type& k)
			{
				(void)k;
				return true;
			}

			bool side(nodePtr src)
			{
				
				if (this->_comp(src->parent->data->first, src->data->first))
					return false; //right
				return true; //left
			}
			/* ---------------------------------------------------- */
			/*                                                      */
			/*                     CONSTRUCTORS                     */
			/*                                                      */
			/* ---------------------------------------------------- */
			tree (const key_compare& comp = key_compare(),const allocator_type& alloc = allocator_type())
			:  _root(nullptr), _comp(comp), _alloc(alloc)
			{
				
			}
			
			~tree()
			{
				//this->printTree(this->_root, nullptr, false, 0);
			}

			/* ---------------------------------------------------- */
			/*                                                      */
			/*                      CAPACITY                        */
			/*                                                      */
			/* ---------------------------------------------------- */
			bool empty() const
			{
				return (!this->_root ? true : false);
			}

			/* ---------------------------------------------------- */
			/*                                                      */
			/*                      FIND                            */
			/*                                                      */
			/* ---------------------------------------------------- */
			nodePtr ret_root()
			{
				return (this->_root);
			}
			
			nodePtr begin()
			{
				nodePtr tmp = this->_root;
				
				if (!tmp)
					return (nullptr);
				if (!tmp->left)
					return (tmp);
				while (tmp->left)
				{
					tmp = tmp->left;
				}
				return (tmp);
			}
			
			nodePtr end()
			{
				nodePtr tmp = this->_root;
				
				if (!tmp)
					return (nullptr);
				if (!tmp->right)
					return (tmp);
				while (tmp->right)
				{
					tmp = tmp->right;
				}
				return (tmp);
			}

			nodePtr	search(const key_type& k)
			{
				nodePtr tmp = this->_root;
				
				if (!tmp)
					return (nullptr);
		
				while (tmp) 
				{
					if (this->_comp(tmp->data->first, k) && tmp->right)
						tmp = tmp->right;
					else if (this->_comp(k, tmp->data->first) && tmp->left)
						tmp = tmp->left;
					else if (this->_comp(k, tmp->data->first) == false && this->_comp(tmp->data->first, k) == false)
						break;
					else
						tmp = nullptr;
				}
				return (tmp);
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
				friend class tree;
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
			/*struct Trunk
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

			void printTree(node<const Key, T>* root, Trunk *prev, bool isLeft, bool type)
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
				std::cout << " " << root->data->first << "( ): " << root->data->second << std::endl;
				if (prev) {
					prev->str = prev_str;
				}
				trunk->str = "   |";
				printTree(root->left, trunk, false, type);
			}*/
		
		
	};
}


#endif
