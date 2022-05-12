/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmartial <tmartial@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 15:54:04 by tmartial          #+#    #+#             */
/*   Updated: 2022/05/12 15:29:23 by tmartial         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_HPP
# define VECTOR_HPP

# include <iostream>
# include <memory>
# include <vector>
# include <iterator>
# include "random_iterator.hpp"

/* Order
	- Constructors
	- Non memberfuctions
	- Elemenet Access
	- Capacity
	- Modifiers
	iterators_traits
	reverse_iterator
*/

/* ----- Doesnt work ----- */
/* 
	- Construct range
	- Swap
	
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
			typedef T*										iterator;//temporaire
			typedef const T*								const_iterator;//temporaire
			
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

			//Constructor Range /* ----- Doesnt work ----- */
			/*template <class InputIterator>
			vector (InputIterator first, InputIterator last, const allocator_type& alloc = allocator_type())
			: _alloc(alloc), _begin(nullptr), _size(std::distance(first, last)), _capacity(std::distance(first, last) * 2) 
			{
				this->_begin = this->_alloc.allocate(_capacity, 0);
				for (size_type i = 0; i < this->_size; i++)
					this->_alloc.construct(this->_begin + i, *(first) + i);
			}*/

			//Constructor Copy
			vector (const vector& x)
			: _alloc(x._alloc), _begin(x._begin), _size(x._size), _capacity(x._capacity) 
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
			iterator begin()
			{
				return (this->_begin);
			}

			const_iterator begin() const
			{
				return (this->_begin);
			}

			/* ----- Capacity ----- */
			//Size
			size_type size() const
			{
				return this->_size;
			}

			/* ----- Element Access ----- */

			/* ----- Modifiers ----- */
			
	};
	
	/* ----- Relational operators ----- */
	template <class T, class Alloc>
	bool operator== (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs);

	template <class T, class Alloc>
	bool operator!= (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs);

	template <class T, class Alloc>
	bool operator< (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs);

	template <class T, class Alloc>
	bool operator<= (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs);

	template <class T, class Alloc>
	bool operator> (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs);

	template <class T, class Alloc>
	bool operator>= (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs);

	//Swap
	template <class T, class Alloc>
	void swap(vector<T,Alloc>& x, vector<T,Alloc>& y);
}

/* ----- Relational operators ----- */
//Operator ==
template <class T, class Alloc>
bool ft::operator== (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
{
	if (lhs.size() != rhs.size())
		return false;
	for (size_t i = 0; i < lhs.size(); i++)
	{
		if (*rhs.begin() + i != *lhs.begin() + i)
			return false;
	}
	return true;
}

//Operator !=
template <class T, class Alloc>
bool ft::operator!= (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
{
	if (lhs.size() != rhs.size())
		return true;
	for (size_t i = 0; i < lhs.size(); i++)
	{
		if (*rhs.begin() + i != *lhs.begin() + i)
			return true;
	}
	return false;
}

//Operator <
template <class T, class Alloc>
bool ft::operator<  (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
{
	size_t i = 0;
		
	while (i < lhs.size())
	{
		if ( i == rhs.size() || (*rhs.begin() + i < *lhs.begin() + i) )
			return false;
		else if (*lhs.begin() + i < *rhs.begin() + i)
			return true;
		i++;
	}
	return (i != rhs.size());
}

//Operator <=
template <class T, class Alloc>
bool ft::operator<= (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
{
	size_t i = 0;
		
	while (i < lhs.size())
	{
		if ( i == rhs.size() || (*rhs.begin() + i <= *lhs.begin() + i) )
			return false;
		else if (*lhs.begin() + i <= *rhs.begin() + i)
			return true;
		i++;
	}
	return (i != rhs.size());
}

//Operator >
template <class T, class Alloc>
bool ft::operator>  (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
{
	size_t i = 0;
		
	while (i < lhs.size())
	{
		if ( i == rhs.size() || (*rhs.begin() + i > *lhs.begin() + i) )
			return false;
		else if (*lhs.begin() + i > *rhs.begin() + i)
			return true;
		i++;
	}
	return (i != rhs.size());
}

//Operator >=
template <class T, class Alloc>
bool ft::operator>= (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
{
	size_t i = 0;
		
	while (i < lhs.size())
	{
		if ( i == rhs.size() || (*rhs.begin() + i >= *lhs.begin() + i) )
			return false;
		else if (*lhs.begin() + i >= *rhs.begin() + i)
			return true;
		i++;
	}
	return (i != rhs.size());
}

/* ----- Swap ----- */ /* ---- Doesnt Work ---- */
/*template <class T, class Alloc>
void ft::swap(vector<T,Alloc>& x, vector<T,Alloc>& y)
{
	x.swap(y);
}*/

#endif