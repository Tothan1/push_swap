/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_sort_small.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-rhun <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/07 13:46:42 by tle-rhun          #+#    #+#             */
/*   Updated: 2026/01/14 13:54:42 by tle-rhun         ###   ########.fr       */
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
		else if(lstsize(*stack_a) == 3)
			sort_3(stack_a);
		else if(((*stack_a)->next)->index == ft_lower_nb(*stack_a))
			ra(stack_a);
		else if(((*stack_a)->previous)->index == ft_lower_nb(*stack_a))
			rra(stack_a);
		else if((((*stack_a)->next)->next)->index == ft_lower_nb(*stack_a))
			ra(stack_a);
		else if((((*stack_a)->previous)->previous)->index == ft_lower_nb(*stack_a))
			rra(stack_a);
		else
			rra(stack_a);
		/*
		t_liste *check_b;
		t_liste *check_a;
	int	a;
				a = 0;
			check_a = *stack_a;
			check_b = *stack_b;
			printf("\n\n\n");
			printf("\n\ntaille de la liste A:%d\n", lstsize(*stack_a));
			printf("taille de la liste B:%d\n", lstsize(*stack_b));
			while (a < 10)
			{
				if(a == 0 || check_a != *stack_a)
				{
					printf("Maillon de la liste chaînnée  A%d: content:%d index:%d",
						a,
						(*stack_a)->content, (*stack_a)->index);
					*stack_a = (*stack_a)->next;
				}
				if((lstsize(*stack_b) != 0) && (check_b != *stack_b || a == 0) )
				{
						printf("        B%d: content:%d index:%d next:%d", a,
							(*stack_b)->content, (*stack_b)->index,
								(((*stack_b)->next)->content));
						*stack_b = (*stack_b)->next;
				}
					printf("\n");
					a++;
			}
			printf("\n\n\n");
				*/
	}
	while (!chek_is_sort(*stack_a, 1) && lstsize(*stack_b) != 0)
		pa(stack_b, stack_a);
}
