/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printing.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nweber <nweber@student.42Heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/10 09:09:20 by nweber            #+#    #+#             */
/*   Updated: 2025/05/11 12:03:11 by nweber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	print_error(void)
{
	write(1, "Error\n", 6);
}

void	print_solution(char **board)
{
	int	i;
	int	j;

	i = 1;
	if (board[0][0] == '1')
		return ;
	board[0][0] = '1';
	while (i <= 4)
	{
		j = 1;
		while (j <= 4)
		{
			write(1, &board[i][j], 1);
			j++;
			if (j != 5)
			{
				write(1, " ", 1);
			}
		}
		write(1, "\n", 1);
		i++;
	}
}
