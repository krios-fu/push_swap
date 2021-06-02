/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krios-fu <krios-fu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/02 19:03:33 by krios-fu          #+#    #+#             */
/*   Updated: 2021/06/02 21:38:48 by krios-fu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


void exec_arg(t_list **stack_a, t_list **stack_b, char *argv)
{
	if((!ft_strncmp("sa", argv, 2) || !ft_strncmp(argv, "ss", 2)) && (*stack_a)->next)
		swap_stack(*stack_a, 'Q');
	if((!ft_strncmp("sb", argv, 2) || !ft_strncmp(argv, "ss", 2)) && (*stack_b)->next)
		swap_stack(*stack_b, 'Q');
	if(!ft_strncmp("pb", argv, 3) && *stack_a)
		push(stack_a, stack_b, 'Q');
	if(!ft_strncmp("pa", argv, 3) && *stack_b)
		push(stack_b, stack_a, 'Q');
	if((!ft_strncmp("ra", argv, 3) || !ft_strncmp(argv, "rr", 3)) && (*stack_a)->next)
		rotate(stack_a, 'Q');
	if((!ft_strncmp("rb", argv, 3) || !ft_strncmp(argv, "rr", 3)) && (*stack_b)->next)
		rotate(stack_b, 'Q');
	if((!ft_strncmp("rra", argv, 4) || !ft_strncmp(argv, "rrr", 4)) && (*stack_a)->next)
		reverse_rotate(stack_a, 'Q');
	if((!ft_strncmp(argv, "rrb", 4) || !ft_strncmp(argv, "rrr", 4)) && (*stack_b)->next)
		reverse_rotate(stack_b, 'Q');
}

void	set_arg(t_list **stack_a, t_list **stack_b)
{
	char	*line;
	int		end;

	line = 0;
	end = 1;
	while(end)
	{
		end = get_next_line (0, &line);
		exec_arg(stack_a, stack_b, line);
		free (line);
	}
	if(check_a(*stack_a, ft_lstsize(*stack_a)) && !*stack_b)
		printf("OK");
	else
		printf("KO");
	
}

int main (int argc, char *argv[])
{
	t_list	*stack_a;
	t_list	*stack_b;
	char	**split_argument;
	int 	i;
	int		j;

	i = 1;
	while (i < argc)
	{
		j = 0;
		split_argument = check_number_argv(argv[i]);
		if (fill_stack(&stack_a, split_argument))
		{
			print_error();
			return (1);
		}
		while (split_argument[j])
			free(split_argument[j++]);
		i++;
	}
	if(argc > 1)
		set_arg(&stack_a, &stack_b);
}