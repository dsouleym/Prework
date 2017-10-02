/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsouleym <dsouleym@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/27 08:22:40 by dsouleym          #+#    #+#             */
/*   Updated: 2016/10/03 19:10:47 by dsouleym         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	char	*str;
	size_t	i;

	i = 0;
	str = (char*)malloc(sizeof(char) * (size + 1));
	if (str)
	{
		str[size] = '\0';
		while (str[i] != '\0')
		{
			str[i] = '\0';
			i++;
		}
	}
	return (str);
}
