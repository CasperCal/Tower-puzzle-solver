/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldietri <aldietri@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/19 16:06:48 by aldietri          #+#    #+#             */
/*   Updated: 2021/09/19 16:06:49 by aldietri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

void	table_creator(int *input_data, int size);

int	get_size_all_cases(char *input)
{
	int	i;
	int	counter;

	i = 0;
	counter = 0;
	while (input[i])
	{
		if ('1' <= input[i] && input[i] <= '9')
		{
			counter++;
		}
		i++;
	}
	return (counter);
}

int	check_input(char *input, int *input_data, int *size)
{
	int	i;
	int	counter;

	i = 0;
	counter = 0;
	if (input[i] == 0)
		return (0);
	while (input[i])
	{
		if (i % 2 == 0 && '1' <= input[i] && input[i] <= '9')
		{
			input_data[counter] = input[i] - 48;
			counter++;
		}
		else if (input[i] != ' ' && input[i] != 0)
			return (0);
		i++;
	}
	if (counter % 4 != 0 || i % 2 == 0 || !counter || counter > 36)
		return (0);
	*size = counter / 4;
	return (1);
}

int	main(int argc, char **argv)
{
	int	*input_data;
	int	size;

	if (argc == 2)
	{
		input_data = malloc(get_size_all_cases(argv[1]) * sizeof(int));
		if (check_input(argv[1], input_data, &size))
		{
			table_creator(input_data, size);
		}
		else
			write(1, "Error\n", 6);
		free(input_data);
	}
	else
	{
		write(1, "Error\n", 6);
	}
	return (0);
}
