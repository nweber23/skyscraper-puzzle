/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   view.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nweber <nweber@student.42Heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/10 09:54:07 by nweber            #+#    #+#             */
/*   Updated: 2025/05/11 09:49:52 by nweber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	right_view(char **board, int row)
{
	int		i;
	char	high;
	char	visible;

	i = 4;
	while (i >= 1)
	{
		if (board[row][i] == '0')
			return (1);
		i--;
	}
	i = 3;
	visible = '1';
	high = board[row][4];
	while (i >= 1)
	{
		if (board[row][i] > high)
		{
			high = board[row][i];
			visible++;
		}
		i--;
	}
	return (board[row][5] == visible);
}

int	left_view(char **board, int row)
{
	int		i;
	char	high;
	char	visible;

	i = 1;
	while (i <= 4)
	{
		if(board[row][i] == '0')
			return (1);
		i++;
	}
	i = 1;
	visible = '1';
	high = board[row][1];
	while (i++ <= 4)
	{
		if (board[row][i] > high)
		{
			high = board[row][i];
			visible++;
		}
	}
	if (board[row][0] == visible)
		return (right_view(board, row));
	return (0);
}

int	bottom_view(char **board, int column)
{
	int		i;
	char	high;
	char	visible;

	i = 4;
	while (i >= 1)
	{
		if (board[i][column] == '0')
			return (1);
		i--;
	}
	i = 3;
	visible = '1';
	high = board[4][column];
	while (i >= 1)
	{
		if (board[i][column] > high)
		{
			high = board[i][column];
			visible++;
		}
		i--;
	}
	return (board[i][column] == visible);
}

int	top_view(char **board, int column)
{
	int		i;
	char	high;
	char	visible;

	i = 1;
	while (i < 4)
	{
		if (board[i][column] == '0')
			return (1);
		i++;
	}
	i = 1;
	visible = '1';
	high = board[1][column];
	while (i++ <= 4)
	{
		if (board[i][column] > high)
		{
			high = board[i][column];
			visible++;
		}
	}
	if (board[0][column] == visible)
		return (bottom_view(board, column));
	return (0);
}
