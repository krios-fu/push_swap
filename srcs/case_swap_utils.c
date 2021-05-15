/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   case_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krios-fu <krios-fu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/15 14:49:34 by krios-fu          #+#    #+#             */
/*   Updated: 2021/05/15 16:22:03 by krios-fu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	case_zero(t_list **stack_a, t_list **stack_b)
{
	push(stack_b, stack_a, 'b');
}

void	case_one(t_list **stack_a, t_list **stack_b)
{
	push(stack_b, stack_a, 'b');
	swap_stack(*stack_a, 'a');
}

void	case_two(t_list **stack_a, t_list **stack_b)
{
	reverse_rotate(stack_a, 'a');
	push(stack_b, stack_a, 'b');
	rotate(stack_a, 'a');
	rotate(stack_a, 'a');
}

void	case_three(t_list **stack_a, t_list **stack_b)
{
	push(stack_b, stack_a, 'b');
	rotate(stack_a, 'a');
}

void	case_four(t_list **stack_a, t_list **stack_b)
{
	rotate(stack_a, 'a');
	push(stack_b, stack_a, 'b');
	swap_stack(*stack_a, 'a');
	reverse_rotate(stack_a, 'a');
}
