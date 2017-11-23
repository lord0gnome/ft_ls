/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_file_to_list_long_format.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guiricha <guiricha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/02 13:34:30 by guiricha          #+#    #+#             */
/*   Updated: 2017/11/23 18:34:11 by guiricha         ###   ########.fr       */
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
 **	NEED TO FIX linking between linked list items, not working as should be, getting close though.
 */

int	add_file_to_list(char *file, t_ls_list **list, char *real_name)
{
    struct stat	buf;
    t_ls_filedata	*data;

    data = (t_ls_filedata *)malloc(sizeof(t_ls_filedata));
    if (stat(file, &(buf)) != -1)
	data->statret = buf;
	else
		return (KO_SYSCALL_ERROR_STAT);
    data->name = ft_strdup(file);
	data->real_name = ft_strdup(real_name);
    *list = create_element_or_new_list(data, *list);
    return (OK);
}
