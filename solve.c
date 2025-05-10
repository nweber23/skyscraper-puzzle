/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nweber <nweber@student.42Heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/10 09:54:20 by nweber            #+#    #+#             */
/*   Updated: 2025/05/10 21:14:08 by nweber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	set_clues(char **board, char **clues);
char	**board_creation(void);
int		top_view(char **board, int column);
int		left_view(char **board, int row);
void	print_solution(char **str);
void	print_error(void);
int		r_check(char **board, int row, int column, int digit);
int		c_check(char **board, int row, int column, int digit);

void	solve_recursive(char **board, int row, int column)
{
	int	i;

	i = 0;
	while (i <= 4 && row <= 4 && column <= 4)
	{
		if (!c_check(board, row, column, i) && !r_check(board, row, column, i))
		{
			board[row][column] = i + '0';
			if (row == 4 && !top_view(board, column))
				return ;
			if (column == 4)
			{
				if (left_view(board, row))
				{
					solve_recursive(board, row + 1, 1);
					if (row == 4 && top_view(board, column))
						print_solution(board);
				}
			}
		}
		else
			solve_recursive(board, row, column + 1);
		i++;
	}
	print_solution(board);
}

void	solve(char **clues)
{
	char	**board;

	board = board_creation();
	set_clues(board, clues);
	solve_recursive(board, 1, 1);
	if (board[0][0] == '0')
	{
		print_error();
	}
}
