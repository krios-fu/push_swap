/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions_rotate.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krios-fu <krios-fu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/15 14:45:34 by krios-fu          #+#    #+#             */
/*   Updated: 2021/05/15 16:26:03 by krios-fu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	rotate (t_list **stack, char c)
{
	t_list	*aux;

	aux = *stack;
	ft_lstadd_back(stack, ft_lstnew((*stack)->content));
	del_first_node(stack);
	if (c == 'a')
		printf("ra\n");
	else
		printf("rb\n");
}

void	rotate_rr (t_list **stack_a, t_list **stack_b)
{
	rotate(stack_a, 'a');
	rotate(stack_b, 'b');
}

void	reverse_rotate (t_list **stack, char c)
{
	t_list	*aux;
	void	*cont;

	aux = *stack;
	while (aux->next->next != NULL)
		aux = aux->next;
	ft_lstadd_front(stack, ft_lstnew(aux->next->content));
	free(aux->next);
	aux->next = NULL;
	if (c == 'a')
		printf("rra\n");
	else
		printf("rrb\n");
}

void	reverse_rotate_rr(t_list **stack_a, t_list **stack_b)
{
	reverse_rotate(stack_a, 'a');
	reverse_rotate(stack_b, 'b');
}
