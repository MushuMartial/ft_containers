/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmartial <tmartial@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 15:54:04 by tmartial          #+#    #+#             */
/*   Updated: 2022/05/11 18:02:25 by tmartial         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_HPP
# define VECTOR_HPP

# include <iostream>
# include <memory>
# include <vector>
# include "random_iterator.hpp"

/* Order 
	- Non memberfuctions
	- Elemenet Access
	- Capacity
	- Modifiers
	iterators_traits
	reverse_iterator
*/
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

			//typedef typename ft::random_access_iterator<value_type>			iterator;
			//typedef typename ft::random_access_iterator<const value_type>	const_iterator;
			//typedef typename ft::reverse_iterator<iterator>					reverse_iterator;
			//typedef typename ft::reverse_iterator<const_iterator>			const_reverse_iterator;
			
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
			/* ----- Constructors ------ */
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

			//Constructor Copy
			vector (const vector& x) : _alloc(x._alloc), _begin(x._begin), _size(x._size), _capacity(x._capacity) 
			{
				this->_begin = this->_alloc.allocate(_capacity, 0);
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

			//Operator =
			vector& operator=(const vector& x)
			{
				this->_alloc = x._alloc;
				this->_begin = x._begin;
				this->_size = x._size;
				this->_capacity = x._capacity;
				
				this->_begin = this->_alloc.allocate(_capacity, 0);
				for (size_type i = 0; i < this->_size; i++)
					this->_alloc.construct(this->_begin + i, *(x._begin + i));
				return (*this);
			}
			
			/* ----- Iterators ----- */
			//Begin
			/*iterator begin()
			{
				return (this->_begin);
			}*/

			/* ----- Capacity ----- */
			//Size
			size_type size() const
			{
				return this->_size;
			}
			/* ----- Relational operators ----- */
			//Operator ==

			/* template <class T, class Alloc>
			bool operator==(const vector<T, Alloc>& lhs, const vector<T, Alloc>& rhs)
			{
				return (lhs.size() == rhs.size() && ft::equal(lhs.begin(), lhs.end(), rhs.begin()));
			}*/
			
			
			

			
	};
	
	/* ----- Relational operators ----- */
	//Operator ==
	template <class T, class Alloc>
  	bool operator== (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
	{
		if (lhs.size() != rhs.size())
			return false;
		for (size_t i = 0; i < lhs.size(); i++)
		{
			if (*(rhs.begin() + i) != *(lhs.begin() + i))
				return false;
		}
		return true;
	}
}


#endif