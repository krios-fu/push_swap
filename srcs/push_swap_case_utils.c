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

int	get_next_min(t_list *stack_a, int ref)
{
	int	len;
	int	min;
	int	pos;

	len = 1;
	min = 0;
	pos = 0;
	while (stack_a)
	{  
		if (stack_a->content > ref)
		{
			if (min == 0)
			{
				min = stack_a->content;;
			}
			if (min >= stack_a->content)
			{
				min = stack_a->content;
				pos = len;
			}
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

void	move_hold_first(t_list **stack_a, t_list **stack_b, int start)
{
	int	len_stack;
	int	hold_first;
	int	hold_second;
	int	iter;

	len_stack = ft_lstsize(*stack_a);
	hold_first = get_next_min(*stack_a, start);
	hold_second = get_next_min(*stack_a, hold_first);
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

void	move_hold_second(t_list **stack_a, t_list **stack_b, int start)
{
	int	len_stack;
	int	hold_first;
	int	hold_second;
	int	iter;

	len_stack = ft_lstsize(*stack_a);
	hold_first = get_next_min(*stack_a, start);
	hold_second = get_next_min(*stack_a, hold_first);
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
		move_hold_first(stack_a, stack_b, start);
}

int	get_max_content(t_list *stack)
{
	int	len;
	int	max;
	int	pos;

	len = 0;
	max = stack->content;
	pos = 1;
	while (stack)
	{
		if (stack->content > max)
		{
			max = stack->content;
			pos = len + 1;
		}
		stack = stack->next;
		len++;
	}
	return (pos);
}

void push_stack_a(t_list **stack_a, t_list **stack_b)
{
	int iter;
	int hold;
	int len_stack;

	iter = 0;
	len_stack = 0;
	hold = 0;

	while(*stack_b)
	{
		hold = get_max_content(*stack_b);
		len_stack = ft_lstsize(*stack_b);
		iter = get_iterative(hold, len_stack);
		while(iter > 0)
		{
			if(len_stack > 1)
			{
				if (hold > (len_stack / 2))
					reverse_rotate(stack_b, 'b');
				else
					rotate(stack_b, 'b');
			}
			iter--;
		}
		push(stack_b, stack_a, 'b');
	}
}