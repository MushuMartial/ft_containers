/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmartial <tmartial@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 15:54:04 by tmartial          #+#    #+#             */
/*   Updated: 2022/07/05 13:30:50 by tmartial         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_HPP
# define VECTOR_HPP

# include <iostream>
# include <algorithm>
# include <memory>
# include <vector>
# include <iterator>
# include "iterator_traits.hpp"
# include "type_traits.hpp"
# include "random_access_iterator.hpp"
# include "reverse_iterator.hpp"
# include "utils.hpp"

namespace ft
{
	template<class T, class Allocator = std::allocator<T> >
	class vector
	{
		public:
			typedef T												value_type;
    		typedef Allocator										allocator_type;
    		typedef typename allocator_type::reference				reference;
    		typedef typename allocator_type::const_reference		const_reference;
			typedef typename allocator_type::pointer				pointer;
			typedef typename allocator_type::const_pointer			const_pointer;
			typedef typename ft::random_access_iterator<T>			iterator;
			typedef typename ft::random_access_iterator<const T>	const_iterator;
			typedef typename ft::reverse_iterator<iterator>			reverse_iterator;
			typedef typename ft::reverse_iterator<const_iterator>	const_reverse_iterator;
			typedef typename allocator_type::size_type				size_type;
			typedef typename allocator_type::difference_type		difference_type;
			
		private:
			allocator_type	_alloc;
			pointer			_begin;
			size_type		_size;
			size_type		_capacity;

		public:
			/* ---------------------------------------------------- */
			/*                                                      */
			/*                     UTILS                            */
			/*                                                      */
			/* ---------------------------------------------------- */
			/* Allocate and construct a new vector, changes all atributes */
			void allocation(size_type size, const value_type& val)
			{
				this->_begin = this->_alloc.allocate(size * 2);
				for (size_type i = 0; i < size; i++)
					this->_alloc.construct(this->_begin + i, val);
				this->_size = size;
				this->_capacity = size * 2;
			}

			/* Free & destroy vector */
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
			: _alloc(alloc), _begin(nullptr), _size(ft::distance(first, last)), _capacity(ft::distance(first, last) * 2) 
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
			void resize(size_type n, value_type val = value_type())
			{
				if (n < this->size())
				{
					for (size_type i = n, len = this->size(); i < len; ++i)
						this->_alloc.destroy(this->_begin + i);
				}
				else if (n > this->size() && n > this->capacity())
				{
					if (this->_size * 2 >= n)
						reserve(this->size() * 2);
					else
						reserve(n);
				}
				if (n > this->size() && n <= this->capacity())
				{
					for (size_type i = this->size(); i < n; ++i)
						this->_alloc.construct(this->_begin + i, val);
				}
				this->_size = n;
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
			void reserve(size_type n)
			{
				if (n > this->_capacity)
				{
					/* Declare new pointer */
					pointer	new_vec;
			
					/* Allocate n blocks of memory for the new vector */
					new_vec = this->_alloc.allocate(n);

					/* Copy content inside the new vector */
					size_type old_size = this->size();
					for (size_type i = 0; i < this->_size; ++i)
						this->_alloc.construct(new_vec + i, this->_begin[i]);
			
					/* Erase elements from old memory area and deallocate */
					this->clear();
					this->_alloc.deallocate(this->_begin, this->_capacity);

					/* Swap our 'old' vector for the new one */
					this->_begin = new_vec;
					this->_size = old_size;
					this->_capacity = n;
				}
				return ;
			}
			
			
			/* ---------------------------------------------------- */
			/*                                                      */
			/*                   ELEMENT ACCESS                     */
			/*                                                      */
			/* ---------------------------------------------------- */
			//Operator []
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
				this->_size = ft::distance(first, last);
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
					this->_size += 1;
				}
				else
				{
					resize(this->_size + 1, val);
				}
			}
			
			//Pop_back
			void pop_back()
			{
				if (this->_size != 0)
					this->_alloc.destroy(this->_begin + (this->_size - 1));
				this->_size -= 1;
			}

			//Insert
			void insert (iterator position, size_type n, const value_type& val)
			{
				size_type i = 0, k = 0;
				pointer tmp;
				iterator test = this->_begin;
				
				while (test != position) //tmp != position ne marche pas
				{
					*test++;
					i++;
				}
				tmp = this->_alloc.allocate(this->_size + n * 2);
				for (size_type j = 0; j < this->_size + n; j++)
				{
					if (i == j - k && k < n)
					{
						this->_alloc.construct(tmp + j, val);
						k++;
					}
					else
						this->_alloc.construct(tmp + j, *(this->_begin + j - k));
				}
				deallocation();
				this->_begin = tmp;
				this->_size += n;
				this->_capacity = this->_size * 2;
			}

			iterator insert (iterator position, const value_type& val)
			{
				size_type i = 0, k = 0, n = 1;
				pointer tmp;
				iterator test = this->_begin;
				
				while (test != position)
				{
					*test++;
					i++;
				}
				tmp = this->_alloc.allocate(this->_size + n * 2);
				for (size_type j = 0; j < this->_size + 1; j++)
				{
					if (i == j - k && k < n)
					{
						this->_alloc.construct(tmp + j, val);
						k++;
					}
					else
					{
						this->_alloc.construct(tmp + j, *(this->_begin + j - k));
					}
				}
				deallocation();
				this->_begin = tmp;
				this->_size += n;
				this->_capacity = this->_size * 2;
				return (tmp + i);
			}
			
			template <class InputIterator>
    		void insert (iterator position, InputIterator first, InputIterator last,
			typename ft::enable_if<!ft::is_integral<InputIterator>::value>::type* = NULL)
			{
				size_type i = 0, k = 0, n = ft::distance(first, last);
				pointer tmp;
				iterator test = this->_begin;
				
				while (test != position)
				{
					*test++;
					i++;
				}
				tmp = this->_alloc.allocate(this->_size + n * 2);
				for (size_type j = 0; j < this->_size + n; j++)
				{
					if (i == j - k && k < n)
					{
						this->_alloc.construct(tmp + j, *first);
						first++;
						k++;
					}
					else
					{
						this->_alloc.construct(tmp + j, *(this->_begin + j - k));
					}
				}
				deallocation();
				this->_begin = tmp;
				this->_size += n;
				this->_capacity = this->_size * 2;
			}

			//Erase
			iterator erase (iterator position)
			{
				size_type i = 0;
				iterator tmp = position;
				iterator test = this->_begin;
				
				while (test != position)
				{
					*test++;
					i++;
				}
				this->_alloc.destroy(this->_begin + i);
				while (position + 1 < end())
				{
					*position = *(position + 1);
					position++;
				}
				this->_size--;
				return (tmp);
			}
			
			iterator erase (iterator first, iterator last)
			{
				size_type i = 0;
				size_type dis = ft::distance(first, last);
				iterator tmp = first;
				iterator ret = first;
				iterator test = this->_begin;
				
				while (test != first)
				{
					*test++;
					i++;
				}
				for (size_t j = 0; j < dis; j++)
					this->_alloc.destroy(this->_begin + i + j);
				
				while (tmp + dis < end())
				{
					*tmp = *(tmp + dis);
					tmp++;
				}
				this->_size -= dis;
				return (ret);
			}
			

			//Swap
			void swap (vector& x)
			{
				std::swap(this->_size, x._size);
				std::swap(this->_capacity, x._capacity);
				std::swap(this->_begin, x._begin);
			}

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
		return (false);
	return (equal(lhs.begin(), lhs.end(), rhs.begin()));
}

//Operator !=
template <class T, class Alloc>
bool ft::operator!= (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
{
	return (!(lhs == rhs));
}

//Operator <
template <class T, class Alloc>
bool ft::operator<  (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
{
	return (lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end()));
}

//Operator <=
template <class T, class Alloc>
bool ft::operator<= (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
{
	return (!(rhs < lhs));
}

//Operator >
template <class T, class Alloc>
bool ft::operator>  (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
{
	return (rhs < lhs);
}

//Operator >=
template <class T, class Alloc>
bool ft::operator>= (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
{
	return (!(rhs > lhs));
}

/* ----- Swap ----- */
template <class T, class Alloc>
void ft::swap(vector<T,Alloc>& x, vector<T,Alloc>& y)
{
	x.swap(y);
}

#endif