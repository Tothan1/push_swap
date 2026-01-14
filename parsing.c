/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-rhun <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/16 13:36:13 by tle-rhun          #+#    #+#             */
/*   Updated: 2026/01/14 18:57:10 by tle-rhun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
void	free_liste(t_liste	*stack_a)
{
	t_liste *check_a;
	t_liste *tempstack_a;
	
	int a = 0;
	check_a = stack_a;
	
	while (a == 0 || check_a != stack_a)
	{
		tempstack_a = (stack_a);
		if(stack_a ->next != NULL)
			stack_a = (tempstack_a)->next;
		else
			check_a = stack_a;
		free(tempstack_a);
		a++;
	}
}

void	error(t_liste	*stack_a)
{
	if(lstsize(stack_a)>0)
		free_liste(stack_a);
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
		error(stack_a);
}

int	safe_atoi(char **str, int a, t_liste	*stack_a)
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
		error(stack_a);
	check_occurence(str, a, stack_a);
	return (nombre);
}
void	free_all(char **str)
{
	int	i;

	i = 0;
	while (str[i] != NULL)
		free(str[i++]);
	free(str);
}



t_liste	**recover_arg_in_linked_list(char **av, int ac, t_liste **stack_a,
		t_liste **stack_b)
{
	int		a;
	char	*join;
	char	**split;
	t_liste *last_a;

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
		error(*stack_a);
	last_a = lstlast(*stack_a);
	last_a->next = *stack_a;
	(*stack_a)->previous = last_a;
	return (stack_a);
}

int	main(int ac, char **av)
{
	t_liste	*stack_a;
	t_liste	*stack_b;

	// t_liste *tempstack_b;
	if (ac < 2)
		error(NULL);
	recover_arg_in_linked_list(av, ac, &stack_a, &stack_b);
	// printf("taille de la liste A:%d\n", lstsize(stack_a));
	index_and_check_sort(&stack_a, &stack_b);
	/*
		check_a = stack_a;
		check_b = stack_b;
		printf("\n\n\n");
		printf("\n\ntaille de la liste A:%d\n", lstsize(stack_a));
		printf("taille de la liste B:%d\n", lstsize(stack_b));
		while (a < 10)
		{
			if(a == 0 || check_a != stack_a)
			{
				printf("Maillon de la liste chaînnée  A%d: content:%d index:%d",
					a,
					(stack_a)->content, (stack_a)->index);
				tempstack_a = (stack_a);
				stack_a = (tempstack_a)->next;
				free(tempstack_a);
			}
			if((lstsize(stack_b) != 0) && (check_b != stack_b || a == 0) )
			{
					printf("        B%d: content:%d index:%d next:%d", a,
						(stack_b)->content, (stack_b)->index,
							(((stack_b)->next)->content));
					tempstack_b = (stack_b);
					stack_b = (tempstack_b)->next;
					free(tempstack_b);
			}
				printf("\n");
				a++;
		}
		printf("\n\n\n");
		*/
	free_liste(stack_a);
	return (1);
}
