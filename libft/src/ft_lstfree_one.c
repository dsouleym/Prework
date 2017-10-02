/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstfree.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsouleym <dsouleym@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/10 19:43:47 by dsouleym          #+#    #+#             */
/*   Updated: 2016/11/15 14:10:26 by dsouleym         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstfree_one(t_list **lst)
{
	if (lst && (*lst)->content)
		free((*lst)->content);
	if (lst)
	{
		free(*lst);
		*lst = NULL;
	}
}
