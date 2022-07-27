/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmartial <tmartial@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 13:16:20 by tmartial          #+#    #+#             */
/*   Updated: 2022/07/27 20:31:27 by tmartial         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef NODE_HPP
# define NODE_HPP

# include "utils.hpp"
# include "pair.hpp"
# include "binary_tree.hpp"

namespace ft
{
	template<class Key, class T, class Compare = std::less<Key>,
		class Alloc = std::allocator<pair<const Key,T> >  >
	struct node
	{
		public:
			typedef	ft::pair<const Key, T>		value_type;
			typedef	Compare						key_compare;
		
		public:
			node*					parent;
			node*					left;
			node*					right;
			ft::pair<const Key, T>*	data;
			Compare					comp;
		
			/* ---------------------------------------------------- */
			/*                                                      */
			/*                     CONSTRUCTORS                     */
			/*                                                      */
			/* ---------------------------------------------------- */
			//Constructor Default
			node() : parent(NULL), left(NULL), right(NULL), data(NULL)
			{

			}

			node(const ft::pair<const Key, T>& val) : parent(NULL), left(NULL), right(NULL)
			{
				std::allocator<pair<const Key,T> >	alloc;

				this->data = alloc.allocate(1);
				alloc.construct(this->data, val);
			}
			//Destructor
			~node()
			{
				// std::allocator<pair<const Key,T> >	alloc;

				// if (this->data)
				// {
				// 	alloc.destroy(this->data);
				// 	alloc.deallocate(data, 1);
				// }
			}

			
	};
}

#endif