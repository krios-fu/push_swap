/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_case.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krios-fu <krios-fu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/15 16:35:58 by krios-fu          #+#    #+#             */
/*   Updated: 2021/05/18 20:29:35 by krios-fu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	push_swap_case_three(t_list **stack_a)
{
	int	pos_1;
	int	pos_2;
	int	last;

	pos_1 = (*stack_a)->content;
	pos_2 = (*stack_a)->next->content;
	last = ft_lstlast(*stack_a)->content;
	if (pos_1 > pos_2 && pos_2 > last)
	{
		rotate(stack_a, 'a');
		swap_stack(*stack_a, 'a');
	}
	else if (pos_2 > last && pos_1 < last)
	{
		swap_stack(*stack_a, 'a');
		rotate(stack_a, 'a');
	}
	else if (last < pos_2 && pos_1 < pos_2)
		reverse_rotate(stack_a, 'a');
	else if (pos_1 > pos_2 && pos_1 < last)
		swap_stack(*stack_a, 'a');
	else if (pos_1 > pos_2 && pos_2 < last)
		rotate(stack_a, 'a');
}

void	push_swap_case_five(t_list **stack_a, t_list **stack_b)
{
	int		len;
	int		pos;
	void	(**case_swap_len_five)(t_list **, t_list **);

	pos = 0;
	case_swap_len_five = case_swap();
	while (!check_a(*stack_a, len))
	{
		while (ft_lstsize(*stack_a) > 3)
			push(stack_a, stack_b, 'a');
		push_swap_case_three(stack_a);
		pos = get_pos_stack(*stack_a, (*stack_b)->content);
		(*case_swap_len_five[pos])(stack_a, stack_b);
		pos = get_pos_stack(*stack_a, (*stack_b)->content);
		if (pos == 4)
			pos = 3;
		else if (pos == 2)
			pos = 4;
		else if (pos == 3)
			pos = 2;
		(*case_swap_len_five[pos])(stack_a, stack_b);
	}	
	free(case_swap_len_five);
}

void	rota_min_stack_b(t_list **stack_b)
{
	int hold;
	int iter;
	int len_stack;

	len_stack = ft_lstsize(*stack_b);
	hold = 0;
	iter = 0;
	if(len_stack >= 2)
	{
		//hold = get_min_pos_hold_first(*stack_b);
		 hold = get_max_content(*stack_b);
		iter = get_iterative(hold, len_stack);
		while (iter > 0)
		{
			if (hold > (len_stack / 2))
				reverse_rotate(stack_b, 'b');
			else
				rotate(stack_b, 'b');
			iter--;
			//print_stacks()
		}
	}
}
int		get_content(t_list *stack, int pos)
{
	int i;

	i = 0;
	while (i < pos)
	{
		stack = stack->next;
		i++;
	}
	return(stack->content);

}

int		get_position_content(t_list *stack, int content)
{
	int pos;

	pos= 0;
	while(stack)
	{
		if (stack->content == content)
			return(pos);
			
		stack = stack->next;
		pos++;
	}
	return(-1);
}
int	*ft_chuck (t_list *stack, int *array, int len)
{
	int *chuck;
	int i;

	i = 0;
	chuck = (int *)malloc(sizeof(int)*len);
	if(!chuck)
		print_error();
	
	while (i < len)
	{
		chuck[i] = get_position_content(stack, array[i]);
		i++;
	}
	return(chuck);
	
}
void	push_swap_case(t_list **stack_a, t_list **stack_b, int *sort_array)
{
	int	len_stack;
	int i;
	int re_start;
	int *chuck;

	re_start = 0;
	i = 0;
	chuck = ft_chuck(*stack_a, sort_array, 20);
	ft_sort_array(chuck, 20);


	len_stack = ft_lstsize(*stack_a);
	if (len_stack >= 20)
	{
		while (i < 20)
		{
			//print_stacks(*stack_a, *stack_b);
			move_hold(stack_a, chuck[0]);
			push(stack_a, stack_b, 'a');
			free(sort_array);
			free(chuck);
			sort_array = fill_array_int(*stack_a);
	 		ft_sort_array(sort_array, ft_lstsize(*stack_a));
			chuck = ft_chuck(*stack_a, sort_array, 20);
			ft_sort_array(chuck, 20);
			i++;
		}
			free(chuck);
			free(sort_array);
			
			sort_array = fill_array_int(*stack_a);
	 		ft_sort_array(sort_array, ft_lstsize(*stack_a));
			push_swap_case(stack_a, stack_b, sort_array);
	}
}
