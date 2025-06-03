/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_parsing.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rodantec <rodantec@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 16:21:47 by rodantec          #+#    #+#             */
/*   Updated: 2025/04/16 08:52:39 by rodantec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	ft_longlongnum(char **array)
{
	int			i;
	long long	num;

	i = 0;
	while (array[i])
	{
		num = ft_atol(array[i]);
		if (num == LLONG_MAX)
			return (1);
		i++;
	}
	return (0);
}

int	ft_strisdigit(char *str)
{
	int	i;

	i = 0;
	if (str == NULL)
		return (0);
	if (str[i] == '-')
		i++;
	while (str[i])
	{
		if (str[i] == ' ')
			i++;
		if ((str[i] < '0' || str[i] > '9'))
			return (1);
		i++;
	}
	return (0);
}

int	check_array_digit(char **array)
{
	int	i;

	i = 0;
	if (array == NULL)
		return (1);
	while (array[i])
	{
		if (ft_strisdigit(array[i]) == 1)
			return (1);
		i++;
	}
	return (0);
}

int	ft_isduplicate(char **array)
{
	int	i;
	int	num;
	int	j;

	i = 0;
	while (array[i])
	{
		num = ft_atoi(array[i]);
		j = i + 1;
		while (array[j])
		{
			if (num == ft_atoi(array[j]))
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	ft_error(char **array)
{
	if (!array || !array[0])
		return (0);
	if (ft_isduplicate(array) == 1 || check_array_digit(array) == 1
		|| ft_strisdigit(array[1]) == 1 || ft_longlongnum(array) == 1)
		return (1);
	return (0);
}
