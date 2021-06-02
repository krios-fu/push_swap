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


static void exec_arg(t_list **stack_a, t_list **stack_b, char *cmd)
{
	if(ft_lstsize((*stack_a)) > 1 && (!ft_strncmp("sa", cmd, 2)
		|| !ft_strncmp(cmd, "ss", 2)))
		swap_stack(*stack_a, 'Q');
	if(ft_lstsize((*stack_b)) > 1 && (!ft_strncmp("sb", cmd, 2)
		|| !ft_strncmp(cmd, "ss", 2)))
		swap_stack(*stack_b, 'Q');
	 if(!ft_strncmp("pb", cmd, 2) && *stack_a)
		 push(stack_a, stack_b, 'Q');
	if(!ft_strncmp("pa", cmd, 2) && *stack_b)
		push(stack_b, stack_a, 'Q');
	 if(ft_lstsize((*stack_a)) > 1 && (!ft_strncmp("rra", cmd, 3)
	 	|| !ft_strncmp("rrr", cmd, 3)))
		 reverse_rotate(stack_a, 'Q');
	if(ft_lstsize((*stack_b)) > 1 && (!ft_strncmp("rrb", cmd, 3)
		|| !ft_strncmp(cmd, "rrr", 3)))
		 reverse_rotate(stack_b, 'Q');
	if(ft_lstsize((*stack_a)) > 1 && (!ft_strncmp("ra", cmd, 2)
		|| !ft_strncmp(cmd, "rr", 2)) && ft_strlen(cmd) < 3)
		 rotate(stack_a, 'Q');
	if(ft_lstsize((*stack_b)) > 1 && (!ft_strncmp("rb", cmd, 2)
		|| !ft_strncmp(cmd, "rr", 2)) && ft_strlen(cmd) < 3 )
		 rotate(stack_b, 'Q');
}

static char	**fill_array_cmd()
{
	char	**list;

	list = malloc(sizeof(char *) * 12);

	list[0] = ft_strdup("sa");
	list[1] = ft_strdup("sb");
	list[2] = ft_strdup("ss");
	list[3] = ft_strdup("ra");
	list[4] = ft_strdup("rb");
	list[5] = ft_strdup("rr");
	list[6] = ft_strdup("rra");
	list[7] = ft_strdup("rrb");
	list[8] = ft_strdup("rrr");
	list[9] = ft_strdup("pa");
	list[10] = ft_strdup("pb");
	list[11] = NULL;

	return (list);
}

static void	check_comand(char **array_comand, char *cmd)
{
	int i;
	int flag;

	i = 0;
	flag = 0;
	while (array_comand[i])
	{
		if (!ft_strncmp(array_comand[i], cmd, ft_strlen(cmd)))
			flag = 1;
		i++;
	}	
	if(flag)
		return ;
	else
		print_error();
}

static void	set_arg(t_list **stack_a, t_list **stack_b)
{
	char	*line;
	int		end;
	char	**comand;
	int		j;

	comand = fill_array_cmd();
	line = 0;
	end = 1;
	j = 0;
	while(end)
	{
		end = get_next_line (0, &line);
		check_comand(comand, line);
		exec_arg(stack_a, stack_b, line);
		free (line);
	}
	if(check_a(*stack_a, ft_lstsize(*stack_a)) && !*stack_b)
		printf("\nOK");
	else
		printf("\nKO");
	while (comand[j])
		free(comand[j++]);
	free(comand);
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
			print_error();
		while (split_argument[j])
			free(split_argument[j++]);
		i++;
	}
	free(split_argument);
	if(argc > 1)
		set_arg(&stack_a, &stack_b);
	return(0);
}