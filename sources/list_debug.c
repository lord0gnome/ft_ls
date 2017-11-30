/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_debug.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guiricha <guiricha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/19 13:31:51 by guiricha          #+#    #+#             */
/*   Updated: 2017/11/30 17:47:12 by guiricha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "ft_ls.h"

void	print_list_from_start(t_ls_list	*link)
{
	if (!link)
	{
		ft_printf("List doesn't exist\n");
		return ;
	}
	while (link && link->prev)
	{
		link = link->prev;
	}
	while (link)
	{
		ft_printf("File name is [%s] and path is [%s] S_ISDIR = %s INIT_ENTRY = %s\n", link->data->real_name, link->data->name, S_ISDIR(link->data->statret.st_mode) ? "True" : "False", link->data->init_entry ? "True" : "False");
		link = link->next;
	}
	ft_putstr("\n\n\n");
}
