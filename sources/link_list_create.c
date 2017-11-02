/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   link_list_create.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guiricha <guiricha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/30 14:45:24 by guiricha          #+#    #+#             */
/*   Updated: 2017/11/02 14:29:12 by guiricha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
#include "error.h"
#include <stdlib.h>
#include <sys/stat.h>

/*
 ** returns last created link
 */

t_ls_list	*create_element_or_new_list(t_ls_filedata *data, t_ls_list *prev)
{
	t_ls_list	*new;

	new = (t_ls_list *)malloc(sizeof(t_ls_list));
	if (!new)
		return (NULL);
	new->data = *data;
	new->prev = NULL;
	if (prev)
	{
		new->prev = prev;
		prev->next = new;
	}
	new->next = NULL;
	return (new);
}

int			free_ls_element(t_ls_list	*element)
{
	if (element)
	{
		if (element->next)
			element->next->prev = element->prev;
		if (element->prev)
			element->prev->next = element->next;
		free(element);
		return (OK);
	}
	return (NO_ELEMENT_TO_FREE);
}

int			free_ls_list(t_ls_list	*start_link)
{
	if (!start_link)
		return(NO_LIST_TO_FREE);
	while (start_link && start_link->next)
	{
		start_link = start_link->next;
		free(start_link->prev);
	}
	free(start_link);
	return (OK);
}
