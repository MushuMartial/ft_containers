/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmartial <tmartial@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 15:53:43 by tmartial          #+#    #+#             */
/*   Updated: 2022/07/26 15:51:54 by tmartial         ###   ########.fr       */
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
#define TESTED_NAMESPACE ft
#define T1 int
#define T2 std::string
typedef TESTED_NAMESPACE::map<T1, T2>::value_type T3;

static int iter = 0;

template <typename MAP>
void	ft_erase(MAP &mp, const T1 param)
{
	//std::cout << "Hello is passing here" << std::endl;
	std::cout << "\t-- [" << iter++ << "] --" << std::endl;
	mp.erase(param);
}

int		main(void)
{
	TESTED_NAMESPACE::map<T1, T2> mp;

	mp[42] = "lol";

	mp[50] = "mdr";
	mp[25] = "funny";

	mp[46] = "bunny";
	mp[21] = "fizz";
	mp[30] = "buzz";
	mp[55] = "fuzzy";

	mp[18] = "bee";
	mp[23] = "coconut";
	mp[28] = "diary";
	mp[35] = "fiesta";
	mp[44] = "hello";
	mp[48] = "world";
	mp[53] = "this is a test";
	mp[80] = "hey";

	mp[12] = "no";
	mp[20] = "idea";
	mp[22] = "123";
	mp[24] = "345";
	mp[27] = "27";
	mp[29] = "29";
	mp[33] = "33";
	mp[38] = "38";

	mp[43] = "1";
	mp[45] = "2";
	mp[47] = "3";
	mp[49] = "4";
	mp[51] = "5";
	mp[54] = "6";
	mp[60] = "7";
	mp[90] = "8";


	ft_erase(mp, 90);
	ft_erase(mp, 25); // right != NULL; left != NULL
	ft_erase(mp, 55); // right != NULL; left != NULL
	ft_erase(mp, 24); // right != NULL; left != NULL
	ft_erase(mp, 54); // right != NULL; left != NULL
	ft_erase(mp, 22); // right == NULL; left == NULL
	ft_erase(mp, 51); // right == NULL; left == NULL
	ft_erase(mp, 21); // right == NULL; left != NULL
	ft_erase(mp, 53); // right != NULL; left == NULL
	ft_erase(mp, 20); // right == NULL; left != NULL
	// ft_erase(mp, 23); // right != NULL; left != NULL
	// ft_erase(mp, 42); // right != NULL; left != NULL; parent == NULL
	// ft_erase(mp, 38); // right != NULL; left != NULL; parent == NULL
	// ft_erase(mp, 35); // right != NULL; left != NULL; parent == NULL
	
	// std::cout << "IT WORKS" << std::endl;
	// ft_erase(mp, 33); // right != NULL; left != NULL; parent == NULL

	return (0);
}



// int		main(void)
// {
// 	ft::map<int, int> map;

// 	map.insert(ft::pair<int, int>(3, 10));
// 	map.insert(ft::pair<int, int>(2, 10));
// 	map.insert(ft::pair<int, int>(1, 10));
// 	map.insert(ft::pair<int, int>(5, 10));
// 	map.insert(ft::pair<int, int>(4, 10));
// 	map.insert(ft::pair<int, int>(6, 10));

	

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
