/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug_print_funcs.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guiricha <guiricha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/20 18:07:19 by guiricha          #+#    #+#             */
/*   Updated: 2017/10/20 18:15:42 by guiricha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "ft_ls.h"

void	print_parameters(t_ls_params *params)
{
	ft_printf("(print_parameters) called!\n");
	ft_printf("show hidden(-a) = %s\n", (params->show_hidden ? "TRUE" : "FALSE"));
	ft_printf("reverse sort(-r) = %s\n", (params->reverse ? "TRUE" : "FALSE"));
	ft_printf("recursive(-R) = %s\n", (params->recursive ? "TRUE" : "FALSE"));
	ft_printf("time sort(-t) = %s\n", (params->sort_by_time ? "TRUE" : "FALSE"));
	ft_printf("long format(-l) = %s\n", (params->long_format ? "TRUE" : "FALSE"));
}
