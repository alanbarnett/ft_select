/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarnett <alanbarnett328@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/28 02:07:42 by abarnett          #+#    #+#             */
/*   Updated: 2019/11/18 10:55:01 by alan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "error.h"
#include "ft_printf.h"
#include <unistd.h>

/*
** This function checks the error code and returns the string it corresponds to
**
** The error messages start at 1, so that's why the first parameter in this
** list is 0 (i.e. no string).
** The e_err_code type is an enum, and ERROR_MESSAGE_COUNT is the last item, so
** it is one larger than the last error message (i.e. a valid error message
** must be less than that number).
*/

static const char	*get_error_string(enum e_err_code error_code)
{
	static const char	*error_strings[ERROR_MESSAGE_COUNT] = {
		0,
		"Needs arguments",
		"Could not get terminal info from the terminfo database",
		"Could not initialize the terminal",
		"Could not enable non-canonical mode",
		"Could not restore previous terminal state",
	};

	return ((error_code > 0 && error_code < ERROR_MESSAGE_COUNT)
			? (error_strings[error_code]) : 0);
}

int					print_error(enum e_err_code error_code)
{
	const char	*error_string;

	error_string = get_error_string(error_code);
	if (error_string)
	{
		ft_printfd(STDERR_FILENO, "ft_select: %s\n", error_string);
	}
	return ((int)error_code);
}
