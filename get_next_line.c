/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lessie <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/12 14:53:06 by lessie            #+#    #+#             */
/*   Updated: 2020/11/18 10:44:44 by lessie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		get_next_line(int fd, char **line)
{
	static t_lst	*head;
	t_lst			*tmp;

	if (fd < 0 || !line || (BUFFER_SIZE <= 0))
		return (-1);
	if (!head)
		if (!(head = ft_newlst(fd)))
			return (-1);
	tmp = head;
	while (tmp->fd != fd)
	{
		if (tmp->next == NULL)
		{
			if (!(tmp->next = ft_newlst(fd)))
				return (ft_freelst(&head, tmp) - 1);
			tmp->next->prev = tmp;
		}
		tmp = tmp->next;
	}
	if (!(*line = ft_new_zerostr(0)))
		return (ft_freelst(&head, tmp) - 1);
	if (tmp->delim[0] == '\0' && tmp->eof == 0)
		return (ft_readfd(&head, tmp, line));
	else
		return (ft_readdelim(&head, tmp, line));
}

int		ft_freelst(t_lst **head, t_lst *lst)
{
	free(lst->delim);
	if (lst->prev == NULL)
		if (lst->next != NULL)
		{
			*head = lst->next;
			lst->next->prev = NULL;
		}
		else
			*head = NULL;
	else if (lst->next == NULL)
		lst->prev->next = NULL;
	else
	{
		lst->prev->next = lst->next;
		lst->next->prev = lst->prev;
	}
	free(lst);
	return (0);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char			*new_s;
	unsigned int	i;
	unsigned int	j;
	unsigned int	s1_len;
	unsigned int	s2_len;

	if (!s1 || !s2)
		return (NULL);
	new_s = NULL;
	s1_len = 0;
	s2_len = 0;
	while (s1[s1_len])
		s1_len++;
	while (s2[s2_len])
		s2_len++;
	i = -1;
	j = -1;
	if (!(new_s = (char *)malloc(sizeof(char) * (s1_len + s2_len + 1))))
		return (NULL);
	while (++i < s1_len)
		new_s[i] = s1[i];
	while (++j < s2_len)
		new_s[i + j] = s2[j];
	new_s[i + j] = '\0';
	return (new_s);
}

int		ft_strchr(char *str, int c)
{
	char	ch;
	int		i;

	ch = (char)c;
	i = 0;
	while (str[i] != ch && str[i] != '\0')
		i++;
	if (str[i] == ch)
	{
		str[i] = '\0';
		return (i);
	}
	else
		return (-1);
}

char	*ft_strcpy(char *dst, char *src)
{
	int i;

	i = 0;
	while (src[i])
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (dst);
}
