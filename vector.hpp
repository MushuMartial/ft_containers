/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmartial <tmartial@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 15:54:04 by tmartial          #+#    #+#             */
/*   Updated: 2022/06/22 16:41:59 by tmartial         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_HPP
# define VECTOR_HPP

# include <iostream>
# include <memory>
# include <vector>
# include <iterator>
# include "type_traits.hpp"
# include "reverse_iterator.hpp"

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
			typedef typename ft::reverse_iterator<iterator>					reverse_iterator;
			typedef typename ft::reverse_iterator<const_iterator>			const_reverse_iterator;
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
			/* ---------------------------------------------------- */
			/*                                                      */
			/*                     UTILS                            */
			/*                                                      */
			/* ---------------------------------------------------- */
			pointer reallocate(size_type new_size, size_type cpy_until)
			{
				pointer tmp = this->_alloc.allocate(new_size * 2);
				for (size_type i = 0; i < cpy_until; i++)
					this->_alloc.construct(tmp + i, *(this->_begin + i));
				return tmp;
			}

			void allocation(size_type size, const value_type& val)
			{
				this->_begin = this->_alloc.allocate(size * 2);
				for (size_type i = 0; i < size; i++)
					this->_alloc.construct(this->_begin + i, val);
				this->_size = size;
				this->_capacity = size * 2;
			}

			void deallocation()
			{
				for (size_type i = 0; i < this->_size; i++)
					this->_alloc.destroy(this->_begin + i);
				this->_alloc.deallocate(_begin, _capacity);
			}
			
			/* ---------------------------------------------------- */
			/*                                                      */
			/*                     CONSTRUCTORS                     */
			/*                                                      */
			/* ---------------------------------------------------- */
			//Constructor Default
			explicit vector(const allocator_type& alloc = allocator_type()) 
			: _alloc(alloc), _begin(nullptr), _size(0), _capacity(0) 
			{
				
			}
			
			//Constructor Fill
			explicit vector (size_type n, const value_type& val = value_type(), const allocator_type& alloc = allocator_type())
			: _alloc(alloc), _begin(nullptr), _size(n), _capacity(n * 2) 
			{
				this->_begin = this->_alloc.allocate(_capacity, 0);
				for (size_type i = 0; i < this->_size; i++)
					this->_alloc.construct(this->_begin + i, val);
			}

			//Constructor Range
			template <class InputIterator>
			vector (InputIterator first, InputIterator last, const allocator_type& alloc = allocator_type(),
			typename ft::enable_if<!ft::is_integral<InputIterator>::value>::type* = NULL)
			: _alloc(alloc), _begin(nullptr), _size(std::distance(first, last)), _capacity(std::distance(first, last) * 2) 
			{
				this->_begin = this->_alloc.allocate(_capacity, 0);
				for (size_type i = 0; i < this->_size; i++)
					this->_alloc.construct(this->_begin + i, *first++);
			}

			//Constructor Copy
			vector (const vector& x)
			: _alloc(x._alloc), _begin(nullptr), _size(x._size), _capacity(x._capacity) 
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
			
			/* ---------------------------------------------------- */
			/*                                                      */
			/*                     ITERATORS                        */
			/*                                                      */
			/* ---------------------------------------------------- */
			//Begin
			iterator begin()
			{
				return (this->_begin);
			}

			const_iterator begin() const
			{
				return (this->_begin);
			}

			//End
			iterator end()
			{
				return (this->_begin + this->_size);
			}

			const_iterator end() const
			{
				return (this->_begin + this->_size);
			}

			//RBegin
			reverse_iterator rbegin()
			{
				return (reverse_iterator(this->end()));
			}
			
			const_reverse_iterator rbegin() const
			{
				return (const_reverse_iterator(this->end()));
			}

			//REnd
			reverse_iterator rend()
			{
				return (reverse_iterator(this->begin()));
			}
			
			const_reverse_iterator rend() const
			{
				return (const_reverse_iterator(this->begin()));
			}
			
			/* ---------------------------------------------------- */
			/*                                                      */
			/*                       SIZE                           */
			/*                                                      */
			/* ---------------------------------------------------- */
			//Size
			size_type size() const
			{
				return this->_size;
			}

			//Max_size
			size_type max_size() const
			{
				return this->_alloc.max_size();
			}

			//Resize 
			void resize (size_type n, value_type val = value_type())
			{
				if (n < this->_size)
				{
					for (size_type i = n; i < this->_size; i++)
						this->_alloc.destroy(this->_begin + i);
					this->_size = n + 1;
				}
				else if (n > this->_size && n <= this->_capacity)
				{
					for (size_type i = this->_size; i < n; i++)
						*(this->_begin + i) = val;
					
				}
				else if (n > this->_size && n > this->_capacity)
				{
					pointer tmp = reallocate(n, this->_size);
					deallocation();
					this->_begin = tmp;
					for (size_type i = this->_size; i < n; i++)
						*(this->_begin + i) = val;
					this->_size = n;
					this->_capacity = n * 2;
				}
			}

			//Capacity
			size_type capacity() const
			{
				return this->_capacity;
			}
			
			//Empty
			bool empty() const
			{
				return (this->_size == 0 ? true : false);
			}

			//Reserve 
			void reserve (size_type n)
			{
				if (this->_capacity < n)
				{
					pointer tmp = reallocate(n, this->_size);
					deallocation();
					this->_begin = tmp;
					this->_size = n;
					this->_capacity = n * 2;
				}
			}
			
			
			/* ---------------------------------------------------- */
			/*                                                      */
			/*                   ELEMENT ACCESS                     */
			/*                                                      */
			/* ---------------------------------------------------- */
			//Operator [] //Execption
			reference operator[] (size_type n)
			{
				return *(this->_begin + n);
			}

			const_reference operator[] (size_type n) const
			{
				return *(this->_begin + n);
			}
			
			//At
			reference at (size_type n)
			{
				if (this->_size <= n)
					throw (std::out_of_range("vector"));
				return *(this->_begin + n);
			}

			const_reference at (size_type n) const
			{
				if (this->_size <= n)
					throw (std::out_of_range("vector"));
				return *(this->_begin + n);
			}

			//Front
			reference front()
			{
				return *(this->_begin);
			}
			
			const_reference front() const
			{
				return *(this->_begin);
			}

			//Back
			reference back()
			{
				return *(this->_begin + this->_size - 1);
			}

			const_reference back() const
			{
				return *(this->_begin + this->_size - 1);
			}
			
			/* ---------------------------------------------------- */
			/*                                                      */
			/*                      MODIFIERS                       */
			/*                                                      */
			/* ---------------------------------------------------- */
			//Assign
			template <class InputIterator>
 			void assign (InputIterator first, InputIterator last,
			typename ft::enable_if<!ft::is_integral<InputIterator>::value>::type* = NULL)
			{
				deallocation();
				this->_size = std::distance(first, last);
				this->_capacity = this->_size * 2;
				this->_begin = this->_alloc.allocate(this->_capacity);
				for (size_type i = 0; i < this->_size; i++)
					this->_alloc.construct(this->_begin + i, *first++);
			}
			
			void assign (size_type n, const value_type& val)
			{
				deallocation();
				allocation(n, val);
			}

			//Push_back
			void push_back (const value_type& val)
			{
				if (this->_size < this->_capacity)
				{
					this->_alloc.construct(this->_begin + this->_size, val);
				}
				else
				{
					resize(this->_size + 1, val);
				}
				this->_size += 1;
			}
			
			//Pop_back /* ----- Doesnt work ----- */
			void pop_back()
			{
				if (this->_size != 0)
					this->_alloc.destroy(this->_begin + (this->_size - 1));
				this->_size -= 1;
			}

			//Insert
			iterator insert (iterator position, const value_type& val);
			void insert (iterator position, size_type n, const value_type& val);
			template <class InputIterator>
    		void insert (iterator position, InputIterator first, InputIterator last);

			//Erase
			iterator erase (iterator position);
			iterator erase (iterator first, iterator last);

			/* iterator insert (iterator position, const value_type& val)
			{
				unsigned int i = 0, j = _size;

				for (iterator it = begin(); it < position; it++, i++);
				reserve(_size + 1);
				_size++;
				while (j > i)
				{
					_v[j] = _v[j - 1];
					j--;
				}
				_alloc.construct(_v + i, val);
				return (iterator(_v + i));
			}
			void insert (iterator position, size_type n, const value_type& val)
			{
				unsigned int i = 0, j = _size + n - 1;
				int boo = 0;
				for (iterator it = begin(); it < position; it++, i++);
				reserve(n + _size);
				_size += n;
				while (j >= n + i)
				{
					_v[j] = _v[j - n];
					j--;
				}
				while (j > i && j != 0)
				{
					_alloc.construct(_v + j, val);
					j--;
					boo = 1;
				}
				if (j >= i && boo == 1)
				{
					_alloc.construct(_v + j, val);
					j--;
				}
				return ;
			}
			template <class InputIterator>
			void insert (iterator position, InputIterator first, InputIterator last, typename ft::enable_if<!ft::is_integral<InputIterator>::value, InputIterator>::type* = nullptr)
			{
				unsigned int	i = 0, pos = 0, j = 0;

				for(InputIterator tmp = first; tmp != last; tmp++)
						j++;
				for(iterator tmp = begin(); tmp != position; tmp++)
						pos++;
				reserve(_size + j);
				position = begin() + pos;
				for(iterator tmp = end() + j - 1; tmp >= position + j; tmp--)
					*tmp = *(tmp - j);
				for (InputIterator tmp = first; tmp != last; tmp++)
				{
					_alloc.construct(&position[i], *(tmp));
					i++;
				}
				_size += j;
			}
			iterator erase (iterator position)
			{
				unsigned int i = 0;
				iterator tmp = position;
				for (iterator it = begin(); it < position; it++, i++);
				_alloc.destroy(_v + i);
				while (position + 1 < end())
				{
					*position = *(position + 1);
					position++;
				}
				_size--;
				return (tmp);
			}
			iterator erase (iterator first, iterator last)
			{
				unsigned int i = 0;
				unsigned int diff = last - first;
				for (iterator it = begin() ; it < last; it++, i++);
				while (first < last)
				{
					last--;
					i--;
					_alloc.destroy(_v + i);
				}
				i = 0;
				while (end() > first + diff + i)
				{
					*(first + i) = *(first + diff + i);
					i++;
				}
				resize(_size - diff);
				return (first);
			}
			void swap (vector& x)
			{
				Alloc alloc;
				unsigned int size;
				unsigned int capacity;
				value_type *tmp;
				
				alloc = x._alloc;
				capacity = x._capacity;
				size = x._size;
				tmp = x._v;

				x._alloc = _alloc;
				x._capacity = _capacity;
				x._size = _size;
				x._v = _v;

				_alloc = alloc;
				_capacity = capacity;
				_size = size;
				_v = tmp;
			}
			void clear()
			{
				for (unsigned int i = 0; i != _size; i++)
				{
					_alloc.destroy(&_v[i]);
				}
				_size = 0;
			}*/

			//Swap
			void swap (vector& x);

			//Clear
			void clear()
			{
				for (size_type i = 0; i < this->_size; i++)
					this->_alloc.destroy(this->_begin + i);
				this->_size = 0;
			}
	};
	
	/* ---------------------------------------------------- */
	/*                                                      */
	/*                     OPERATORS                        */
	/*                                                      */
	/*  --------------------------------------------------- */
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

/* ---------------------------------------------------- */
/*                                                      */
/*                     OPERATORS                        */
/*                                                      */
/* ---------------------------------------------------- */
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