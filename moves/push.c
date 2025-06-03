/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rodantec <rodantec@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 16:21:39 by rodantec          #+#    #+#             */
/*   Updated: 2025/04/11 12:29:59 by rodantec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_push(t_lst **lst_a, t_lst **lst_b)
{
	t_lst	*head_a;

	head_a = *lst_a;
	*lst_a = head_a->next;
	ft_lstadd_front(lst_b, head_a);
}

void	pa(t_lst **lst_a, t_lst **lst_b)
{
	if ((*lst_a) == NULL)
		return ;
	ft_push(lst_a, lst_b);
	ft_printf("pa\n");
	return ;
}

void	pb(t_lst **lst_b, t_lst **lst_a)
{
	if ((*lst_b) == NULL)
		return ;
	ft_push(lst_b, lst_a);
	ft_printf("pb\n");
	return ;
}
