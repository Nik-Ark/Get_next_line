#include "get_next_line.h"

t_lst	*ft_newlst(const int fd)
{
	t_lst	*new;

	if (!(new = (t_lst *)malloc(sizeof(t_lst))))
		return (NULL);
	new->fd = fd;
	new->eof = 0;
	if (!(new->delim = ft_new_zerostr(BUFFER_SIZE + 1)))
		return (NULL);
	new->prev = NULL;
	new->next = NULL;
	return (new);
}

int		ft_readfd(t_lst **head, t_lst *lst, char **line)
{
	char	buf[BUFFER_SIZE + 1];
	int		newln_index;
	char	*tmp;
	int		ret;

	tmp = NULL;
	while ((ret = read(lst->fd, buf, BUFFER_SIZE)) > 0)
	{
		buf[ret] = '\0';
		if ((newln_index = ft_strchr(buf, '\n')) >= 0)
			lst->delim = ft_strcpy(lst->delim, &buf[newln_index + 1]);
		tmp = *line;
		if (!(*line = ft_strjoin(*line, buf)))
			return ((ft_freelst(head, lst)) - 1);
		free(tmp);
		if (newln_index >= 0)
			break ;
	}
	if (ret == -1)
		return ((ft_freelst(head, lst)) - 1);
	if (ret == 0)
		lst->eof = 1;
	if (ret == 0 && lst->delim[0] == '\0')
		return (ft_freelst(head, lst));
	return (1);
}

int		ft_readdelim(t_lst **head, t_lst *lst, char **line)
{
	int		newln_index;
	char	*tmp;

	tmp = NULL;
	if ((newln_index = ft_strchr(lst->delim, '\n')) >= 0)
	{
		tmp = *line;
		if (!(*line = ft_strjoin(*line, lst->delim)))
			return (ft_freelst(head, lst) - 1);
		free(tmp);
		lst->delim = ft_strcpy(lst->delim, &lst->delim[newln_index + 1]);
		if (lst->eof == 1 && lst->delim[0] == '\0')
			return (ft_freelst(head, lst));
		return (1);
	}
	tmp = *line;
	if (!(*line = ft_strjoin(*line, lst->delim)))
		return (ft_freelst(head, lst) - 1);
	free(tmp);
	if (lst->eof == 1)
		return (ft_freelst(head, lst));
	ft_fillzero(lst->delim, BUFFER_SIZE + 1);
	return (ft_readfd(head, lst, line));
}

char	*ft_new_zerostr(int len)
{
	char	*str;

	str = NULL;
	if (!(str = (char *)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	ft_fillzero(str, (len + 1));
	return (str);
}

void	ft_fillzero(char *str, int len)
{
	int		i;

	i = 0;
	while (i < len)
	{
		str[i] = '\0';
		i++;
	}
}
