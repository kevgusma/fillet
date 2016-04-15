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

# define MAX_CHAR 545
# define FILLIT_H

typedef struct  s_list
{
  char          **jeton;
  char          id;
  struct s_list *next;
  struct s_list *prev;
}               t_list;

#endif
