/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   liste_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tle-rhun <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/19 20:13:46 by tle-rhun          #+#    #+#             */
/*   Updated: 2025/12/22 15:59:23 by tle-rhun         ###   ########.fr       */
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

t_liste	*lstlast(t_liste *lst)
{
	int	i;

	i = 0;
	if (lst == NULL)
		return (NULL);
	while (lst->next)
		lst = lst->next;
	return (lst);
}

void	lstadd_back(t_liste **lst, t_liste *new, t_liste *previous)
{
	t_liste	*last;

	if (*lst == NULL)
		*lst = new;
	else
	{
		last = lstlast(*lst);
		last->next = new;
		last->previous = previous;
	}
}
t_liste	*lstfirst(t_liste *lst)
{
	int	i;

	i = 0;
	if (lst == NULL)
		return (NULL);
	while (lst->previous)
		lst = lst->previous;
	return (lst);
}
int	ft_lstsize(t_list *lst)
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
}