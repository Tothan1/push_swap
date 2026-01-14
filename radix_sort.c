/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-rhun <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/05 16:19:29 by tle-rhun          #+#    #+#             */
/*   Updated: 2026/01/12 10:06:37 by tle-rhun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"



int	nb_of_loop_for_radix(t_liste *stack_a)
{
	int	loop;
	int	big_nb;
	
	loop = 0;
	big_nb = ft_big_nb(stack_a);
	while (big_nb != 0)
	{
		loop++;
		big_nb /= 2;
	}
	return (loop);
}

void	full_pb(t_liste **stack_a, t_liste **stack_b, int a)
{
	int	i;
	int	len_stack_a;

	i = 0;
	len_stack_a = lstsize(*stack_a);
	while (i < len_stack_a)
	{
		if ((((*stack_a)->index) >> a & 1) == 0)
			pb(stack_a, stack_b);
		else
			ra(stack_a);
		i++;
	}
}

void	full_pa(t_liste **stack_a, t_liste **stack_b)
{
	int	i;
	int	len_stack_b;

	i = 0;
	len_stack_b = lstsize(*stack_b);
	while (i < len_stack_b)
	{
		pa(stack_b, stack_a);
		i++;
	}
}

void	algo_radix_sort(t_liste **stack_a, t_liste **stack_b)
{
	int	loop;
	int	i;

	i = 0;
	loop = nb_of_loop_for_radix(*stack_a);
	// printf("\n \n nb de loop:%d\n \n", loop);
	while (i < loop)
	{
		full_pb(stack_a, stack_b, i);
		full_pa(stack_a, stack_b);
		i++;
	}
}
