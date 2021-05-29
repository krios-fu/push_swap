/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krios-fu <krios-fu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/17 14:54:27 by krios-fu          #+#    #+#             */
/*   Updated: 2021/05/29 22:10:25 by krios-fu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	*fill_array_int(t_list *stack)
{
	int	*array;
	int	len_stack;
	int	i;

	len_stack = ft_lstsize(stack);
	i = 0;
	array = (int *)malloc(len_stack * sizeof(int));
	if (!array)
		return (NULL);
	while (stack)
	{
		array[i] = (int)stack->content;
		stack = stack->next;
		i++;
	}
	return (array);
}

void	ft_sort_array(int *tab, int size)
{
	int	i;
	int	pos;
	int	cut;
	int	min;

	pos = 0;
	i = 0;
	while (i < size)
	{
		min = i;
		pos = i + 1;
		while (pos < size)
		{
			if (tab[pos] < tab[min])
			{
				min = pos;
			}
			pos++;
		}
		cut = tab[i];
		tab[i] = tab[min];
		tab[min] = cut;
		i++;
	}
}
