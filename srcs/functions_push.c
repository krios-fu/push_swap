/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions_push.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krios-fu <krios-fu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/15 14:42:43 by krios-fu          #+#    #+#             */
/*   Updated: 2021/05/22 19:10:44 by krios-fu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	push(t_list **stack, t_list **stack_dest, char c)
{
	if (*stack_dest)
		ft_lstadd_front(stack_dest, ft_lstnew((*stack)->content));
	else
		*stack_dest = ft_lstnew((*stack)->content);
	del_first_node(stack);
	if (c == 'a')
		printf("pb\n");
	else if (c == 'b')
		printf("pa\n");
}
