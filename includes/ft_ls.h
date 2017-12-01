/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guiricha <guiricha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/19 16:14:44 by guiricha          #+#    #+#             */
/*   Updated: 2017/12/01 12:31:15 by guiricha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H
# include <sys/stat.h>
# define SEE_FUNCTION_CALLS 0
# define SEE_FUNCTION_ENDS 0


typedef struct	s_ls_filedata
{
	mode_t		file_mode;
	struct stat	statret;
	char		*name;
	char		*real_name;
	int			init_entry;
}				t_ls_filedata;

typedef struct	s_ls_list
{
	t_ls_filedata		*data;


	struct s_ls_list	*prev;
	struct s_ls_list	*next;
}				t_ls_list;


struct	s_ls_params;

typedef struct	s_ls_data
{
	t_ls_list			*list;
	struct s_ls_params	*params;
	int					last_param;
	char		parse_error_culprit;
	char		*current_dir;
	int			err;
	char		*errstr;
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
t_ls_list		*create_element_or_new_list(t_ls_filedata *data, t_ls_list *prev);
int				free_ls_element(t_ls_list *element);
int				add_file_to_list(char *file, t_ls_list **list, char *real_name);
int				ft_ls(t_ls_list **item, t_ls_data *data);
int				sort_by_name_asc(t_ls_list *item1, t_ls_list *item2, t_ls_data *d);
void			handle_error(t_ls_data data);
void			handle_error_soft(t_ls_data data);
void			print_parameters(t_ls_params *params);
void			print_list_from_start(t_ls_list *link);

#endif
