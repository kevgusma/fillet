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

// penser a faire une fonction qui sub une partie d'un tab
// pour le mettre dans un autre
// mettre cette fonction dans la libft

char           *check_jeton(char **buf)
{
  int   nb_#;
  int   i;
  int   j;

  while (i < 4)
  {
    
    if (nb_# > 4)
      ft_error("Invalid jeton in file");
    i++;
  }
  /*
    si un caractere sur la ligne : tester si les autres caracteres sont a i=
    et a j+
    si 4 caracteres sur la ligne : tester si aucun autre caractere dans le jeton
    si # tester si suivant # OU ## si oui
      option 1: + tester # en i= ou i++ et j+
      option 2 : + tester si ## en i+ et j+
    variable qui compte le nombre de #
  */
}

 struct s_list *set_a_node(char **buf, struct s_list *list)
{
  if (!list)
  {
    if ((list = (struct s_list *)malloc(sizeof(struct s_list))) == NULL)
      ft_error("malloc fail.");
    list->next = NULL;
    list->prev = NULL;
    if ((list->jeton = check_jeton(buf)) == NULL)
      ft_error("Invalid jeton in file.");
  }
  return (list);
}

static void ft_check_buf(char *buf)
{
  int i; // c'est l'emplacement d'un caractere
  int j; // egale au nombre du caractere
  char **split_buf;
  struct s_list *list;

  i = 0;
  j = 1;
  while (buf[i])
  {
    if (buf[i] != '#' && buf[i] != '.' && buf[i] != '\n')
      ft_error("Invalid character in file.");
// faire des test supplementaire pour le modulo
    if ((j % 21) == 0 && (buf[i] != '\n' || buf[i - 1] != '\n')) // si c'est un '\n' on ne rentre pas dans cette condition
      ft_error("file does not valid.");
    j++;
    i++;
  }

  split_buf = ft_strsplit(buf, '\n'); // fait un tab de toute les lignes
  i = 0;
  list = NULL;
  while (split_buf[i])
  {
  //  ft_putendl(split_buf[i]);
    // penser a verifier que les piece font bien 4 ligne suivit '\n'
    // sauf pour la derniere piece a part si le split a rajouter un '\n' a la fin

    if (i % 4 == 0) // modulo de ZERO = ZERO !!!!!!!!!!!!!!
      list = set_a_node(&split_buf[i], list);
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
