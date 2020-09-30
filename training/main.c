/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cerebus <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/28 13:07:01 by cerebus           #+#    #+#             */
/*   Updated: 2020/09/28 13:07:02 by cerebus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
#include "functions.h"
#define BUFF_SIZE 1
// #include <stdio.h>
// #include <stdlib.h>
// #include <unistd.h>
int get_1_arr(char **buf, int size);
// #include <fcntl.h>
s_decis *get_deсis(s_board *m_board);


int main(int argc, char *argv[])
{

	//доска
	s_board *m_board;
	//символы

	s_chars *m_chars;
	//имя нужного файла
	char *file_name = 0;
	//делаем буффер
	//char *buffer;
	//число строк
	int lines;
	int columns;
	//число байт
	int bytes_num;
	//число аргументов
	int args_count;

	//задаем наши чары
	m_chars = create_s_chars('.', '0', 'x');

	lines = 9;
	s_decis *decis;
   //условие обработки одного файла
   if (argc == 2)
   {
	file_name = argv[1];
	//читаем из файла нашу доску
	//buffer = malloc(BUFF_SIZE);
	char *my_1_arr;
	int size = 100;
	my_1_arr = malloc(sizeof(char)*size);

	bytes_num = read_from_file(file_name, my_1_arr, size);
	//узнаем число аргументов

	args_count = count_args(my_1_arr);

	printf("число считанных байт %d\n", bytes_num);
	 //узнаем число колонок
	columns = count_columns(my_1_arr, args_count);
	printf("число колонок %d\n", columns);
	//теперь нужно создать двумерный массив
	printf("до сюда работает");
	int **my_arr = create_my_2_arr(lines, columns, my_1_arr, args_count);
	



	//создаем нашу доску
	m_board = create_s_board(m_chars, lines, columns, my_arr);
	//получаем решение
	decis = get_deсis(m_board);
	printf("x квадрата %d\n", decis->x);
    printf("y квадрата %d\n", decis->y);
    printf("число шагов %d\n", decis->steps);
	//печатаем исходный массив
	//print_arr(my_arr, lines, columns);
	//печатаем результат
	print_res_arr(decis, m_board);
   }
}


//распечатка файла
void print_result(char *arr, int bytes_count)
{
	write (1, arr, bytes_count);
}


void print_arr(int **arr, int lines, int columns)
{
	int i = 0;
	int j = 0;
	char *newline = "\n";
	while (i < lines)
	{
		j=0;
		while (j<columns)
		{
			ft_putnbr(arr[i][j]);
			j++;
		}
		write(1, newline, 1);
		i++;
	}
}

//функция чтения из файла
// int read_from_file(char *file_name, char *buffer)
// {
// 	int fd;  //дескриптор
// 	int rd_bs_count; //число прочитанных байтов
// 	int bytes_count; //счётчик прочитанных байт  

// 	rd_bs_count = 0;
// 	fd = 0;
// 	//открываем файл на чтение
// 	fd = open(file_name, O_RDONLY);

// 	while ((bytes_count = read(fd, buffer, BUFF_SIZE))>0)
// 	{
// 	   rd_bs_count = rd_bs_count + bytes_count;
// 		//printf("число байт в цикле%d\n", rd_bs_count);
// 	}
// 	close(fd);
// 	return (rd_bs_count);
// }

int read_from_file(char *file_name, char *my_1_arr, int size)
{
	int fd;  //дескриптор
	int rd_bs_count; //число прочитанных байтов
	int bytes_count; //счётчик прочитанных байт  
	char *buffer;
	//char *my_1_arr;
	rd_bs_count = 0;
	fd = 0;
	
	buffer = malloc(sizeof(char)*1);
	
	//int buff_size = 1;
	//открываем файл на чтение
	fd = open(file_name, O_RDONLY);


	//считает количество считанных байт
	while ((bytes_count = read(fd, buffer, 1))>0)
	{
		//по сути мой счетчик
	   //rd_bs_count = rd_bs_count + bytes_count;
		if(rd_bs_count < size)
		{
			my_1_arr[rd_bs_count] = buffer[0];
			printf("%c", my_1_arr[rd_bs_count]);
	
		}	else {
			size = get_1_arr(&my_1_arr, size);
			my_1_arr[rd_bs_count] = buffer[0];
			printf("%c", my_1_arr[rd_bs_count]);
		}
		rd_bs_count = rd_bs_count + bytes_count;
	}
	close(fd);
	free(buffer);
	printf("число прочитанных байт %d\n", rd_bs_count);
	return (rd_bs_count);
}

//считаем длину строки аргументов
int count_args(char *arr)
{
	int i;
	i = 0;
	while (arr[i]!='\n')
	{
		i++;
	}
	i++;
	return i;
}

//считаем длину строки
int count_columns(char *arr, int start)
{
	int g = 0;
	while(arr[start]!='\n')
	{
		g++;
		start++;
	}
	return(g);
}

//создаём двумерный массив и сразу делаем его интовым - из нулей и единиц
int **create_my_2_arr(int lines, int columns, char *buffer, int start)
{
	
	int **arr;
	int i; 
	int j;

	

	arr = malloc(sizeof(int *)*lines);
	i = 0;
	while (i < lines)
	{
		j = 0;
		arr[i] = malloc(sizeof(int)*(columns));
		while (buffer[start] != '\n')
		{
			//printf("buffer[start] %c", buffer[start]);
			if (buffer[start] == '.')
			{
				arr[i][j] = 1;
				//printf("%d", arr[i][j]);
			} else {
				arr[i][j] = 0;
				//printf("%d", arr[i][j]);
			}
			start++;
			j++;
		}
		printf("\n");
		start++;
		i++;
	}
	//free(buffer);
	return (arr);
}


//создать структуру доску
s_board	*create_s_board(s_chars *m_chars, int lines, int columns, int **my_arr)
{
	s_board *m_board;

	m_board = malloc(sizeof(m_board));
	if (!m_board)
	{
		return (0);
	}
	m_board->m_chars = m_chars;
	m_board->lines = lines;
	m_board->columns = columns;
	m_board->my_arr = my_arr;
	return (m_board);
}



//заменитель единицы и нули на символ
char change_num_to_char(s_decis *m_dis, int i, int j, s_board *m_board)
{
	int start_x;
	int start_y;
	char res_char = 's';
	
	start_x = m_dis->x - (m_dis->steps - 1);
	start_y = m_dis->y - (m_dis->steps - 1);
	
	//если i между старт_x и x
	if ((i>=start_y) && (i<=m_dis->y) && (j >= start_x) && (j <= m_dis->x)) 
	{
		//write(1, "if\n", 3);
		//res_char = m_board ->m_chars ->full;
		res_char = 'x';
	} else {
		//write(1, "do\n", 3);
		//если в этом индексе равно 0,то возвращаем чар 0, иначе возвращаем чар пустота '.';

		if (m_board->my_arr[i][j] == 0)
		{
			//write(1, "if\n", 3);
			//res_char = m_board->m_chars->obs;
			res_char = 'o';
		} else
		{
			//write(1, "do\n", 3);
			//res_char = m_board->m_chars->empt;
			res_char = '.';
		}
		
		//res_char = (m_board->my_arr[i][j] == 0 ? (m_board->m_chars->obs) : (m_board->m_chars->empt));
	}
	return (res_char);
}

void print_res_arr(s_decis *m_dis, s_board *m_board)
{
	int i = 0;
	int j = 0;
	char *newline = "\n";
	char p_char = 'u'; 
	//write(1, "do\n", 3);
	while (i < m_board->lines)
	{
		j=0;
		while (j<m_board->columns)
		{
			p_char = change_num_to_char(m_dis, i, j, m_board);
			write(1, &p_char, 1);
			j++;
		}
		write(1, newline, 1);
		i++;
	}
}


//функция увеличения памяти
int get_1_arr(char **buf, int size)
{
	int new_size;
	int i;
	
	i = 0;
	new_size = size*2;
	char *big_arr = malloc(sizeof(char)*new_size);
	
	while (i < size)
	{
		//char *c =  *buf;
		
		big_arr[i] = *buf[i];
		
		i++;

	}
	//free(*buf);
	*buf = big_arr;
	return new_size;
}