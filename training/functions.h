/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cerebus <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/29 11:55:06 by cerebus           #+#    #+#             */
/*   Updated: 2020/09/29 11:55:10 by cerebus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FUNCTIONS_H
# define FUNCTIONS_H
# include "header.h"

//распечатка результата
void print_result(char *arr, int bytes_count);

//получить решение
s_decis *get_deсis(s_board *m_board);

//создать структуру с чарами
s_chars	*create_s_chars(char empt, char obs, char full);

//создать доску
s_board	*create_s_board(s_chars *m_chars, int lines, int columns, int **my_arr);

//функция чтения из файла
//int read_from_file(char *file_name, char *buffer); 
int read_from_file(char *file_name, char *my_1_arr, int size);

//посчитать число элементов в первой строке
int count_args(char *arr);

//посчитать число колонок
int count_columns(char *arr, int start);

//создание двумерного массива
int **create_my_2_arr(int lines, int columns, char *buffer, int start);

//создать структуру-решение
s_decis	*create_desis(int x, int y, char steps);

//поиск минимального значения
int min(int first, int second, int third);

//распечатать массив
void print_arr(int **arr, int lines, int columns);

//заменитель единицы и нуля на символ, для результата
char change_num_to_char(s_decis *m_dis, int i, int j, s_board *m_board);

//распечатка результата
void print_res_arr(s_decis *m_dis, s_board *m_board);
#endif