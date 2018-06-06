/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_options.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guiricha <guiricha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/20 16:39:57 by guiricha          #+#    #+#             */
/*   Updated: 2018/06/06 12:51:23 by guiricha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"
#include "error.h"
#include "ft_ls.h"

static void	activate_option(t_ls_params *params, char option)
{
	if (option == 'l')
		params->long_format = 1;
	else if (option == 'a')
		params->show_hidden = 1;
	else if (option == 'h')
		params->print_options = 1;
	else if (option == 'r')
		params->reverse = 1;
	else if (option == 'R')
		params->recursive = 1;
	else if (option == 't')
		params->sort_by_time = 1;
}

static int	is_valid_opt(char option, char *options)
{
	while (*options)
	{
		if (option == *options)
			return (1);
		options++;
	}
	return (0);
}

/*
 **	returns int to indicate success (SUCCESS) or error (ft_ls/includes/error.h)
 **	NEEDS FIXING, COUNTS PARAMETERS INCORRECTLY.
 */

int			parse_options(int argc, char **argv, t_ls_data *data)
{
	int		index;
	char	*current_arg;

	ft_putstr(SEE_FUNCTION_CALLS ? "parse_options called\n" : "");
	while (data->last_param < argc)
	{
		index = 0;
		current_arg = argv[data->last_param];
		ft_printf("Current arg is \"%s\"\n", current_arg);
		if (current_arg[index] != '-'
				|| (current_arg[index] == '-' && !(current_arg[index + 1])))
			return (OK);
		while (current_arg[++index])
		{
			data->parse_error_culprit = current_arg[index];
			if (current_arg[index] == '-' && index == 1)
				return (current_arg[index + 1] ? KO_INVALID_OPTION : OK);
			if (is_valid_opt(current_arg[index], data->params->valid_options))
				activate_option(data->params, current_arg[index]);
			else
				return (KO_INVALID_OPTION);
		}
		data->last_param++;
	}
	return (OK);
}
