/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djoao <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 12:17:29 by djoao             #+#    #+#             */
/*   Updated: 2024/10/14 17:50:17 by djoao            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../ft_printf/ft_printf.h"
# include "../libft/libft.h"

typedef struct s_n
{
	int				data;
	unsigned int	index;
	struct s_n		*next;
}	t_node;

typedef struct s_minmax
{
	int	min;
	int	max;
}	t_minmax;

unsigned int	calc_index_node(t_node **head_a, int curr_data);
t_node			*createnode(int data);
void			stack_insert(t_node **head, int newdata);
void			stack_print(t_node *head);
int				stack_size(t_node *head);
void			stack_free(t_node **head);
int				stack_min(t_node *head);
int				stack_max(t_node *head);
void			sa(t_node **head);
void			sb(t_node **head);
void			ss(t_node **head, t_node **head_b);
void			pa(t_node **head_a, t_node **head_b);
void			pb(t_node **head_a, t_node **head_b);
void			ra(t_node **head);
void			rb(t_node **head);
void			rr(t_node **head_a, t_node **head_b);
void			rra(t_node **head);
void			rrb(t_node **head);
void			rrr(t_node **head_a, t_node **head_b);
void			verify_arg(t_node **head_a, t_node **head_b);
void			organize_two(t_node **head);
void			organize_three(t_node **head);
void			organize_four(t_node **head_a, t_node **head_b);
void			organize_five(t_node **head_a, t_node **head_b);
void			organize_n(t_node **head_a, t_node **head_b);
int				get_index(t_node *head, int value);
int				is_number(char *nptr);
int				ft_count(char **str);
void			push_min_to_b(t_node **head_a, t_node **head_b);
void			push_max_to_a(t_node **head_a, t_node **head_b);
void			index_node_in_order(t_node **head_a);
int				get_map(int len, t_minmax in, t_minmax out);
void			send_partition(t_node **head_a, t_node **head_b, int len);
void			index_node_in_order(t_node **head_a);
void				check_duplicate_stack(t_node **head);
int				check_sorted(t_node *head);
void			check_args(int argc, char **args, t_node **head_a);
void			free_matrix(char **m);
void			ft_error_msg(void);

#endif
