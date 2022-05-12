/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmartial <tmartial@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 15:53:43 by tmartial          #+#    #+#             */
/*   Updated: 2022/05/12 15:25:41 by tmartial         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <memory>
#include <vector>
#include "vector.hpp"
#include "random_iterator.hpp"

int main()
{
	ft::vector<int> foo(10, 100);
	//ft::vector<int> bar;

	ft::vector<int>::iterator i;
	i = foo.begin();
	ft::vector<int>::iterator j; 
	j = foo.begin() + 3;

	//ft::vector<int> bar(i, j);


	
	
	return (0);
}
