t_path	*select_next_path(t_env *env)
{
	if (!env->pthds && env->ptheads)
		env->pthds = env->ptheads;
	else if (env->pthds)
	{
		if (!env->pthds->next)
		{
			env->pthds = (t_ptheads *)malloc(sizeof(t_ptheads));
			env->pthds->next = NULL;
			env->pthds->path = (t_path *)malloc(sizeof(t_path));
			env->pthds->path->next = NULL;
		}
		env->pthds = env->pthds->next;
	}
	printf("select next path: %p\n", env->pthds);
	return (env->pthds->path);
}