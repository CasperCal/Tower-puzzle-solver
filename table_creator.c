/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   table_creator.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldietri <aldietri@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/19 16:07:25 by aldietri          #+#    #+#             */
/*   Updated: 2021/09/19 16:07:26 by aldietri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

int		table_check(int **tab, int *input_data, int size);
void	print_tab(int **tab, int size);

void	empty_table_creator(int **tab, int size)
{
	int	i;
	int	j;

	i = 0;
	while (i < size)
	{
		j = 0;
		while (j < size)
		{
			tab[i][j] = 0;
			j++;
		}
		i++;
	}
}

void	table_init(int **tab, int *input_data, int size)
{
	empty_table_creator(tab, size);
	if (table_check(tab, input_data, size))
		print_tab(tab, size);
	else
		write(1, "Error\n", 6);
}

void	table_creator(int *input_data, int size)
{
	int	**tab;
	int	*line;
	int	i;

	line = malloc(sizeof(int) * size);
	tab = malloc(sizeof(line) * size);
	if (!line || !tab)
	{
		write(1, "Error\n", 6);
		return ;
	}
	i = 0;
	while (i < size)
	{
		tab[i] = malloc(sizeof(int) * size);
		if (!tab[i])
		{
			write(1, "Error\n", 6);
			return ;
		}
		i++;
	}
	table_init(tab, input_data, size);
	free(line);
	free(tab);
}
