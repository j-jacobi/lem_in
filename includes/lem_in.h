/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjacobi <jjacobi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/25 11:48:52 by jjacobi           #+#    #+#             */
/*   Updated: 2017/05/25 21:27:04 by jjacobi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H

# include "lem_in_map.h"
# include "libft.h"

typedef struct	s_lem_info
{
	int			ants;
	t_lem_map	*map;
	char		*startname;
	char		*endname;
}				t_lem_info;

char			**read_all();
int				parsing(t_lem_info *data, char **readed);
int				get_ants_number(t_lem_info *data, char **readed);
int				analyse_line(char *prop, char *line);
int				reg_piece(char *name, char *line, char *prop);
int				reg_connection(char *name, char *line);
int				store_piece_list(t_lem_map *store_piece_list);
int				structure_data(t_lem_map *map);
t_list			*remove_connection(t_list *previous, t_list *list,
								t_lem_connection *connec);
t_list			*getset_connection(t_list *all);
t_list			*getset_map(t_list *param);
t_lem_map		*getset_startmap(t_lem_map *param);
t_lem_map		*getset_endmap(t_lem_map *param);

#endif
