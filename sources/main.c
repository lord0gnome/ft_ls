/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guiricha <guiricha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/19 14:19:14 by guiricha          #+#    #+#             */
/*   Updated: 2017/12/01 14:06:10 by guiricha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"
#include "ft_ls.h"
#include <sys/stat.h>

int	main(int argc, char **argv)
{
	t_ls_data	data;
	char		**sorted_args;
	t_ls_list	*end;
	int			len;

	init_data(&data);
	sorted_args = &(argv[1]);
	len = argc - 1;
	if ((data.err = parse_options(len, sorted_args, &data)) < 0)
		handle_error(data);
	sorted_args = &(sorted_args[data.last_param]);
	len -= data.last_param;
	if (len == 0)
	{
		*sorted_args = (ft_strdup("."));
		len = 1;
	}
	else
		sorted_args = ft_sort_str_array(sorted_args, len, &(ft_strcmp), 1);
	seperate_files_and_folders(len, sorted_args, &data);
	while (data.list && data.list->prev)
		data.list = data.list->prev;
	end = NULL;
	while (data.list)
	{
		if (ft_ls(&(data.list), &data) < 1)
		{
			handle_error(data);
		}
		if (data.list && !data.list->next)
			end = data.list;
		data.list = data.list->next;
	}
	data.list = end;
	while (data.list && data.list->prev)
			data.list = data.list->prev;
	while (data.list)
	{
		ft_printf("%30-s%s\n", data.list->data->real_name, data.list->data->name);
		data.list = data.list->next;
	}
	return (0);
}
