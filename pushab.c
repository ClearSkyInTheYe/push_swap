/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushab.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chfederi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 19:38:10 by chfederi          #+#    #+#             */
/*   Updated: 2022/02/14 19:38:13 by chfederi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pusha(t_stack **a, t_stack **b)
{
	t_stack	*tmp;

	if (!*b)
		return ;
	tmp = NULL;
	tmp = *b;
	*b = tmp->next;
	tmp->next = *a;
	*a = tmp;
	write (1, "pa\n", 3);
}

void	pushb(t_stack **a, t_stack **b)
{
	t_stack	*tmp;

	tmp = NULL;
	if (!*a)
		return ;
	tmp = *a;
	*a = tmp->next;
	tmp->next = *b;
	*b = tmp;
	write (1, "pb\n", 3);
}

void	fp(t_stack **a, t_stack **b)
{
	if ((*b)->i == findmax(b))
		pusha(a, b);
	if ((*b)->next->i == findmax(b))
	{
		sb(b);
		pusha(a, b);
	}
}

int	ft_isdigit(char c)
{
	if ((c >= '0' && c <= '9') || c == '-' || c == '+')
		return (1);
	else
		return (0);
}

int	ft_isdigit2(char c)
{
	if (c >= '0' && c <= '9')
		return (1);
	else
		return (0);
}
