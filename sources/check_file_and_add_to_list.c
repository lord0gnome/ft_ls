/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_file_to_list_long_format.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guiricha <guiricha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/02 13:34:30 by guiricha          #+#    #+#             */
/*   Updated: 2017/11/02 15:31:36 by guiricha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/stat.h>
#include "ft_ls.h"
#include "ft_printf.h"
#include "error.h"
#include "libft.h"
#include <stdlib.h>

/*
** 	Todo: get all potential necessary data if -l flag is passed.
**	otherwise just get the name, should already be sorted appropriately.
*/

int	add_file_to_list(char *file, t_ls_list **list)
{
	struct stat	buf;
	t_ls_filedata	*data;

	data = (t_ls_filedata *)malloc(sizeof(t_ls_filedata));
	if (lstat(file, &(buf)) != -1)
	{
		data->statret = buf;
	}
	// ft_memcpy(&(data->statret), &(buf), sizeof(struct stat));
	data->name = ft_strdup(file);
	*list = create_element_or_new_list(data, *list);
	return (OK);
}

int	add_file_to_list_long_format(char *file, t_ls_list **list)
{
	t_ls_filedata	*data;

	data = (t_ls_filedata *)malloc(sizeof(t_ls_filedata));
	data->name = ft_strdup(file);
	*list = create_element_or_new_list(data, *list);
	ft_printf("list data = %s, pointer of list item is %p\n", (*list)->data.name, *list);
	return (OK);
}
