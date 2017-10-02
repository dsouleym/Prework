/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsouleym <dsouleym@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/27 08:23:00 by dsouleym          #+#    #+#             */
/*   Updated: 2016/11/10 17:12:48 by dsouleym         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int	ft_strlen_mod(char const *s)
{
	int	i;

	i = 0;
	while ((s[i] == ' ' || s[i] == '\t' || s[i] == '\n') && s[i] != '\0')
		i++;
	return (i);
}

char		*ft_strtrim(char const *s)
{
	int		i;
	int		j;
	char	*str;
	int		k;

	k = 0;
	if (s == NULL)
		return (NULL);
	i = ft_strlen_mod(s);
	j = ft_strlen(s);
	while ((s[j - 1] == ' ' || s[j - 1] == '\t' || s[j - 1] == '\n') && j > i)
		j--;
	str = (char*)malloc(sizeof(char) * ((j - i) + 1));
	if (str == NULL)
		return (NULL);
	str[j - i] = '\0';
	while (k + i < j)
	{
		str[k] = ((char*)s)[i + k];
		k++;
	}
	return (str);
}
