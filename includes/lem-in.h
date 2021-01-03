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
#define LEM_IN_H

#include "../libft/libft.h"
#include "../libft/get_next_line.h"
#include <stdio.h>

#define ERROR	-1
#define INP_END	0
#define START	1
#define ROOM	2
#define END		3
#define	LINK	4
#define FIRST_CH 5
#define LAST_CH	6
#define	COMMENT	7

#define NONE 0
#define PRINTED 1
#define PASSED 2

typedef struct	s_inp
{
	char			*line;
	struct s_inp	*next;
}				t_inp;
typedef struct s_queue
{
	struct s_room	*room;
	struct s_queue	*next;
}				t_queue;
typedef struct	s_link
{
	struct s_room	*room;
	struct s_link	*next;
	int				flow;
}				t_link;

typedef struct s_ptheads
{
	struct s_path	*path;
	int				totalRooms;
	int id;
	int len;
	int ants;
	int status;
	struct s_ptheads *next;
}				t_ptheads;

typedef struct	s_path
{
	struct s_room	*room;
	struct s_path	*next;
	int status;
	int				ant_id;
}				t_path;

typedef struct	s_room
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
	int				correctionRoom;
}				t_room;

typedef struct s_ant_opt
{
	int id;
	int antsnb;
	int antsnb_org;
	int nbrpaths;
	int ret;
	int flag;
}				t_ant_opt;

typedef struct	s_pathGroup
{
	struct s_ptheads	*head;
	struct s_pathGroup	*next;
	int					groupNumber;
	int					totalRoomsInGroup;
	int					totalHeads;
	int					score;
}				t_pathGroup;


typedef struct s_env
{
	t_room		**room;	 
	t_room		*start;	 
	t_room		*end;	 
	t_room		*ptr;	 
	t_link		*lnk;	 
	t_pathGroup	*pathGroup; 
	t_pathGroup	*pthGrp; 
	t_pathGroup	*bestGroup; 
	t_ptheads	*ptheads;
	t_ptheads	*pthds;	 
	t_path		*path;	 
	t_path		*pth;	 
	t_inp		*inp;	 
	char		*tmp;
	int			antsnb;
	int			iteration_nb;
	int			nbrooms;
	int			retry;
	int			second_call;
	int			nbrpaths;
	int			totallen;
	int			index;
	int			section;
	int			startEndLinked;
	int			groupNb;
	int			bestScore;
}				t_env;

void	liberate_memory(t_env *env);
int		check_error(t_inp **inp, char **line, int *section);
void	input_to_list(t_env *env);
int		save_input(t_env *env);
int		get_index(int max, char *str);
int		bfs(t_env *env, int follow, t_room *start);
t_room	*get_room(t_env *env, char *room);
void    initialize_var(t_env *env);
int		path_generator(t_env *env, t_room *start);
void	delete_heads_rest(t_ptheads *pthds);
void	delete_path_rest(t_path *ptr);
void	set_antsnb(t_inp **inp, t_env *env);

void ft_calc_ants(t_env *env);
int ft_select_path(t_env *env, int next_len, int avg_len);
void ft_select_paths(t_env *env, t_ptheads *current, int avg_len);
void ft_move_ants_lip(t_ptheads *path, t_ant_opt *opt);
void ft_move_ants_trip(t_ptheads *paths, t_ptheads *pivot, t_ant_opt opt, int start);
int ft_print_ants(t_path *path, int *flag);

int		ft_str_is_num(char *str);
int		ft_str_is_name(char *str);

void	setOnePath(t_env *env);
void    setDeptLayers(t_env *env);
void	MoveBackToFirstPossibleStart(t_env *env, t_room *room);
void	verifyReverseLink(t_env *env, t_link *lnk, t_room *rm);

#endif
