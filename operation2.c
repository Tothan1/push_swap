/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-rhun <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/21 11:33:55 by tle-rhun          #+#    #+#             */
/*   Updated: 2026/01/07 16:49:11 by tle-rhun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pb (t_liste **stack_a, t_liste **stack_b)
{
	operation_push(&stack_a, &stack_b);
	write (1, "Pb\n", 3);
}

void	pa (t_liste **stack_b, t_liste **stack_a)
{
	operation_push(&stack_b, &stack_a);
	write (1, "Pa\n", 3);
}









































void	operation_push(t_liste **from, t_liste **dest)
{
	t_liste	*temp;

	lstadd_front(dest, lstnew((*from)->content, (*from)->index ), *dest);
	((*from)->previous)->next = (*from)->next;
	((*from)->next)->previous = (*from)->previous;
	temp = *from;
	*from = (temp)->next;
	free(temp);
}
void	operation_rotate(t_liste **stack, t_liste **head_stack_a)
{
	*head_stack_a = (*stack)->next;
}
void	operation_reverse_rotate(t_liste **stack, t_liste **head_stack_a)
{
	*head_stack_a = (*stack)->previous;
}
