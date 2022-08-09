/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_iterator.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmartial <tmartial@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/02 11:52:03 by tmartial          #+#    #+#             */
/*   Updated: 2022/08/09 17:45:22 by tmartial         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef MAP_ITERATOR_HPP
# define MAP_ITERATOR_HPP

# include "random_access_iterator.hpp"
# include "reverse_iterator.hpp"
# include "utils.hpp"
# include "binary_tree.hpp"

template<class Key, class T>
struct node;

namespace	ft
{
	template< class T2 > struct remove_const                { typedef T2 type; };
	template< class T2 > struct remove_const<const T2>       { typedef T2 type; };
	
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

			// My Members Types
			typedef node<typename T::first_type, typename T::second_type>* nodePtr;

		private:
			//Attributes
			nodePtr	_node;
			nodePtr	_end;
		
		public:
			/* ---------------------------------------------------- */
			/*                                                      */
			/*                     CONSTRUCTORS                     */
			/*                                                      */
			/* ---------------------------------------------------- */
			map_iterator() : _node(NULL), _end(NULL)
			{
				
			}

			map_iterator(nodePtr node) : _node(node), _end(NULL)
			{
				
			}

			
			map_iterator(nodePtr node, nodePtr end) : _node(node), _end(end)
			{
				
			}

			map_iterator(const map_iterator<typename remove_const<T>::type> & ref) : _node(ref._node), _end(ref._end)
			{
				
			}
			
			map_iterator	&operator=(const map_iterator& ref)
			{
				this->_node = ref._node;
				this->_end	= ref._end;
				return (*this);
			}

			~map_iterator() {}
			
			/* ---------------------------------------------------- */
			/*                                                      */
			/*                     OPERATORS                        */
			/*                                                      */
			/*  --------------------------------------------------- */
			map_iterator&	operator++()
			{
				if (this->_node == NULL)//iterator at end or empty 
				{
					return *this;
				}
				
				else if (!this->_node->parent && !this->_node->right)//node == root && !right
				{
					this->_end = this->_node;
					this->_node = NULL;
				}

				else if (this->_node->right)
				{
					this->_node = down_bigger_node();
				}
				
				else
				{
					this->_node = up_bigger_node(this->_node);
				}
				return *this;
			}

			map_iterator  operator++(int)
			{
				map_iterator tmp = *this;

				this->operator++();
				return (tmp);
			}

			map_iterator&	operator--()
			{
				if (this->_node == NULL)//iterator at end or empty 
				{
					if (this->_end)
						this->_node = this->_end;
				}
				else if (!this->_node->parent && !this->_node->left)//node == root && !left
				{
					this->_node = NULL;
				}
				else if (this->_node->left)
				{
					this->_node = down_smallest_node();
				}
				else
				{
					this->_node = up_smallest_node(this->_node);
				}
				return *this;
			}

			map_iterator  operator--(int)
			{
				map_iterator tmp = *this;

				--*this;
				return tmp;
			}
			
			T&	operator*() const
			{
				return (*(this->_node->data));
			}

			T*		operator->() const 
			{
				return (this->_node->data);
			}

			bool	operator==(const map_iterator ref) const 
			{
				if (!this->_node || !ref._node)
				{
					if (!this->_node && !ref._node)
						return true;
					return false;
				}
				if (this->_node == ref._node)
				 	return true;
				return false;
			}
			
			bool	operator!=(const map_iterator ref) const 
			{
				if (!this->_node || !ref._node)
				{
					if (!this->_node && !ref._node)
						return false;
					return true;
				}
				if (this->_node == ref._node)
				 	return false;
				return true;
			}
			/* ---------------------------------------------------- */
			/*                                                      */
			/*                     UTILS                            */
			/*                                                      */
			/* ---------------------------------------------------- */
		private:
			//Return root
			nodePtr ret_root()
			{
				nodePtr tmp = this->_node;

				while (tmp->parent)
				{
					tmp = tmp->parent;
				}
				return (tmp);
			}
			

			//Return the node bigger than this->_node on the branch
			nodePtr up_bigger_node(nodePtr node)
			{
				nodePtr next;
				if (!node->right)
				{
					next = node;
					if (next->parent->right != next && next != next->parent->left)
						return (NULL);
					while (next->parent != NULL && next == next->parent->right)
						next = next->parent;
					next = next->parent;
				}
				else
				{
					next = node->right;
					while (next->left)
						next = next->left;
				}
				return (next);
			}

			//Return next smalles
			nodePtr down_bigger_node()
			{
				nodePtr tmp = this->_node->right;

				while (tmp->left)
				{
					tmp = tmp->left;
				}
				return tmp;
			}

			//Return the node bigger than this->_node on the branch
			nodePtr up_smallest_node(nodePtr node)
			{
				nodePtr	prev;

				if (node->left == NULL || node->left == NULL)
				{
					prev = node;
					while (prev->parent != NULL && prev == prev->parent->left)
						prev = prev->parent;
					prev = prev->parent;
				}
				else
				{
					prev = node->left;
					while (prev->right != NULL)
						prev = prev->right;
				}
				return (prev);
			}

			//Return next smalles
			nodePtr down_smallest_node()
			{
				nodePtr tmp = this->_node->left;

				while (tmp->right)
				{
					tmp = tmp->right;
				}
				return tmp;
			}

			
	
	};
}


#endif