/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chfederi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 19:39:50 by chfederi          #+#    #+#             */
/*   Updated: 2022/02/07 21:42:03 by chfederi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <limits.h>
# include <stdio.h>
# include <stdint.h>

typedef struct s_stack
{
	long			n;
	int				i;
	struct s_stack	*next;
}					t_stack;

char	**getarg(int argc, char **argv);
char	**getarg2(char **argv);
char	**ft_split(char const *s, char c);
int		checkarg(char **args);
long	ctoi(char *s);
t_stack	*slast(t_stack *a);
t_stack	*prelast(t_stack *a);
t_stack	*createstacka(char **args, int argc);
void	checkarg2(char **args, int argc, char **argv);
void	sb(t_stack **b);
void	sa(t_stack **a);
void	rb(t_stack **b);
void	ra(t_stack **a);
void	rra(t_stack **a);
void	rrb(t_stack **b);
void	pushb(t_stack **a, t_stack **b);
void	pusha(t_stack **a, t_stack **b);
int		checkorderstack(t_stack *a);
void	sort3(t_stack **a);
int		findmin(t_stack *a);
int		findl(t_stack *a);
void	sort4(t_stack **a, t_stack **b);
int		stacklen(t_stack *a);
void	sort1(t_stack **a, t_stack **b, int m);
void	sort2(t_stack **a, t_stack **b);
void	sort5(t_stack **a, t_stack **b);
void	sort(t_stack **a, t_stack **b);
void	freestack(t_stack **a, void (*del)(void *));
void	*ft_1free(char **s);
int		checkorderarr(double *s);
void	setindex2(t_stack **a, double *s);
double	*sortind(double *s);
void	setindex(t_stack **a);
void	*ft_calloc(size_t n, size_t size);
int		findmax(t_stack	**b);
int		find01(double *s);
int		findl1(t_stack *b);
void	ffree(char **s, t_stack **a, int argc);
void	finalpush(t_stack **a, t_stack **b);
void	fp(t_stack **a, t_stack **b);
int		fcheck(char c);
size_t	ft_strlen(char *str);
int		ft_isdigit2(char c);
int		ft_isdigit(char c);

#endif
