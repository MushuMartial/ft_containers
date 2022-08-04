/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   binary_tree.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmartial <tmartial@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/02 11:52:33 by tmartial          #+#    #+#             */
/*   Updated: 2022/08/04 14:33:34 by tmartial         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef BINARY_TREE_HPP
# define BINARY_TREE_HPP

# include "utils.hpp"

int i = 0;

namespace ft
{
	template<class Key, class T>
	struct node
	{
		public:
			node*					parent;
			node*					left;
			node*					right;
			ft::pair<const Key, T>*	data;
		
			node() : parent(NULL), left(NULL), right(NULL), data(NULL)
			{

			}

			node(const ft::pair<const Key, T>& val) : parent(NULL), left(NULL), right(NULL), data(NULL)
			{
				std::allocator<ft::pair<const Key,T> >	alloc;

				this->data = alloc.allocate(1);
				alloc.construct(this->data, val);
			}
			
			node (const node& x)
			:  parent(x.parent), left(x.left), right(x.right), data(x.data)
			{
				
			}
			
			~node()
			{
				std::allocator<pair<const Key,T> >	alloc;
				
				if (this->data)
				{
					alloc.destroy(this->data);
					alloc.deallocate(this->data, 1);
				 	this->data = NULL;
				}
			}
	};
	
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
			typedef typename allocator_type::size_type			size_type;
			
			// My Members Types
			typedef node<const Key, T> *								nodePtr;
			typedef std::allocator<node<const key_type, mapped_type> >	nodeAlloc;
		
		public:
			nodePtr		_root;
			Compare		_comp;
			Alloc		_alloc;
				
		public:
			/* ---------------------------------------------------- */
			/*                                                      */
			/*                     CONSTRUCTORS                     */
			/*                                                      */
			/* ---------------------------------------------------- */
			tree (const key_compare& comp = key_compare(),const allocator_type& alloc = allocator_type())
			:  _root(NULL), _comp(comp), _alloc(alloc)
			{
				
			}
			
			~tree()
			{
				//this->delete_tree(this->_root);
				//this->printTree(this->_root, NULL, false, 0);
			}
		
			/* ---------------------------------------------------- */
			/*                                                      */
			/*                     UTILS                            */
			/*                                                      */
			/* ---------------------------------------------------- */
			//New node with pair param
			nodePtr	new_node(const value_type& val)
			{
				nodeAlloc	alloc;
				nodePtr		node_ptr;
				
				node_ptr = alloc.allocate(1);
				alloc.construct(node_ptr, val);
				return (node_ptr);
			}
	
			//Delete Tree
			void delete_tree(nodePtr src)
			{
				std::allocator<node<const Key, T> >	alloca;
				
				if (src->left)
					delete_tree(src->left);
				if (src->right)
					delete_tree(src->right);
				alloca.destroy(src);
				alloca.deallocate(src, 1);
				src = NULL;
			}
			
			//Destroy Node
			void destroy_node(nodePtr src)
			{
				std::allocator<node<const Key, T> >	alloca;
				alloca.destroy(src);
				alloca.deallocate(src, 1);
			}
			
			//Insert
			void insert (const value_type& val)
			{
				if (!this->_root)
					this->_root = new_node(val);
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
			
			//Return true if something is erased
			bool erase (const key_type& k)
			{
				nodePtr tmp = this->search(k);
				std::allocator<node<const Key, T> >	alloca;
				
				if (!this->_root || !tmp) //No Tree or k is not in tree
				 	return false;

				if (tmp == this->_root) //erase root
				{
					if (!tmp->left && !tmp->right)
						this->_root = NULL;
					else if (!tmp->left)
					{
						tmp->right->parent = NULL;
						this->_root = tmp->right;
					}
					else if (!tmp->right)
					{
						tmp->left->parent = NULL;
						this->_root = tmp->left;
					}
					else
					{
						tmp->right->parent = NULL;
						tmp->left->parent = this->down_smallest_node(tmp->right); //DO NOT CHANGE ORDER
						(this->down_smallest_node(tmp->right))->left = tmp->left;
						this->_root = tmp->right;
						destroy_node(tmp);
						tmp = NULL;
					}
				 	return true;
				}
				
				bool side = this->side(tmp, tmp->parent); //false: parent->left = tmp, true: parent->right = tmp; 
				if (!tmp->left && !tmp->right) //erase leaf
				{
					if (!side)
						tmp->parent->left = NULL;
					else
						tmp->parent->right = NULL;
					destroy_node(tmp);
					tmp = NULL;
					return true;
				}
				else if (!tmp->left || !tmp->right)  //erase single node
				{
					if (!tmp->left)
					{
						tmp->right->parent = tmp->parent;
						if (!side)//parent->left = tmp
							tmp->parent->left = tmp->right;
						else//parent->right = tmp
							tmp->parent->right = tmp->right;
					}
					else
					{
						tmp->left->parent = tmp->parent;
						if (!side)
							tmp->parent->left = tmp->left;
						else
							tmp->parent->right = tmp->left;
					}
					destroy_node(tmp);
					return true;
				}
				else
				{
					tmp->right->parent = tmp->parent;
					tmp->left->parent = this->down_smallest_node(tmp->right); //DO NOT CHANGE ORDER
					(this->down_smallest_node(tmp->right))->left = tmp->left;
					if (!side)
						tmp->parent->left = tmp->right;
					else
						tmp->parent->right = tmp->right;
					destroy_node(tmp);
					return true;
				}
				return false;
			}

			//Return side of the child compared to parent
			bool side(nodePtr child, nodePtr parent) const
			{
				if (parent->left == child)
					return false; //left
				return true; //right
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
			nodePtr ret_root() const
			{
				nodePtr tmp = this->_root;
				return (tmp);
			}
			
			//Return Smallest Node
			nodePtr begin() const//IF NOT HERE BUG
			{
				nodePtr tmp = this->_root;
				
				if (!tmp)
					return (NULL);
				if (!tmp->left)
					return (tmp);
				while (tmp->left)
				{
					tmp = tmp->left;
				}
				return (tmp);
			}
			
			//Return Biggest Node
			nodePtr end() const
			{
				nodePtr tmp = this->_root;
				
				if (!tmp)
					return (NULL);
				if (!tmp->right)
					return (tmp);
				while (tmp->right)
				{
					tmp = tmp->right;
				}
				return (tmp);
			}
			
			//Return node or NULL if not found
			nodePtr	search(const key_type& k) const
			{
				nodePtr tmp = this->_root;
				
				if (!tmp)
					return (NULL);

				while (tmp) 
				{
					if (this->_comp(tmp->data->first, k) && tmp->right) //bigger
						tmp = tmp->right;
					else if (this->_comp(k, tmp->data->first) && tmp->left) //smaller
						tmp = tmp->left;
					else if (this->_comp(k, tmp->data->first) == false && this->_comp(tmp->data->first, k) == false) //equal
						break;
					else //tmp not found
						tmp = NULL;
				}
				return (tmp);
			}
			
			//Return smallest node
			nodePtr down_smallest_node(nodePtr src) const
			{
				nodePtr tmp = src;

				while (tmp->left)
					tmp = tmp->left;
				return tmp;
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
			// printTree(this->_root, NULL, false, 0);
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
			}
	};
}


#endif
