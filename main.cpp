/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmartial <tmartial@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 15:53:43 by tmartial          #+#    #+#             */
/*   Updated: 2022/07/25 17:49:50 by tmartial         ###   ########.fr       */
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
#include "stack.hpp"
#include <map>
#include <list>
#include <string>


//std::cout << "Hello is passing here" << std::endl;
#define T1 int
#define T2 std::string
#define TESTED_NAMESPACE std

TESTED_NAMESPACE::map<T1, T2> mp;
TESTED_NAMESPACE::map<T1, T2>::iterator it = mp.end();

void	ft_find(T1 const &k)
{
	TESTED_NAMESPACE::map<T1, T2>::iterator ret = mp.find(k);

	if (ret == it)
		std::cout << "map::find(" << k << ") returned end()" << std::endl;
}

void	ft_count(T1 const &k)
{
	std::cout << "map::count(" << k << ")\treturned [" << mp.count(k) << "]" << std::endl;
}

int		main(void)
{
	ft::map<int, int> map;

	map.insert(ft::pair<int, int>(1, 10));
	map.insert(ft::pair<int, int>(2, 10));
	map.insert(ft::pair<int, int>(3, 10));
	map.insert(ft::pair<int, int>(4, 10));

	ft::map<int, int>::iterator it = map.begin();
	return (0);
}


// int		main(void)
// {
// 	ft::map<int, int> map;

// 	map.insert(ft::pair<int, int>(1, 10));
// 	map.insert(ft::pair<int, int>(2, 10));
// 	map.insert(ft::pair<int, int>(3, 10));
// 	map.insert(ft::pair<int, int>(4, 10));

// 	ft::map<int, int>sec(map);

// 	// for (size_t i = 0; i < 3; i++)
// 	// {
// 	// 	ft::cout << "it = " << it->first <<ft::endl;
// 	// 	it++;
// 	// }
	
// 	// for (unsigned long int i = 0; i < 4; i++)
// 	// 	it++->second = i * 7;
	
// 	// ft::map<int, int>::iterator itt = map.begin();
// 	// for (size_t i = 0; i < 4; i++)
// 	// {
// 	// 	std::cout << "it = " << itt->first << " and sec = " << itt->second << std::endl;
// 	// 	itt++;
// 	// }

	
// 	return (0);
// }
