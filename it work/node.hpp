/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmartial <tmartial@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 13:16:20 by tmartial          #+#    #+#             */
/*   Updated: 2022/07/13 15:30:30 by tmartial         ###   ########.fr       */
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

#define EMPTY 0
#define LEFT 1
#define RIGHT 2
#define ROOT 3


namespace ft
{
	template<class Key, class T, class Compare = std::less<Key>,
		class Alloc = std::allocator<pair<const Key,T> >  >
	struct node
	{
		public:
			typedef	ft::pair<const Key, T>		value_type;
		
		public:
			node*					parent;
			node*					left;
			node*					right;
			ft::pair<Key, T>		data;
			Compare					comp;
			int						side;
		
			/* ---------------------------------------------------- */
			/*                                                      */
			/*                     CONSTRUCTORS                     */
			/*                                                      */
			/* ---------------------------------------------------- */
			//Constructor Default
			node() : parent(NULL), left(NULL), right(NULL), data(), side(0)
			{
				//std::cout << "Root in node = " << this->data.first << std::endl;
			}

			//Destructor
			~node()
			{
				
			}

			

			
	};
}

#endif