/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_mvt.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rodantec <rodantec@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 13:06:11 by rodantec          #+#    #+#             */
/*   Updated: 2025/04/11 11:52:47 by rodantec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	apply_rarb_mvt(t_lst **lst_a, t_lst **lst_b, t_move_params params)
{
	if (params.direction == 0)
	{
		while ((*lst_a)->content != params.position && ft_find_index_b(*lst_b,
				params.position) > 0)
			rr(lst_a, lst_b);
		while ((*lst_a)->content != params.position)
			ra(lst_a);
		while (ft_find_index_b(*lst_b, params.position) > 0)
			rb(lst_b);
		pb(lst_a, lst_b);
	}
	if (params.direction == 1)
	{
		while ((*lst_b)->content != params.position && ft_find_index_a(*lst_a,
				params.position) > 0)
			rr(lst_a, lst_b);
		while ((*lst_b)->content != params.position)
			rb(lst_b);
		while (ft_find_index_a(*lst_a, params.position) > 0)
			ra(lst_a);
		pa(lst_b, lst_a);
	}
}

void	apply_rarrb_mvt(t_lst **lst_a, t_lst **lst_b, t_move_params params)
{
	if (params.direction == 0)
	{
		while ((*lst_a)->content != params.position)
			ra(lst_a);
		while (ft_find_index_b(*lst_b, params.position) > 0)
			rrb(lst_b);
		pb(lst_a, lst_b);
	}
	if (params.direction == 1)
	{
		while (ft_find_index_a(*lst_a, params.position) > 0)
			ra(lst_a);
		while ((*lst_b)->content != params.position)
			rrb(lst_b);
		pa(lst_b, lst_a);
	}
}

void	apply_rrarb_mvt(t_lst **lst_a, t_lst **lst_b, t_move_params params)
{
	if (params.direction == 0)
	{
		while ((*lst_a)->content != params.position)
			rra(lst_a);
		while (ft_find_index_b(*lst_b, params.position) > 0)
			rb(lst_b);
		pb(lst_a, lst_b);
	}
	if (params.direction == 1)
	{
		while (ft_find_index_a(*lst_a, params.position) > 0)
			rra(lst_a);
		while ((*lst_b)->content != params.position)
			rb(lst_b);
		pa(lst_b, lst_a);
	}
}

void	apply_rrarrb_mvt(t_lst **lst_a, t_lst **lst_b, t_move_params params)
{
	if (params.direction == 0)
	{
		while ((*lst_a)->content != params.position && ft_find_index_b(*lst_b,
				params.position) > 0)
			rrr(lst_a, lst_b);
		while ((*lst_a)->content != params.position)
			rra(lst_a);
		while (ft_find_index_b(*lst_b, params.position) > 0)
			rrb(lst_b);
		pb(lst_a, lst_b);
	}
	if (params.direction == 1)
	{
		while ((*lst_b)->content != params.position && ft_find_index_a(*lst_a,
				params.position) > 0)
			rrr(lst_a, lst_b);
		while ((*lst_b)->content != params.position)
			rrb(lst_b);
		while (ft_find_index_a(*lst_a, params.position) > 0)
			rra(lst_a);
		pa(lst_b, lst_a);
	}
}

void	apply_movement(t_lst **lst_a, t_lst **lst_b, t_move_params params)
{
	if (params.mvt == RR)
		apply_rarb_mvt(lst_a, lst_b, params);
	else if (params.mvt == RARRB)
		apply_rarrb_mvt(lst_a, lst_b, params);
	else if (params.mvt == RRARB)
		apply_rrarb_mvt(lst_a, lst_b, params);
	else if (params.mvt == RRR)
		apply_rrarrb_mvt(lst_a, lst_b, params);
}
