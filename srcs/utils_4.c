/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_4.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djoao <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 11:15:37 by djoao             #+#    #+#             */
/*   Updated: 2024/10/17 11:15:40 by djoao            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

unsigned int	calc_index_node(t_node **head_a, int curr_data)
{
	t_node			*aux;
	unsigned int	i;

	if (*head_a == NULL)
		return (0);
	i = 0;
	aux = *head_a;
	while (aux != NULL)
	{
		if (curr_data > aux->data)
			i++;
		aux = aux->next;
	}
	return (i);
}

void	index_node_in_order(t_node **head_a)
{
	t_node	*aux;

	if (*head_a == NULL)
		return ;
	aux = *head_a;
	while (aux != NULL)
	{
		aux->index = calc_index_node(head_a, aux->data);
		aux = aux->next;
	}
}

int	get_map(int len, t_minmax in, t_minmax out)
{
	return ((len - in.min) * (out.max - out.min) / (in.max + in.min) + out.min);
}

void	send_partition(t_node **head_a, t_node **head_b, int len)
{
	t_minmax	in;
	t_minmax	out;
	int			i;
	int			part;
	int			curr_len;

	if (*head_a == NULL)
		return ;
	in = (t_minmax){1, 500};
	out = (t_minmax){3, 6};
	part = len / get_map(len, in, out);
	while (part < len + 1)
	{
		i = -1;
		curr_len = stack_size(*head_a);
		while (++i < curr_len)
		{
			if ((*head_a)->index < (unsigned int)part)
				pb(head_a, head_b);
			else
				ra(head_a);
		}
		part += (len / get_map(len, in, out));
	}
}
