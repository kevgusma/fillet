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

int set_a_jeton(char **square, struct s_list *list, int i, int j)
{
  while (square[i])
  {
    while (square[i][j])
    {
      if (square[i][j] == '.' && list->jeton[i][j] != '.')
        square[i][j] = list->id;
      if (square[i][j] != '.' && list->jeton[i][j] != '.')
        return (-1);
        j++;
    }
    j = 0;
    i++;
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
