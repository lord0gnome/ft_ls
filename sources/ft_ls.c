/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guiricha <guiricha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/24 17:28:41 by guiricha          #+#    #+#             */
/*   Updated: 2017/11/19 14:57:24 by guiricha         ###   ########.fr       */
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

static int	handle_dir(const char *name, t_ls_list *current_item, t_ls_data *d)
{
	DIR	*stream;
	struct dirent *entry;

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
	if (!closedir(stream))
		return (OK);
	return (KO_SYSCALL_ERROR_OPENDIR);
}

int			ft_ls(t_ls_list *item, t_ls_data *data)
{
	if (((data->params->recursive 
					&& ft_strcmp("..", item->data.real_name)
					&& ft_strcmp(".", item->data.real_name)
					&& item->data.real_name[0] != '.')
				|| item->init_entry)
			&& S_ISDIR(item->data.statret.st_mode))
	{
		if (handle_dir(item->data.name, item, data) < 0)
		{
			ft_printf("ft_ls error : %s", strerror(errno));
		}
	}

	return (OK);
}
