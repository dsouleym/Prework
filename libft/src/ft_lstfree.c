/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstfree.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsouleym <dsouleym@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/10 19:50:25 by dsouleym          #+#    #+#             */
/*   Updated: 2016/11/10 19:52:23 by dsouleym         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstfree(t_list **lst)
{
	t_list *tmp;

	while (*lst)
	{
		tmp = (*lst)->next;
		ft_lstfree_one(lst);
		(*lst) = tmp;
	}
}
