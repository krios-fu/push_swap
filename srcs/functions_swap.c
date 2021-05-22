/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions_swap.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krios-fu <krios-fu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/15 14:41:18 by krios-fu          #+#    #+#             */
/*   Updated: 2021/05/15 21:34:46 by krios-fu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_swap (int *content_a, int *content_b, char c)
{
	int	content;

	content = *content_a;
	*content_a = *content_b;
	*content_b = content;
	if (c == 'a')
		printf("sa\n");
	else if ( c  == 'b')
		printf("sb\n");
	else if(c == 'x')
		printf("ss\n");
}

void	swap_stack (t_list *stack, char c)
{
	if (stack->next)
	{
		ft_swap(&stack->content, &stack->next->content, c);
	}
}

void	swap_ss (t_list *stack_a, t_list *stack_b)
{
	ft_swap(&stack_a->content, &stack_a->next->content, 'x');
	ft_swap(&stack_b->content, &stack_b->next->content, ' ');
}
