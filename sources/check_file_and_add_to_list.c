/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_file_and_add_to_list.c                       :+:      :+:    :+:   */
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

int	check_file_and_add_to_list(char *file, t_ls_list **list, struct stat *buf)
{
	int	ret;
	t_ls_filedata *data;

	ret = lstat(file, buf);
	data = (t_ls_filedata *)malloc(sizeof(t_ls_filedata));
	data->file_mode = buf->st_mode;
	data->name = ft_strdup(file);
	*list = create_element_or_new_list(data, *list);
	ft_printf("list data = %s, pointer of list item is %p\n", (*list)->data.name, *list);
	return (OK);	
}
