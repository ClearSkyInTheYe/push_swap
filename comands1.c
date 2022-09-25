/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   comands1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chfederi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 21:06:08 by chfederi          #+#    #+#             */
/*   Updated: 2022/02/11 21:06:12 by chfederi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sb(t_stack **b)
{
	t_stack	*temp1;
	t_stack	*temp2;

	temp1 = NULL;
	temp2 = NULL;
	if (stacklen(*b) > 1)
	{
		temp1 = *b;
		temp2 = temp1->next;
		temp1->next = temp1->next->next;
		temp2->next = temp1;
		*b = temp2;
		write (1, "sb\n", 3);
	}
}

void	rb(t_stack **b)
{
	t_stack	*temp;

	temp = *b;
	slast(*b)->next = temp;
	*b = temp->next;
	temp->next = NULL;
	write (1, "rb\n", 3);
}

void	rrb(t_stack **b)
{
	t_stack	*tmp;

	if ((*b)->next == NULL)
		return ;
	tmp = slast(*b);
	prelast(*b)->next = NULL;
	tmp->next = *b;
	*b = tmp;
	write (1, "rrb\n", 4);
}
