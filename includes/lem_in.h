/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem-in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdeanne <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/11 17:27:04 by mdeanne           #+#    #+#             */
/*   Updated: 2020/01/31 21:02:08 by yas              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H

# include "libft.h"
# include "../read_and_check/readfile.h"
# include <stdint.h>

typedef struct	s_room
{
	char			*name;
	int				x;
	int				y;
	struct s_link	*link;
	struct s_room	*next;
	int				depth;
	int				way_nu;
	int16_t			cent_x;
	int16_t			cent_y;
}				t_room;

typedef struct	s_link
{
	t_room			*room;
	struct s_link	*next;
}				t_link;

typedef struct	s_group
{
	t_room *start;
	t_room *end;
	t_room *room;
}				t_grp;

void			push_room(t_room **head, char *line);
void			add_links(t_room *head, char *line);

void			go_exit(char *error);

t_fline			*making_lists(t_grp *grp, int *ants);
t_room			*making_rooms_and_links(t_fline *head, t_grp *grp);

void			finding_ways(t_grp *grp);
void			marking_list(t_grp *grp);
void			set_start_depth(t_grp *grp);
void			clear_nonwayed_nodes_depth(t_room *room);
int				is_one_step_way(t_grp *grp);

/*
** check
*/

int				type_of_line(char *line);
int				check_valid_line(char *line);
_Bool			check_ways(t_link *link);

///
void			print_rooms(t_room *room);
void			print_rooms_with_depth(t_room *start);
void			print_ways(t_grp *grp);
void			print_seted_way_number(t_room *room);
void			print_rooms_with_depth_and_way(t_room *room, t_room *this_room);
void			print_links(t_grp *grp, t_room *room, char wich_node,
																char rule);
void			print_links_node_by_name(char *name, t_room *room,
																int need_all);

void			make_names_aroud_start_end_better(t_grp *grp);
void			print_arr_of_combinations(int len_way1, int len_way2,
																int num_ants);

#endif
