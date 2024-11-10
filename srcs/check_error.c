/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djoao <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 11:12:02 by djoao             #+#    #+#             */
/*   Updated: 2024/10/17 11:12:06 by djoao            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

void	check_duplicate_stack(t_node **head)
{
	t_node	*current;
	t_node	*runner;
	int	c;

	c = 0;
	if (*head == NULL || (*head)->next == NULL)
		return ;
	current = *head;
	while (current != NULL)
	{
		runner = current->next;
		while (runner != NULL)
		{
			if (current->data == runner->data)
				c++;
			runner = runner->next;
		}
		current = current->next;
	}
	if (c > 0)
	{
		ft_printf("Error\n");
		stack_free(head);
		exit (1);
	}
}

void	check_args(int argc, char **args, t_node **head_a)
{
	int		i;
	char	**tmp;
	char	**ptr;
	int		size;

	i = argc - 1;
	while (i > 0)
	{
		tmp = ft_split(args[i], ' ');
		ptr = tmp;
		size = ft_count(tmp) - 1;
		while (size >= 0)
		{
			if (!is_number(tmp[size]))
			{
				ft_printf("Error\n");
				free_matrix(ptr);
				exit(1);
			}
			stack_insert(head_a, ft_atoi(tmp[size]));
			size--;
		}
		free_matrix(ptr);
		i--;
	}
}

void	ft_error_msg(void)
{
	ft_printf("Error\n");
	return ;
}
