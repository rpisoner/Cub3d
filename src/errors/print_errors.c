/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_errors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpisoner <rpisoner@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 12:47:44 by jolivare          #+#    #+#             */
/*   Updated: 2024/11/26 12:55:19 by rpisoner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

static void	print_errors2(int code)
{
	if (code == 11)
		printf("Error\nEl mapa no está rodeado por muros\n");
}

void	print_errors(int code)
{
	if (code == -1)
		printf("Error\nError de malloc\n");
	else if (code == 1)
		printf("Error\nMapa vacío\n");
	else if (code == 2)
		printf ("Error\nFallo al cargar a textura norte\n");
	else if (code == 3)
		printf ("Error\nFallo al cargar a textura sur\n");
	else if (code == 4)
		printf ("Error\nFallo al cargar a textura oeste\n");
	else if (code == 5)
		printf ("Error\nFallo al cargar a textura este\n");
	else if (code == 6)
		printf("Error\nConfiguración del mapa incompleta\n");
	else if (code == 7)
		printf("Error\nNúmero de jugadores inválido\n");
	else if (code == 8)
		printf("Error\nCarácter en el mapa inválido\n");
	else if (code == 9)
		printf("Error\nEl archivo no tiene extensión .cub\n");
	else if (code == 10)
		printf("Error\nNúmero de argumentos inválido\n");
	print_errors2(code);
	exit (1);
}
