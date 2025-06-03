/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rodantec <rodantec@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 16:21:34 by rodantec          #+#    #+#             */
/*   Updated: 2025/04/11 12:31:56 by rodantec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_rotate(t_lst **lst)
{
	t_lst	*head;
	t_lst	*last;
	t_lst	*second;

	if ((*lst) == NULL || (*lst)->next == NULL)
		return ;
	head = *lst;
	second = head->next;
	last = *lst;
	while (last->next != NULL)
		last = last->next;
	*lst = second;
	last->next = head;
	head->next = NULL;
}

void	ra(t_lst **lst_a)
{
	if ((*lst_a) == NULL && (*lst_a)->next == NULL)
		return ;
	ft_rotate(lst_a);
	ft_printf("ra\n");
	return ;
}

void	rb(t_lst **lst_b)
{
	if ((*lst_b) == NULL || (*lst_b)->next == NULL)
		return ;
	ft_rotate(lst_b);
	ft_printf("rb\n");
	return ;
}

void	rr(t_lst **lst_a, t_lst **lst_b)
{
	if ((*lst_b) == NULL || (*lst_b)->next == NULL)
		return ;
	ft_rotate(lst_a);
	ft_rotate(lst_b);
	ft_printf("rr\n");
	return ;
}
