/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_global.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-rhun <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/21 11:33:55 by tle-rhun          #+#    #+#             */
/*   Updated: 2026/01/09 17:21:53 by tle-rhun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	operation_swap(t_liste **stack)
{
	int	temp;
	int	temp_index;

	temp = (*stack)->content;
	temp_index = (*stack)->index;
	(*stack)->content = ((*stack)->next)->content;
	(*stack)->index = ((*stack)->next)->index;
	((*stack)->next)->content = temp;
	((*stack)->next)->index = temp_index;
}

//déplacer mon node au lieu d'en créer un nouveau
void	operation_push(t_liste **from, t_liste **dest)
{
	t_liste	*temp;

	if (!from || !*from)
		return ;
	temp = *from;
	if(lstsize(*from) == 1)
		(*from) = NULL;
	else
	{
		*from = (*from)->next;
		(((*from)->previous)-> previous)->next = (*from);
		((*from)->previous) = ((*from)->previous)-> previous;
	}
	lstadd_front(dest, (temp), *dest);
}
void	operation_rotate(t_liste **stack)
{
	*stack = (*stack)->next;
}
void	operation_reverse_rotate(t_liste **stack)
{
	*stack = (*stack)->previous;
}
