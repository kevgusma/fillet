#include "fillit.h"

void *check_jeton(char **buf, char id) // buf == &split_buf[i]
// buf = a split_buf mais a partir de i
{
  int   nb_hashtag;
  int   i;
  int   j;
  int   total;
  char  **jeton;

  nb_hashtag = 0;
  total = 0;
  i = 0;
  while (i < 4)
  {
    j = 0;
    while (buf[i][j]) // i = ligne et j = caractere
    {
      if (buf[i][j] == '#')
      {
        if (j < 3 && buf[i][j + 1] && buf[i][j + 1] == '#')
          total++;
        if (i < 3 && buf[i + 1][j] && buf[i + 1][j] == '#')
          total++;
        if (j > 0 && buf[i][j - 1] && buf[i][j - 1] == '#')
          total++;
        if (i > 0 && buf[i - 1][j] && buf[i - 1][j] == '#')
          total++;
        nb_hashtag++;
      }
      j++;
    }
    if (nb_hashtag > 4)
      ft_error("Invalid # in file.");
    i++;
  }
  if (total < 5)
    return (NULL);

  if ((jeton = (char **)malloc(sizeof(char *) * 5)) == NULL)
    return (NULL);

  i = 0;
  while (i < 4)
  {
    jeton[i] = ft_strdup(buf[i]);
    j = 0;
    while (jeton[i][j])
    {
      if (jeton[i][j] == '#')
        jeton[i][j] = id;
      j++;
    }
    i++;
  }
  jeton[i] = NULL;
  return (jeton);
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
  struct s_list *tmp;

  if (!list)
  {
    if ((list = (struct s_list *)malloc(sizeof(struct s_list))) == NULL)
      ft_error("malloc fail.");
    list->next = NULL;
    list->prev = NULL;
    list->flag = 0;
    list->id = 'A';
    if ((list->jeton = check_jeton(buf, 'A')) == NULL)
      ft_error("Invalid jeton in file.");
    return (list);
  }
  if ((tmp = (struct s_list *)malloc(sizeof(struct s_list))) == NULL)
    ft_error("malloc fail.");
  tmp->next = list;
  list->prev = tmp;
  tmp->flag = 0;
  tmp->id = list->id + 1;
  if ((tmp->jeton = check_jeton(buf, list->id + 1)) == NULL)
    ft_error("Invalid jeton in file.");
  return (tmp);
}

struct s_list *set_coord(struct s_list *list)
{
  int i;
  int j;
  int init;
  t_list *tmp;

  tmp = list;
  while (tmp != NULL)
  {
    i = 0;
    init = 0;
    while (tmp->jeton[i])
    {
      j = 0;
      while (tmp->jeton[i][j])
      {
        if (tmp->jeton[i][j] != '.' && init == 0)
        {
          tmp->x = j;
          tmp->y = i;
          init = 1;
        }
        j++;
      }
      i++;
    }
    tmp = tmp->next;
  }
  return (list);
}

void  show_list(struct s_list *list)
{
  int i;

  while (list)
  {
    i = 0;
    while(list->jeton[i])
    {
      ft_putendl(list->jeton[i]);
      i++;
    }
    ft_putendl("");
    list = list->next;
  }
}

void  ft_check_buf(char *buf)
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
      ft_error("File does not valid.");
    j++;
    i++;
  }

  split_buf = ft_strsplit(buf, '\n'); // fait un tableau de toute les lignes de buf sans '\n'
  i = 0;
  list = NULL;
  while (split_buf[i])
  {
  //  ft_putendl(split_buf[i]);
    // penser a verifier que les piece font bien 4 ligne suivit '\n'
    // sauf pour la derniere piece a part si le split a rajouter un '\n' a la fin

    if (i % 4 == 0) // modulo de ZERO = ZERO !!!!!!!!!!!!!!
      list = set_a_node(&split_buf[i], list);

  /*  while (*test) // a utiliser avec precaution, ne pas oublier que LE pointeur peut etre NULL
    {
      ft_putendl(*test);
      test++;
    }*/

    i++;
  }
  list = set_coord(list);
  show_list(list);
  show_list(list);
  ft_putendl("ON PASSE AU BACKTRAKING");
  backtracking(list);
}
