/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsouleym <dsouleym@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/27 08:10:39 by dsouleym          #+#    #+#             */
/*   Updated: 2016/01/27 19:07:06 by dsouleym         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	void	*v;
	size_t	i;

	v = malloc(size);
	i = 0;
	if (v)
		v = ft_memset(v, 0, size);
	return (v);
}
