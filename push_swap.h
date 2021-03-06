/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krios-fu <krios-fu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/15 14:21:00 by krios-fu          #+#    #+#             */
/*   Updated: 2021/06/02 19:09:36 by krios-fu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include    "./libft/libft.h"
# include    "./gnl/get_next_line_bonus.h"
# include    <stdio.h>
# include    <stdlib.h>

typedef struct s_var_split
{
	char	**num;
	int		i;
	int		j;
	int		flag;
}				t_var_split;

typedef struct s_var
{
	int		iter;
	int		hold;
	int		len_stack;
	int		len_b;
	int		flag;
}				t_var;

void	print_error(void);
int		dup_number(t_list *stack, int number);
int		fill_stack (t_list	**stack_a, char **str);
void	del_first_node(t_list **stack);
int		check_a (t_list *stack, int len);
void	push(t_list **stack, t_list **stack_dest, char c);
void	ft_swap(int *content_a, int *content_b, char c);
void	swap_stack (t_list *stack, char c);
void	swap_ss(t_list *stack_a, t_list *stack_b);
void	rotate(t_list **stack, char c);
void	rotate_rr(t_list **stack_a, t_list **stack_b);
void	reverse_rotate(t_list **stack, char c);
void	reverse_rotate_rr(t_list **stack_a, t_list **stack_b);
void	*case_swap(void);
void	case_zero(t_list **stack_a, t_list **stack_b);
void	case_one(t_list **stack_a, t_list **stack_b);
void	case_two(t_list **stack_a, t_list **stack_b);
void	case_three(t_list **stack_a, t_list **stack_b);
void	case_four(t_list **stack_a, t_list **stack_b);
int		get_pos_stack(t_list *stack_a, int content_b);
void	push_swap_case_three(t_list **stack_a);
void	push_case_three_stack_b(t_list **stack_a);
void	push_swap_case_five(t_list **stack_a, t_list **stack_b);
void	push_hundred (t_list **stack_a, t_list **stack_b,
			int len, int *s_array);
int		get_max_content(t_list *stack);
void	push_stack_a(t_list **stack_a, t_list **stack_b);
int		get_iterative(int hold, int len_stack);
void	ft_sort_array(int *tab, int size);
int		*fill_array_int(t_list *stack);
int		check_number(char *argv []);
int		ft_atoi_check(const char *str);
char	**check_number_argv(char *argv);
void	iter_push(t_list **stack_a, t_list **stack_b, t_var *var, int *s_array);

#endif
