/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kevgusma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/15 11:25:18 by kevgusma          #+#    #+#             */
/*   Updated: 2016/04/15 11:25:23 by kevgusma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H

# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>
# include "libft/libft.h"
# include <sys/types.h>
# include <sys/uio.h>
# include <stdio.h>
# define FILLIT_H

# define MAX_CHAR 545
# define DEFAULT 4

typedef struct  s_list
{
  char          **jeton;
  char          id;
  int           flag;
  int           x;
  int           y;
  struct s_list *next;
  struct s_list *prev;
}               t_list;

void  ft_check_buf(char *buf);
void        ft_error(char *str);
void  backtracking(struct s_list *list);

#endif
