/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   seperate_files_and_folders.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guiricha <guiricha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/20 18:43:13 by guiricha          #+#    #+#             */
/*   Updated: 2017/11/02 14:39:49 by guiricha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_ls.h"
#include "error.h"
#include "ft_printf.h"
#include <stdio.h>

int	seperate_files_and_folders(int names_len, char **names, t_ls_data *data)
{
    int			index;
    int			error_file_folder_index;
    struct stat	current_item;
    int			*status;

    index = 0;
    ft_printf("len of remaining args: [%d = argc]\n", names_len);
    status = (int *)malloc(sizeof(int) * names_len + 1);
    status[names_len] = -1;
    while (index < names_len)
    {
	if (lstat(names[index], &current_item) != -1)
	    status[index] = current_item.st_mode & S_IFDIR ? 3 : 2;
	else
	    status[index] = 1;
	index++;
    }
    index = 0;
    error_file_folder_index = 0;
    while (++error_file_folder_index < 4)
    {
	index = 0;
	while (status[index] != -1)
	{
	    if (status[index] == error_file_folder_index)
	    {
		add_file_to_list(names[index], &(data->list));
		data->list->init_entry = 1;
	    }
	    index++;
	}
    }
    return (OK);
}
