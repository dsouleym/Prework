/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsouleym <dsouleym@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/27 05:09:59 by dsouleym          #+#    #+#             */
/*   Updated: 2016/02/09 13:59:12 by dsouleym         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	de;

	i = 0;
	de = 0;
	while (dst[de] != '\0' && de < size)
		de++;
	while (src[i] != '\0' && i + de < size - 1)
	{
		dst[i + de] = src[i];
		i++;
	}
	if (de < size)
		dst[i + de] = '\0';
	return (de + ft_strlen(src));
}
