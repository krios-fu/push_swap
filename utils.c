/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krios-fu <krios-fu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/31 15:33:09 by krios-fu          #+#    #+#             */
/*   Updated: 2021/04/03 01:26:09 by krios-fu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft/libft.h"
#include <stdio.h>

void ft_swap (void **content_a, void **content_b)
{
	void *content;

	content = *content_a;
	*content_a = *content_b;
	*content_b = content;
}

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

void swap_stack (t_list *stack)
{
	ft_swap(&stack->content, &stack->next->content);
}

void swap_ss (t_list *stack_a, t_list *stack_b)
{
	ft_swap(&stack_a->content, &stack_a->next->content);
	ft_swap(&stack_b->content, &stack_b->next->content);
}
void del_first_node(t_list **stack)
{
	t_list *aux;
	aux = *stack;
	*stack = (*stack)->next;
	free(aux);
}
void push(t_list **stack, t_list **stack_dest)
{
	if (*stack_dest)
		ft_lstadd_front(stack_dest, ft_lstnew((*stack)->content));
	else
		*stack_dest = ft_lstnew((*stack)->content);
	
	del_first_node(stack);
}

void rotate (t_list **stack)
{
	t_list *aux;
	aux = *stack;
	ft_lstadd_back(stack, ft_lstnew((*stack)->content));
	del_first_node(stack);	
}

void rotate_rr (t_list **stack_a, t_list **stack_b)
{
	rotate(stack_a);
	rotate(stack_b);	
}

void reverse_rotate (t_list **stack)
{
	t_list *aux;
	void *cont;

	aux = *stack;
	while (aux->next->next != NULL)
		aux =  aux->next;
	ft_lstadd_front(stack, ft_lstnew(aux->next->content));
	free(aux->next);
	aux->next = NULL;
}

void reverse_rotate_rr(t_list **stack_a, t_list **stack_b)
{
	reverse_rotate(stack_a);
	reverse_rotate(stack_b);	
}

void print_error()
{
	printf("Error\n");
	exit(0);
}

void print_stacks(t_list *stack_a, t_list *stack_b)
{
	
	while (stack_a || stack_b)
	{
		if (stack_a)
		{
			printf("%s", stack_a->content);
			stack_a = stack_a->next;
			
		}
		else
			printf(" ");
		if (stack_b)
		{
			printf(" %s", stack_b->content);
			stack_b = stack_b->next;
			
		}
		else
			printf(" ");
		
		printf("\n");	
	}
	
	printf("  \na b");
	
}
int main (int argc, char * argv[])
{
	t_list	*stack_a;
	t_list	*stack_b;
	printf("[%d]\n", argc);
	if (fill_stack(&stack_a, argv))
	{
		print_error();
		return(0);
	}

	//swap_stack(stack_a);
	//reverse_rotate(&stack_a);
	//rotate(&stack_a);
	//reverse_rotate(&stack_a);
	//reverse_rotate(&stack_a);
	//swap_stack(stack_a);
	//push(&stack_a, &stack_b);
	//push(&stack_a, &stack_b);
	//reverse_rotate_rr(&stack_a, &stack_b);
	//rotate_rr(&stack_a, &stack_b);
	//push_b(&stack_a, &stack_b);
	/*while (stack_a)
	{
		printf("%s\n", stack_a->content);
		stack_a = stack_a->next;
	}
	printf("\nStack_b\n");
	while (stack_b)
	{
		printf("%s\n", stack_b->content);
		stack_b = stack_b->next;
	}*/
	print_stacks(stack_a, stack_b);
}