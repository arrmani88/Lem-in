/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem-in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anel-bou <anel-bou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/18 12:56:04 by anel-bou          #+#    #+#             */
/*   Updated: 2020/11/19 14:51:20 by anel-bou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
#define LEM_IN_H

#include "libft/libft.h"
#include "gnl/get_next_line.h"

#include <stdio.h> /* a supprimer */

#define ERROR	-1
#define INP_END	0
#define START	1
#define ROOM	2
#define END		3
#define	LINK	4
#define FIRST_CH 5
#define LAST_CH	6

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
	struct s_ptheads *next;
}				t_ptheads;

typedef struct	s_path
{
	struct s_room	*room;
	struct s_path	*next;
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
	int				used; /* asup */
	int				full;
	int				set_last;
}				t_room;

typedef struct s_env
{
	t_room		**room;	 //56
	t_room		*start;	 //56
	t_room		*end;	 //56
	t_room		*ptr;	 //56
	t_link		*lnk;	 //24
	t_ptheads	*ptheads;//16
	t_ptheads	*pthds;	 //16
	t_path		*path;	 //16
	t_path		*pth;	 //16
	t_inp		*inp;	 //16
	char		*tmp;
	int			antsnb;
	int			iteration_nb;
	int			nbrooms;
	int			retry;
	int			second_call;
}				t_env;

void	liberate_memory();
int		check_error(t_inp **inp, char **line);
void	input_to_list(t_env *env);
int		save_input(t_env *env);
int		get_index(int max, char *str);
int		bfs(t_env *env, int var);
t_room	*get_room(t_env *env, char *room);
void    initialize_var(t_env *env);
int		path_generator(t_env *env);
void	delete_heads_rest(t_ptheads *ptr);
void	delete_path_rest(t_path *ptr);
void	set_antsnb(t_inp **inp, t_env *env);

/*************** functions to test ******************/
void	test_loop(t_env *env, char *name);
void	print_current_queue(t_queue *qu);
void	print_path(t_path *path);
void	print_all_paths(t_env *env);
/*************** functions to test ******************/

#endif

// # error checking:
// 	+the same link 2 times

// # n3teh i9aleb 3la chi room makaynach f liste **room 
// # env->room[x]->link had liste nfreei gha nodes ama stringat blach 7it
// 	lpointer m affecti lih gha l'adresse men liste li fiha initial data
