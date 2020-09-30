/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   min.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cerebus <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/29 12:34:40 by cerebus           #+#    #+#             */
/*   Updated: 2020/09/29 12:34:45 by cerebus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	min(int first, int second, int third)
{
	int min = first;
	min = (first > second) ? second : first;
	min = (min > third) ? third : min;
	return (min);
}
