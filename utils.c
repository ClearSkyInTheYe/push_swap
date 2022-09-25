/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chfederi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 21:29:38 by chfederi          #+#    #+#             */
/*   Updated: 2022/02/08 21:29:40 by chfederi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	checkorderargs(char **args)
{
	int	i;
	int	x;

	i = 0;
	while (args[i] != NULL)
	{
		x = i;
		while (args[x])
		{
			if (ctoi(args[i]) > ctoi(args[x]) && args[i] != NULL && i != x)
				return (0);
			x++;
		}
		i++;
	}
	return (1);
}

int	checkrepeat(char **args)
{
	int	i;
	int	x;

	i = 0;
	while (args[i] != NULL)
	{
		x = 0;
		while (args[x] != NULL)
		{
			if (ctoi(args[i]) == ctoi(args[x]) && x != i)
				return (1);
			x++;
		}
		i++;
	}
	return (0);
}

int	checkargv(int argc, char **argv)
{
	int	i;

	i = 0;
	if (argc >= 2)
	{
		while (argv[i])
		{
			if (argv[i] == NULL)
				return (1);
			i++;
		}
	}
	return (0);
}

void	checkarg2(char **args, int argc, char **argv)
{
	if (checkargv(argc, argv) == 1)
	{
		write (1, "Error\n", 6);
		exit(EXIT_FAILURE);
	}
	if (checkrepeat(args) == 1)
	{
		write (1, "Error\n", 6);
		exit(EXIT_FAILURE);
	}
	if (checkarg(args) == 2)
	{
		write (1, "Error\n", 6);
		exit(EXIT_FAILURE);
	}
	if (checkargv(argc, argv) == 1)
	{
		write (1, "Error\n", 6);
		exit(EXIT_FAILURE);
	}
	if (checkarg(args) == 1)
		exit(EXIT_FAILURE);
	if (checkorderargs(args) == 1)
		exit(EXIT_FAILURE);
}

int	checkorderarr(double *s)
{
	int		i;
	long	j;

	i = 0;
	j = 1;
	while (s[j])
	{
		if (s[i] > s[j])
			return (1);
		i++;
		j++;
	}
	return (0);
}
