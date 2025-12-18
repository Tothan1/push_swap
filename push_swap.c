/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-rhun <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/16 13:36:13 by tle-rhun          #+#    #+#             */
/*   Updated: 2025/12/17 21:31:27 by tle-rhun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	error (void)
{
	write(1, "Error\n", 6);
	exit( EXIT_FAILURE );
}

void	check_occurence(int	*number, int check)
{
	int	a;
	
	a = 0;
	while(number[a] != number[check] && a < check)
		a++;
	if( number[a] == number[check] && a < check)
		error();
}
/* void	ft_check_args(char **split)
{
	int	a;
	int	i;
	a = 0;
	
	while(split[a] != NULL)
	{
		i = 0;
		while (split[a][i] != '\0' && (ft_isdigit(split[a][i]) || ((split[a][i] == '-'|| split[a][0] == '+') && i == 0)))
			i++;
		if (split[a][i] != '\0' && !ft_isdigit(split[a][i]))
			error();
		check_occurence(split, a);
		a++;
	}
} */

int	safe_atoi(char **str, int a)
{
	int	i;
	int	signe;
	long	nombre;

	i = 0;
	signe = 1;
	nombre = 0;
	if (str [a][i] == '-' || str [a][i] == '+' )
	{
		if (str [a][i] == '-')
			signe *= -1;
		i++;
	}
	while (ft_isdigit(str[a][i]) && str[a][i] != '\0')
	{
		nombre = nombre * 10 + str [a][i] - '0';
		i++;
	}
	nombre = signe * nombre;
	if ((!ft_isdigit(str[a][i]) && str[a][i] != '\0') || nombre < INT_MIN || nombre > INT_MAX)
			error();
	return (nombre);
}


#include <stdio.h>
int main (int ac, char **av)
{
	int	a;
	int lentab;
	int *number;
	char *join;
	char **split;

	a = 0;
	printf("test");
	if (ac < 2)
		error();
	join = ft_super_strjoin(ac-1 , &av[1], " ");
	split = ft_split(join, ' ');
	lentab = 0;
	while (split[lentab])
		lentab++;
	number = malloc(sizeof(int) * lentab);
	if (number == NULL)
		error();
	free (join);
	while (split[a] != NULL)
	{
		number[a] = safe_atoi(split, a);
		check_occurence(number, a);
		a++;
	}
	// ft_check_args(split);

	return (1);
}

//faire mon check doublon après mon atoi pour gérer le 0 devant et le signe +
//et faire dans mon atoi check les args