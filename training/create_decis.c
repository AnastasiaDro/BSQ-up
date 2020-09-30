/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_desic.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cerebus <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/29 12:36:12 by cerebus           #+#    #+#             */
/*   Updated: 2020/09/29 12:36:14 by cerebus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

s_decis	*create_desis(int x, int y, char steps)
{
	s_decis *my_desis;

	my_desis = malloc(sizeof(s_decis));
	if (!my_desis)
	{
		return (0);
	}
	my_desis->x = x;
	my_desis->y = y;
	my_desis->steps = steps;
	return (my_desis);
}
