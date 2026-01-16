/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-rhun <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/15 18:18:07 by tle-rhun          #+#    #+#             */
/*   Updated: 2026/01/15 18:19:03 by tle-rhun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_liste(t_liste *stack_a)
{
	t_liste	*check_a;
	t_liste	*tempstack_a;
	int		a;

	a = 0;
	check_a = stack_a;
	while ((a == 0 || check_a != stack_a) && check_a != NULL)
	{
		tempstack_a = (stack_a);
		stack_a = (tempstack_a)->next;
		free(tempstack_a);
		a++;
	}
}

void	free_all(char **str)
{
	int	i;

	i = 0;
	while (str[i] != NULL)
		free(str[i++]);
	free(str);
}
