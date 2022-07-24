/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmartial <tmartial@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/23 14:55:25 by tmartial          #+#    #+#             */
/*   Updated: 2022/07/24 15:28:01 by tmartial         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_HPP
# define STACK_HPP

# include "vector.hpp"

namespace ft
{
	template <class T, class Container = ft::vector<T> >
	class stack
	{
		public:
			typedef T			value_type;
			typedef Container	container_type;
			typedef size_t		size_type;

		protected:
			container_type c;

		public:
			//Constructor
			explicit stack (const container_type& ctnr = container_type())
			: c(ctnr)
			{
				
			}

			//Empty
			bool empty() const
			{
				return (this->c.empty());
			}

			//Size
			size_type size() const
			{
				return (this->c.size());
			}

			//Top
			value_type& top()
			{
				return (this->c.back());
			}
			
			const value_type& top() const
			{
				return (this->c.back());
			}
			
			//Push
			void push (const value_type& val)
			{
				this->c.push_back(val);
			}

			//Pop
			void pop()
			{
				this->c.pop_back();
			}

			//Operators
			template <class T2, class Container2>
  			friend bool operator== (const stack<T2,Container2>& lhs, const stack<T2,Container2>& rhs);

			template <class T2, class Container2>
  			friend bool operator!= (const stack<T2,Container2>& lhs, const stack<T2,Container2>& rhs);

			template <class T2, class Container2>
  			friend bool operator< (const stack<T2,Container2>& lhs, const stack<T2,Container2>& rhs);

			template <class T2, class Container2>
  			friend bool operator<= (const stack<T2,Container2>& lhs, const stack<T2,Container2>& rhs);
	
			template <class T2, class Container2>
  			friend bool operator> (const stack<T2,Container2>& lhs, const stack<T2,Container2>& rhs);
			  	
			template <class T2, class Container2>
  			friend bool operator>= (const stack<T2,Container2>& lhs, const stack<T2,Container2>& rhs);
	};
	/* ---------------------------------------------------- */
	/*                                                      */
	/*                     OPERATORS                        */
	/*                                                      */
	/*  --------------------------------------------------- */
	template <class T, class Container>
  	bool operator== (const stack<T,Container>& lhs, const stack<T,Container>& rhs)
	{
		return (lhs.c == rhs.c);
	}

	template <class T, class Container>
  	bool operator!= (const stack<T,Container>& lhs, const stack<T,Container>& rhs)
	{
		return (!(lhs.c == rhs.c));
	}

	template <class T, class Container>
  	bool operator<  (const stack<T,Container>& lhs, const stack<T,Container>& rhs)
	{
		return (rhs.c > lhs.c);
	}

	template <class T, class Container>
  	bool operator<= (const stack<T,Container>& lhs, const stack<T,Container>& rhs)
	{
		return (rhs.c >= lhs.c);
	}
	
	template <class T, class Container>
  	bool operator>  (const stack<T,Container>& lhs, const stack<T,Container>& rhs)
	{
		return (rhs.c < lhs.c);
	}
			  	
	template <class T, class Container>
  	bool operator>= (const stack<T,Container>& lhs, const stack<T,Container>& rhs)
	{
		return (rhs.c <= lhs.c);
	}


}


#endif