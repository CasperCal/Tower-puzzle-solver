/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   table_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldietri <aldietri@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/19 16:07:17 by aldietri          #+#    #+#             */
/*   Updated: 2021/09/19 16:07:18 by aldietri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	check_l_c(int **tab, int *input_data, int coord[2], int size);
int	check_dupli(int box_nbr, int **tab, int coord[2]);

int	check_empty_coord(int coord[2], int **tab, int size)
{
	int	i;
	int	j;

	i = 0;
	while (i < size)
	{
		j = 0;
		while (j < size)
		{
			if (tab[i][j] == 0)
			{
				coord[0] = i;
				coord[1] = j;
				return (1);
			}
			j++;
		}
		i++;
	}
	return (0);
}

int	table_check(int **tab, int *input_data, int size)
{
	int	box_nbr;
	int	coord[2];

	if (!check_empty_coord(coord, tab, size))
		return (1);
	box_nbr = 0;
	while (box_nbr < size)
	{
		box_nbr++;
		tab[coord[0]][coord[1]] = box_nbr;
		if (check_dupli(box_nbr, tab, coord)
			&& check_l_c(tab, input_data, coord, size))
		{
			if (table_check(tab, input_data, size))
				return (1);
		}
		tab[coord[0]][coord[1]] = 0;
	}
	return (0);
}
