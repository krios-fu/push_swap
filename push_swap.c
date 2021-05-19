/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krios-fu <krios-fu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/31 15:33:09 by krios-fu          #+#    #+#             */
/*   Updated: 2021/05/19 23:08:04 by krios-fu         ###   ########.fr       */
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

void recursive_sort_b(t_list **stack_a, t_list **stack_b, int ref)
{
	int 	*sort_array_b;
	int		pivote_b;
	int 	len_b;

	while(ft_lstsize(*stack_b) > 5 )
	{		
		sort_array_b = fill_array_int(*stack_b);
		ft_sort_array(sort_array_b, ft_lstsize(*stack_b));
		pivote_b = sort_array_b[ft_lstsize(*stack_b) >> 1];
		len_b = ft_lstsize(*stack_b);
		printf("[[[pivote b %d]]]\n", pivote_b);
		while ((ft_lstsize(*stack_b) > len_b / 2 && ft_lstsize(*stack_b) > 5))
		{
			if(pivote_b < (*stack_b)->content)
				push(stack_b, stack_a,'b');
			else
				rotate(stack_b, 'b');
		}
		print_stacks(*stack_a, *stack_b);

		print_stacks(*stack_a, *stack_b);
		free(sort_array_b);
	}
		print_stacks(*stack_a, *stack_b);
		if(*stack_b)
			push_swap_case_five(stack_b, stack_a);
		print_stacks(*stack_a, *stack_b);
		while(*stack_b)
		{
			push(stack_b, stack_a, 'b');
			rotate(stack_a, 'a');	
		}
		print_stacks(*stack_a, *stack_b);

		while ((*stack_a)->content <= ref)
		{
			printf("[[[ref: %d]]", ref);
			print_stacks(*stack_a, *stack_b);
			push(stack_a, stack_b, 'a');
			print_stacks(*stack_a, *stack_b);

		}
		 if (*stack_b)
			 recursive_sort_b(stack_a, stack_b, ref);
}

int	push_swap(t_list **stack_a, t_list **stack_b)
{
	int		len;
	int		*sort_array;
	int		i = 0;
	int 	j = 0;
	int 	pivote_a;
	int		content_pos;
	int		content_pos_b;


	int 	ref;


	int 	len_aux;

	len  = ft_lstsize(*stack_a);
	sort_array = fill_array_int(*stack_a);
	ft_sort_array(sort_array, ft_lstsize(*stack_a));
	//pivote = sort_array[len >> 1];
	while (!check_a(*stack_a, len))
	{
		pivote_a = sort_array[len / 2];
		printf("pivote [%d]\n", pivote_a);
		// content_pos = get_content(*stack_a, i);
		
		while (ft_lstsize(*stack_a) > (len / 2))
		{
			print_stacks(*stack_a, *stack_b);
			if(pivote_a == (*stack_a)->content)
				swap_stack(*stack_a, 'a');
			if(pivote_a > (*stack_a)->content)
				push(stack_a, stack_b,'a');
			else
				rotate(stack_a, 'a');
		}
			print_stacks(*stack_a, *stack_b);
			ref = pivote_a;
			recursive_sort_b(stack_a, stack_b, ref);
			
			print_stacks(*stack_a, *stack_b);
			break ;
		}
		
		/*while(*stack_b)
		{
			push(stack_b, stack_a, 'b');
		}*/
		//print_stacks(*stack_a, *stack_b);
		i++;
		/*  if (len == 3)
			push_swap_case_three(stack_a);
		if (len == 5)
			push_swap_case_five(stack_a, stack_b);
		else
		{
			//printf("[[%d]]", get_content( *stack_a, get_min_pos_hold_first(*stack_a)));
			push_swap_case(stack_a, stack_b, sort_array);
			push_stack_a(stack_a, stack_b);
		}
	}
	push_stack_a(stack_a, stack_b);*/

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