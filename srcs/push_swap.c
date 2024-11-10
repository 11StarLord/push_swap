/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djoao <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 11:14:14 by djoao             #+#    #+#             */
/*   Updated: 2024/10/17 11:14:17 by djoao            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_node	*a;
	t_node	*b;

	if (argc > 1)
	{
		a = NULL;
		b = NULL;
		check_args(argc, argv, &a);
		check_duplicate_stack(&a);
		if (check_sorted(a) == 1)
			verify_arg(&a, &b);
		stack_free(&a);
	}
	else if (argc == 1 || (argc == 2 && argv[1][0] == '\0'))
		return (1);
	return (0);
}
