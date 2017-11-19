/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_error.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guiricha <guiricha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/19 15:06:17 by guiricha          #+#    #+#             */
/*   Updated: 2017/11/19 15:20:13 by guiricha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "error.h"
#include "ft_printf.h"
#include "libft.h"
#include "ft_ls.h"
#include "errno.h"

void	handle_error(t_ls_data data)
{
	ft_printf("ft_ls ErrorCode[%d]: ", data.err);
	if (data.err == KO_MALLOC)
		ft_putstr("Memory Allocation Error");
	else if (data.err == KO_INVALID_OPTION)
		ft_putstr("Invalid Parameter");
	else if (data.err == NO_LIST_TO_FREE)
		ft_putstr("No List To Free");
	else if (data.err == NO_ELEMENT_TO_FREE)
		ft_putstr("No Element To Free");
	else if (data.err == KO_SYSCALL_ERROR_OPENDIR)
		ft_printf("Call to opendir() failed with error: %s", strerror(errno));
	else if (data.err == KO_SYSCALL_ERROR_LSTAT)
		ft_printf("Call to lstat() failed with error: %s", strerror(errno));
	ft_putchar('\n');
	exit(0);
}
