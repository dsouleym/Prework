/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim_char.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsouleym <dsouleym@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/10 15:00:24 by dsouleym          #+#    #+#             */
/*   Updated: 2016/11/10 17:19:22 by dsouleym         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int	ft_strlen_ch(char const *s, char const c)
{
	int i;

	i = 0;
	while (s[i] == c && s[i])
		i++;
	return (i);
}

char		*ft_strtrim_char(char const *s, char const c)
{
	int		i;
	int		j;
	char	*str;
	int		k;

	k = 0;
	if (s == NULL)
		return (NULL);
	i = ft_strlen_ch(s, c);
	j = ft_strlen(s);
	while (s[j - 1] == c && j > i)
		j--;
	str = (char*)malloc(sizeof(char) * ((j - i) + 1));
	str[j - i] = '\0';
	while (k + i < j)
	{
		str[k] = s[i + k];
		k++;
	}
	return (str);
}
