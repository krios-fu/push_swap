/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krios-fu <krios-fu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/15 14:35:17 by krios-fu          #+#    #+#             */
/*   Updated: 2021/05/28 19:42:33 by krios-fu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	del_first_node(t_list **stack)
{
	t_list	*aux;

	aux = *stack;
	*stack = (*stack)->next;
	free(aux);
}

int	check_a (t_list *stack, int len)
{
	int	len_start;

	len_start = ft_lstsize(stack);
	while (stack->next)
	{
		if (stack->content < stack->next->content)
			stack = stack->next;
		else
			return (0);
	}
	if (len == len_start)
		return (1);
	else
		return (0);
}

int	get_pos_stack(t_list *stack_a, int content_b)
{
	int	pos;

	pos = 0;
	while (stack_a)
	{
		if (stack_a->content < content_b)
			pos++;
		stack_a = stack_a->next;
	}
	return (pos);
}
