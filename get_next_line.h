/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lessie <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/12 14:12:52 by lessie            #+#    #+#             */
/*   Updated: 2020/11/15 23:11:07 by lessie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <sys/types.h>
# include <sys/uio.h>
# include <unistd.h>
# include <stdlib.h>

typedef struct		s_lst
{
	int				fd;
	int				eof;
	char			*delim;
	struct s_lst	*prev;
	struct s_lst	*next;
}					t_lst;

int					get_next_line(int fd, char **line);
int					ft_freelst(t_lst **head, t_lst *lst);
char				*ft_strjoin(char const *s1, char const *s2);
t_lst				*ft_newlst(const int fd);
int					ft_readfd(t_lst **head, t_lst *lst, char **line);
int					ft_readdelim(t_lst **head, t_lst *lst, char **line);
int					ft_strchr(char *str, int c);
char				*ft_new_zerostr(int len);
void				ft_fillzero(char *str, int len);
char				*ft_strcpy(char *dst, char *src);

#endif
