/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   organize.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djoao <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 11:13:37 by djoao             #+#    #+#             */
/*   Updated: 2024/10/17 11:13:40 by djoao            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

void	organize_two(t_node **head)
{
	if ((*head == NULL) || (*head)->next == NULL)
		ft_error_msg();
	if ((*head)->data > (*head)->next->data)
		sa(head);
}

void	organize_three(t_node **head)
{
	if (*head == NULL || (*head)->next == NULL || (*head)->next->next == NULL)
		ft_error_msg();
	if ((*head)->data > (*head)->next->data
		&& (*head)->next->data > (*head)->next->next->data)
	{
		sa(head);
		rra(head);
	}
	else if ((*head)->data > (*head)->next->next->data
		&& (*head)->next->next->data > (*head)->next->data)
		ra(head);
	else if ((*head)->next->data > (*head)->data
		&& (*head)->data > (*head)->next->next->data)
		rra(head);
	else if ((*head)->next->data > (*head)->next->next->data
		&& (*head)->next->next->data > (*head)->data)
	{
		sa(head);
		ra(head);
	}
	else if ((*head)->next->next->data > (*head)->data
		&& (*head)->data > (*head)->next->data)
		sa(head);
}

void	organize_four(t_node **head_a, t_node **head_b)
{
	if (*head_a == NULL || (*head_a)->next == NULL)
		ft_error_msg();
	push_min_to_b(head_a, head_b);
	organize_three(head_a);
	pa(head_a, head_b);
}

void	organize_five(t_node **head_a, t_node **head_b)
{
	if (*head_a == NULL || (*head_a)->next == NULL)
		ft_error_msg();
	push_min_to_b(head_a, head_b);
	organize_four(head_a, head_b);
	pa(head_a, head_b);
}

void	organize_n(t_node **head_a, t_node **head_b)
{
	index_node_in_order(head_a);
	send_partition(head_a, head_b, stack_size(*head_a));
	while (stack_size(*head_b) > 0)
		push_max_to_a(head_a, head_b);
}
