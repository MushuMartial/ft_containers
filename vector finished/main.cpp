/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmartial <tmartial@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 15:53:43 by tmartial          #+#    #+#             */
/*   Updated: 2022/06/29 18:16:09 by tmartial         ###   ########.fr       */
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

#include <list>


// ft::vector<TESTED_TYPE>::iterator it_vec;
	// it_vec = vct.begin();
	// while ( it_vec != vct.end() )
	// {
	// 	std::cout << "- " << *it_vec << std::endl;
	// 	it_vec++;
	// }



int		main(void)
{
	std::vector<int> vec(-1);
	ft::vector<int> tim(1);
	
	// std::list<TESTED_TYPE> lst;
	// std::list<TESTED_TYPE>::iterator lst_it;
	// for (int i = 1; i < 5; ++i)
	// 	lst.push_back(i * 3);

	// ft::vector<TESTED_TYPE> vct(lst.begin(), lst.end());

	// lst_it = lst.begin();
	// for (int i = 1; lst_it != lst.end(); ++i)
	// 	*lst_it++ = i * 5;
	// vct.assign(lst.begin(), lst.end());

	// vct.insert(vct.end(), lst.rbegin(), lst.rend());
	// // ft::vector<TESTED_TYPE>::iterator it_vec;
	// // it_vec = vct.begin();
	// // while ( it_vec != vct.end() )
	// // {
	// // 	std::cout << "- " << *it_vec << std::endl;
	// // 	it_vec++;
	// // }
	return (0);
}
