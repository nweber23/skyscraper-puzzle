/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nweber <nweber@student.42Heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/10 09:54:20 by nweber            #+#    #+#             */
/*   Updated: 2025/05/11 18:31:10 by nweber           ###   ########.fr       */
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

int	solve_recursive(char **board, int row, int column)
{
	int	i;

	i = 1;
	if (row > 4)
		return (1);
	while (i <= 4)
	{
		if (!c_check(board, row, column, i) && !r_check(board, row, column, i))
		{
			board[row][column] = i + '0';
			if (column == 4 && (!top_view(board, column)
					|| !left_view(board, row)))
				board[row][column] = '0';
			else if (column == 4 && solve_recursive(board, row + 1, 1))
				return (1);
			else if (column != 4 && solve_recursive(board, row, column + 1))
				return (1);
			else
				board[row][column] = '0';
		}
		i++;
	}
	return (0);
}

void	solve(char **clues)
{
	char	**board;

	board = board_creation();
	set_clues(board, clues);
	if (!solve_recursive(board, 1, 1))
		print_error();
	else
		print_solution(board);
}
