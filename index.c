/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-rhun <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/06 17:13:20 by tle-rhun          #+#    #+#             */
/*   Updated: 2026/01/06 19:00:56 by tle-rhun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	indexsort(t_liste *stack_a)
{
	int	i;
	int	temp_check;

	i = 0;
	while (i < lstsize(stack_a))
	{
		while (stack_a->index != -1)
			stack_a = stack_a->next;
		temp_check = (stack_a)->content;
		while (temp_check != (stack_a->next)->content)
		{
			if((temp_check > stack_a->content ) && (stack_a->index == -1 ))
				temp_check = (stack_a->content);
			stack_a = stack_a->next;
		}
		if (temp_check ==(stack_a->next)->content)
			(stack_a->next)->index = i;
		stack_a = stack_a->next;
		i++;
	}
}
