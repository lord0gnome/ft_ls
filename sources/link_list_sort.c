/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   link_list_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guiricha <guiricha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/19 16:55:21 by guiricha          #+#    #+#             */
/*   Updated: 2017/11/30 15:38:54 by guiricha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
#include "libft.h"
#include "ft_printf.h"

int	sort_by_name_asc(t_ls_list *item1, t_ls_list *item2, t_ls_data *d)
{
	t_ls_filedata	*temp;
	d->err = d->err;
	if ((ft_strcmp((item1)->data->real_name, (item2)->data->real_name)) < 0)
	{
		temp = item1->data;
		item1->data = item2->data;
		item2->data = temp;
		return (0);
	}
	return (1);
}
