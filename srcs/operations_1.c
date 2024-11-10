/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djoao <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 10:42:58 by djoao             #+#    #+#             */
/*   Updated: 2024/10/17 10:43:02 by djoao            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

void	sa(t_node **head)
{
	t_node	*first;
	t_node	*second;

	if (*head == NULL || (*head)->next == NULL)
		ft_error_msg();
	first = *head;
	second = first->next;
	first->next = second->next;
	second->next = first;
	*head = second;
	ft_printf("sa\n");
}

void	sb(t_node **head)
{
	t_node	*first;
	t_node	*second;

	if (*head == NULL || (*head)->next == NULL)
		ft_error_msg();
	first = *head;
	second = first->next;
	first->next = second->next;
	second->next = first;
	*head = second;
	ft_printf("sb\n");
}

void	ss(t_node **head_a, t_node **head_b)
{
	sa(head_a);
	sb(head_b);
	ft_printf("ss\n");
}

void	pa(t_node **head_a, t_node **head_b)
{
	t_node	*aux;

	if (*head_b == NULL)
		ft_error_msg();
	aux = *head_a;
	*head_a = (*head_b);
	*head_b = (*head_b)->next;
	(*head_a)->next = aux;
	ft_printf("pa\n");
}

void	pb(t_node **head_a, t_node **head_b)
{
	t_node	*aux;

	if (*head_a == NULL)
		ft_error_msg();
	aux = *head_b;
	*head_b = (*head_a);
	*head_a = (*head_a)->next;
	(*head_b)->next = aux;
	ft_printf("pb\n");
}
