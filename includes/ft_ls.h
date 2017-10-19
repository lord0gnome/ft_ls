/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guiricha <guiricha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/19 16:14:44 by guiricha          #+#    #+#             */
/*   Updated: 2017/10/19 16:37:22 by guiricha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H

typedef struct	s_ls_params t_ls_params;

typedef struct	s_ls_data
{
	struct t_ls_params	*params;

}				t_ls_data;

typedef struct	s_ls_params
{
	int			show_hidden; // -a
	int			recursive; // -R
	int			long_format; // -l
	int			reverse; // -r
	int			sort_by_time; // -t
	int			slash_for_dir; // -p '/' after each entry that is a directory
	int			stream_format; // -m ", " after each entry
}				t_ls_params;

#endif
