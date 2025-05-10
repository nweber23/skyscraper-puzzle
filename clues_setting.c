/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clues_setting.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nweber <nweber@student.42Heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/10 09:54:17 by nweber            #+#    #+#             */
/*   Updated: 2025/05/10 20:15:46 by nweber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	**memory_allocating(int size)
{
	char	**table;
	int		i;

	i = 0;
	table = (char **)malloc(sizeof(char *) * size);
	if (table == NULL)
		return (NULL);
	while (i < size)
	{
		table[i] = (char *)malloc(sizeof(char) * size);
		if (table[i] == NULL)
		{
			return (NULL);
		}
		i++;
	}
	return (table);
}

char	**clues_to_array(char *str)
{
	char	**clues;
	int		i;
	int		j;

	i = 0;
	j = 0;
	clues = memory_allocating(4);
	while (j < 4)
	{
		clues[0][j] = str[i];
		clues[1][j] = str[i + 8];
		clues[2][j] = str[i + 16];
		clues[3][j] = str[i + 24];
		j++;
		i += 2;
	}
	return (clues);
}

void	set_clues(char **board, char **clues)
{
	int	i;
	int	j;

	i = 1;
	j = 0;
	while (i <= 4)
	{
		board[0][i] = clues[0][j];
		board[5][i] = clues[1][j];
		board[i][0] = clues[2][j];
		board[i][5] = clues[3][j];
		i++;
		j++;
	}
}

char	**board_creation(void)
{
	char	**board;
	int		i;
	int		j;

	board = memory_allocating(6);
	i = 0;
	while (i < 6)
	{
		j = 0;
		while (j < 6)
		{
			board[i][j] = '0';
			j++;
		}
		i++;
	}
	return (board);
}
