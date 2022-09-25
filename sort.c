/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chfederi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 21:01:51 by chfederi          #+#    #+#             */
/*   Updated: 2022/02/15 21:01:54 by chfederi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort5(t_stack **a, t_stack **b)
{
	int	l;

	l = findl(*a);
	if (l == 1)
		sa(a);
	if (l == 2)
	{
		ra(a);
		ra(a);
	}
	if (l == 3)
	{
		rra(a);
		rra(a);
	}
	if (l == 4)
		rra(a);
	pushb(a, b);
	sort4(a, b);
	pusha(a, b);
}

void	sort(t_stack **a, t_stack **b)
{
	int	n;

	n = 0;
	if (stacklen(*a) + 1 <= 30)
		n = 1;
	else if (stacklen(*a) < 100)
		n = 14;
	else if (stacklen(*a) + 1 >= 101)
		n = 31;
	sort1(a, b, n);
}

void	sort1(t_stack **a, t_stack **b, int m)
{
	int		cn;

	cn = 0;
	while (*a)
	{
		if ((*a)->i <= cn)
		{
			pushb(a, b);
			if (stacklen(*b) > 1)
				rb(b);
			cn++;
		}
		else if ((*a)->i <= cn + m)
		{
			pushb(a, b);
			cn++;
		}
		else if ((*a)->i > cn + m)
			ra(a);
	}
	pushb(a, b);
	sort2(a, b);
}

void	sort2(t_stack **a, t_stack **b)
{
	while (stacklen(*b) > 2)
	{
		fp(a, b);
		if (findl1(*b) >= stacklen(*b) / 2 && stacklen(*b) > 1)
		{
			if (stacklen(*b) > 2)
			{
				while ((*b)->i != findmax(b))
					rrb(b);
			}
		}
		else if (findl1(*b) < stacklen(*b) / 2)
		{
			while ((*b)->i != findmax(b))
				rb(b);
		}
	}
	finalpush(a, b);
}

int	findl1(t_stack *b)
{
	int	l;

	l = 0;
	while (b->next)
	{
		if (b->i == findmax(&b))
			break ;
		b = b->next;
		l++;
	}
	return (l);
}
