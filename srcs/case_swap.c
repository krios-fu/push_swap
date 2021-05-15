/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   case_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krios-fu <krios-fu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/15 15:05:17 by krios-fu          #+#    #+#             */
/*   Updated: 2021/05/15 16:20:44 by krios-fu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	*case_swap(void)
{
	void	(**ptr_func)(t_list **, t_list **);

	ptr_func = malloc(sizeof(*ptr_func) * 5);
	ptr_func[0] = &case_zero;
	ptr_func[1] = &case_one;
	ptr_func[2] = &case_two;
	ptr_func[3] = &case_three;
	ptr_func[4] = &case_four;
	return (ptr_func);
}
