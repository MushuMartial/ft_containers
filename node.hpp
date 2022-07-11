/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmartial <tmartial@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 13:16:20 by tmartial          #+#    #+#             */
/*   Updated: 2022/07/11 17:11:29 by tmartial         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef NODE_HPP
# define NODE_HPP

# include "utils.hpp"
# include "pair.hpp"
# include "binary_tree.hpp"

/* 
      2
	/   \
   1     3
*/

namespace ft
{
	template<class Key, class T, class Compare = std::less<Key>,
		class Alloc = std::allocator<pair<const Key,T> >  >
	struct node
	{
		public:
			node*					parent;
			node*					left;
			node*					right;
			ft::pair< Key, T>		data;
			Compare					comp;
			bool					side;
		
			/* ---------------------------------------------------- */
			/*                                                      */
			/*                     CONSTRUCTORS                     */
			/*                                                      */
			/* ---------------------------------------------------- */
			//Constructor Default
			node() : parent(NULL), left(NULL), right(NULL), data(), side()
			{

			}

			//Destructor
			~node()
			{
				
			}

			
	};
}

#endif