/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmartial <tmartial@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 15:53:43 by tmartial          #+#    #+#             */
/*   Updated: 2022/07/23 15:01:30 by tmartial         ###   ########.fr       */
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
#include <string>
#include <cstdlib>

int main()
{
	ft::map<int, int> first;

	for (int i = 1; i <= 11; i++)
		first.insert(ft::pair<int, int>(i, 10));
	
	ft::map<int, int>::const_iterator it(first.begin());



	
	//ft::map<int, int>::iterator it_end = first.end();

	// ft::map<int, int> two(it, it_end);
	// it = two.begin();
	// it_end = two.end();
	// while (it != it_end)
	// {
	// 	std::cout << "first = " << it->first << std::endl;
	// 	it++;
	// }
	// std::cout << "end = " << it_end->first << std::endl;
	
	
	
}