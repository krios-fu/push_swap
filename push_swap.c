/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krios-fu <krios-fu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/31 15:33:09 by krios-fu          #+#    #+#             */
/*   Updated: 2021/05/26 18:01:11 by krios-fu         ###   ########.fr       */
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

void sort_stack_block (t_list ** stack_a, int len)
{
	int i;
	i = 0;
	int finish_a;

	finish_a = (*stack_a)->next->content;
		while (!check_a(*stack_a, len))
	{
		
		if((*stack_a)->content > (*stack_a)->next->content)
		{
				swap_stack(*stack_a, 'a');	
		}
		if(!check_stack_n(*stack_a, (*stack_a)->content, finish_a))
		{
			while(!check_stack_n(*stack_a, (*stack_a)->next->content, finish_a) && (*stack_a)->next->content != finish_a)
			{
				rotate(stack_a, 'a');
				if((*stack_a)->content > (*stack_a)->next->content)
				{
					swap_stack(*stack_a, 'a');
					if((*stack_a)->content == finish_a)
					 	finish_a = (*stack_a)->next->content;	
				}
			}
		}
		while(check_stack_n(*stack_a, (*stack_a)->content, finish_a) && !check_a(*stack_a, ft_lstsize(*stack_a) ))
				reverse_rotate(stack_a, 'a');
		i++;
	}
}
void recursive_sort_b(t_list **stack_a, t_list **stack_b)
{
	int 	*sort_array_b;
	int		pivote_b;
	int 	len_b;
	int i ;

	i = 0;


	
	// sort_array_b = fill_array_int(*stack_b);
	// ft_sort_array(sort_array_b, ft_lstsize(*stack_b));
	// len_b = ft_lstsize(*stack_b);
	

		// while (i < 5)
		// {
			// push(stack_b, stack_a, 'b');
			// i++;
		// }
		// sort_stack_block(stack_a, ft_lstsize(*stack_a));
		// printf("fuera del ciclo");
		// if(ft_lstsize(*stack_b) >= 5)
			// recursive_sort_b(stack_a, stack_a);
}


int	push_swap(t_list **stack_a, t_list **stack_b)
{

	int		len;
	int		*sort_array_a;
	int 	*sort_array_b;
	int 	pivote_a;
	int 	pivote_b;
	int 	start_b = 0;
	int 	finish_a = 0;
	int i;
	int j;
	i = 0;
	j = 0;

	len  = ft_lstsize(*stack_a);

	 sort_array_a = fill_array_int(*stack_a);
	ft_sort_array(sort_array_a, ft_lstsize(*stack_a));
	// if (len % 2 == 0)
		// pivote_a = sort_array_a[len / 2 ];
	// else 
		// pivote_a = sort_array_a[(len / 2) + 1];
	if(!check_a(*stack_a, len))
	{
		// while (ft_lstsize(*stack_a) > (len / 2))
		// {
				// push(stack_a, stack_b,'a');
		// }

		sort_stack_block(stack_a,ft_lstsize(*stack_a));
		// sort_stack_block(stack_b, ft_lstsize(*stack_b));
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
		return(1);
	}
	
	push_swap(&stack_a, &stack_b);
		 print_stacks(stack_a, stack_b);
	//printf("%d", get_min_pos_hold_first(stack_a));
	//push_swap_case(&stack_a, &stack_b);

}











/*  int	push_swap(t_list **stack_a, t_list **stack_b)
{
	int		len;
	int		*sort_array;
	int 	pivote_a;
	int 	ref;
	int		min_mod;

	len  = ft_lstsize(*stack_a);
	sort_array = fill_array_int(*stack_a);
	ft_sort_array(sort_array, ft_lstsize(*stack_a));
	if (len % 2 == 0)
		pivote_a = sort_array[len / 2 ];
	else 
		pivote_a = sort_array[(len / 2) + 1];
	ref = pivote_a;
	if(!check_a(*stack_a, len))
	{
		while (ft_lstsize(*stack_a) > (len / 2))
		{
			if(pivote_a > (*stack_a)->content)
				push(stack_a, stack_b,'a');
			else
				rotate(stack_a, 'a');
		}	
		min_mod = ft_lstsize(*stack_b) % 2;
		recursive_sort_b(stack_a, stack_b, ref, 0, &min_mod);
		 while ((*stack_a)->content != sort_array[0])
		 {
		 	push(stack_a, stack_b, 'a');
		 } 	
		recursive_sort_b(stack_a, stack_b, sort_array[0], 1, &min_mod);
		if (len % 2 != 0)
		{
			push(stack_b, stack_a, 'b');
			rotate(stack_a, 'a');
		}
		free(sort_array);
		}
	return (check_a(*stack_a, len));
}  */

/*void recursive_sort_b(t_list **stack_a, t_list **stack_b, int ref, int status, int *ref_mod)
{
	int 	*sort_array_b;
	int		pivote_b;
	int 	len_b;

	sort_array_b = fill_array_int(*stack_b);
	ft_sort_array(sort_array_b, ft_lstsize(*stack_b));
	len_b = ft_lstsize(*stack_b);
	pivote_b = sort_array_b[len_b / 2 - 1];
	if (len_b == 3)
		pivote_b = sort_array_b[2];
	if (len_b > 2 && !check_a(*stack_b, len_b))
	{
		while (ft_lstsize(*stack_b) > (len_b / 2) && ft_lstsize(*stack_b) > 2 && !check_a(*stack_b, ft_lstsize(*stack_b)))
		{	
			if (((len_b % 2 != 0) && (*stack_b)->content == sort_array_b[len_b / 2 + 1])|| (len_b == 3  && (*stack_b)->content == pivote_b))
				{
					push(stack_b, stack_a, 'b');
				}
			else if((*stack_b)->content > pivote_b)
				push(stack_b, stack_a, 'b');
				else 
					rotate(stack_b, 'b');	
		}
		free(sort_array_b);
		if (*stack_b)
			recursive_sort_b(stack_a, stack_b, ref, status, ref_mod);
	}
	else
	{
		if (ref_mod == 0)
		{
			if ((*stack_b)->content > (*stack_b)->next->content && (*stack_a)->content > (*stack_a)->next->content)
				{
					swap_ss(*stack_a, *stack_b);
					 *ref_mod += *ref_mod + 1;
					 *ref_mod %= 2;
				}
			if ((*stack_b)->content > (*stack_b)->next->content)
					swap_stack(*stack_b, 'b');
			if ((*stack_a)->content > (*stack_a)->next->content)
					swap_stack(*stack_a, 'a');
			while (*stack_b)
			{
				push(stack_b, stack_a, 'b');
				rotate(stack_a, 'a');
			}
			if ((*stack_a)->content  < ref && status == 0)
			{
				rotate(stack_a, 'a');
				rotate(stack_a, 'a');
			}
			else if ((*stack_a)->content > ref && status == 1)
			{
				rotate(stack_a, 'a');
				rotate(stack_a, 'a');
			}
		}
		else if ((*stack_b)->content > (*stack_b)->next->content)
				swap_stack(*stack_b, 'b');
		while (*stack_b)
		{
			push(stack_b, stack_a, 'b');
			rotate(stack_a, 'a');
		}
			//   printf("[[[[[[[[%d]]]]]]]]]\n", return_num_push(stack_a, ref));
			//   return ;
	  	while((*stack_a)->content < ref && status == 0 )
		  {
				push(stack_a, stack_b, 'a');
		  }
	 	while((*stack_a)->content > ref && status == 1 )
			{
				push(stack_a, stack_b, 'a');
			}
		if(ft_lstsize(*stack_b) > 1)
	 		recursive_sort_b(stack_a, stack_b, ref, status, ref_mod);
	 }
}*/