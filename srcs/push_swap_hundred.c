/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_hundred.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krios-fu <krios-fu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/15 17:33:25 by krios-fu          #+#    #+#             */
/*   Updated: 2021/05/15 19:33:30 by krios-fu         ###   ########.fr       */
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

	len = 1;
	pos = 0;
	if (pos_hold_first == 1)
	{
		min = stack_a->next->content;
		stack_a = stack_a->next;
	}
	else
	{
		min = stack_a->content;
		len = 0;
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


