/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_case_utils.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krios-fu <krios-fu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/15 17:33:25 by krios-fu          #+#    #+#             */
/*   Updated: 2021/05/15 22:30:27 by krios-fu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	get_min_pos_hold_first(t_list *stack_a)
{
	int	len;
	int	min;
	int	pos;

	len = 0;
	min = stack_a->content;
	pos = 1;
	while (stack_a)
	{
		if (stack_a->content < min)
		{
			min = stack_a->content;
			pos = len + 1;
		}
		stack_a = stack_a->next;
		len++;
	}
	return (pos);
}

int	get_min_pos_hold_second(t_list *stack_a, int pos_hold_first)
{
	int	len;
	int	min;
	int	pos;

	len = 0;
	pos = 0;
	min = stack_a->content;
	if (pos_hold_first == 1)
	{
		min = stack_a->next->content;
		stack_a = stack_a->next;
		len = 1;
	}
	while (stack_a)
	{
		if (len != pos_hold_first - 1 && stack_a->content <= min)
		{
			min = stack_a->content;
			pos = len + 1;
		}
		stack_a = stack_a->next;
		len++;
	}
	return (pos);
}

int	get_iterative(int hold, int len_stack)
{
	if (hold <= (len_stack / 2))
		return (hold - 1);
	else
		return (len_stack - hold + 1);
}

void	move_hold_first(t_list **stack_a, t_list **stack_b)
{
	int	len_stack;
	int	hold_first;
	int	hold_second;
	int	iter;

	len_stack = ft_lstsize(*stack_a);
	hold_first = get_min_pos_hold_first(*stack_a);
	hold_second = get_min_pos_hold_second(*stack_a, hold_first);
	iter = get_iterative(hold_first, len_stack);
	while (iter > 0)
	{
		if (hold_first > (len_stack / 2))
			reverse_rotate(stack_a, 'a');
		else
			rotate(stack_a, 'a');
		iter--;
	}
}

void	move_hold_second(t_list **stack_a, t_list **stack_b)
{
	int	len_stack;
	int	hold_first;
	int	hold_second;
	int	iter;

	len_stack = ft_lstsize(*stack_a);
	hold_first = get_min_pos_hold_first(*stack_a);
	hold_second = get_min_pos_hold_second(*stack_a, hold_first);
	if (get_iterative(hold_second, len_stack)
		< get_iterative(hold_first, len_stack))
	{
		iter = get_iterative(hold_second, len_stack);
		while (iter > 0)
		{
			if (hold_second > (len_stack / 2))
				reverse_rotate(stack_a, 'a');
			else
				rotate(stack_a, 'a');
			iter--;
		}
	}
	else
		move_hold_first(stack_a, stack_b);
}
