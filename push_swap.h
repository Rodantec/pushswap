/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rodantec <rodantec@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 12:18:23 by rodantec          #+#    #+#             */
/*   Updated: 2025/04/12 13:02:02 by rodantec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"
# include <limits.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_lst
{
	int				content;
	struct s_lst	*next;
}					t_lst;

typedef enum e_mvt
{
	RR,
	RARRB,
	RRARB,
	RRR
}					t_mvt;

typedef struct s_cost
{
	int				min;
	int				position;
	int				value;
	t_mvt			mvt;
}					t_cost;

typedef struct s_move_params
{
	t_mvt			mvt;
	int				position;
	int				direction;
}					t_move_params;

// Utility functions
int					ft_lstsize(t_lst *lst);
int					sorted_lst(t_lst **lst);
int					ft_find_index_a(t_lst *lst_a, int value);
int					ft_find_index_b(t_lst *lst_b, int value);
int					find_index_of_element(t_lst *lst, int value);
void				sorted_three(t_lst **lst_a);
void				move_min_to_top(t_lst **lst_a);

// Operations
void				sa(t_lst **lst_a);
void				sb(t_lst **lst_b);
void				ss(t_lst **lst_a, t_lst **lst_b);
void				pa(t_lst **lst_b, t_lst **lst_a);
void				pb(t_lst **lst_a, t_lst **lst_b);
void				ra(t_lst **lst_a);
void				rb(t_lst **lst_b);
void				rr(t_lst **lst_a, t_lst **lst_b);
void				rra(t_lst **lst_a);
void				rrb(t_lst **lst_b);
void				rrr(t_lst **lst_a, t_lst **lst_b);

// Cost calculation functions for stack A
int					calc_mvt_rarb_a(t_lst **lst_a, t_lst **lst_b, t_cost *cost);
int					calc_mvt_rarrb_a(t_lst **lst_a, t_lst **lst_b,
						t_cost *cost);
int					calc_mvt_rrarb_a(t_lst **lst_a, t_lst **lst_b,
						t_cost *cost);
int					calc_mvt_rrarrb_a(t_lst **lst_a, t_lst **lst_b,
						t_cost *cost);

// Cost calculation functions for stack B
int					calc_mvt_rarb_b(t_lst **lst_a, t_lst **lst_b, t_cost *cost);
int					calc_mvt_rarrb_b(t_lst **lst_a, t_lst **lst_b,
						t_cost *cost);
int					calc_mvt_rrarb_b(t_lst **lst_a, t_lst **lst_b,
						t_cost *cost);
int					calc_mvt_rrarrb_b(t_lst **lst_a, t_lst **lst_b,
						t_cost *cost);

// Movement application functions
void				apply_rarb_mvt(t_lst **lst_a, t_lst **lst_b,
						t_move_params params);
void				apply_rarrb_mvt(t_lst **lst_a, t_lst **lst_b,
						t_move_params params);
void				apply_rrarb_mvt(t_lst **lst_a, t_lst **lst_b,
						t_move_params params);
void				apply_rrarrb_mvt(t_lst **lst_a, t_lst **lst_b,
						t_move_params params);
void				apply_movement(t_lst **lst_a, t_lst **lst_b,
						t_move_params params);

// Sorting functions
void				sort(t_lst **lst_a, t_lst **lst_b);

// lst
t_lst				*ft_lstnew(int content);
void				ft_lstadd_front(t_lst **lst, t_lst *new);
int					ft_lstsize(t_lst *lst);
t_lst				*ft_lstlast(t_lst *lst);
void				ft_lstdd_back(t_lst **lst, t_lst *new);
void				ft_lstclear(t_lst **lst);

// parse
t_lst				*simple_arg(char *str);
t_lst				*multiple_arg(char **array);

int					find_min(t_lst *lst);

int					ft_error(char **array);
#endif