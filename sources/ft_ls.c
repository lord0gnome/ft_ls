/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guiricha <guiricha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/24 17:28:41 by guiricha          #+#    #+#             */
/*   Updated: 2017/11/23 18:46:40 by guiricha         ###   ########.fr       */
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
	while (42)
	{
		if (from == to)
		{
			break ;
		}
		if (!sort_by_name_asc(from, compare, d))
		{
			compare = from->next;
			continue;
		}
		compare = compare->next;
		if (!compare->next)
		{	
			restart = from->next;
			from = from->next;
			compare = from->next;
		}
	}
	return (1);
}

static int	handle_dir(const char *name, t_ls_list *current_item, t_ls_data *d)
{
	DIR	*stream;
	struct dirent *entry;
	t_ls_list	*first;

	first = current_item;
	d->current_dir = d->current_dir;
	if ((stream = opendir(name)) == NULL)
		return (KO_SYSCALL_ERROR_OPENDIR);
	else
	{
		while ((entry = readdir(stream)) != NULL)
		{
			add_file_to_list(add_dir_to_str(name ,entry->d_name), &current_item, entry->d_name);
		}
	}
	if ((sort_by_parameter(first, current_item, d)) < 1)
	{
		handle_error(*d);
	}
	if (!closedir(stream))
		return (OK);
	return (KO_SYSCALL_ERROR_OPENDIR);
}

int			ft_ls(t_ls_list *item, t_ls_data *data)
{
	if (((data->params->recursive 
					&& ft_strcmp("..", item->data->real_name)
					&& ft_strcmp(".", item->data->real_name)
					&& (item->data->real_name[0] != '.' || data->params->show_hidden))
				|| item->init_entry)
			&& S_ISDIR(item->data->statret.st_mode))
	{
		if ((data->err = handle_dir(item->data->name, item, data)) < 0)
			handle_error(*data);
	}

	return (OK);
}
