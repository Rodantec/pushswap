/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rodantec <rodantec@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 16:21:30 by rodantec          #+#    #+#             */
/*   Updated: 2025/04/11 12:32:05 by rodantec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_swap(t_lst **lst)
{
	t_lst	*head;
	t_lst	*next;
	int		tmp_val;

	if ((*lst) == NULL || (*lst)->next == NULL)
		return ;
	head = *lst;
	next = head->next;
	tmp_val = (int)head->content;
	head->content = next->content;
	next->content = tmp_val;
	return ;
}

void	sa(t_lst **lst_a)
{
	if ((*lst_a) == NULL || (*lst_a)->next == NULL)
		return ;
	ft_swap(lst_a);
	ft_printf("sa\n");
	return ;
}

void	sb(t_lst **lst_b)
{
	if ((*lst_b) == NULL || (*lst_b)->next == NULL)
		return ;
	ft_swap(lst_b);
	ft_printf("sb\n");
	return ;
}

void	ss(t_lst **lst_a, t_lst **lst_b)
{
	if ((*lst_b) == NULL || (*lst_b)->next == NULL)
		return ;
	if ((*lst_a) == NULL || (*lst_a)->next == NULL)
		return ;
	ft_swap(lst_a);
	ft_swap(lst_b);
	ft_printf("ss\n");
	return ;
}
