/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmartial <tmartial@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 15:53:43 by tmartial          #+#    #+#             */
/*   Updated: 2022/07/29 10:24:38 by tmartial         ###   ########.fr       */
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
typedef TESTED_NAMESPACE::pair<const T1, T2> T3;

static int iter = 0;

template <typename MAP, typename U>
void	ft_erase(MAP &mp, U param)
{
	std::cout << "\t-- [" << iter++ << "] --" << std::endl;
	mp.erase(param);
}

template <typename MAP, typename U, typename V>
void	ft_erase(MAP &mp, U param, V param2)
{
	std::cout << "\t-- [" << iter++ << "] --" << std::endl;
	mp.erase(param, param2);
}

int		main(void)
{
	std::list<T3> lst;
	unsigned int lst_size = 10;
	for (unsigned int i = 0; i < lst_size; ++i)
		lst.push_back(T3(i, std::string((lst_size - i), i + 65)));
	TESTED_NAMESPACE::map<T1, T2> mp(lst.begin(), lst.end());
	
	ft_erase(mp, ++mp.begin());
	
	ft_erase(mp, mp.begin());
	ft_erase(mp, --mp.end());

	ft_erase(mp, mp.begin(), ++(++(++mp.begin())));
	ft_erase(mp, --(--(--mp.end())), (--mp.end()));

	mp[10] = "Hello";
	mp[11] = "Hi there";
	//TESTED_NAMESPACE::map<T1, T2>::iterator one = --(--(--mp.end()));
	//std::cout << "it = " << one->first <<std::endl;
	ft_erase(mp, --(--(--mp.end())), mp.end());

	// mp[12] = "ONE";
	// mp[13] = "TWO";
	// mp[14] = "THREE";
	// mp[15] = "FOUR";
	// printSize(mp);
	// ft_erase(mp, mp.begin(), mp.end());

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
