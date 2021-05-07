/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krios-fu <krios-fu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/31 15:33:09 by krios-fu          #+#    #+#             */
/*   Updated: 2021/05/06 16:23:02 by krios-fu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft/libft.h"
#include <stdio.h>

void print_error()
{
	printf("Error\n");
	exit(0);
}

void del_first_node(t_list **stack)
{
	t_list *aux;
	aux = *stack;
	*stack = (*stack)->next;
	free(aux);
}

void ft_swap (int *content_a, int *content_b, char c)
{
	int	content;

	content = *content_a;
	*content_a = *content_b;
	*content_b = content;

	if(c == 'a')
		printf("sa\n");
	else
		printf("sb\n");
}

int dup_number(t_list *stack, int number)
{
	while (stack)
	{
		if(stack->content == number)
			return(1);
		stack = stack->next;
	}
		return(0);

}
int fill_stack (t_list	**stack_a, char **str)
{
	int	i;
	int content;
	int *num;

	i = 1;
	if (!str[i])
		return (1);
	content = ft_atoi(&str[i][0]);
	*stack_a = ft_lstnew(content);	
	while (str[++i] != '\0')
	{
		content =ft_atoi(&str[i][0]);
		if(dup_number(*stack_a, content))
		{
			while (*stack_a)
				del_first_node(stack_a);
			print_error();
		}
		else
			ft_lstadd_back(stack_a, ft_lstnew(content));
	}
	return (0);
}

void swap_stack (t_list *stack, char c)
{
	ft_swap(&stack->content, &stack->next->content, c);
}

void swap_ss (t_list *stack_a, t_list *stack_b)
{
	ft_swap(&stack_a->content, &stack_a->next->content, 'a');
	ft_swap(&stack_b->content, &stack_b->next->content, 'b');
}

void push(t_list **stack, t_list **stack_dest, char c)
{
	if (*stack_dest)
		ft_lstadd_front(stack_dest, ft_lstnew((*stack)->content));
	else
		*stack_dest = ft_lstnew((*stack)->content);
	
	del_first_node(stack);
		if(c == 'a')
		printf("pb\n");
	else
		printf("pa\n");

}

void rotate (t_list **stack, char c)
{
	t_list *aux;
	aux = *stack;
	ft_lstadd_back(stack, ft_lstnew((*stack)->content));
	del_first_node(stack);
	if(c == 'a')
		printf("ra\n");
	else
		printf("rb\n");
}

void rotate_rr (t_list **stack_a, t_list **stack_b)
{
	rotate(stack_a, 'a');
	rotate(stack_b, 'b');	
}

void reverse_rotate (t_list **stack, char c)
{
	t_list *aux;
	void *cont;

	aux = *stack;
	while (aux->next->next != NULL)
		aux =  aux->next;
	ft_lstadd_front(stack, ft_lstnew(aux->next->content));
	free(aux->next);
	aux->next = NULL;
	if(c == 'a')
		printf("rra\n");
	else
		printf("rrb\n");
}

void reverse_rotate_rr(t_list **stack_a, t_list **stack_b)
{
	reverse_rotate(stack_a, 'a');
	reverse_rotate(stack_b, 'b');	
}

void print_stacks(t_list *stack_a, t_list *stack_b)
{
	
	while (stack_a || stack_b)
	{
		if (stack_a)
		{
			printf("%d\t", stack_a->content);
			stack_a = stack_a->next;
			
		}
		else
			printf(" \t");
		if (stack_b)
		{
			printf("%d", stack_b->content);
			stack_b = stack_b->next;
			
		}
		else
			printf(" ");
		
		printf("\n");	
	}
	
	printf("\na\tb\n\n");
	
}

int		check_a (t_list *stack)
{
	while (stack->next)
	{
		if (stack->content < stack->next->content)
			stack = stack->next;
		else
			return (0);
	}
	return (1);
}

int		check_b (t_list *stack)
{
	while (stack->next)
	{
		if (stack->content > stack->next->content)
			stack = stack->next;
		else
			return (0);
	}
	return (1);
}

int average (t_list *stack)
{
	long i;
	i = 0;
	while (stack)
	{
		i += stack->content;
		stack = stack->next;
	}	
	
	return(i / 2);
}

int	push_swap(t_list **stack_a, t_list **stack_b)
{
	int flag;
	int i;

	i = 0;
	flag = 8;
	while (i <= 8)
	{
		if(check_a(*stack_a) && !(*stack_b))
			return (check_a(*stack_a));
		if((*stack_a)->content > ft_lstlast(*stack_a)->content && (*stack_a)->content > (*stack_a)->next->content)
			reverse_rotate(stack_a, 'a');
		if(check_a(*stack_a) && !(*stack_b))
			return (check_a(*stack_a));
		if((*stack_a)->content > ft_lstlast(*stack_a)->content)
			reverse_rotate(stack_a, 'a');
		if(check_a(*stack_a) && !(*stack_b))
			return (check_a(*stack_a));
		if((*stack_a)->content < ft_lstlast(*stack_a)->content && ((*stack_a)->content) < (*stack_a)->next->content && (ft_lstsize(*stack_a) > 2))
			push(stack_a, stack_b, 'a');
		if(check_a(*stack_a) && !(*stack_b))
			return (check_a(*stack_a));
		if((*stack_b) && check_a(*stack_a) && check_b(*stack_b))
			push(stack_b, stack_a, 'b');
		if ((*stack_a)->content > (*stack_a)->next->content)
			swap_stack((*stack_a), 'a');
		
		if (ft_lstsize(*stack_b) > 1)
		{
			while (!check_b(*stack_b))
			{

				if((*stack_b)->content < ft_lstlast(*stack_b)->content && (*stack_b)->content < (*stack_b)->next->content)
					reverse_rotate(stack_b, 'b');
				if((*stack_b)->content < ft_lstlast(*stack_b)->content)
					reverse_rotate(stack_b, 'b');
				if ((*stack_b)->content < (*stack_b)->next->content)
					swap_stack((*stack_b), 'b');
			}
				while(check_a(*stack_a) && check_b(*stack_b) && ft_lstsize(*stack_b) > 1)
					 push(stack_b, stack_a, 'b');
		}
		if(ft_lstsize(*stack_b) == 1 && check_a(*stack_a))
		{
			push(stack_b, stack_a, 'b');
		}
		i++;

	}


	printf("[%d]", i);
	return (check_a(*stack_a));
}

int main (int argc, char * argv[])
{
	t_list	*stack_a;
	t_list	*stack_b;
	if (fill_stack(&stack_a, argv))
	{
		print_error();
		return(0);
	}

	if (push_swap(&stack_a, &stack_b))
		printf("\nOrdenado\n");
	else
		printf("\nNo esta ordenado\n");
	
	print_stacks(stack_a, stack_b);

	printf("%d", average(stack_a));
}