/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guiricha <guiricha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/24 17:28:41 by guiricha          #+#    #+#             */
/*   Updated: 2017/11/02 13:10:19 by guiricha         ###   ########.fr       */
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

int	handle_dir(const char *name, t_ls_list *current_item)
{
    DIR	*stream;
    struct dirent *entry;

    ft_printf("opendir called on [%s]", current_item->data.name);
    if ((stream = opendir(name)) == NULL)
    {
	ft_printf("ft_ls error : %s\n", strerror(errno));
    }
    else
    {
	while ((entry = readdir(stream)) != NULL)
	{

	    add_file_to_list(entry->d_name, &current_item);
	    ft_printf("%s\t", entry->d_name);
	}
	ft_printf("\n");
    }
    return (OK);
}

int	ft_ls(t_ls_list *item, t_ls_data *data)
{
    ft_printf("ls called on parameter [%s]", item->data.name); // debug pliz remove
    if (((data->params->recursive 
	    && strcmp("..", item->data.name)
	    && strcmp(".", item->data.name))
	    || item->init_entry)
	    && S_ISDIR(item->data.statret.st_mode))
    {
	ft_printf("... Will call opendir on it.\n");
	handle_dir(item->data.name, item);
    }
    ft_printf("\n");

    return (OK);
}
