/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   select_info.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alan <alanbarnett328@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 21:06:42 by alan              #+#    #+#             */
/*   Updated: 2019/12/08 03:23:54 by abarnett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SELECT_INFO_H
# define SELECT_INFO_H

# include "point.h"

/*
** combine selected strings into output string
**
** select struct
** iterator list of strings
** string for final output
** overall widest string
** number of string columns
** width of column
** s_point for window size
**	lines in terminal
**	columns in terminal
*/

struct			s_select
{
	struct s_iter	*strings;
	const char		*output;
	unsigned int	str_maxlen;
	unsigned int	sel_columns;
	unsigned int	sel_column_width;
	struct s_point	term_size;
};

void			select_info_init(struct s_select *select_info);
void			update_term_size(struct s_select *info);
void			update_select_columns(struct s_select *info);
void			update_grid_pos(struct s_select *info);
int				get_str_maxlen(struct s_iter *select_strings,
					unsigned int max);
struct s_iter	*make_select_iter(int str_amnt, char **str_array,
					unsigned int *str_maxlen);
void			calibrate_screen(struct s_select *info);

#endif
