/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-rhun <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/21 11:33:55 by tle-rhun          #+#    #+#             */
/*   Updated: 2025/12/22 15:53:43 by tle-rhun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
void	operation_swap(t_liste	**stack)
{
	int temp;
	temp= (*stack)->content;
	(*stack)->content = ((*stack)->next)->content;
	((*stack)->next)->content = temp;
}
void	operation_push(t_liste	**from, t_liste	**dest)
{
	t_liste *temp;
	lstadd_front(dest, lstnew((*from)->content),*dest);
	((*from)->previous)->next = (*from)-> next; 
	((*from)->next)->previous = (*from)-> previous;
	temp = *from;
	*from = (temp)->next;
	free(temp);
}
void	operation_rotate(t_liste	**stack)
{
	int temp;
	while (stack)
	{
		temp= (*stack)->content;
		(*stack)->content = ((*stack)->next)->content;
		((*stack)->next)->content = temp;
		*stack = (*stack)->next;
	}
	
}
