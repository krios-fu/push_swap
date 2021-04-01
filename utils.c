/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krios-fu <krios-fu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/31 15:33:09 by krios-fu          #+#    #+#             */
/*   Updated: 2021/04/01 16:48:39 by krios-fu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft/libft.h"
#include <stdio.h>

int fill_stack (t_list	**stack_a, char **str)
{
	int	i;

	i = 1;
	if (!str[i])
		return (1);
	*stack_a = ft_lstnew(&str[i][0]);	
	while (str[++i] != '\0')
		ft_lstadd_back(stack_a, ft_lstnew(&str[i][0]));

	return (0);
}

void swap_a (t_list *stack_a)
{
	void *cont;

	cont = stack_a->content;
	stack_a->content = stack_a->next->content;
	stack_a->next->content = cont;	
}

void rotate (t_list *stack_a)
{
	t_list *aux;
	void *cont;

	aux = stack_a;
	while (aux->next != NULL)
	{
		aux =  aux->next;
	}

	cont = aux->content;
	aux->content = stack_a->content;
	stack_a->content = cont;
	
}
int main (int argc, char * argv[])
{
	t_list	*stack_a;
	printf("[%d]\n", argc);
	if (fill_stack(&stack_a, argv))
		printf("no hay numeros");

	swap_a(stack_a);
	rotate(stack_a);
	while (stack_a)
	{
		printf("%s\n", stack_a->content);
		stack_a = stack_a->next;
	}
}