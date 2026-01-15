/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_sort_small.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-rhun <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/07 13:46:42 by tle-rhun          #+#    #+#             */
/*   Updated: 2026/01/15 16:12:55 by tle-rhun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_2(t_liste **stack_a)
{
	sa(stack_a);
}

void	sort_3(t_liste **stack_a)
{
	if ((*stack_a)->index > ((*stack_a)->next)->index
		&& ((*stack_a)->next)->index > ((*stack_a)->previous)->index) // "3 2 1"
	{
		ra(stack_a);
		sa(stack_a);
	}
	else if ((*stack_a)->index > ((*stack_a)->next)->index
		&& ((*stack_a)->next)->index < ((*stack_a)->previous)->index
		&& (*stack_a)->index > ((*stack_a)->previous)->index) // "3 1 2"
		ra(stack_a);
	else if ((*stack_a)->index < ((*stack_a)->next)->index
		&& ((*stack_a)->next)->index > ((*stack_a)->previous)->index
		&& (*stack_a)->index < ((*stack_a)->previous)->index) // "1 3 2"
	{
		rra(stack_a);
		sa(stack_a);
	}
	else if ((*stack_a)->index < ((*stack_a)->next)->index
		&& ((*stack_a)->next)->index > ((*stack_a)->previous)->index
		&& (*stack_a)->index > ((*stack_a)->previous)->index) // "2 3 1"
		rra(stack_a);
	else if ((*stack_a)->index > ((*stack_a)->next)->index
		&& ((*stack_a)->next)->index < ((*stack_a)->previous)->index
		&& (*stack_a)->index < ((*stack_a)->previous)->index) // "2 1 3"
		sa(stack_a);
}

void	algo_sort_small(t_liste **stack_a, t_liste **stack_b, int lst_size_a)
{
	while (chek_is_sort(*stack_a, 1) && (lstsize(*stack_b) == 0
			|| lst_size_a != lstsize(*stack_a)))
	{
		if (lstsize(*stack_a) > 3 && (*stack_a)->index == ft_lower_nb(*stack_a))
			pb(stack_a, stack_b);
		else if (lstsize(*stack_a) == 3)
			sort_3(stack_a);
		else if (((*stack_a)->next)->index == ft_lower_nb(*stack_a))
			ra(stack_a);
		else if (((*stack_a)->previous)->index == ft_lower_nb(*stack_a))
			rra(stack_a);
		else if ((((*stack_a)->next)->next)->index == ft_lower_nb(*stack_a))
			ra(stack_a);
		else if ((((*stack_a)->previous)->previous)->index == ft_lower_nb(*stack_a))
			rra(stack_a);
		else
			rra(stack_a);
	}
	while (!chek_is_sort(*stack_a, 1) && lstsize(*stack_b) != 0)
		pa(stack_b, stack_a);
}
