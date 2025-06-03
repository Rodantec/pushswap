/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rodantec <rodantec@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 15:00:17 by rodantec          #+#    #+#             */
/*   Updated: 2025/04/11 11:53:00 by rodantec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	move_to_b_until_3_in_a(t_lst **lst_a, t_lst **lst_b)
{
	t_lst			*current;
	t_cost			cost;
	t_move_params	params;

	while (ft_lstsize(*lst_a) > 3 && !sorted_lst(lst_a))
	{
		current = *lst_a;
		cost.min = INT_MAX;
		while (current)
		{
			cost.value = current->content;
			calc_mvt_rarb_b(lst_a, lst_b, &cost);
			calc_mvt_rrarrb_b(lst_a, lst_b, &cost);
			calc_mvt_rrarb_b(lst_a, lst_b, &cost);
			calc_mvt_rarrb_b(lst_a, lst_b, &cost);
			current = current->next;
			if (cost.min == 0)
				break ;
		}
		params.mvt = cost.mvt;
		params.position = cost.position;
		params.direction = 0;
		apply_movement(lst_a, lst_b, params);
	}
}

static void	come_back_to_stack_a(t_lst **lst_a, t_lst **lst_b)
{
	t_lst			*current;
	t_cost			cost;
	t_move_params	params;

	while (ft_lstsize(*lst_b) > 0)
	{
		current = *lst_b;
		cost.min = INT_MAX;
		while (current)
		{
			cost.value = current->content;
			calc_mvt_rarb_a(lst_a, lst_b, &cost);
			calc_mvt_rrarrb_a(lst_a, lst_b, &cost);
			calc_mvt_rrarb_a(lst_a, lst_b, &cost);
			calc_mvt_rarrb_a(lst_a, lst_b, &cost);
			current = current->next;
		}
		params.mvt = cost.mvt;
		params.position = cost.position;
		params.direction = 1;
		apply_movement(lst_a, lst_b, params);
	}
}

static void	init_lst_b(t_lst **lst_a, t_lst **lst_b)
{
	if (ft_lstsize(*lst_a) <= 3 || sorted_lst(lst_a))
		return ;
	if (ft_lstsize(*lst_a) > 3)
		pb(lst_a, lst_b);
	if (ft_lstsize(*lst_a) > 3)
		pb(lst_a, lst_b);
	if (ft_lstsize(*lst_a) > 3)
		move_to_b_until_3_in_a(lst_a, lst_b);
	if (!sorted_lst(lst_a))
		sorted_three(lst_a);
}

void	sort(t_lst **lst_a, t_lst **lst_b)
{
	if (!lst_a || !*lst_a)
		return ;
	init_lst_b(lst_a, lst_b);
	if (*lst_b)
		come_back_to_stack_a(lst_a, lst_b);
	move_min_to_top(lst_a);
}
