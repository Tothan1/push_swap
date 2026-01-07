/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-rhun <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 16:41:15 by tle-rhun          #+#    #+#             */
/*   Updated: 2026/01/07 17:45:36 by tle-rhun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include "./libft/libft.h"
#include <limits.h>
#include <stdio.h>

/* liste chaînnée*/
typedef struct s_liste
{
	int			    content;
	int			    index;
	struct s_liste	*next;
	struct s_liste	*previous;
}			t_liste;

/* typedef struct h_liste
{
	int			    content;
	struct h_liste	*first;
}			head_liste; */

t_liste	*lstnew(int content, int index);
void	lstadd_front(t_liste **lst, t_liste *new, t_liste *previous);
void	lstadd_back(t_liste **lst, t_liste *new);
t_liste	*lstlast(t_liste *lst);
t_liste	*lstfirst(t_liste *lst);
int	lstsize(t_liste *lst);
/* algo_little*/
void	algo_sort_small(t_liste **stack_a);
/* algo_radix*/
void	algo_radix_sort(t_liste **stack_a, t_liste **stack_b);
/* index*/
void indexsort(t_liste *stack_a);
void	chek_is_sort(t_liste *stack_a);
void	index_and_check_sort(t_liste **stack_a, t_liste **stack_b);

/* operation*/
void	operation_push(t_liste	**from, t_liste	**dest);
void	operation_swap(t_liste	**stack);
void	operation_rotate(t_liste **stack);
void	operation_reverse_rotate(t_liste **stack);

/* fonction*/
int		PUSH_SWAP(const char *str, ...);
int	ft_seplen(char *sep);
int	ft_strslen(char **strs, int b, int i, int sizestrs);
char	*ft_remplir_concat(int size, char *concat, char *sep, char **strs);
int	ft_malloc(char *sep, int size, char **strs, int b);
char	*ft_super_strjoin(int size, char **strs, char *sep);

/* error*/
void	error(void);

#endif
