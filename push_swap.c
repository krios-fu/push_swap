/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krios-fu <krios-fu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/31 15:33:09 by krios-fu          #+#    #+#             */
/*   Updated: 2021/05/28 22:04:11 by krios-fu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void print_stacks(t_list *stack_a, t_list *stack_b)
{
	
	// system("clear");
	// printf("\n\n\n");
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

int get_ref_final(t_list *stack_a, int ref_mod)
{
	while (stack_a && stack_a->content != ref_mod)
	{
		if (stack_a->next->content == ref_mod)
			return(stack_a->content);
		stack_a = stack_a->next;
	}
	return (ref_mod);
}

int push_swap(t_list **stack_a, t_list **stack_b)
{
	int		len;

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



int main (int argc, char * argv[])
{
	t_list	*stack_a;
	t_list	*stack_b;

	//check_number(argv);
	if (fill_stack(&stack_a, argv))
	 {
		 print_error();
		 return(1);
	 }
	
		push_swap(&stack_a, &stack_b);
	//print_stacks(stack_a, stack_b);
	//printf("%d", get_min_pos_hold_first(stack_a));
	//push_swap_case(&stack_a, &stack_b);

}
