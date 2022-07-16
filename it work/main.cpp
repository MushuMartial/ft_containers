/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmartial <tmartial@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 15:53:43 by tmartial          #+#    #+#             */
/*   Updated: 2022/07/16 16:44:33 by tmartial         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <memory>
#include <vector>
#include "vector.hpp"
#include "utils.hpp"
#include "type_traits.hpp"
#include "reverse_iterator.hpp"
#include "map.hpp"
#include "binary_tree.hpp"
#include "pair.hpp"
#include "node.hpp"
#include "map_iterator.hpp"
#include <algorithm>

#include <map>
#include <list>

int		main(void)
{
	ft::tree<int, int> tree;
	tree.insert(ft::pair<int, int>(8, 10));

	tree.insert(ft::pair<int, int>(7, 10));
	tree.insert(ft::pair<int, int>(1, 10));
	tree.insert(ft::pair<int, int>(4, 10));
	tree.insert(ft::pair<int, int>(3, 10));
	tree.insert(ft::pair<int, int>(2, 10));
	tree.insert(ft::pair<int, int>(5, 10));
	tree.insert(ft::pair<int, int>(6, 10));

	ft::map_iterator<ft::pair<int,int> > it;
	it._node = tree.begin();

	std::cout << "first = " << it->first << " && second = " << it->second << std::endl;
	for (size_t i = 0; i < 1; i++)
	{
		++it;
		std::cout << "first = " << it->first << " && second = " << it->second << std::endl;
	}

	
}
