/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alan <alanbarnett328@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/18 08:20:20 by alan              #+#    #+#             */
/*   Updated: 2019/11/18 17:15:48 by alan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "select_info.h"
#include "select_keys.h"
#include "ft_iter.h"
#include "stdint.h"

/*
** These functions return 1 if the loop is to continue, or 0 if it is to quit.
*/

int	handle_char_input(char input, struct s_select *info)
{
	static int	(*input_functions[128])(struct s_select *info) = {
		[KEY_CTRL_A] = ft_select_all,
		[KEY_CTRL_N] = ft_select_down,
		[KEY_CTRL_P] = ft_select_up,
		[KEY_CTRL_F] = ft_select_right,
		[KEY_CTRL_B] = ft_select_left,
		['h'] = ft_select_left,
		['j'] = ft_select_down,
		['k'] = ft_select_up,
		['l'] = ft_select_right,
		['g'] = ft_select_home,
		['G'] = ft_select_end,
		['a'] = ft_select_all,
		['d'] = ft_deselect_all,
		['i'] = ft_select_invert,
		[' '] = ft_select_select,
		['\n'] = ft_select_complete,
		['q'] = ft_select_quit,
		['\033'] = ft_select_quit,
	};

	if (!info || ft_iter_isempty(info->strings))
	{
		return (0);
	}
	if (input_functions[(int)input])
	{
		return (input_functions[(int)input](info));
	}
	return (1);
}

int	handle_arrow_key(uint32_t input, struct s_select *info)
{
	if (!info || ft_iter_isempty(info->strings))
	{
		return (0);
	}
	if (input == KEY_RIGHT_ARROW)
		return (ft_select_right(info));
	else if (input == KEY_DOWN_ARROW)
		return (ft_select_down(info));
	else if (input == KEY_UP_ARROW)
		return (ft_select_up(info));
	else if (input == KEY_LEFT_ARROW)
		return (ft_select_left(info));
	else
		return (1);
}