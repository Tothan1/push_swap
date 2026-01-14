/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_precise2.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-rhun <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/21 11:33:55 by tle-rhun          #+#    #+#             */
/*   Updated: 2026/01/14 12:25:37 by tle-rhun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra (t_liste **stack_a)
{
	operation_rotate(stack_a);
	write (1, "ra\n", 3);
}
void	rb (t_liste **stack_b)
{
	operation_rotate(stack_b);
	write (1, "rb\n", 3);
}



void	rra (t_liste **stack_a)
{
	operation_reverse_rotate(stack_a);
	write (1, "rra\n", 4);
}
void	rrb (t_liste **stack_b)
{
	operation_reverse_rotate(stack_b);
	write (1, "rrb\n", 4);
}



