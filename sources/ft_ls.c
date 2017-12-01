/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guiricha <guiricha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/24 17:28:41 by guiricha          #+#    #+#             */
/*   Updated: 2017/12/01 14:30:15 by guiricha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
#include "libft.h"
#include "error.h"
#include "ft_printf.h"
#include <sys/types.h>
#include <dirent.h>
#include <string.h>
#include <errno.h>

int			sort_by_parameter(t_ls_list *from, t_ls_list *to, t_ls_data *d)
{
	t_ls_list	*restart = from;
	t_ls_list	*compare = from->next;
	int			swapped;

	ft_putstr(SEE_FUNCTION_CALLS ? "ft_ls_called\n" : "");
	swapped = 1;
	while (42)
	{
		if (swapped == 0)
			break ;
		swapped = 0;
		while (from && compare)
		{
			if (!sort_by_name_asc(from, compare, d))
			{
				swapped = 1;
			}
			if (compare == to)
			{
				from = restart;
				compare = from->next;
				break ;
			}
			from = from->next;
			compare = compare->next;
		}
		from = restart;
		compare = from->next;
	}
	return (1);
}

static int	handle_dir(const char *name, t_ls_list **current_item, t_ls_data *d)
{
	DIR	*stream;
	struct dirent *entry;
	t_ls_list	*first;

	first = *current_item;
	if ((stream = opendir(name)) == NULL)
		return (KO_SYSCALL_ERROR_OPENDIR);
	else
	{
		while ((entry = readdir(stream)) != NULL)
		{
			if (entry->d_name[0] != '.' ||
					d->params->show_hidden)
				add_file_to_list(add_dir_to_str(name ,entry->d_name), current_item, entry->d_name);
		}
	}
	first = first->next;
	//free_ls_element(first->prev);
	if ((sort_by_parameter(first, (*current_item), d)) < 1)
		handle_error(*d);
	(*current_item) = first;
	if (!closedir(stream))
		return (OK);
	return (KO_SYSCALL_ERROR_OPENDIR);
}

static int	call_handle_dir(t_ls_list *item, t_ls_data *data)
{
	if (!S_ISDIR(item->data->statret.st_mode))
		return (0);
	if (item->data->init_entry)
		return (1);
	if (ft_strrevncmp("..", item->data->real_name, 2) &&
			ft_strrevncmp(".", item->data->real_name, 1))
	{
		if ((item->data->real_name[0] != '.' || data->params->show_hidden) && data->params->recursive)
			return (1);
	}
	return (0);
}

int			ft_ls(t_ls_list **item, t_ls_data *data)
{
	/*	if (((data->params->recursive 
		&& ft_strcmp("..", item->data->real_name)
		&& ft_strcmp(".", item->data->real_name)
		&& (item->data->real_name[0] != '.' || data->params->show_hidden))
		|| item->init_entry)
		&& S_ISDIR(item->data->statret.st_mode))
		{*/
	if (call_handle_dir(*item, data))
	{
		if ((data->err = handle_dir((*item)->data->name, item, data)) < 0)
			handle_error(*data);
	}
	return (OK);
}
