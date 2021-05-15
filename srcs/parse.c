/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krios-fu <krios-fu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/15 14:31:07 by krios-fu          #+#    #+#             */
/*   Updated: 2021/05/15 16:29:17 by krios-fu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	dup_number(t_list *stack, int number)
{
	while (stack)
	{
		if (stack->content == number)
			return (1);
		stack = stack->next;
	}
	return (0);
}

int	fill_stack (t_list	**stack_a, char **str)
{
	int	i;
	int	content;
	int	*num;

	i = 1;
	if (!str[i])
		return (1);
	content = ft_atoi(&str[i][0]);
	*stack_a = ft_lstnew(content);
	while (str[++i] != '\0')
	{
		content = ft_atoi(&str[i][0]);
		if (dup_number(*stack_a, content))
		{
			while (*stack_a)
				del_first_node(stack_a);
			print_error();
		}
		else
			ft_lstadd_back(stack_a, ft_lstnew(content));
	}
	return (0);
}
