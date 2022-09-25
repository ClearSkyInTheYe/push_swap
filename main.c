/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chfederi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 19:36:22 by chfederi          #+#    #+#             */
/*   Updated: 2022/03/18 22:33:10 by chfederi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	**getarg(int argc, char **argv)
{
	char	**args;

	args = NULL;
	if (argc < 2)
		exit(EXIT_FAILURE);
	if (argc == 2)
		args = ft_split(argv[1], ' ');
	if (argc > 2)
		args = getarg2(argv);
	return (args);
}

char	**getarg2(char **argv)
{
	char	**args;
	int		x;
	int		i;

	x = 1;
	i = 0;
	while (argv[x])
		x++;
	args = malloc(sizeof (char *) * x + 1);
	if (args == NULL)
		return (NULL);
	x = 1;
	while (argv[x] != NULL)
	{
		args[i] = argv[x];
		x++;
		i++;
	}
	args[i] = NULL;
	return (args);
}

int	checkarg(char **args)
{
	int	i;
	int	x;
	int	f;

	x = -1;
	f = 0;
	while (args[++x] != NULL)
	{
		i = 0;
		if (ft_strlen(args[x]) == 0 || ft_isdigit(args[x][i]) == 0
		|| ft_strlen(args[x]) == 0)
			f = 2;
		if ((args[x][i] == '-' || args[x][i] == '+') && ft_strlen(args[x]) == 1)
			f = 2;
		while (args[x][++i] != '\0')
		{
			if (ft_isdigit2(args[x][i]) == 0)
				f = 2;
		}
	}
	return (f);
}

long	ctoi(char *s)
{
	long	i;
	int		x;
	int		a;

	x = 0;
	i = 0;
	a = 1;
	if (s[0] == '-')
	{
		a = -1;
		x++;
	}
	if (s[0] == '+')
		x++;
	while (s[x])
	{
		i = i * 10;
		i += s[x++] - '0';
	}
	if (i * a > INT_MAX || i * a < INT_MIN)
	{
		write (1, "Error\n", 7);
		exit(EXIT_FAILURE);
	}
	return (i * a);
}

int	main(int argc, char **argv)
{
	char	**arg;
	t_stack	*a;
	t_stack	*b;

	a = NULL;
	arg = getarg(argc, argv);
	checkarg2(arg, argc, argv);
	a = createstacka(arg, argc);
	setindex(&a);
	if (stacklen(a) == 1)
		sa(&a);
	if (stacklen(a) == 2)
		sort3(&a);
	if (stacklen(a) == 3)
		sort4(&a, &b);
	if (stacklen(a) == 4)
		sort5(&a, &b);
	else if (stacklen(a) > 4)
		sort(&a, &b);
	freestack(&a, free);
	if (argc == 2)
		ft_1free(arg);
	else
		free(arg);
	return (0);
}
