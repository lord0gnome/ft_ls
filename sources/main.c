/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guiricha <guiricha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/19 14:19:14 by guiricha          #+#    #+#             */
/*   Updated: 2017/10/19 16:39:29 by guiricha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"
#include "ft_ls.h"

int	main(int argc, char **argv)
{
	ft_sort_str_array(&(argv[1]), argc - 1, 1);
}
