/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djoao <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 10:45:53 by djoao             #+#    #+#             */
/*   Updated: 2024/10/17 10:45:59 by djoao            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

int	ft_count(char **str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void	free_matrix(char **m)
{
	int	i;

	i = 0;
	if (m)
	{
		while (m[i])
		{
			free(m[i]);
			i++;
		}
		free (m);
	}
}

int	get_index(t_node *head, int value)
{
	t_node	*aux;
	int		index;

	aux = head;
	index = 0;
	while (aux != NULL)
	{
		if (aux -> data == value)
			return (index);
		index++;
		aux = aux -> next;
	}
	return (-1);
}

int	is_number(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '-' || str[i] == '+')
		i++;
	if (str[i] == '\0')
		return (0);
	if (ft_atoi(str) > 2147483647 || ft_atoi(str) < -2147483648)
		return (0);
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (0);
		i++;
	}
	return (1);
}

int	check_sorted(t_node *head)
{
	t_node	*current;

	if (!head)
		return (1);
	current = head;
	while (current->next != NULL)
	{
		if (current->data > current->next->data)
			return (1);
		current = current->next;
	}
	return (0);
}
