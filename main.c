/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nweber <nweber@student.42Heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/10 09:35:12 by nweber            #+#    #+#             */
/*   Updated: 2025/05/11 10:13:12 by nweber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	solve(char **clues);
void	print_error(void);
char	**clues_to_array(char *str);
int		parameter_check(char **str);

int	main(int argc, char **argv)
{
	char	**clues;

	if (argc != 2)
	{
		print_error();
		return (1);
		if (!parameter_check(argv))
		{
			print_error();
			return (1);
		}
	}
	clues = clues_to_array(argv[1]);
	solve(clues);
}
