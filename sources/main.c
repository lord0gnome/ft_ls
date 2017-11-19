/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guiricha <guiricha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/19 14:19:14 by guiricha          #+#    #+#             */
/*   Updated: 2017/11/19 15:27:15 by guiricha         ###   ########.fr       */
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
	int			len;

	init_data(&data);
	sorted_args = &(argv[1]);
	len = argc - 1;
	if ((data.err = parse_options(len, sorted_args, &data)) < 0)
		handle_error(data);
	print_parameters(data.params);
	sorted_args = &(sorted_args[data.last_param]);
	len -= data.last_param;
	if (len == 0)
	{
		*sorted_args = (ft_strdup("."));
		len = 1;
	}
	else
		sorted_args = ft_sort_str_array(sorted_args, len, &(ft_strcmp), 1); //careful here
	seperate_files_and_folders(len, sorted_args, &data);
	while (data.list->prev)
	{
		data.list = data.list->prev;
	}
	while (data.list)
	{
		if (data.list->data.real_name[0] != '.')
		{
			ft_putstr(data.list->data.real_name);
			ft_putchar('\n');
		}
		ft_ls(data.list, &data);
		data.list = data.list->next;
	}
	return (0);
}
