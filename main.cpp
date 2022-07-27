/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmartial <tmartial@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 15:53:43 by tmartial          #+#    #+#             */
/*   Updated: 2022/07/27 16:28:40 by tmartial         ###   ########.fr       */
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

struct ft_more {
	bool	operator()(const T1 &first, const T1 &second) const {
		return (first > second);
	}
};

typedef TESTED_NAMESPACE::map<T1, T2, ft_more> ft_mp;
typedef TESTED_NAMESPACE::map<T1, T2, ft_more>::iterator ft_mp_it;

int		main(void)
{
	ft_mp mp;

	mp[42] = "fgzgxfn";
	mp[25] = "funny";
	mp[80] = "hey";
	mp[12] = "no";
	mp[27] = "bee";
	mp[90] = "8";
	
	ft_mp_it it = mp.begin();
	ft_mp_it it_end = mp.end();
	
	while (it != it_end)
	{
		std::cout << "it = " << it->first <<std::endl;
		it++;
	}

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
