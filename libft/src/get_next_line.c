/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsouleym <dsouleym@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/10 18:22:49 by dsouleym          #+#    #+#             */
/*   Updated: 2017/03/03 14:09:37 by dsouleym         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*get_remain(t_list *list, const int fd)
{
	char	*tmp;
	t_list	*prev;

	while (list && list->content_size != (size_t)fd)
	{
		prev = list;
		list = list->next;
	}
	if (list && list->content)
	{
		tmp = ft_strdup(list->content);
		ft_strdel((char**)(&(list->content)));
		return (tmp);
	}
	else if (!list)
	{
		prev->next = ft_lstnew(NULL, 0);
		prev->next->content_size = (size_t)fd;
	}
	return (NULL);
}

static char	*stock_ret(char *buf, char *to_ret, int ret)
{
	char	*tmp;

	if (ret < 0)
		return (to_ret);
	if (to_ret == NULL)
		return (ft_strdup(buf));
	else
	{
		tmp = to_ret;
		to_ret = ft_strjoin(to_ret, buf);
		free(tmp);
		return (to_ret);
	}
}

static char	*stock_remain(t_list **lst, size_t fd, char *to_ret)
{
	t_list	*new;
	char	*tmp;

	new = *lst;
	while (new->content_size != fd && new)
		new = new->next;
	if (ft_strchr(to_ret, '\n'))
	{
		new->content = ft_strdup(ft_strchr(to_ret, '\n') + 1);
		if (ft_strcmp((const char*)new->content, "\0") == 0)
			ft_strdel((char**)(&(new->content)));
	}
	if (ft_strchr(to_ret, '\n'))
	{
		tmp = ft_strsub(to_ret, 0, ft_strlen_char(to_ret, '\n'));
		free(to_ret);
	}
	else
		tmp = to_ret;
	return (tmp);
}

static void	ft_del_this_one(t_list **list, size_t fd)
{
	t_list *prev;

	prev = (*list);
	while ((*list)->content_size != fd && list)
	{
		prev = (*list);
		(*list) = (*list)->next;
	}
	if (list)
	{
		if (prev == (*list))
		{
			*list = prev->next;
			ft_lstfree_one(&prev);
		}
		else
		{
			prev->next = (*list)->next;
			ft_lstfree_one(list);
		}
	}
}

int			get_next_line(const int fd, char **line)
{
	static t_list	*list = NULL;
	int				ret;
	char			buf[BUFF_SIZE + 1];
	char			*to_ret;

	if (!list)
	{
		list = ft_lstnew(NULL, 0);
		list->content_size = (size_t)fd;
	}
	to_ret = get_remain(list, (const int)fd);
	while (!ft_strchr(to_ret, '\n') && (ret = read(fd, buf, BUFF_SIZE)) > 0)
	{
		buf[ret] = '\0';
		to_ret = stock_ret(buf, to_ret, ret);
	}
	if (ret == 0 && to_ret == NULL)
	{
		ft_del_this_one(&list, (size_t)fd);
		return (0);
	}
	if (ret == -1)
		return (-1);
	*line = stock_remain(&list, (size_t)fd, to_ret);
	return (1);
}
