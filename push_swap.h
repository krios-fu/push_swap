/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krios-fu <krios-fu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/15 14:21:00 by krios-fu          #+#    #+#             */
/*   Updated: 2021/05/15 22:29:53 by krios-fu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include    "./libft/libft.h"
# include    <stdio.h>
# include    <stdlib.h>

void	print_error(void);
int		dup_number(t_list *stack, int number);
int		fill_stack (t_list	**stack_a, char **str);
void	del_first_node(t_list **stack);
int		check_a (t_list *stack, int len);
int		check_b (t_list *stack);
void	push(t_list **stack, t_list **stack_dest, char c);
void	ft_swap (int *content_a, int *content_b, char c);
void	swap_stack (t_list *stack, char c);
void	swap_ss (t_list *stack_a, t_list *stack_b);
void	rotate (t_list **stack, char c);
void	rotate_rr (t_list **stack_a, t_list **stack_b);
void	reverse_rotate (t_list **stack, char c);
void	reverse_rotate_rr(t_list **stack_a, t_list **stack_b);
void	*case_swap(void);
void	case_zero(t_list **stack_a, t_list **stack_b);
void	case_one(t_list **stack_a, t_list **stack_b);
void	case_two(t_list **stack_a, t_list **stack_b);
void	case_three(t_list **stack_a, t_list **stack_b);
void	case_four(t_list **stack_a, t_list **stack_b);
int		get_pos_stack(t_list *stack_a, int content_b);
void	push_swap_case_three(t_list **stack_a);
void	push_swap_case_five(t_list **stack_a, t_list **stack_b);
int     get_min_pos_hold_first(t_list *stack_a);
int     get_min_pos_hold_second(t_list *stack_a, int pos_hold_first);
void    print_stacks(t_list *stack_a, t_list *stack_b);
void	push_swap_case(t_list **stack_a, t_list **stack_b);
void	move_hold_second(t_list **stack_a, t_list **stack_b);
void	move_hold_first(t_list **stack_a, t_list **stack_b);

#endif
