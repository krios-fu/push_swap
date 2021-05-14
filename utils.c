/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krios-fu <krios-fu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/31 15:33:09 by krios-fu          #+#    #+#             */
/*   Updated: 2021/05/14 16:53:21 by krios-fu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft/libft.h"
#include <stdio.h>
#include <stdlib.h>

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
	system("clear");
	printf("\n\n\n");
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
	


long i;
i = 0;
	while (i < 100000000 >> 1)
		i++;	
}

int		check_a (t_list *stack, int len)
{
	int len_start;

	len_start = ft_lstsize(stack);
	while (stack->next)
	{
		if (stack->content < stack->next->content)
			stack = stack->next;
		else
			return (0);
	}
	if(len == len_start)
		return (1);
	else
		return(0);
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

int get_pos(t_list *stack_a, int content_b)
{
	int pos;

	pos = 0;
	while(stack_a)
	{
		if (stack_a->content < content_b)
			pos++;
		stack_a = stack_a->next;
	}
	return (pos);
}
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

/*
** Función que apunta a una lista de funciones
**	para evitar condicionales extensas
**
**
*/
void *list_functions()
{
	void (**ptr_func)(t_list **, t_list **);

	ptr_func = malloc(sizeof(*ptr_func) * 5);
	ptr_func[0] = &get_pos_0;
	ptr_func[1] = &get_pos_1;
	ptr_func[2] = &get_pos_2;
	ptr_func[3] = &get_pos_3;
	ptr_func[4] = &get_pos_3_u;

	return (ptr_func);
}

void push_swap_3(t_list **stack_a)
{
	int pos_1;
	int pos_2;
	int last;

	pos_1 = (*stack_a)->content;
	pos_2 = (*stack_a)->next->content;
	last = ft_lstlast(*stack_a)->content;
	if(pos_1 > pos_2 && pos_2 > last)
	{
		rotate(stack_a, 'a');
		swap_stack(*stack_a, 'a');
	}
	else if(pos_2 > last && pos_1 < last)
		{
			swap_stack(*stack_a, 'a');
			rotate(stack_a, 'a');
		}
	else if (last < pos_2 && pos_1 < pos_2)
		reverse_rotate(stack_a,'a');
	else if (pos_1 > pos_2 && pos_1 < last)
				swap_stack(*stack_a,'a');
	else if (pos_1 > pos_2 && pos_2 < last)
			rotate(stack_a, 'a');
}

void push_swap_5(t_list **stack_a, t_list **stack_b)
{
	int len;
	int i;
	int pos;
	void (**ptr_func)(t_list **, t_list **);

	i = 0;
	pos = 0;
	len = ft_lstsize(*stack_a);
	ptr_func = list_functions();
	while (!check_a(*stack_a, len))
	{
		while (i < 2)
		{
			push(stack_a, stack_b, 'a');
			i++;
		}
		push_swap_3(stack_a);
		pos = get_pos(*stack_a, (*stack_b)->content);
		(*ptr_func[pos])(stack_a, stack_b);
		
		pos = get_pos(*stack_a, (*stack_b)->content);
		if (pos == 4)
			pos = 3;
		else if(pos == 2)
				pos = 4;
		else if (pos == 3)
				pos = 2;
		(*ptr_func[pos])(stack_a, stack_b);
	}
	
	
}
int	push_swap(t_list **stack_a, t_list **stack_b)
{
	int len;
	len  = ft_lstsize(*stack_a);
	while (!check_a(*stack_a, len))
	{
		if (len == 3)
			push_swap_3(stack_a);
		if (len == 5)
			push_swap_5(stack_a, stack_b);
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
		return(0);
	}

	push_swap(&stack_a, &stack_b);
	
}