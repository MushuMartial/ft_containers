/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmartial <tmartial@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 15:53:43 by tmartial          #+#    #+#             */
/*   Updated: 2022/05/18 18:20:02 by tmartial         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <memory>
#include <vector>
#include "vector.hpp"
#include "random_iterator.hpp"
#include "type_traits.hpp"

//Yasin chaussure
int main()
{
	ft::vector<int> foo(4, 100);
	std::vector<int> bar(4, 90);

	ft::vector<int>::iterator it_foo = foo.begin();
	std::vector<int>::iterator it_bar = bar.begin();

	foo.pop_back();
	bar.pop_back();

	for (size_t i = 0; i < 4; i++)
	{
		std::cout << "foo = " << foo[i] << std::endl;
	}
	for (size_t i = 0; i < 4; i++)
	{
		std::cout << "bar = " << bar[i] << std::endl;
	}
	

	return (0);
}
