/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stackutils1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chfederi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 21:53:35 by chfederi          #+#    #+#             */
/*   Updated: 2022/02/11 21:53:37 by chfederi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*prelast(t_stack *a)
{
	while (a->next)
	{
		if (a->next->next == NULL)
			return (a);
		a = a->next;
	}
	return (a);
}

int	stacklen(t_stack *a)
{
	int	i;

	if (!a)
		return (0);
	i = 0;
	while (a->next)
	{
		i++;
		a = a->next;
	}
	return (i);
}

void	setindex(t_stack **a)
{
	double	*s;
	int		i;
	t_stack	*tmp;
	double	x;

	tmp = *a;
	i = 0;
	s = ft_calloc(32, (stacklen(*a) + 1));
	if (s == NULL)
		return ;
	while (tmp)
	{
		x = (double )tmp->n;
		if (tmp->n == 0)
			x = 0.1;
		s[i] = x;
		tmp = tmp->next;
		i++;
	}
	s = sortind(s);
	setindex2(a, s);
	free(s);
}

void	setindex2(t_stack **a, double *s)
{
	int		x;
	int		l;
	t_stack	*tmp;

	x = 0;
	l = stacklen(*a) + 1;
	while (l-- > 0)
	{
		tmp = *a;
		while (tmp)
		{
			if (tmp->n == (long)s[x])
			{
				if (tmp->n == 0)
				{
					tmp->i = find01(s);
					break ;
				}
				tmp->i = x;
				break ;
			}
			tmp = tmp->next;
		}
		x++;
	}
}

double	*sortind(double *s)
{
	double	swp;
	double	sw;
	int		i;
	int		j;

	while (checkorderarr(s) == 1)
	{
		i = 0;
		j = 1;
		while (s[j])
		{
			if (s[i] > s[j])
			{
				sw = s[i];
				swp = s[j];
				s[i] = swp;
				s[j] = sw;
			}
			i++;
			j++;
		}
	}
	return (s);
}
