/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chfederi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 22:33:32 by chfederi          #+#    #+#             */
/*   Updated: 2022/03/18 22:33:35 by chfederi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	*ft_calloc(size_t n, size_t size)
{
	char			*s;
	size_t			total;
	size_t			i;

	if (size && SIZE_MAX / size < n)
		return (NULL);
	total = n * size;
	s = malloc(total);
	if (s == NULL)
		return (NULL);
	i = 0;
	while (total--)
	{
		s[i] = 0;
		i++;
	}
	return (s);
}

int	findmax(t_stack	**b)
{
	int		n;
	t_stack	*tmp;

	n = -1;
	tmp = *b;
	while (tmp)
	{
		if (tmp->i > n)
			n = tmp->i;
		tmp = tmp->next;
	}
	return (n);
}

int	find01(double *s)
{
	int	i;
	int	x;

	i = 0;
	while (s[i])
	{
		if (s[i] == 0.1)
			x = i;
		i++;
	}
	return (x);
}

void	finalpush(t_stack **a, t_stack **b)
{
	while (*b)
	{
		if ((*b)->i == findmax(b))
			pusha(a, b);
		else
			rb(b);
	}
}

size_t	ft_strlen(char *str)
{
	size_t	i;

	i = 0;
	if (str[0] == '\0')
		return (0);
	while (str && str[i])
		i++;
	return (i);
}
