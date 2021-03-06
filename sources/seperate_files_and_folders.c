/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   seperate_files_and_folders.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guiricha <guiricha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/20 18:43:13 by guiricha          #+#    #+#             */
/*   Updated: 2017/12/01 12:40:59 by guiricha         ###   ########.fr       */
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

	ft_putstr(SEE_FUNCTION_CALLS ? "seperate_files_and_folders called\n" : "");
	index = 0;
	status = (int *)malloc(sizeof(int) * names_len + 1);
	status[names_len] = -1;
	while (index < names_len)
	{
		if (lstat(names[index], &current_item) != -1)
			status[index] = current_item.st_mode & S_IFDIR ? 3 : 2;
		else
		{
			data->err = KO_SYSCALL_ERROR_LSTAT;
			data->errstr = names[index];
			handle_error_soft(*data);
			status[index] = 1;
		}
		index++;
	}
	index = 0;
	error_file_folder_index = 1;
	while (++error_file_folder_index < 4)
	{
		index = 0;
		while (status[index] != -1)
		{
			if (status[index] == error_file_folder_index)
			{
				if ((data->err = add_file_to_list(names[index], &(data->list), names[index])) < 1)
				{
					handle_error_soft(*data);
				}
				data->list->data->init_entry = 1;
			}
			index++;
		}
	}
	ft_putstr(SEE_FUNCTION_ENDS ? "seperate_files_and_folders completed\n" : "");
	return (OK);
}
