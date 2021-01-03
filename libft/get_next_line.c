#include "get_next_line.h"

# define BUFFSZ 1000
# define L 5000
# define TMP 5001
# define BS BUFFSZ

int	get_next_line(const int fd, char **line)
{
	int			r;
	char		b[BUFFSZ + 1];
	static char	*re[5002];

	if (!line || fd < 0 || fd > L || !(re[fd] = re[fd] ? re[fd] : ft_strnew(0)))
		return (-1);
	r = 1;
	while (!(re[L] = ft_strchr(re[fd], '\n')) &&
			(r = read(fd, b, BS)) > 0)
	{
		re[TMP] = re[fd];
		b[r] = 0;
		re[fd] = ft_strjoin(re[fd], b);
		free(re[TMP]);
		if (!re[fd])
			return (-1);
	}
	*line = ft_strsub(re[fd], 0, (re[L] ? re[L] - re[fd] : ft_strlen(re[fd])));
	re[TMP] = re[fd];
	re[fd] = r > 0 ? ft_strdup(re[L] + 1) : NULL;
	free(re[TMP]);
	if ((!re[fd] && re[L] && re[L][1]) || !*line)
		return (-1);
	return (**line || re[L] ? 1 + (r == 0) : r);
}