/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guiricha <guiricha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/19 14:19:14 by guiricha          #+#    #+#             */
/*   Updated: 2017/11/02 15:08:40 by guiricha         ###   ########.fr       */
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
	if (parse_options(len, sorted_args, &data) < 0)
		ft_printf( "\e[91m" "WARNING:" "\e[39m"" errors detected in parsing!\n"
				"Culprit character is [%c]\n", data.parse_error_culprit);
	print_parameters(data.params);
	sorted_args = &(sorted_args[data.last_param]);
	len -= data.last_param;
	ft_printf("first arg is now %s and len should be %d\n", sorted_args[0], len);
	sorted_args = ft_sort_str_array(sorted_args, len, &(ft_strcmp), 1); //careful here
	seperate_files_and_folders(len, sorted_args, &data);
	while (data.list->prev)
	{
		data.list = data.list->prev;
	}
	while (data.list)
	{
		ft_ls(data.list, &data);
		data.list = data.list->next;
	}
	return (0);
}
