/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krios-fu <krios-fu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/31 15:33:09 by krios-fu          #+#    #+#             */
/*   Updated: 2021/05/29 22:43:27 by krios-fu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	push_swap(t_list **stack_a, t_list **stack_b)
{
	int	len;

	len = ft_lstsize(*stack_a);
	if (len == 2)
	{
		if ((*stack_a)->content > (*stack_a)->next->content)
			swap_stack(*stack_a, 'a');
	}
	if (len == 3)
		push_swap_case_three(stack_a);
	else if (len == 5)
		push_swap_case_five(stack_a, stack_b);
	else if (len > 5 || len == 4)
	{
		push_swap_case_hundred(stack_a, stack_b, len);
		push_stack_a(stack_a, stack_b);
	}
	return (check_a(*stack_a, len));
}

int	main(int argc, char *argv[])
{
	t_list	*stack_a;
	t_list	*stack_b;
	char	**split_argument;
	int		i;

	i = 1;
	split_argument = NULL;
	if (argc > 1)
	{
		while (i < argc)
		{
			split_argument = check_number_argv(argv[i]);
			if (fill_stack(&stack_a, &split_argument[0]))
			{
				print_error();
				return (1);
			}
			free(split_argument);
			i++;
		}
		push_swap(&stack_a, &stack_b);
	}
}
