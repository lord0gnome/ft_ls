/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guiricha <guiricha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/19 14:19:14 by guiricha          #+#    #+#             */
/*   Updated: 2017/10/20 20:13:16 by guiricha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"
#include "ft_ls.h"
#include <sys/stat.h>

int	main(int argc, char **argv)
{
	t_ls_data	data;

	init_data(&data);
	if (parse_options(argc - 1, &(argv[1]), &data) > 0)
		data.last_param++;
	else
		ft_printf( "\e[91m" "WARNING:" "\e[39m"" errors detected in parsing!\n"
				"Culprit character is [%c]\n", data.parse_error_culprit);
	print_parameters(data.params);
	seperate_files_and_folders(argc - data.last_param, &(argv[data.last_param]), &data);
	return (0);
}
