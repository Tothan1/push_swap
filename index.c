/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-rhun <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/06 17:13:20 by tle-rhun          #+#    #+#             */
/*   Updated: 2026/01/15 16:13:22 by tle-rhun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	chek_is_sort(t_liste *stack_a, int from)
{
	int	i;

	i = 0;
	while (i++ < lstsize(stack_a)
		&& (stack_a->content < (stack_a->next)->content))
		stack_a = stack_a->next;
	if (i == lstsize(stack_a) && from == 0)
	{
		if (lstsize(stack_a) > 0)
			free_liste(stack_a);
		exit(EXIT_FAILURE);
	}
	else if (i == lstsize(stack_a) && from == 1)
		return (0);
	else
		return (1);
}
void	indexsort(t_liste *stack_a)
{
	int	i;
	int	a;
	int	temp_check;

	i = 0;
	while (i < lstsize(stack_a))
	{
		while (stack_a->index != -1)
			stack_a = stack_a->next;
		temp_check = (stack_a)->content;
		a = 0;
		while (temp_check != (stack_a)->content || a == 0)
		{
			if ((temp_check > stack_a->content) && (stack_a->index == -1))
				temp_check = (stack_a->content);
			stack_a = stack_a->next;
			a++;
		}
		if (temp_check == (stack_a)->content)
			(stack_a)->index = i;
		stack_a = stack_a->next;
		i++;
	}
}

int	ft_big_nb(t_liste *stack)
{
	int	i;
	int	big_nb;

	i = 0;
	big_nb = (stack->previous)->index;
	while (i < lstsize(stack))
	{
		if (big_nb < (stack->index))
			big_nb = stack->index;
		stack = stack->next;
		i++;
	}
	return (big_nb);
}

int	ft_lower_nb(t_liste *stack)
{
	int	i;
	int	lower_nb;

	i = 0;
	lower_nb = (stack->previous)->index;
	while (i < lstsize(stack))
	{
		if (lower_nb > (stack->index))
			lower_nb = stack->index;
		stack = stack->next;
		i++;
	}
	return (lower_nb);
}

void	index_and_check_sort(t_liste **stack_a, t_liste **stack_b)
{
	indexsort(*stack_a);
	chek_is_sort(*stack_a, 0);
	if (lstsize(*stack_a) > 5)
		algo_radix_sort(stack_a, stack_b);
	else if (lstsize(*stack_a) == 2)
		sort_2(stack_a);
	else if (lstsize(*stack_a) == 3)
		sort_3(stack_a);
	else
		algo_sort_small(stack_a, stack_b, lstsize(*stack_a));
}