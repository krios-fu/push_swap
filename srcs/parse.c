/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krios-fu <krios-fu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/15 14:31:07 by krios-fu          #+#    #+#             */
/*   Updated: 2021/05/28 22:14:51 by krios-fu         ###   ########.fr       */
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

int check_number_argv(char *argv [])
{
	char **split_arg;
	int i;
	int j;
	int flag;

	i = 0;
	j = 0;
	flag = 0;
	split_arg = ft_split(argv[1], ' ');
	while (split_arg[i])
	{
		while(split_arg[i][j])
		{
			if ( ft_isdigit(split_arg[i][j]) || split_arg[i][j] == '-' || split_arg[i][j] == '+')
				{
					if(ft_isdigit(split_arg[i][j]))
						flag = 1;
					if ((flag == 1 && (split_arg[i][j] == '-' || split_arg[i][j] == '+')))
						print_error();
				}
				else
						print_error();
			j++;
		}
		i++;
	}
	return(1);
}

int	parse(char *argv[])
{
	return (0);
}