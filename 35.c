/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   35.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chfederi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 20:11:49 by chfederi          #+#    #+#             */
/*   Updated: 2022/02/14 20:11:52 by chfederi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	checkorderstack(t_stack *a)
{
	t_stack	*head;

	head = a;
	while (head && (head->next != NULL))
	{
		if (head->n > head->next->n)
		{
			return (1);
		}
		head = head->next;
	}
	return (0);
}

void	sort3(t_stack **a)
{
	while (a && (checkorderstack(*a)))
	{
		if ((*a)->n > (*a)->next->n)
			sa(a);
		else if ((*a)->next->n > (*a)->next->next->n)
			rra(a);
	}
}

int	findmin(t_stack *a)
{
	t_stack	*tmp;
	int		min;
	int		i;

	i = 0;
	tmp = a;
	min = tmp->n;
	while (tmp)
	{
		if (tmp->n < min)
			min = tmp->n;
		tmp = tmp->next;
		i++;
		if (i == stacklen(a) + 100)
			break ;
	}
	return (min);
}

int	findl(t_stack *a)
{
	int	l;

	l = 0;
	while (a->next)
	{
		if (a->n == findmin(a))
			break ;
		a = a->next;
		l++;
	}
	return (l);
}

void	sort4(t_stack **a, t_stack **b)
{
	int	l;

	l = findl(*a);
	if (l == 1)
		sa(a);
	else if (l == 2)
	{
		ra(a);
		ra(a);
	}
	else if (l == 3)
	{
		rra(a);
	}
	if (checkorderstack(*a) == 0)
		return ;
	pushb(a, b);
	sort3(a);
	pusha(a, b);
}
