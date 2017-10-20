/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   seperate_files_and_folders.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guiricha <guiricha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/20 18:43:13 by guiricha          #+#    #+#             */
/*   Updated: 2017/10/20 21:02:22 by guiricha         ###   ########.fr       */
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
	struct stat	current_item;

	index = 0;
	data->files = NULL;
	ft_printf("len of remaining args: [%d = argc]\n", names_len);
	while (index < names_len)
	{
		if (lstat(names[index], &current_item) != -1)
		{
			ft_printf("%s\n", current_item.st_mode & S_IFDIR ? "dir" : "file");
		}
		else
		{
			perror("FT_LS ERROR: ");
		}
		index++;
	}
	return (OK);
}
