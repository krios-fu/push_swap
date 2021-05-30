/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krios-fu <krios-fu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/15 14:31:07 by krios-fu          #+#    #+#             */
/*   Updated: 2021/05/30 15:57:49 by krios-fu         ###   ########.fr       */
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

	i = 0;
	if (!str[0] || (ft_strlen(&str[0][0]) >= 11 && str[0][0] != '-'))
		return (1);
	content = ft_atoi_check(&str[0][0]);
	while (str[i])
	{
		content = ft_atoi_check(&str[i][0]);
		if (dup_number(*stack_a, content))
		{
			while (*stack_a)
				del_first_node(stack_a);
			 print_error();
			printf ("error");
		}
		else
			ft_lstadd_back(stack_a, ft_lstnew(content));
		i++;
	}
	return (0);
}

static	int	is_neg_pos(int c)
{
	if (c == '-' || c == '+')
		return (1);
	return (0);
}

char	**check_number_argv(char *argv)
{
	t_var_split	var;

	var.i = 0;
	var.j = 0;
	var.num = ft_split(argv, ' ');
	while (var.num[var.i])
	{
		var.flag = 0;
		while (var.num[var.i][var.j])
		{
			if (ft_isdigit(var.num[var.i][var.j]) ||
				is_neg_pos(var.num[var.i][var.j]))
			{
				if (ft_isdigit(var.num[var.i][var.j]))
					var.flag = 1;
				if (var.flag == 1 && is_neg_pos(var.num[var.i][var.j]))
					print_error();
			}
			else
				print_error();
			var.j++;
		}
		var.i++;
	}
	return (var.num);
}
