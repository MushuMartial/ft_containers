/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_iterator.hpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmartial <tmartial@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 14:23:35 by tmartial          #+#    #+#             */
/*   Updated: 2022/06/22 16:43:58 by tmartial         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef REVERSE_ITERATOR_HPP
# define REVERSE_ITERATOR_HPP

#include "iterator_traits.hpp"
namespace ft
{
	template <class Iterator>
	class reverse_iterator
	{
	public:
		typedef 			Iterator										iterator_type;
		typedef typename	iterator_traits<Iterator>::iterator_category	iterator_category;
		typedef typename	iterator_traits<Iterator>::value_type			value_type;
		typedef typename	iterator_traits<Iterator>::difference_type		difference_type;
		typedef typename	iterator_traits<Iterator>::pointer				pointer;
		typedef typename	iterator_traits<Iterator>::reference			reference;
	protected:
		iterator_type	original;
	public:
		// Default constructor
		reverse_iterator() : original() {}

		// Copy constructor from original iterator
		explicit reverse_iterator(iterator_type it) : original(it) {}

		// Copy constructor from reverse iterator
		template <class Iter>
		reverse_iterator(const reverse_iterator<Iter>& rev_it) : original(rev_it.base()) {}

		// Casting operator
		operator reverse_iterator<const Iterator>() const { return this->original; }
	
		// Destructor
		virtual ~reverse_iterator() {}

		// Member functions
		iterator_type base() const { return this->original; }

		// Dereference operators
		reference operator*() const { iterator_type tmp(this->original); return *(--tmp); }
		pointer operator->() const { return &(operator*()); }
		reference operator[](difference_type n) const { return *(*this + n); }

		// Addition operator
		reverse_iterator operator+(difference_type n) const { return reverse_iterator(this->original - n); }

		// Increment operators
		reverse_iterator& operator++() { --this->original; return *this; }
		reverse_iterator operator++(int) { reverse_iterator tmp(*this); --this->original; return tmp; }

		// Advance operator
		reverse_iterator& operator+=(difference_type n) { this->original -= n; return *this; }

		// Substruction operator
		reverse_iterator operator-(difference_type n) const { return reverse_iterator(this->original + n); }

		// Decrement operators
		reverse_iterator& operator--() { ++this->original; return *this; }
		reverse_iterator operator--(int) { reverse_iterator tmp(*this); ++this->original; return tmp; }

		// Retrocede operator
		reverse_iterator& operator-=(difference_type n) { this->original += n; return *this; }
	};

	// Relational operators
	template <class Iterator1, class Iterator2>
	bool operator==(const reverse_iterator<Iterator1>& lhs, const reverse_iterator<Iterator2>& rhs) { return lhs.base() == rhs.base(); }

	template <class Iterator1, class Iterator2>
	bool operator!=(const reverse_iterator<Iterator1>& lhs, const reverse_iterator<Iterator2>& rhs) { return lhs.base() != rhs.base(); }

	template <class Iterator1, class Iterator2>
	bool operator<(const reverse_iterator<Iterator1>& lhs, const reverse_iterator<Iterator2>& rhs) { return lhs.base() > rhs.base(); }

	template <class Iterator1, class Iterator2>
	bool operator<=(const reverse_iterator<Iterator1>& lhs, const reverse_iterator<Iterator2>& rhs) { return lhs.base() >= rhs.base(); }

	template <class Iterator1, class Iterator2>
	bool operator>(const reverse_iterator<Iterator1>& lhs, const reverse_iterator<Iterator2>& rhs) { return lhs.base() < rhs.base(); }

	template <class Iterator1, class Iterator2>
	bool operator>=(const reverse_iterator<Iterator1>& lhs, const reverse_iterator<Iterator2>& rhs) { return lhs.base() <= rhs.base(); }

	// Addition operator overload
	template <class Iterator>
	reverse_iterator<Iterator> operator+(typename reverse_iterator<Iterator>::difference_type n, const reverse_iterator<Iterator>& rev_it)
	{
		return rev_it + n;
	}

	// Subtraction operator overload
	template <class Iterator1, class Iterator2>
	typename reverse_iterator<Iterator1>::difference_type operator-(const reverse_iterator<Iterator2>& lhs, const reverse_iterator<Iterator1>& rhs)
	{
		return rhs.base() - lhs.base();
	}
}
/*namespace ft
{
	template <class Iter>
		class reverse_iterator
		{
			Iter it;
			public:
			typedef Iter iterator_type;
			typedef typename iterator_traits<Iter>::iterator_category iterator_category;
			typedef typename iterator_traits<Iter>::value_type value_type;
			typedef typename iterator_traits<Iter>::difference_type difference_type;
			typedef typename iterator_traits<Iter>::pointer pointer;
			typedef typename iterator_traits<Iter>::reference reference;

			reverse_iterator();
			explicit reverse_iterator(iterator_type x);
			template <class U>
				reverse_iterator(const reverse_iterator<U>& other);

			iterator_type base() const;
			reference operator*() const;
			pointer operator->() const;
			reverse_iterator<Iter> operator+(difference_type n) const;
			reverse_iterator<Iter> operator-(difference_type n) const;
			reference operator[](difference_type n) const;
			template <class U>
			reverse_iterator<Iter>& operator=(const reverse_iterator<U>& p);
			reverse_iterator<Iter>&  operator++();
			reverse_iterator<Iter> operator++(int);
			reverse_iterator<Iter>& operator--();
			reverse_iterator<Iter> operator--(int);
			reverse_iterator<Iter>& operator+=(difference_type n);
			reverse_iterator<Iter>& operator-=(difference_type n);
		};
}

//#define ft::reverse_iterator<Iter> ft::reverse_iterator<Iter>

	template <class Iter>
ft::reverse_iterator<Iter>::reverse_iterator()
	: it() {}

	template <class Iter>
ft::reverse_iterator<Iter>::reverse_iterator(iterator_type x)
	: it (x) {}

	template <class Iter>
	template <class U>
ft::reverse_iterator<Iter>::reverse_iterator(const reverse_iterator<U>& other)
	: it(other.base())
{}


template <class Iter>
typename ft::reverse_iterator<Iter>::iterator_type ft::reverse_iterator<Iter>::base() const
{
	return it;
}

template <class Iter>
typename ft::reverse_iterator<Iter>::reference ft::reverse_iterator<Iter>::operator*() const
{
	Iter tmp = it;
	return *--tmp;
}

template <class Iter>
typename ft::reverse_iterator<Iter>::pointer ft::reverse_iterator<Iter>::operator->() const
{
	return &(operator*());
}

template <class Iter>
ft::reverse_iterator<Iter>  ft::reverse_iterator<Iter>::operator+(difference_type n) const
{
	return reverse_iterator<Iter>(it - n);
}

template <class Iter>
ft::reverse_iterator<Iter>  ft::reverse_iterator<Iter>::operator-(difference_type n) const
{
	return reverse_iterator<Iter>(it + n);
}

	template <class Iter>
ft::reverse_iterator<Iter>&  ft::reverse_iterator<Iter>::operator++()
{
	--it;
	return *this;
}

	template <class Iter>
ft::reverse_iterator<Iter>  ft::reverse_iterator<Iter>::operator++(int)
{
	reverse_iterator<Iter> tmp = *this;
	it--;
	return tmp;
}

	template <class Iter>
ft::reverse_iterator<Iter>&  ft::reverse_iterator<Iter>::operator--()
{
	++it;
	return *this;
}

	template <class Iter>
ft::reverse_iterator<Iter>  ft::reverse_iterator<Iter>::operator--(int)
{
	reverse_iterator<Iter> tmp = *this;
	it++;
	return tmp;
}

	template <class Iter>
ft::reverse_iterator<Iter>&  ft::reverse_iterator<Iter>::operator+=(difference_type n)
{
	it -= n;
	return *this;
}

	template <class Iter>
ft::reverse_iterator<Iter>&  ft::reverse_iterator<Iter>::operator-=(difference_type n)
{
	it += n;
	return *this;
}

template <class Iter>
typename ft::reverse_iterator<Iter>::reference ft::reverse_iterator<Iter>::operator[](difference_type n) const
{
	return it[-n - 1];
}

template <class Iter>
	template <class U>
ft::reverse_iterator<Iter>& ft::reverse_iterator<Iter>::operator=(const reverse_iterator<U>& p)
{
	it = p.base;
	return *this;
}

	template <class Iter>
bool operator==(const ft::reverse_iterator<Iter>& lhs, const ft::reverse_iterator<Iter>& rhs)
{ return lhs.base() == rhs.base(); }

	template <class Iter>
bool operator!=(const ft::reverse_iterator<Iter>& lhs, const ft::reverse_iterator<Iter>& rhs)
{ return lhs.base() != rhs.base(); }

	template <class Iter>
bool operator>=(const ft::reverse_iterator<Iter>& lhs, const ft::reverse_iterator<Iter>& rhs)
{ return lhs.base() <= rhs.base(); }

	template <class Iter>
bool operator<=(const ft::reverse_iterator<Iter>& lhs, const ft::reverse_iterator<Iter>& rhs)
{ return lhs.base() >= rhs.base(); }

	template <class Iter>
bool operator>(const ft::reverse_iterator<Iter>& lhs, const ft::reverse_iterator<Iter>& rhs)
{ return lhs.base() < rhs.base(); }

	template <class Iter>
bool operator<(const ft::reverse_iterator<Iter>& lhs, const ft::reverse_iterator<Iter>& rhs)
{ return lhs.base() > rhs.base(); }
*/

#endif