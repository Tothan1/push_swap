/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-rhun <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 16:41:15 by tle-rhun          #+#    #+#             */
/*   Updated: 2025/12/17 21:05:04 by tle-rhun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include "./libft/libft.h"
#include <limits.h>

int		PUSH_SWAP(const char *str, ...);
int	ft_seplen(char *sep);
int	ft_strslen(char **strs, int b, int i, int sizestrs);
char	*ft_remplir_concat(int size, char *concat, char *sep, char **strs);
int	ft_malloc(char *sep, int size, char **strs, int b);
char	*ft_super_strjoin(int size, char **strs, char *sep);

#endif /* PUSH_SWAP_H */
