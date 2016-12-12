/*
** myio.h for libmyio in /home/bassintag/delivery/Libmyio/include
** 
** Made by Antoine Stempfer
** Login   <antoine.stempfer@epitech.net>
** 
** Started on  Thu Nov 17 17:06:10 2016 Antoine Stempfer
** Last update Mon Nov 28 14:53:01 2016 Antoine Stempfer
*/

#ifndef LIBMYIO_H_
#define LIBMYIO_H_

char	*my_buff_file(char *, int);

char	**my_readlines(char *);

char	**my_split(char *, char);

int	my_free_strtab(char **);

int	my_prepare_buffer(char **, char *);

int	my_file_len(char *);

#endif
