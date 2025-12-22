/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-rhun <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/16 13:36:13 by tle-rhun          #+#    #+#             */
/*   Updated: 2025/12/22 20:40:30 by tle-rhun         ###   ########.fr       */
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
void	free_all(char **str)
{
	int i;
	
	i = 0;
	while (str[i] != NULL)
		free(str[i++]);
	free (str);
}

#include <stdio.h>
t_liste	*recover_arg_in_linked_list(char **av, int ac, t_liste	**stack_a)
{
	int		a;
	char	*join;
	char	**split;
	t_liste	*last_a;

	*stack_a = NULL;
	a = 0;
	join = ft_super_strjoin(ac - 1, &av[1], " ");
	split = ft_split(join, ' ');
	free(join);
	while (split[a] != NULL)
	{
		lstadd_back(stack_a, lstnew(safe_atoi(split, a)));
		a++;
	}
	last_a = lstlast(*stack_a);
	last_a->next = *stack_a;
	(*stack_a)->previous = last_a;
	free_all (split);
	return (*stack_a);
}


int	main(int ac, char **av)
{
	int		a;
	t_liste	*stack_a;
	// t_liste	*tempstack_a;
	// t_liste	*tempstack_b;
	// t_liste	*stack_b;

	// stack_b = NULL;
	if (ac < 2)
		error();
	recover_arg_in_linked_list(av, ac, &stack_a);
	a = 0;

	printf("taille de la liste %d\n", lstsize(stack_a));
	//Sa
	// operation_swap(&stack_a);
	// Ra
	operation_rotate(&stack_a, lstsize(stack_a));
	//Rra
	// operation_reverse_rotate(&stack_a, lstsize(stack_a));
	//Pb
	// operation_push(&stack_a, &stack_b);
	// operation_push(&stack_a, &stack_b);
	//Pa
	// operation_push(&stack_b, &stack_a);



	
	//voir pour débuguer mais enlever après	

	while (a < ac - 1)
	{
		printf("Maillon de la liste chaînnée A%d:%d", a, stack_a->content);
		printf("  Previous:%d", (stack_a->previous)->content);
		printf("  Next:%d\n", (stack_a->next)->content);

		stack_a = stack_a->next;
		a++;
	}
/* 	a = 0;
	while (a < ac)
	{
		tempstack_a = stack_a;
		stack_a = tempstack_a->next;
		free (tempstack_a);
	} */
	/* while (a < 1)
	{
		printf("Maillon de la liste chaînnée B%d: %d\n", a , stack_b->content);
		tempstack_b = stack_b;
		stack_b = tempstack_b->next;
		free(tempstack_b);
		a++;
	} */
/* 	while (a < 1)
	{
		printf("Maillon de la liste chaînnée  A%d: %d      B:%d\n", a, stack_a->content , stack_b->content);
		tempstack_a = stack_a;
		tempstack_b = stack_b;
		stack_a = tempstack_a->next;
		stack_b = tempstack_b->next;
		free(tempstack_a);
		free(tempstack_b);
		a++;
	} */
	return (1);
}