/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_case_hundred.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krios-fu <krios-fu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/28 16:06:17 by krios-fu          #+#    #+#             */
/*   Updated: 2021/05/30 19:34:32 by krios-fu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	len_block (int len)
{
	if (len >= 100 && len < 500)
		return (20);
	else if (len >= 500)
		return (50);
	else if (len > 5)
		return (5);
	else if (len == 4)
		return (2);
	return (0);
}

void	push_min(t_list **stack_a, t_list **stack_b, int pivote_a)
{
	int	*sort_array_b;
	int	len_b;

	push(stack_a, stack_b, 'a');
	sort_array_b = fill_array_int(*stack_b);
	ft_sort_array(sort_array_b, ft_lstsize(*stack_b));
	len_b = ft_lstsize(*stack_b);
	if (ft_lstsize(*stack_b) >= 2 && (*stack_b)->content
		< sort_array_b[len_b / 2] && ft_lstsize(*stack_a) >= 2
		&& (*stack_a)->content > pivote_a)
		rotate_rr(stack_a, stack_b);
	free(sort_array_b);
}

void	rotate_max(t_list **stack_a, t_list **stack_b)
{
	int	*sort_array_b;
	int	len_b;

	sort_array_b = fill_array_int(*stack_b);
	ft_sort_array(sort_array_b, ft_lstsize(*stack_b));
	len_b = ft_lstsize(*stack_b);
	if (ft_lstsize(*stack_b) >= 2 && (*stack_b)->content
		< sort_array_b[len_b / 2])
		rotate_rr(stack_a, stack_b);
	else
		rotate(stack_a, 'a');
	free(sort_array_b);
}

void	push_hundred (t_list **stack_a, t_list **stack_b, int len, int *s_array)
{
	int	i;
	int	block_inc;
	int	pivote_a;

	block_inc = len_block(len);
	i = block_inc;
	pivote_a = s_array[i];
	while (ft_lstsize(*stack_a) > 0)
	{
		while (ft_lstsize(*stack_b) < i)
		{
			if (pivote_a > (*stack_a)->content || i == len)
				push_min(stack_a, stack_b, pivote_a);
			else
				rotate_max(stack_a, stack_b);
		}
		i += block_inc;
		if (i < len)
			pivote_a = s_array[i];
		else
		{
			pivote_a = s_array[len - 1];
			i = len;
		}
	}
}
