/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem-in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anel-bou <anel-bou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/18 12:56:04 by anel-bou          #+#    #+#             */
/*   Updated: 2021/01/02 12:03:22 by anel-bou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H

# include "../libft/libft.h"
# include "../libft/get_next_line.h"
# include <stdio.h>

# define ERROR -1
# define INP_END 0
# define START 1
# define ROOM 2
# define END 3
# define LINK 4
# define FIRST_CH 5
# define LAST_CH 6
# define COMMENT 7
# define NONE 0
# define PRINTED 1
# define PASSED 2

typedef struct		s_inp
{
	char			*line;
	struct s_inp	*next;
}					t_inp;
typedef struct		s_queue
{
	struct s_room	*room;
	struct s_queue	*next;
}					t_queue;
typedef struct		s_link
{
	struct s_room	*room;
	struct s_link	*next;
	int				flow;
}					t_link;

typedef struct		s_ptheads
{
	struct s_path		*path;
	int					total_rooms;
	int					id;
	int					len;
	int					ants;
	int					status;
	struct s_ptheads	*next;
}					t_ptheads;

typedef struct		s_path
{
	struct s_room	*room;
	struct s_path	*next;
	int				status;
	int				ant_id;
}					t_path;

typedef struct		s_room
{
	struct s_room	*next;
	struct s_room	*parent;
	struct s_link	*link;
	char			*name;
	int				x;
	int				y;
	int				iterated;
	int				childnb;
	int				used;
	int				full;
	int				set_last;
	int				dept_layer;
	int				correction_room;
}					t_room;

typedef struct		s_ant_opt
{
	int id;
	int antsnb;
	int antsnb_org;
	int nbrpaths;
	int ret;
	int flag;
}					t_ant_opt;

typedef struct		s_path_group
{
	struct s_ptheads	*head;
	struct s_path_group	*next;
	int					group_number;
	int					total_rooms_in_group;
	int					total_heads;
	int					score;
}					t_path_group;

typedef struct		s_norm_sp
{
	unsigned int	i;
	unsigned int	meanlen;
	int				totallen;
	int				mod;
	int				ret;
	t_ptheads		*tmp;
}					t_norm_sp;

typedef struct		s_norm_bfs
{
	t_queue	*last;
	t_queue	*first;
	t_queue	*tmp;
	int		rpt;
	int		altern;
}					t_norm_bfs;

typedef struct		s_norm_sfcg
{
	t_path_group	*grp;
	t_ptheads		*prev;
	int				is_any_path_saved;
	int				current_score;
}					t_norm_sfcg;

typedef struct		s_norm_pg
{
	t_room	*rm;
	t_link	*lnk;
	int		total_rooms;
	t_path	*papr;
}					t_norm_pg;

typedef struct		s_norm_sdl
{
	t_queue	*last;
	t_queue	*first;
	t_queue	*tmp;
	t_link	*lnk;
	int		dept;
}					t_norm_sdl;

typedef struct		s_env
{
	t_room			**room;
	t_room			*start;
	t_room			*end;
	t_room			*ptr;
	t_link			*lnk;
	t_path_group	*path_group;
	t_path_group	*pth_grp;
	t_path_group	*best_group;
	t_ptheads		*ptheads;
	t_ptheads		*pthds;
	t_path			*path;
	t_path			*pth;
	t_inp			*inp;
	char			*tmp;
	int				antsnb;
	int				iteration_nb;
	int				nbrooms;
	int				retry;
	int				second_call;
	unsigned int	nbrpaths;
	int				totallen;
	int				index;
	int				section;
	int				start_end_linked;
	int				group_nb;
	int				best_score;
}					t_env;

void				liberate_memory(t_env *env);
int					check_error(t_inp **inp, char **line, int *section);
int					input_to_list(t_env *env);
int					save_input(t_env *env);
int					get_index(int max, char *str);
int					bfs(t_env *env, int follow, t_room *start);
t_room				*get_room(t_env *env, char *room);
void				initialize_var(t_env *env);
int					path_generator(t_env *env, t_room *start);
void				delete_heads_rest(t_ptheads *pthds);
void				delete_path_rest(t_path *ptr);
void				set_antsnb(t_inp **inp, t_env *env);
void				ft_calc_ants(t_env *env);
int					ft_select_path(t_env *env, int next_len, int avg_len);
void				ft_select_paths(t_env *env, t_ptheads *current,
int avg_len);
void				ft_move_ants_lip(t_ptheads *path, t_ant_opt *opt);
void				ft_move_ants_trip(t_ptheads *paths, t_ptheads
*pivot, t_ant_opt opt);
int					ft_print_ants(t_path *path, int *flag);
int					ft_str_is_num(char *str);
int					ft_str_is_name(char *str);
void				set_one_path(t_env *env);
void				set_dept_layers(t_env *env);
void				verify_reverse_link(t_env *env, t_link *lnk, t_room *rm);
void				ft_free_doubld_table(char ***table);
void				fill_link(t_env *env, char *line);
void				fill_room(t_env *env, char *str, int msg);
void				ft_move_ants(t_path *path, int *antsnb);
int					check_if_room_duplicated_in_both(t_path *p1, t_path *p2);
int					get_group_score(int ants, int rooms_in_grp, int heads);
void				save_head_in_this_group(t_env *env, t_ptheads *prev,
t_path_group **grp, int	total_rooms_in_path);
t_room				*enumerate_from_end_to_start(t_env *env, t_room *start);
void				allocate_path_head(t_env *env);
t_path				*allocate_pheads(t_env *env);
void				save_head_in_new_grp(t_env *env, int total_rooms_in_path);

#endif
