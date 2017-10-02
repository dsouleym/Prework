/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsouleym <dsouleym@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/27 05:11:30 by dsouleym          #+#    #+#             */
/*   Updated: 2016/02/06 17:32:42 by dsouleym         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *big, const char *little)
{
	char	*s;
	char	*to;

	if (*little == '\0')
		return ((char*)big);
	to = (char*)little;
	while (*big != '\0')
	{
		if (*big == *to)
		{
			s = (char*)big;
			while (*s == *to || *to == '\0')
			{
				if (*to == '\0')
					return ((char*)big);
				s++;
				to++;
			}
			to = (char*)little;
		}
		big++;
	}
	return (0);
}
