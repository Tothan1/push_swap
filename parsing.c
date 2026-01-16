/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-rhun <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/16 13:36:13 by tle-rhun          #+#    #+#             */
/*   Updated: 2026/01/15 23:05:12 by tle-rhun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	error(t_liste *stack_a, char **split)
{
	if (lstsize(stack_a) > 0)
		free_liste(stack_a);
	if (split != NULL)
		free_all(split);
	write(2, "Error\n", 6);
	exit(EXIT_FAILURE);
}

void	check_occurence(char **split, int check, t_liste *stack_a)
{
	int	a;

	a = 0;
	while (ft_atoi(split[a]) != ft_atoi(split[check]) && a < check)
		a++;
	if (ft_atoi(split[a]) == ft_atoi(split[check]) && a < check)
		error(stack_a, split);
}

int	safe_atoi(char **str, int a, t_liste *stack_a)
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
		error(stack_a, str);
	check_occurence(str, a, stack_a);
	return (nombre);
}

t_liste	**recover_arg_in_linked_list(char **av, int ac, t_liste **stack_a,
		t_liste **stack_b)
{
	int		a;
	char	*join;
	char	**split;

	*stack_a = NULL;
	*stack_b = NULL;
	join = ft_super_strjoin(ac - 1, &av[1], " ");
	split = ft_split(join, ' ');
	free(join);
	a = 0;
	while (split[a] != NULL)
	{
		lstadd_back(stack_a, lstnew(safe_atoi(split, a, *stack_a), -1));
		a++;
	}
	free_all(split);
	if (a < 2)
	{
		free_liste(*stack_a);
		exit(EXIT_FAILURE);
	}
	return (stack_a);
}

int	main(int ac, char **av)
{
	t_liste	*stack_a;
	t_liste	*stack_b;

	if (ac == 1)
		return (1);
	recover_arg_in_linked_list(av, ac, &stack_a, &stack_b);
	index_and_check_sort(&stack_a, &stack_b);
	free_liste(stack_a);
	return (0);
}
