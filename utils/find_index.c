/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rodantec <rodantec@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 16:21:54 by rodantec          #+#    #+#             */
/*   Updated: 2025/04/11 12:24:59 by rodantec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	find_min(t_lst *lst)
{
	int	min;

	min = lst->content;
	while (lst)
	{
		if (lst->content < min)
			min = lst->content;
		lst = lst->next;
	}
	return (min);
}

int	find_max(t_lst *lst)
{
	int	max;

	max = lst->content;
	while (lst)
	{
		if (lst->content > max)
			max = lst->content;
		lst = lst->next;
	}
	return (max);
}

int	find_index_of_element(t_lst *lst, int content)
{
	int	index;

	index = 0;
	while (lst)
	{
		if (lst->content == content)
			return (index);
		index++;
		lst = lst->next;
	}
	return (-1);
}

int	ft_find_index_a(t_lst *lst_a, int content_push)
{
	int		i;
	t_lst	*tmp;

	i = 0;
	if (content_push < lst_a->content
		&& content_push > ft_lstlast(lst_a)->content)
		return (0);
	if (content_push > find_max(lst_a) || content_push < find_min(lst_a))
		return (find_index_of_element(lst_a, find_min(lst_a)));
	i = 1;
	tmp = lst_a->next;
	while (tmp != NULL)
	{
		if (lst_a->content <= content_push && tmp->content >= content_push)
			break ;
		lst_a = lst_a->next;
		tmp = lst_a->next;
		if (tmp == NULL)
			break ;
		i++;
	}
	return (i);
}

int	ft_find_index_b(t_lst *lst_b, int content)
{
	t_lst	*tmp;
	int		i;

	if (content > lst_b->content && content < ft_lstlast(lst_b)->content)
		return (0);
	if (content > find_max(lst_b) || content < find_min(lst_b))
		return (find_index_of_element(lst_b, find_max(lst_b)));
	i = 1;
	tmp = lst_b->next;
	while (lst_b->content < content || tmp->content > content)
	{
		lst_b = lst_b->next;
		tmp = lst_b->next;
		i++;
	}
	return (i);
}
