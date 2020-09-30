/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_s_chars.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cerebus <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/29 12:39:55 by cerebus           #+#    #+#             */
/*   Updated: 2020/09/29 12:39:57 by cerebus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

s_chars	*create_s_chars(char empt, char obs, char full)
{
	s_chars *my_chars;

	my_chars = malloc(sizeof(my_chars));
	if (!my_chars)
	{
		return (0);
	}
	my_chars->empt = empt;
	my_chars->obs = obs;
	my_chars->full = full;
	return (my_chars);
}
