/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-rhun <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/05 16:19:29 by tle-rhun          #+#    #+#             */
/*   Updated: 2026/01/07 18:11:48 by tle-rhun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	nb_of_loop_for_radix (t_liste *stack_a)
{
	int i;
	int loop;
	int big_nb;

	i = 0;
	big_nb = (stack_a->previous)->index;
	while (i < lstsize(stack_a))
	{
		if(big_nb < (stack_a->index))
			big_nb = stack_a->index;
		stack_a = stack_a->next;
		i++;
	}
	printf("\n \n big_nb:%d\n \n", big_nb);
	loop = 0;
	while (big_nb != 0)
	{
		loop++;
		big_nb/=2;
	}
	return (loop);
}



void	full_pb(t_liste **stack_a, t_liste **stack_b)
{
	int i;

	i = 0;
	while (i < lstsize(*stack_a))
	{
		if(((*stack_a)->index & 1) == 0)
		{
			//PB
			operation_push(stack_a, stack_b);
		}
		else
			{
				// Ra
				operation_rotate(stack_a);
				i--;
			}
		i++;
	}
	
}

void	full_pa(t_liste **stack_a, t_liste **stack_b)
{
	int i;

	i = 0;
	while (i < lstsize(*stack_b))
	{
			//PA
			operation_push(stack_b, stack_a);
		i++;
	}
}



void	algo_radix_sort(t_liste **stack_a, t_liste **stack_b)
{
	int loop;
	int i;
	
	i = 0;
	loop = nb_of_loop_for_radix(*stack_a);
	printf("\n \n nb de loop:%d\n \n", loop);
	while (i < 1)
	{
		full_pb(stack_a, stack_b);
		// full_pa(stack_a, stack_b);
		i++;
	}
	
}
