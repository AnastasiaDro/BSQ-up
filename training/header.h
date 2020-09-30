/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cerebus <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/28 12:44:41 by cerebus           #+#    #+#             */
/*   Updated: 2020/09/28 12:44:43 by cerebus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H
# include <stdlib.h>
# include <fcntl.h>
#include <stdio.h>
#include <unistd.h>

//решение
typedef struct	decision
{
	//индекс начала
	int x;
	//индекс конца
	int y;
	//char steps;
    int steps;
}				s_decis;

//структура с чарами
typedef struct	characters
{
	char empt;
	char obs;
    char full;
}				s_chars;

//доска
typedef	struct	m_board
{
	int lines;
	int columns;
	int **my_arr;
	//чары
	s_chars *m_chars;
}				s_board;
void    ft_putnbr(int nb);


#endif
