/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rodantec <rodantec@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 16:21:37 by rodantec          #+#    #+#             */
/*   Updated: 2025/04/11 12:31:38 by rodantec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_revrotate(t_lst **lst)
{
	t_lst	*last;
	t_lst	*second_last;

	if (*lst == NULL || (*lst)->next == NULL)
		return ;
	last = *lst;
	while (last->next != NULL)
	{
		second_last = last;
		last = last->next;
	}
	second_last->next = NULL;
	last->next = *lst;
	*lst = last;
}

void	rra(t_lst **lst_a)
{
	if ((*lst_a) == NULL && (*lst_a)->next == NULL)
		return ;
	ft_revrotate(lst_a);
	ft_printf("rra\n");
	return ;
}

void	rrb(t_lst **lst_b)
{
	if ((*lst_b) == NULL || (*lst_b)->next == NULL)
		return ;
	ft_revrotate(lst_b);
	ft_printf("rrb\n");
	return ;
}

void	rrr(t_lst **lst_a, t_lst **lst_b)
{
	if ((*lst_b) == NULL || (*lst_b)->next == NULL)
		return ;
	ft_revrotate(lst_a);
	ft_revrotate(lst_b);
	ft_printf("rrr\n");
	return ;
}
