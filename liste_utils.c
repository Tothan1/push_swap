/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   liste_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-rhun <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/19 20:13:46 by tle-rhun          #+#    #+#             */
/*   Updated: 2026/01/15 15:27:10 by tle-rhun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_liste	*lstnew(int content, int index)
{
	t_liste	*newlst;

	newlst = malloc(sizeof(t_liste));
	if (!newlst)
		return (NULL);
	newlst->content = content;
	newlst->next = NULL;
	newlst->index = index;
	newlst->previous = NULL;
	return (newlst);
}
void	lstadd_front(t_liste **lst, t_liste *new, t_liste *previous)
{
	t_liste	*tail;

	(void)previous;
	if (!*lst)
	{
		*lst = new;
		new->previous = new;
		new->next = new;
	}
	else
	{
		tail = (*lst)->previous;
		new->next = *lst;
		new->previous = tail;
		tail->next = new;
		(*lst)->previous = new;
		*lst = new;
	}
}

void	lstadd_back(t_liste **lst, t_liste *new)
{
	if (*lst == NULL)
	{
		*lst = new;
		new->previous = new;
		new->next = new;
	}
	else
	{
		new->previous = (*lst)->previous;
		new->next = *lst;
		((*lst)->previous)->next = new;
		(*lst)->previous = new;
	}
}
int	lstsize(t_liste *lst)
{
	int i;
	t_liste *verif;
	verif = lst;
	i = 0;
	if (!lst)
		return (0);
	while (lst != verif || i == 0)
	{
		lst = lst->next;
		i++;
	}
	return (i);
}