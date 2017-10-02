/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsouleym <dsouleym@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/27 05:14:36 by dsouleym          #+#    #+#             */
/*   Updated: 2016/10/03 18:52:00 by dsouleym         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t i;

	i = 0;
	if (*little == '\0')
		return ((char*)big);
	if (ft_strlen(little) > ft_strlen(big)
			|| ft_strlen(little) > len)
		return (0);
	while (i + ft_strlen(little) < len + 1 && *big)
	{
		if (*big == *little && ft_memcmp((void*)big,
					(void*)little, ft_strlen(little)) == 0)
			return ((char*)big);
		big++;
		i++;
	}
	return (NULL);
}
