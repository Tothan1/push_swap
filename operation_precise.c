/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_precise.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-rhun <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/21 11:33:55 by tle-rhun          #+#    #+#             */
/*   Updated: 2026/01/14 13:51:57 by tle-rhun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa (t_liste **stack_a)
{
	operation_swap(stack_a);
	write (1, "sa\n", 3);
}

void	sb (t_liste **stack_b)
{
	operation_swap(stack_b);
	write (1, "sb\n", 3);
}


void	pb (t_liste **stack_a, t_liste **stack_b)
{
	operation_push(stack_a, stack_b);
	write (1, "pb\n", 3);
}

void	pa (t_liste **stack_b, t_liste **stack_a)
{
	operation_push(stack_b, stack_a);
	write (1, "pa\n", 3);
}



