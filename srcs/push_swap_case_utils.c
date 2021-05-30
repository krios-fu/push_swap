/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_case_utils.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krios-fu <krios-fu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/15 17:33:25 by krios-fu          #+#    #+#             */
/*   Updated: 2021/05/30 17:55:58 by krios-fu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

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

void	iter_push(t_list **stack_a, t_list **stack_b, t_var *var, int *s_array)
{
	while (var->iter > 0)
	{
		if (var->len_stack > 1)
		{
			if (var->len_b >= 2 && (*stack_b)->content
				== s_array[var->len_b - 2 ] && var->flag == 0)
			{
				push(stack_b, stack_a, 'b');
				var->iter = 0;
				var->flag = 1;
			}
			else if (var->hold > (var->len_stack / 2))
				reverse_rotate(stack_b, 'b');
			else
				rotate(stack_b, 'b');
		}
		var->iter--;
	}
	if (var->iter == 0)
	{
		push(stack_b, stack_a, 'b');
		var->flag = 0;
	}
	free(s_array);
}

void	push_stack_a(t_list **stack_a, t_list **stack_b)
{
	t_var	var;
	int		*s_array;

	var.flag = 0;
	var.iter = 0;
	var.len_stack = 0;
	var.hold = 0;
	while (*stack_b)
	{
		var.hold = get_max_content(*stack_b);
		var.len_stack = ft_lstsize(*stack_b);
		var.iter = get_iterative(var.hold, var.len_stack);
		s_array = fill_array_int(*stack_b);
		ft_sort_array(s_array, ft_lstsize(*stack_b));
		var.len_b = ft_lstsize(*stack_b);
		iter_push(stack_a, stack_b, &var, s_array);
		if (ft_lstsize(*stack_a) >= 2 && (*stack_a)->content
			> (*stack_a)->next->content && var.len_b > 2
			&& (*stack_b)->content < (*stack_b)->next->content)
			swap_ss(*stack_a, *stack_b);
		if (ft_lstsize(*stack_a) >= 2 && (*stack_a)->content
			> (*stack_a)->next->content)
			swap_stack(*stack_a, 'a');
	}
}
