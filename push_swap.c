/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krios-fu <krios-fu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/31 15:33:09 by krios-fu          #+#    #+#             */
/*   Updated: 2021/05/17 21:07:24 by krios-fu         ###   ########.fr       */
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
	int		len;
	int		*sort_array;
	int		i = 0;

	int 	len_aux;

	len  = ft_lstsize(*stack_a);
	/*sort_array = fill_array_int(*stack_a);
	ft_sort_array(sort_array, ft_lstsize(*stack_a));*/
	while (!check_a(*stack_a, len))
	{
		len_aux = ft_lstsize(*stack_a);
		i = 0;
		reverse_rotate(stack_a, 'a');
		while (i < len_aux)
		{
			//print_stacks(*stack_a, *stack_b);
			
			if((*stack_a)->content < (*stack_a)->next->content)
			{
				swap_stack(*stack_a, 'a');
				rotate(stack_a, 'a');
				
			}
			else
			{
				swap_stack(*stack_a, 'a');
				push(stack_a, stack_b, 'a');	
			}
			
				i++;
		}
		//print_stacks(*stack_a, *stack_b);
		push_stack_a(stack_a, stack_b);
		//print_stacks(*stack_a, *stack_b);






		
		/*  if (len == 3)
			push_swap_case_three(stack_a);
		if (len == 5)
			push_swap_case_five(stack_a, stack_b);
		else
		{
			//printf("[[%d]]", get_content( *stack_a, get_min_pos_hold_first(*stack_a)));
			push_swap_case(stack_a, stack_b, sort_array);
			push_stack_a(stack_a, stack_b);
		}*/
	}
	push_stack_a(stack_a, stack_b);
	return (check_a(*stack_a, len));
}

int main (int argc, char * argv[])
{
	t_list	*stack_a;
	t_list	*stack_b;
	if (fill_stack(&stack_a, argv))
	{
		print_error();
		return(1);
	}
	
	push_swap(&stack_a, &stack_b);
	//printf("%d", get_min_pos_hold_first(stack_a));
	//push_swap_case(&stack_a, &stack_b);
	//print_stacks(stack_a, stack_b);

}