/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjacobi <jjacobi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/25 11:33:54 by jjacobi           #+#    #+#             */
/*   Updated: 2017/05/26 01:50:46 by jjacobi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"
#include "ft_printf.h"

int		error(void)
{
	ft_printf("ERROR");
	return (-1);
}

void	clear_map(t_lem_map *map)
{
	int	i;

	i = 0;
	while (map->next[i] != NULL)
	{
		clear_map(map->next[i++]);
	}
	free(map->name);
	free(map->next);
	free(map);
}

int		clear_all(t_lem_info *info)
{
	t_list		*list;
	t_list		*tmp;

	list = getset_map(NULL);
	while (list)
	{
		tmp = list;
		list = list->next;
		free(tmp);
	}
	clear_map(info->map);
	return (0);
}

int		main(void)
{
	t_lem_info	data;

	parsing(&data, read_all());
	data.map = getset_startmap(NULL);
	if (!data.map || structure_data(data.map) == -1)
		return (error());
	ft_printf("The shortest path make %d rooms\n", calc_shortest(data.map, 0, ft_strdup("")));
	// return (clear_all(&data));
	return (0);
}
