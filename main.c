/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rodantec <rodantec@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 16:21:58 by rodantec          #+#    #+#             */
/*   Updated: 2025/04/16 08:49:08 by rodantec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_lst	*lst_a;
	t_lst	*lst_b;

	lst_a = NULL;
	lst_b = NULL;
	if (argc == 1)
		return (0);
	else if (argc == 2)
		lst_a = simple_arg(argv[1]);
	else if (argc >= 3)
		lst_a = multiple_arg(++argv);
	if (lst_a == NULL)
		return (0);
	if (!sorted_lst(&lst_a))
	{
		if (ft_lstsize(lst_a) == 2)
			sa(&lst_a);
		else if (ft_lstsize(lst_a) == 3)
			sorted_three(&lst_a);
		else if (ft_lstsize(lst_a) > 3)
			sort(&lst_a, &lst_b);
	}
	ft_lstclear(&lst_a);
	ft_lstclear(&lst_b);
	return (0);
}
