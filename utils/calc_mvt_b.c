/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_mvt_b.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rodantec <rodantec@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 12:18:20 by rodantec          #+#    #+#             */
/*   Updated: 2025/04/11 11:50:08 by rodantec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	calc_mvt_rarb_b(t_lst **lst_a, t_lst **lst_b, t_cost *cost)
{
	int	i;

	i = ft_find_index_b(*lst_b, cost->value);
	if (i < find_index_of_element(*lst_a, cost->value))
		i = find_index_of_element(*lst_a, cost->value);
	if (cost->min > i)
	{
		cost->min = i;
		cost->position = cost->value;
		cost->mvt = RR;
		return (1);
	}
	return (0);
}

int	calc_mvt_rarrb_b(t_lst **lst_a, t_lst **lst_b, t_cost *cost)
{
	int	i;

	i = 0;
	if (ft_find_index_b(*lst_b, cost->value))
		i = ft_lstsize(*lst_b) - ft_find_index_b(*lst_b, cost->value);
	i += find_index_of_element(*lst_a, cost->value);
	if (cost->min > i)
	{
		cost->min = i;
		cost->position = cost->value;
		cost->mvt = RARRB;
		return (1);
	}
	return (0);
}

int	calc_mvt_rrarb_b(t_lst **lst_a, t_lst **lst_b, t_cost *cost)
{
	int	i;

	i = 0;
	if (find_index_of_element(*lst_a, cost->value))
		i = ft_lstsize(*lst_a) - find_index_of_element(*lst_a, cost->value);
	i += ft_find_index_b(*lst_b, cost->value);
	if (cost->min > i)
	{
		cost->min = i;
		cost->position = cost->value;
		cost->mvt = RRARB;
		return (1);
	}
	return (0);
}

int	calc_mvt_rrarrb_b(t_lst **lst_a, t_lst **lst_b, t_cost *cost)
{
	int	i;

	i = 0;
	if (ft_find_index_b(*lst_b, cost->value))
		i = ft_lstsize(*lst_b) - ft_find_index_b(*lst_b, cost->value);
	if ((i < (ft_lstsize(*lst_a) - find_index_of_element(*lst_a, cost->value)))
		&& find_index_of_element(*lst_a, cost->value))
		i = ft_lstsize(*lst_a) - find_index_of_element(*lst_a, cost->value);
	if (cost->min > i)
	{
		cost->min = i;
		cost->position = cost->value;
		cost->mvt = RRR;
		return (1);
	}
	return (0);
}
