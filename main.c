/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alan <alanbarnett328@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/26 00:10:33 by alan              #+#    #+#             */
/*   Updated: 2019/07/27 09:27:42 by abarnett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "debug.h"
#include "terminal.h"
#include "ft_printf.h"
#include <termios.h>
#include <unistd.h>

/*
** TODO: error codes
*/

int		main(int argc, char **argv)
{
	int		err;

	(void)argc;
	(void)argv;
	if (!isatty(STDIN_FILENO))
	{
		ft_printfd(STDERR_FILENO, "ft_select: Not a terminal.\n");
		return (EXIT_FAILURE);
	}
	print_debug("Setting up terminal");
	err = terminal_setup();
	if (err != 0)
		return (1);
	return (0);
}
