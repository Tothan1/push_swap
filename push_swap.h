/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-rhun <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 16:41:15 by tle-rhun          #+#    #+#             */
/*   Updated: 2026/01/05 11:55:33 by tle-rhun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include "./libft/libft.h"
#include <limits.h>

/* liste chaînnée*/
typedef struct s_liste
{
	int			    content;
	struct s_liste	*next;
	struct s_liste	*previous;
}			t_liste;

typedef struct h_liste
{
	int			    content;
	struct h_liste	*first;
}			head_liste;

t_liste	*lstnew(int content);
void	lstadd_front(t_liste **lst, t_liste *new, t_liste *previous);
void	lstadd_back(t_liste **lst, t_liste *new);
t_liste	*lstlast(t_liste *lst);
t_liste	*lstfirst(t_liste *lst);
int	lstsize(t_liste *lst);


/* operation*/
void	operation_push(t_liste	**from, t_liste	**dest);
void	operation_swap(t_liste	**stack);
void	operation_reverse_rotate(t_liste **stack, int sizelst);
void	operation_rotate(t_liste **stack, t_liste **head_stack_a);
/* fonction*/
int		PUSH_SWAP(const char *str, ...);
int	ft_seplen(char *sep);
int	ft_strslen(char **strs, int b, int i, int sizestrs);
char	*ft_remplir_concat(int size, char *concat, char *sep, char **strs);
int	ft_malloc(char *sep, int size, char **strs, int b);
char	*ft_super_strjoin(int size, char **strs, char *sep);

#endif
