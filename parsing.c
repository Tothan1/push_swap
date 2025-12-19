/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-rhun <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/16 13:36:13 by tle-rhun          #+#    #+#             */
/*   Updated: 2025/12/19 21:20:10 by tle-rhun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	error(void)
{
	write(1, "Error\n", 6);
	exit(EXIT_FAILURE);
}

void	check_occurence(char **split, int check)
{
	int	a;

	a = 0;
	while (ft_atoi(split[a]) != ft_atoi(split[check]) && a < check)
		a++;
	if (ft_atoi(split[a]) == ft_atoi(split[check]) && a < check)
		error();
}

int	safe_atoi(char **str, int a)
{
	int		i;
	int		signe;
	long	nombre;

	i = 0;
	signe = 1;
	nombre = 0;
	if (str[a][i] == '-' || str[a][i] == '+')
	{
		if (str[a][i] == '-')
			signe *= -1;
		i++;
	}
	while (ft_isdigit(str[a][i]) && str[a][i] != '\0')
	{
		nombre = nombre * 10 + str[a][i] - '0';
		i++;
	}
	nombre = signe * nombre;
	if ((!ft_isdigit(str[a][i]) && str[a][i] != '\0') || nombre < INT_MIN
		|| nombre > INT_MAX)
		error();
	check_occurence(str, a);
	return (nombre);
}

#include <stdio.h>
t_liste	*recover_arg_in_linked_list(char **av, int ac)
{
	int		a;
	char	*join;
	char	**split;
	int		lentab;
	t_liste	*stack_a;
	t_liste	*previous;

	a = 0;
	join = ft_super_strjoin(ac - 1, &av[1], " ");
	split = ft_split(join, ' ');
	lentab = 0;
	while (split[lentab])
		lentab++;
	free(join);
	stack_a = NULL;
	while (split[a] != NULL)
	{
		previous = stack_a;
		lstadd_front(&stack_a, lstnew(safe_atoi(split, a)), previous);
		printf("Maillon de la liste chaînnée : %d\n", stack_a->content);
		a++;
	}
	free (split);
	printf ("%d", lstsize(stack_a));
	return (stack_a);
}

int	main(int ac, char **av)
{
	if (ac < 2)
		error();
	recover_arg_in_linked_list(av, ac);
	return (1);
}