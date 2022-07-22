/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmartial <tmartial@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 15:53:43 by tmartial          #+#    #+#             */
/*   Updated: 2022/07/22 12:06:31 by tmartial         ###   ########.fr       */
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
	ft::map<int, int> first;
	first.insert(ft::pair<int, int>(2, 10));
	first.insert(ft::pair<int, int>(1, 10));
	first.insert(ft::pair<int, int>(3, 10));
	first.insert(ft::pair<int, int>(4, 10));

	ft::map<int, int>::iterator it = first.begin();

	size_t i = first.size();
	

}
