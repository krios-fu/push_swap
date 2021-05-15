/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krios-fu <krios-fu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/31 15:33:09 by krios-fu          #+#    #+#             */
/*   Updated: 2021/05/15 19:48:25 by krios-fu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void print_stacks(t_list *stack_a, t_list *stack_b)
{
	//system("clear");
	//printf("\n\n\n");
	printf("\na\t\t\tb\n\n");
	while (stack_a || stack_b)
	{
		if (stack_a)
		{
			printf("%d\t\t\t", stack_a->content);
			stack_a = stack_a->next;
			
		}
		else
			printf(" \t\t\t");
		if (stack_b)
		{
			printf("%d", stack_b->content);
			stack_b = stack_b->next;
			
		}
		else
			printf(" ");
		
		printf("\n");	
	}
}



int	push_swap(t_list **stack_a, t_list **stack_b)
{
	int len;
	len  = ft_lstsize(*stack_a);
	while (!check_a(*stack_a, len))
	{
		if (len == 3)
			push_swap_case_three(stack_a);
		if (len == 5)
			push_swap_case_five(stack_a, stack_b);
	}

	return (check_a(*stack_a, len));
}

int main (int argc, char * argv[])
{
	t_list	*stack_a;
	t_list	*stack_b;
	if (fill_stack(&stack_a, argv))
	{
		print_error();
		return(0);
	}
	push_swap_case(&stack_a, &stack_b);
	print_stacks(stack_a, stack_b);
	//push_swap(&stack_a, &stack_b);

}