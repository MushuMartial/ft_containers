/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmartial <tmartial@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 15:53:43 by tmartial          #+#    #+#             */
/*   Updated: 2022/05/13 15:20:21 by tmartial         ###   ########.fr       */
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
	std::vector<int> bar(10, 90);

	std::vector<int>::iterator i;
	std::vector<int>::iterator j;
	i = bar.begin();
	j = bar.begin() + 2;

	
	




	
	
	return (0);
}
