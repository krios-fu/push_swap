/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_case_utils.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krios-fu <krios-fu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/15 17:33:25 by krios-fu          #+#    #+#             */
/*   Updated: 2021/05/28 19:40:32 by krios-fu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

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

int	get_iterative(int hold, int len_stack)
{
	if (hold <= (len_stack / 2))
		return (hold - 1);
	else
		return (len_stack - hold + 1);
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
	int *sort_array_b;
	int len_b;
	int flag;

	flag = 0;
	iter = 0;
	len_stack = 0;
	hold = 0;


	while(*stack_b)
	{
		hold = get_max_content(*stack_b);
		len_stack = ft_lstsize(*stack_b);
		iter = get_iterative(hold, len_stack);

		sort_array_b = fill_array_int(*stack_b);
		ft_sort_array(sort_array_b, ft_lstsize(*stack_b));
		len_b = ft_lstsize(*stack_b);

		while(iter > 0)
		{
			if(len_stack > 1)
			{
				if(len_b >= 2 && (*stack_b)->content == sort_array_b[len_b - 2 ] && flag == 0)
				{
					push(stack_b, stack_a, 'b');
					iter = 0;
					flag = 1;
				}
				else if (hold > (len_stack / 2))	
					reverse_rotate(stack_b, 'b');
				else
					rotate(stack_b, 'b');
			}
			iter--;
		}
		if(iter == 0)
		{
			push(stack_b, stack_a, 'b');
			flag = 0;
		}
		free(sort_array_b);
		 if(ft_lstsize(*stack_a) >= 2 && (*stack_a)->content > (*stack_a)->next->content && len_b > 2 && (*stack_b)->content < (*stack_b)->next->content)
			  swap_ss(*stack_a, *stack_b);
		if (ft_lstsize(*stack_a) >= 2 && (*stack_a)->content > (*stack_a)->next->content)
				 swap_stack(*stack_a, 'a');

	}
}