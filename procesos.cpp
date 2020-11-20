//implementaciones
#include <stdio.h>
#include <stdlib.h>
#include <stdlib.h>
#include <windows.h>

#include "procesos.h"

void vaciar_Matriz(char nombre[6][50])
{
	for (int j = 0; j < 6; j++)
	{
		for (int i = 0; i < 50; i++)
		{
			nombre[j][i] = '\0';
		}
	}
}

void vaciar_Matriz3x3(char nombre[6][4][6])
{
	for (int j = 0; j < 6; j++)
	{
		for (int i = 0; i < 4; i++)
		{
			for (int k = 0; k < 6; k++)
			{
				nombre[j][i][k] = '\0';
			}
		}
	}
}


void blanquemiento_salaOriginal(char sala_original[6][4][7][10])
{
	for (int i = 0; i < 6; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			for (int k = 0; k < 7; k++)
			{
				for (int m = 0; m < 10; m++)
				{
					sala_original[i][j][k][m] = 'O';
				}
			}
		}
	}
}

void blanqueamiento_datos(char dato[20])
{
	for (int i = 0; i < 20; i++)
	{
		dato[i] = '\0';
	}
}


void enumerar_asientos(int sala_asiento[7][10])
{
	for (int i = 0; i <= 9; i++)
	{
		sala_asiento[0][i] = i + 1;
	}
	for (int i = 0; i <= 9; i++)
	{
		sala_asiento[1][i] = i + 11;
	}
	for (int i = 0; i <= 9; i++)
	{
		sala_asiento[2][i] = i + 21;
	}
	for (int i = 0; i <= 9; i++)
	{
		sala_asiento[3][i] = i + 31;
	}
	for (int i = 0; i <= 9; i++)
	{
		sala_asiento[4][i] = i + 41;
	}
	for (int i = 0; i <= 9; i++)
	{
		sala_asiento[5][i] = i + 51;
	}
	for (int i = 0; i <= 9; i++)
	{
		sala_asiento[6][i] = i + 61;
	}
}

int cantidad_entradas()
{
	int num;
	printf("## Ingrese la cantidad de entradas que desea comprar ##\n");
	scanf("%d", &num);
	while (num <= 0)
	{
		printf("Error, Ingrese una cantidad valida\n");
		scanf("%d", &num);
	}
	return num;
}
