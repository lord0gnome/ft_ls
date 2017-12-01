/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_structs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guiricha <guiricha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/20 17:45:58 by guiricha          #+#    #+#             */
/*   Updated: 2017/12/01 12:23:26 by guiricha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
#include "error.h"
#include "libft.h"

int	init_data(t_ls_data *data)
{
	ft_memset(data, 0, sizeof(data));
	data->list = NULL;
	data->params = (t_ls_params *)ft_memalloc(sizeof(t_ls_params));
	if (!data->params)
		return (KO_MALLOC);
	data->params->valid_options = ft_strnew(ft_strlen("lrRtah"));
	if (!data->params->valid_options)
		return (KO_MALLOC);
	ft_strcpy(data->params->valid_options, "lrRtah");
	return (OK);
}
