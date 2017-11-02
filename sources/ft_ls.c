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
#include "error.h"
#include "ft_printf.h"
#include <sys/ioctl.h>

int	ft_ls(char *item, t_ls_data *data)
{
	struct winsize	w;
	int				written;

	ioctl(0, TIOCGWINSZ, &w);
	written = ft_printf("%s\n", item);
	if (data->last_param)
		item = &item[1];
	return (OK);
}
