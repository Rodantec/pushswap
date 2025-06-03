/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rodantec <rodantec@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 16:21:50 by rodantec          #+#    #+#             */
/*   Updated: 2025/04/16 08:45:17 by rodantec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	freesplit(char **split)
{
	int	i;

	i = 0;
	while (split[i])
	{
		free(split[i]);
		i++;
	}
	free(split);
	return ;
}

t_lst	*simple_arg(char *str)
{
	int			i;
	char		**split;
	t_lst		*lsta;
	long long	num;

	i = 0;
	lsta = NULL;
	split = ft_split(str, ' ');
	if (ft_error(split) == 1)
		return (freesplit(split), ft_printf("Error\n"), NULL);
	if (split)
	{
		while (split[i])
		{
			num = ft_atol(split[i]);
			ft_lstdd_back(&lsta, ft_lstnew(num));
			free(split[i]);
			i++;
		}
		free(split);
	}
	return (lsta);
}

t_lst	*multiple_arg(char **array)
{
	int			i;
	t_lst		*lsta;
	long long	num;

	i = 0;
	lsta = NULL;
	if (ft_error(array) == 1)
		return (ft_printf("Error\n"), NULL);
	while (array[i])
	{
		num = ft_atoi(array[i]);
		ft_lstdd_back(&lsta, ft_lstnew(num));
		i++;
	}
	return (lsta);
}
