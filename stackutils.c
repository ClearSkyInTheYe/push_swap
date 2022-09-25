/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stackutils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chfederi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 20:23:58 by chfederi          #+#    #+#             */
/*   Updated: 2022/02/10 20:24:02 by chfederi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*newstack(long num)
{
	t_stack	*a;

	a = ft_calloc(sizeof (t_stack), 1);
	if (a == NULL)
		return (NULL);
	a->n = num;
	a->next = NULL;
	return (a);
}

t_stack	*slast(t_stack *a)
{
	while (a)
	{
		if (!a->next)
			return (a);
		a = a->next;
	}
	return (a);
}

void	addb(t_stack **a, t_stack *na)
{
	t_stack	*la;

	if (a)
	{
		if (*a)
		{
			la = slast(*a);
			la->next = na;
		}
		else
			*a = na;
	}
}

t_stack	*createstacka(char **args, int argc)
{
	int		i;
	t_stack	*a;
	t_stack	*tmp;

	i = 1;
	a = newstack(ctoi(args[0]));
	if (a == NULL)
	{
		freestack(&a, free);
		if (argc == 2)
			ft_1free(args);
		else
			free(args);
		exit(EXIT_FAILURE);
	}
	while (args[i])
	{
		if (args[i] == NULL)
			break ;
		tmp = newstack(ctoi(args[i]));
		addb(&a, tmp);
		i++;
	}
	return (a);
}

void	freestack(t_stack **a, void (*del)(void *))
{
	t_stack	*tmp;

	while (*a)
	{
		tmp = *a;
		*a = (*a)->next;
		(del)(tmp);
	}
	*a = NULL;
}
