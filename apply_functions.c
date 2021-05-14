/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_functions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krios-fu <krios-fu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/14 13:51:38 by krios-fu          #+#    #+#             */
/*   Updated: 2021/05/14 15:22:35 by krios-fu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft/libft.h"
#include <stdio.h>
#include <stdlib.h>

void get_pos_0(t_list **stack_a, t_list **stack_b)
{
	push(stack_b, stack_a, 'b');
}

void get_pos_1(t_list **stack_a, t_list **stack_b)
{
	push(stack_b, stack_a, 'b');
	swap_stack(*stack_a, 'a');
}

void get_pos_2(t_list **stack_a, t_list **stack_b)
{
	reverse_rotate(stack_a, 'a');
	push(stack_b, stack_a, 'b');
	rotate(stack_a, 'a');
	rotate(stack_a, 'a');
}

void get_pos_3(t_list **stack_a, t_list **stack_b)
{
	push(stack_b, stack_a, 'b');
	rotate(stack_a, 'a');
}

void get_pos_3_u(t_list **stack_a, t_list **stack_b)
{
	rotate(stack_a, 'a');
	push(stack_b, stack_a, 'b');
	swap_stack(*stack_a, 'a');
	reverse_rotate(stack_a, 'a');
}


void **list_functions()
{
	void (*ptr_func[4])(t_list, t_list );

	ptr_func[0] = get_pos_0;
	ptr_func[1] = get_pos_1;
	ptr_func[2] = get_pos_2;
	ptr_func[3] = get_pos_3;
	return (ptr_func);
}