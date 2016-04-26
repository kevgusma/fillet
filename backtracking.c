#include "fillit.h"

static char **make_square(size_t lenght)
{
  char **square;
  size_t  i;
  size_t  j;

  if ((square = (char **)malloc(sizeof(char *) * lenght + 1)) == NULL)
    ft_error("Malloc fail.");
  square[lenght] = NULL;
  i = 0;
  while (i < lenght)
  {
    if ((square[i] = (char *)malloc(sizeof(char) * lenght + 1)) == NULL)
      ft_error("Malloc fail.");
    square[i][lenght] = '\0';
    j = 0;
    while (j < lenght)
    {
      square[i][j] = '.';
      j++;
    }
    i++;
  }
  return (square);
}

static void display(char **square)
{
  int i;

  i = 0;
  while(square[i])
  {
    ft_putendl(square[i]);
    i++;
  }
  ft_putendl("");
}

char **remove_jeton(char **square, char id)
{
  int i;
  int j;

  i = 0;
  while (square[i])
  {
    j = 0;
    while(square[i][j])
    {
      if (square[i][j] == id)
        square[i][j] = '.';
      j++;
    }
    i++;
  }
  return (square);
}

int set_a_jeton(char **square, struct s_list *list, int i, int j)
{
  int x;
  int y;
  int nb_id;

  x = list->x;
  y = list->y;
  nb_id = 0;
  while (square[i])
  {
    ft_putendl("je passe");
    while (square[i][j])
    {
      if (y < 4 && x < 4 && square[i][j] == '.' && list->jeton[y][x] != '.')
      {
        printf("i = %d et j = %d et y = %d et x = %d\n", i, j, list->y, list->x);
        square[i][j] = list->id;
        nb_id++;
      }
    //  if (square[i][j] != '.' && list->jeton[list->y + i][list->x + j] != '.')
      //  return (-1);
        j++;
        x++;
    }
    j = 0;
    x = 0;
    y++;
    i++;
  }
  if (nb_id < 3)
    {
      square = remove_jeton(square, list->id);
      return (-1);
    }
  return (0);
}

void  brute_force(struct s_list *list, char **square)
{
  int i;
  int j;

  i = 0;
  while (square[i])
  {
    j = 0;
    while (square[i][j])
    {
      if (square[i][j] == '.')
      {
        if (set_a_jeton(square, list, i, j) == 0)
          list = list->next;
        if (list == NULL) // liste circulaire soit on s'arrete 
          return ;
        display(square);
      }
      j++;
    }
    i++;
  }
}

void  backtracking(struct s_list *list)
{
  char **square;
//  int i;

  (void)*list;
  square = make_square(DEFAULT);
  display(square);
  brute_force(list, square);
/*  if (set_a_jeton(list->jeton, &square) == -1)
    ft_putendl("Solution non trouver");
  else
    display(square);*/
}
