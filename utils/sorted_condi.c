/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorted_condi.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rodantec <rodantec@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 14:23:11 by rodantec          #+#    #+#             */
/*   Updated: 2025/04/11 12:35:27 by rodantec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	sorted_lst(t_lst **lst_a)
{
	t_lst	*current;

	current = *lst_a;
	while (current && current->next)
	{
		if (current->content > current->next->content)
			return (0);
		current = current->next;
	}
	return (1);
}

void	sorted_three(t_lst **lst_a)
{
	if ((*lst_a)->content > (*lst_a)->next->next->content
		&& (*lst_a)->content > (*lst_a)->next->content)
		ra(lst_a);
	else if ((*lst_a)->next->content > (*lst_a)->content
		&& (*lst_a)->next->content > (*lst_a)->next->next->content)
		rra(lst_a);
	if ((*lst_a)->content > (*lst_a)->next->content)
		sa(lst_a);
}
