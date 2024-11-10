/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djoao <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 10:46:36 by djoao             #+#    #+#             */
/*   Updated: 2024/10/17 10:46:41 by djoao            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

int	stack_min(t_node *head)
{
	int		min;
	t_node	*aux;

	aux = head;
	min = head->data;
	while (aux != NULL)
	{
		if ((aux->data) < min)
			min = aux->data;
		aux = aux->next;
	}
	return (min);
}

int	stack_max(t_node *head)
{
	int		max;
	t_node	*aux;

	aux = head;
	max = head->data;
	while (aux != NULL)
	{
		if ((aux->data) > max)
			max = aux->data;
		aux = aux->next;
	}
	return (max);
}

void	verify_arg(t_node **head_a, t_node **head_b)
{
	if (stack_size(*head_a) == 2)
		organize_two(head_a);
	else if (stack_size(*head_a) == 3)
		organize_three(head_a);
	else if (stack_size(*head_a) == 4)
		organize_four(head_a, head_b);
	else if (stack_size(*head_a) == 5)
		organize_five(head_a, head_b);
	else if (stack_size(*head_a) >= 6)
		organize_n(head_a, head_b);
}

void	push_min_to_b(t_node **head_a, t_node **head_b)
{
	int	min;

	min = stack_min(*head_a);
	while ((*head_a)->data != min)
	{
		if (get_index(*head_a, min) <= stack_size(*head_a) / 2)
			ra(head_a);
		else
			rra(head_a);
	}
	pb(head_a, head_b);
}

void	push_max_to_a(t_node **head_a, t_node **head_b)
{
	int	max;

	max = stack_max(*head_b);
	while ((*head_b)->data != max)
	{
		if (get_index(*head_b, max) <= stack_size(*head_b) / 2)
			rb(head_b);
		else
			rrb(head_b);
	}
	pa(head_a, head_b);
}
