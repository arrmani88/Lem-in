#include "../includes/lem-in.h"

void ft_calc_ants(t_env *env)
{
    t_ptheads *tmp;

    int		i;
	int		meanlen;
	int		mod;
    t_ptheads *prev;

	meanlen = (env->antsnb + env->totallen) / env->nbrpaths;
	mod = (env->antsnb + env->totallen) % env->nbrpaths;
    tmp = env->ptheads;
    prev = tmp;
    i = -1;
	while (++i < env->nbrpaths && tmp)
	{
		tmp->ants = meanlen - tmp->len + (mod > 0);
		mod--;
        prev = tmp; 
        tmp = tmp->next;
	}
    if (tmp)
    {
        // ft_free_queue(&tmp, 0);
        prev->next = NULL;
    }
}

void ft_move_ants(t_path *path, int *antsnb)
{
    if (*antsnb < 0 || !path)
        return ;
    ft_move_ants(path->next, antsnb);
    path->status = NONE;
    if (!(path->next) && path->ant_id > 0)
    {
        path->ant_id = 0;
        (*antsnb)--;
    }
    else if (path->next && path->ant_id > 0)
    {
        path->next->ant_id = path->ant_id;
        path->ant_id = 0;
    }
}

int ft_print_ants(t_path *path, int *flag)
{
    int ret;

    if (!path || (path && path->status == PRINTED))
        return (0);
    if (path && path->ant_id == -1)
        return (1);
    ret = ft_print_ants(path->next, flag);
    if (ret != 2 && path->ant_id > 0)
    {
        path->status = PRINTED;
        printf("L%u-%s ", path->ant_id, path->room->name);
        return (2);
    }
    else if (path->ant_id > 0 && path->status != PRINTED)
        *flag = 1;
    path->status = PASSED;
    return (ret);
}

void ft_move_ants_lip(t_ptheads *path, t_ant_opt *opt)
{
    if (!path)
        return ;
    ft_move_ants(path->path->next, &(opt->antsnb));
    if (opt->id <= opt->antsnb_org && path->ants > 0)
    {
        path->path->next->ant_id = ++(opt->id);
        path->ants--;
    }
    ft_move_ants_lip(path->next, opt);
}

void ft_move_ants_trip(t_ptheads *paths, t_ptheads *pivot, t_ant_opt opt, int start)
{
    
    opt.ret = ft_print_ants(pivot->path->next, &(opt.flag));
    if (!(pivot->next) && !(opt.flag))
    {
        ft_move_ants_lip(paths, &opt);
        printf("\n");
    }
    
    if (!(pivot->next) && opt.flag)
        opt.flag = 0;

    if (opt.antsnb == 0)
        return ;
  
    ft_move_ants_trip(paths, (pivot->next) ? pivot->next : paths, opt, 0);
}

int ft_select_path(t_env *env, int next_len, int avg_len)
{
    int				i;
	unsigned int	meanlen;
    int             totallen;
	int				mod;
	int				ret;
    t_ptheads *tmp;

	totallen = avg_len + next_len;
	meanlen = totallen / (env->nbrpaths + 1);
	mod = totallen % (env->nbrpaths + 1);
	ret = env->antsnb;
	if (env->nbrpaths && avg_len / env->nbrpaths < meanlen)
		return (0);
	i = -1;
    tmp = env->ptheads;
	while (++i < env->nbrpaths && tmp)
	{
		ret -= meanlen - tmp->len + (mod > 0);
		mod--;
        tmp = tmp->next;
	}
    return (ret > 0);
}

int ft_links_lenght(t_path *path)
{
    int i;

    i = 0;
    while(path)
    {
        i++;
        path->ant_id = 0;
        path = path->next;
    }
    return (i);
}

void ft_select_paths(t_env *env, t_ptheads *current, int avg_len)
{
    if (!current)
        return ;
    current->len = ft_links_lenght(current->path) - 2;
    if (!ft_select_path(env, current->len, avg_len))
        return ;
    if (avg_len == 0)
        avg_len += env->antsnb;
    env->totallen += current->len;
    avg_len += current->len;
    env->nbrpaths++;
	ft_select_paths(env, current->next, avg_len);
}
