/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   comands.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chfederi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 18:21:04 by chfederi          #+#    #+#             */
/*   Updated: 2022/02/11 18:21:08 by chfederi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_stack **a)
{
	t_stack	*temp1;
	t_stack	*temp2;

	temp1 = NULL;
	temp2 = NULL;
	if (stacklen(*a) > 0)
	{
		temp1 = *a;
		temp2 = temp1->next;
		temp1->next = temp1->next->next;
		temp2->next = temp1;
		*a = temp2;
		write (1, "sa\n", 3);
	}
}

void	ra(t_stack **a)
{
	t_stack	*temp;

	temp = *a;
	slast(*a)->next = temp;
	*a = temp->next;
	temp->next = NULL;
	write (1, "ra\n", 3);
}

void	rra(t_stack **a)
{
	t_stack	*tmp;

	tmp = slast(*a);
	prelast(*a)->next = NULL;
	tmp->next = *a;
	*a = tmp;
	write (1, "rra\n", 4);
}
