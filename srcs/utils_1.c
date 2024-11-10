/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djoao <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 10:46:17 by djoao             #+#    #+#             */
/*   Updated: 2024/10/17 10:46:21 by djoao            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

t_node	*createnode(int data)
{
	t_node	*newnode;

	newnode = (t_node *)malloc(sizeof(t_node));
	newnode->data = data;
	newnode->next = NULL;
	return (newnode);
}

void	stack_insert(t_node **head, int newdata)
{
	t_node	*newnode;

	newnode = createnode(newdata);
	newnode->next = *head;
	*head = newnode;
}

void	stack_print(t_node *head)
{
	t_node	*aux;

	aux = head;
	while (aux != NULL)
	{
		ft_printf("%d\n", aux->data);
		aux = aux->next;
	}
	ft_printf("NULL\n");
}

int	stack_size(t_node *head)
{
	t_node	*aux;
	int		count;

	aux = head;
	count = 0;
	while (aux != NULL)
	{
		count++;
		aux = aux->next;
	}
	return (count);
}

void	stack_free(t_node **head)
{
	t_node	*aux;

	while (*head != NULL)
	{
		aux = *head;
		*head = (*head)->next;
		free(aux);
	}
}
