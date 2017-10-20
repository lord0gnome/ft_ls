/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guiricha <guiricha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/19 16:14:44 by guiricha          #+#    #+#             */
/*   Updated: 2017/10/20 20:03:09 by guiricha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H

struct	s_ls_params;

typedef struct	s_ls_data
{
	struct s_ls_params	*params;
	int					last_param;
	char				**files;
	char				**folders;
	char		parse_error_culprit;
}				t_ls_data;

typedef struct	s_ls_params
{
	int			print_options; // -h
	int			show_hidden; // -a
	int			recursive; // -R
	int			long_format; // -l
	int			reverse; // -r
	int			sort_by_time; // -t
	int			slash_for_dir; // -p '/' after each entry that is a directory
	int			stream_format; // -m ", " after each entry
	char		*valid_options;
}				t_ls_params;

int				init_data(t_ls_data *data);
int				parse_options(int argc, char **argv, t_ls_data *data);
int				seperate_files_and_folders(int names_len, char **names, t_ls_data *data);
void			print_parameters(t_ls_params *params);

#endif
