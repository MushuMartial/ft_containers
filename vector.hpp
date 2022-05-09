/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmartial <tmartial@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 15:54:04 by tmartial          #+#    #+#             */
/*   Updated: 2022/05/09 18:00:41 by tmartial         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_HPP
# define VECTOR_HPP

# include <iostream>
# include <memory>
# include <vector>

namespace ft
{
	template<class T, class Allocator = std::allocator<T> >
	class vector
	{
		public:
			typedef T                                        value_type;
    		typedef Allocator                                allocator_type;
    		typedef typename allocator_type::reference       reference;
    		typedef typename allocator_type::const_reference const_reference;
			typedef typename allocator_type::pointer         pointer;
			typedef typename allocator_type::const_pointer   const_pointer;

			typedef typename allocator_type::size_type       size_type;
			typedef typename allocator_type::difference_type difference_type;
			
		private:
			allocator_type	_alloc;
			pointer			_begin;
			size_type		_size;
			size_type		_capacity;

			pointer			_psize;//no need maybe
			pointer			_pcapacity;//no need maybe
		
		public:
			//Constructor Default
			explicit vector(const allocator_type& alloc = allocator_type()) 
			: _alloc(alloc), _begin(nullptr), _size(0), _capacity(0) {}
			
			//Constructor Fill
			explicit vector (size_type n, const value_type& val = value_type(), const allocator_type& alloc = allocator_type())
			: _alloc(alloc), _begin(nullptr), _size(n), _capacity(n * 2) 
			{
				this->_begin = this->_alloc.allocate(_capacity, 0);
				for (size_type i = 0; i < this->_size; i++)
					this->_alloc.construct(this->_begin + i, val);
			}

			//Constructor Range
			/*template <class InputIterator>
			vector (InputIterator first, InputIterator last, const allocator_type& alloc = allocator_type())
			{
				return ;
			}*/

			//Constructor Copy /* Destruction doesnt work */
			vector (const vector& x) : _alloc(x._alloc), _begin(x._begin), _size(x._size), _capacity(x._capacity) 
			{
				for (size_type i = 0; i < this->_size; i++)
					this->_alloc.construct(this->_begin + i, *(x._begin + i));
			}
			
			//Destructor
			~vector()
			{
				for (size_type i = 0; i < this->_size; i++)
					this->_alloc.destroy(this->_begin + i);
				this->_alloc.deallocate(_begin, _capacity);
			}
	};
}


#endif