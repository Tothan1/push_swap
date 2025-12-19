/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   liste_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-rhun <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/19 20:13:46 by tle-rhun          #+#    #+#             */
/*   Updated: 2025/12/19 21:16:50 by tle-rhun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_liste	*lstnew(int content)
{
	t_liste	*newlst;

	newlst = malloc(sizeof (t_liste));
	if (!newlst)
		return (NULL);
	newlst->content = content;
	newlst->next = NULL;
	newlst->previous = NULL;
	return (newlst);
}
void	lstadd_front(t_liste **lst, t_liste *new, t_liste *previous)
{
	new->previous = previous;
	new->next = *lst;
	*lst = new;
}

int	lstsize(t_liste *lst)
{
	int	i;

	i = 0;
	while (lst != NULL)
	{
		lst = lst->next;
		i++;
	}
	return (i);
}