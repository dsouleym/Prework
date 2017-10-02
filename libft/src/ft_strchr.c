/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsouleym <dsouleym@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/27 05:09:37 by dsouleym          #+#    #+#             */
/*   Updated: 2016/11/11 11:21:32 by dsouleym         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	size_t	i;

	i = 0;
	if (!s)
		return (NULL);
	if (c == '\0')
		return (&(((char*)s)[ft_strlen(s)]));
	while (s[i] != '\0')
	{
		if (s[i] == (char)c)
			return (&((char*)s)[i]);
		i++;
	}
	return (NULL);
}
