/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djoao <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 10:43:12 by djoao             #+#    #+#             */
/*   Updated: 2024/10/17 10:43:15 by djoao            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

void	ra(t_node **head)
{
	t_node	*first;
	t_node	*last;

	if (*head == NULL || (*head)->next == NULL)
		ft_error_msg();
	first = *head;
	last = *head;
	while (last->next != NULL)
		last = last->next;
	*head = first->next;
	first->next = NULL;
	last->next = first;
	ft_printf("ra\n");
}

void	rb(t_node **head)
{
	t_node	*first;
	t_node	*last;

	if (*head == NULL || (*head)->next == NULL)
		ft_error_msg();
	first = *head;
	last = *head;
	while (last->next != NULL)
		last = last->next;
	*head = first->next;
	first->next = NULL;
	last->next = first;
	ft_printf("rb\n");
}

void	rr(t_node **head_a, t_node **head_b)
{
	ra(head_a);
	rb(head_b);
	ft_printf("rr\n");
}
