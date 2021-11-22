/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   box_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldietri <aldietri@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/19 16:06:15 by aldietri          #+#    #+#             */
/*   Updated: 2021/09/19 16:06:20 by aldietri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	line_check_right(int line_nbr, int **tab, int *input_data, int size);
int	line_check_left(int line_nbr, int **tab, int *input_data, int size);
int	col_check_top(int col_nbr, int **tab, int *input_data, int size);
int	col_check_bot(int col_nbr, int **tab, int *input_data, int size);

int	check_dupli(int box_nbr, int **tab, int coord[2])
{
	int	i;

	i = 0;
	while (i < coord[0])
	{
		if (tab[i][coord[1]] == box_nbr)
		{
			return (0);
		}
		i++;
	}
	i = 0;
	while (i < coord[1])
	{
		if (tab[coord[0]][i] == box_nbr)
		{
			return (0);
		}
		i++;
	}
	return (1);
}

int	check_l_c(int **tab, int *input_data, int coord[2], int size)
{
	if (coord[1] == size - 1)
	{
		if (!line_check_left(coord[0], tab, input_data, size)
			|| !line_check_right(coord[0], tab, input_data, size))
		{
			return (0);
		}
	}
	if (coord[0] == size - 1)
	{
		if (!col_check_top(coord[1], tab, input_data, size)
			|| !col_check_bot(coord[1], tab, input_data, size))
		{
			return (0);
		}
	}
	return (1);
}
