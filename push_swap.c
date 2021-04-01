/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krios-fu <krios-fu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/31 15:22:04 by krios-fu          #+#    #+#             */
/*   Updated: 2021/03/31 16:41:29 by krios-fu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include "./libft/libft.h"

int main (int argc, char * argv[])
{

	int i;
	char ** k;

	i = 1;
	while (i < argc)
	{
		printf("[%s]\n", &argv[i][0]);
		i++;
	}
		
	return (0);
}