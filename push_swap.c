/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krios-fu <krios-fu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/31 15:33:09 by krios-fu          #+#    #+#             */
/*   Updated: 2021/05/20 22:58:26 by krios-fu         ###   ########.fr       */
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

int get_ref_final(t_list *stack_a, int min_top)
{
	while (stack_a && stack_a->content != min_top)
	{
		if (stack_a->next->content == min_top)
			return(stack_a->content);			
		stack_a = stack_a->next;
	}
	return (min_top);
}

void recursive_sort_b(t_list **stack_a, t_list **stack_b, int ref, int status, int min_top)
{
	int 	*sort_array_b;
	int		pivote_b;
	int 	len_b;

	print_stacks(*stack_a, *stack_b);
	sort_array_b = fill_array_int(*stack_b);
	ft_sort_array(sort_array_b, ft_lstsize(*stack_b));
	len_b = ft_lstsize(*stack_b);
	printf(" original len_b [[[%d]]] len_b/2 [[%d]]\n", len_b, len_b/2);
	if (len_b % 2 == 0)
	{
		pivote_b = sort_array_b[(len_b / 2) - 1];
		
	}
	  else 
	{
		 pivote_b = sort_array_b[(len_b / 2)];
		
	 }
	//pivote_b = sort_array_b[ft_lstsize(*stack_b) >> 1];
	printf("[[[pivote b %d]]]\n", pivote_b);
		printf("[[[ref a %d]]]\n", ref);
	while ((ft_lstsize(*stack_b) > len_b / 2) && ft_lstsize(*stack_b) > 2)
	{
		printf("len_b [[[%d]]] len_b/2 [[%d]]", len_b, len_b/2);
		if(pivote_b < (*stack_b)->content)
			push(stack_b, stack_a,'b');
		else
			rotate(stack_b, 'b');
		print_stacks(*stack_a, *stack_b);
	}
	free(sort_array_b);
	if(ft_lstsize(*stack_b) == 2)
	{
		if((*stack_b)->content > (*stack_b)->next->content && (*stack_a)->content > (*stack_a)->next->content)
			swap_ss(*stack_a, *stack_b);
		else if ((*stack_b)->content > (*stack_b)->next->content)
			swap_stack(*stack_b,'b');
		while (*stack_b)
		{
			push(stack_b, stack_a, 'b');
			rotate(stack_a, 'a');
			print_stacks(*stack_a, *stack_b);
		}
		print_stacks(*stack_a, *stack_b);
	}
	else
		recursive_sort_b(stack_a, stack_b, ref, status, min_top);

	printf("recursive before while");
	print_stacks(*stack_a, *stack_b);
	 if (status == 1)
	 	ref = get_ref_final(*stack_a, min_top);
	printf("ref before while [[%d]]", ref);
	while((*stack_a)->content != ref && ref)
	{
		push(stack_a, stack_b, 'a');
		print_stacks(*stack_a, *stack_b);
	}
	if (ft_lstsize(*stack_b) > 1)
		recursive_sort_b(stack_a, stack_b, ref, status, min_top);
	else
	{
		if (ft_lstsize(*stack_b) == 1)
		{	
			push(stack_b, stack_a, 'b');
			if((*stack_a)->content > (*stack_a)->next->content)
			{
				swap_stack(*stack_a, 'a');

			}
			printf("final\n");
				rotate(stack_a, 'a');
				rotate(stack_a, 'a');
		}
	
		
	}
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
	int ref_final;


	int 	len_aux;

	len  = ft_lstsize(*stack_a);
	//pivote = sort_array[len >> 1];
	sort_array = fill_array_int(*stack_a);
	ft_sort_array(sort_array, ft_lstsize(*stack_a));

	// if (len % 2 == 0)
		 pivote_a = sort_array[ft_lstsize(*stack_a) >> 1];
	// else 
		// pivote_a = sort_array[(len / 2) + 1];
	while (!check_a(*stack_a, len))
	{
		//pivote_a = sort_array[len / 2];
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
	

			//sort_array = fill_array_int(*stack_a);
			//ft_sort_array(sort_array, ft_lstsize(*stack_a));
			
			ref_final = ft_lstlast(*stack_a)->content;
			len_aux = ft_lstsize(*stack_a);
			
			print_stacks(*stack_a, *stack_b);
			ref = pivote_a;
			recursive_sort_b(stack_a, stack_b, ref, 0, sort_array[0]);
			print_stacks(*stack_a, *stack_b);
			printf("[len_aux%d]", len_aux);
			while (len_aux > 0)
			{
				push(stack_a, stack_b, 'a');
				len_aux--;
			}
			print_stacks(*stack_a, *stack_b);
			recursive_sort_b(stack_a, stack_b, ref_final, 1, sort_array[0]);
			printf("Final print\n");
			print_stacks(*stack_a, *stack_b);
				
			free(sort_array);
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