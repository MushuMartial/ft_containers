/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmartial <tmartial@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 15:53:43 by tmartial          #+#    #+#             */
/*   Updated: 2022/05/18 13:42:08 by tmartial         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <memory>
#include <vector>
#include "vector.hpp"
#include "random_iterator.hpp"
#include "type_traits.hpp"

int main()
{
	ft::vector<int> foo(10, 100);
	//ft::vector<int> bar;
	ft::vector<int> bar(2, 90);

	bar.push_back(12);
	bar.push_back(13);
	bar.push_back(14);
	for (size_t i = 0; i < 5; i++)
	{
		std::cout << "bar = " << bar[i] << std::endl;
	}
	

	
	




	
	
	return (0);
}
