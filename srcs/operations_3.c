/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_3.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djoao <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 10:44:13 by djoao             #+#    #+#             */
/*   Updated: 2024/10/17 10:44:18 by djoao            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

void	rra(t_node **head)
{
	t_node	*last;
	t_node	*bf_last;

	if (*head == NULL || (*head)->next == NULL)
		ft_error_msg();
	last = *head;
	while (last->next != NULL)
	{
		bf_last = last;
		last = last->next;
	}
	bf_last->next = NULL;
	last->next = *head;
	*head = last;
	ft_printf("rra\n");
}

void	rrb(t_node **head)
{
	t_node	*last;
	t_node	*bf_last;

	if (*head == NULL || (*head)->next == NULL)
		ft_error_msg();
	last = *head;
	while (last->next != NULL)
	{
		bf_last = last;
		last = last->next;
	}
	bf_last->next = NULL;
	last->next = *head;
	*head = last;
	ft_printf("rrb\n");
}

void	rrr(t_node **head_a, t_node **head_b)
{
	rra(head_a);
	rrb(head_b);
	ft_printf("rrr\n");
}
