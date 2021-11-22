/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   col_line_check.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldietri <aldietri@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/19 16:06:39 by aldietri          #+#    #+#             */
/*   Updated: 2021/09/19 16:06:40 by aldietri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	line_check_left(int line_nbr, int **tab, int *input_data, int size)
{
	int	i;
	int	delta;
	int	delta_max;
	int	box_seen;

	i = 1;
	delta = 0;
	delta_max = 0;
	box_seen = 1;
	while (i < size)
	{
		delta = tab[line_nbr][i] - tab[line_nbr][0];
		if (delta > delta_max)
		{
			delta_max = delta;
			box_seen++;
		}
		i++;
	}
	if (box_seen != input_data[2 * size + line_nbr])
		return (0);
	return (1);
}

int	line_check_right(int line_nbr, int **tab, int *input_data, int size)
{
	int	i;
	int	delta;
	int	delta_max;
	int	box_seen;

	box_seen = 1;
	delta = 0;
	delta_max = 0;
	i = size - 2;
	while (i > -1)
	{
		delta = tab[line_nbr][i] - tab[line_nbr][size - 1];
		if (delta > delta_max)
		{
			delta_max = delta;
			box_seen++;
		}
		i--;
	}
	if (box_seen != input_data[3 * size + line_nbr])
		return (0);
	return (1);
}

int	col_check_top(int col_nbr, int **tab, int *input_data, int size)
{
	int	i;
	int	delta;
	int	delta_max;
	int	box_seen;

	i = 1;
	delta = 0;
	delta_max = 0;
	box_seen = 1;
	while (i < size)
	{
		delta = tab[i][col_nbr] - tab[0][col_nbr];
		if (delta > delta_max)
		{
			delta_max = delta;
			box_seen++;
		}
		i++;
	}
	if (box_seen != input_data[col_nbr])
		return (0);
	return (1);
}

int	col_check_bot(int col_nbr, int **tab, int *input_data, int size)
{
	int	i;
	int	delta;
	int	delta_max;
	int	box_seen;

	delta = 0;
	box_seen = 1;
	delta_max = 0;
	i = size - 2;
	while (i > -1)
	{
		delta = tab[i][col_nbr] - tab[size - 1][col_nbr];
		if (delta > delta_max)
		{
			delta_max = delta;
			box_seen++;
		}
		i--;
	}
	if (box_seen != input_data[size + col_nbr])
		return (0);
	return (1);
}
