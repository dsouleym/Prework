/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsouleym <dsouleym@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/22 15:12:42 by dsouleym          #+#    #+#             */
/*   Updated: 2017/03/03 14:15:22 by dsouleym         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_negative(char *str)
{
	if (str && str[0] == '-')
		return (-1);
	return (1);
}

int			ft_getnbr(char *str)
{
	int is_neg;
	int	i;
	int	ret;
	int i_start;

	i_start = 0;
	i = 0;
	ret = 0;
	is_neg = 0;
	while (str[i] && str[i] == ' ')
		i++;
	if ((is_neg = is_negative(&str[i]) == -1))
		i++;
	i_start = i;
	while (str[i] && str[i] >= '0' && str[i] <= '9' && i_start < 3)
	{
		i_start++;
		ret = (ret * 10) + str[i] - '0';
		i++;
	}
	if (is_neg)
		ret = -ret;
	return (ret);
}
