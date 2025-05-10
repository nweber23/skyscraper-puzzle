/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handling.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nweber <nweber@student.42Heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/10 14:24:51 by nweber            #+#    #+#             */
/*   Updated: 2025/05/10 20:14:10 by nweber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	parameter_check(char **str)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (str[1][i])
	{
		if (str[1][i] >= '1' && str[1][i] <= '4')
		{
			count++;
		}
		else if (str[1][i] != ' ')
		{
			return (0);
		}
		i++;
	}
	if (count == 16)
	{
		return (1);
	}
	return (0);
}

int	c_check(char **board, int row, int column, int digits)
{
	int	i;

	i = 1;
	while (i < row)
	{
		if (board[i][column] == digits + '0')
		{
			return (1);
		}
		i++;
	}
	return (0);
}

int	r_check(char **board, int row, int column, int digits)
{
	int	i;

	i = 1;
	while (i < column)
	{
		if (board[row][i] == digits + '0')
		{
			return (1);
		}
		i++;
	}
	return (0);
}
