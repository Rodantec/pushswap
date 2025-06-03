/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rodantec <rodantec@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 16:27:24 by rodantec          #+#    #+#             */
/*   Updated: 2025/04/11 12:26:57 by rodantec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	move_min_to_top(t_lst **lst_a)
{
	int	min;
	int	size;
	int	index;

	min = find_min(*lst_a);
	size = ft_lstsize(*lst_a);
	index = find_index_of_element(*lst_a, min);
	if (index <= size / 2)
	{
		while (index > 0)
		{
			ra(lst_a);
			index--;
		}
	}
	else
	{
		while (index++ < size)
			rra(lst_a);
	}
}
