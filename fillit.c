/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kevgusma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/15 11:25:00 by kevgusma          #+#    #+#             */
/*   Updated: 2016/04/15 11:25:01 by kevgusma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void        ft_error(char *str)
{
  ft_putendl(str);
  exit(1);
}

static struct s_list *set_a_node(char **buf, int len, struct s_list *list)
{
  if (!list)
  {
    ft_putendl("premier maillon");
  //  list->next = NULL;
  //  list->prev = NULL;
  }
  (void)*buf;
  (void)len;
  return (list);
}

static void ft_check_buf(char *buf)
{
  int i;
  int j;
  char **split_buf;
  struct s_list *list;

  i = 0;
  j = 0;
  while (buf[i])
  {
    if (buf[i] != '#' && buf[i] != '.' && buf[i] != '\n')
      ft_error("Invalid character in file.");
    if (i > 0 && (j % 21) == 0 && buf[j] != '\n')
    {
      printf("buf[i] = %c \n", buf[i - 1]);
      printf("i = %d\n", i);
      ft_error("file does not valid.");
    }
    j++;
    i++;
  }


  split_buf = ft_strsplit(buf, '\n');
  i = 0;
  list = NULL;
  while (split_buf[i])
  {
    ft_putendl(split_buf[i]);
    // penser a verifier que les piece font bien 4 ligne suivit '\n'
    // sauf pour la derniere piece a part si le split a rajouter un '\n' a la fin
    if (i % 5 == 0)
      list = set_a_node(split_buf, i, list);
    i++;
  }
}

static void  ft_open_file(char *name_file)
{
  int     fd;
  size_t  size;
  char    buf[MAX_CHAR + 2];

  if ((fd = open(name_file, O_RDONLY)) == -1)
    ft_error("file does not exist.");
  if ((size = read(fd, buf, MAX_CHAR + 2)) <= 0 || size > MAX_CHAR)
    ft_error("file does not valid. MAX_CHAR");

  printf("size lus = %lu\n", size); // a supp

  if ((size + 1) % 21 != 0) // 21 parce que une piece = 21 caractere
    ft_error("file does not valid. MODULO");
  buf[size + 1] = '\n';
  buf[size + 2] = '\0';
  ft_check_buf(buf);
}

static void  ft_usage(char *name_file)
{
  ft_putstr("usage: ");
  ft_putstr(name_file);
  ft_putendl(" source_file");
}

int   main(int ac, char **av)
{
  if (ac != 2)
    ft_usage(av[0]);
  else
    ft_open_file(av[1]);
  return (0);
}
