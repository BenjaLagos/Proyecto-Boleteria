//implementaciones
#include <stdio.h>
#include <stdlib.h>
#include <stdlib.h>
#include <windows.h>

#include "entradas_y_salidas.h"

void logo()
{
	printf("----------------------------------------\n");
	printf("-----**----------****------------**-----\n");
	printf("-----------##Simple-Tickets##-----------\n");
	printf("-----**----------****------------**-----\n");
	printf("---------Programando para usted---------\n");
}

int valor_entrada(char tipo[7], int aux)
{
	int valor_individual;
	int valor_base = 3200;
	int valor_extra = 600;

	char tipo_normal[7] = "normal";
	char tipo_3d[6] = "3d";

	if (strcmp(tipo, tipo_normal) == 0)
	{

		if ((aux > 12) && (aux <= 17))
		{

			valor_individual = valor_base + (valor_extra * 1);
		}
		else if ((aux > 60) || (aux <= 12))
		{

			valor_individual = valor_base + (valor_extra * 0);
		}
		else
		{

			valor_individual = valor_base + (valor_extra * 2);
		}
	}
	else if (strcmp(tipo, tipo_3d) == 0)
	{

		if ((aux > 12) && (aux <= 17))
		{

			valor_individual = valor_base + (valor_extra * 2);
		}
		else if ((aux > 60) || (aux <= 12))
		{

			valor_individual = valor_base + (valor_extra * 1);
		}
		else
		{

			valor_individual = valor_base + (valor_extra * 3);
		}
	}
	return valor_individual;
}

int pregunta_registro()
{
	int b;
	printf("Se ha registrado anteriormente en nuestro cine?\n");
	printf("1.Si\n");
	printf("2.No\n");
	scanf("%d", &b);
	while ((b < 1) || (b > 2))
	{
		printf("Error, elija una opccion valida\n");
		printf("1.Si\n");
		printf("2.No\n");
		scanf("%d", &b);
	}
	return b;
}

int edad_cliente_individual(int i, int edad_clientes[280])
{
	printf("## Ingrese edad del cliente %d ##\n", i + 1);
	scanf("%d", &edad_clientes[i]);

	while ((edad_clientes[i] <= 0) || (edad_clientes[i] > 100))
	{
		printf("Error, Ingrese una edad valida\n");
		scanf("%d", &edad_clientes[i]);
	}
	return edad_clientes[i];
}

int seleccion_pelicula(int num_peliculas, char nombre_pelicula[6][50])
{
	int a;
	printf("Seleccione una pelicula:\n");
	for (int i = 0; i <= num_peliculas; i++)
	{
		if (i == num_peliculas)
		{
			printf("%d.Cancelar\n", i + 1);
			continue;
		}
		printf("%d.%s\n", i + 1, nombre_pelicula[i]);
	}
	scanf("%d", &a);

	while ((a <= 0) || (a > (num_peliculas + 1)))
	{
		printf("Error, Ingrese una opcion valida\n");
		scanf("%d", &a);
	}
	return a;
}

int seleccion_horario(int numero_salasNormal[6], int pelicula_seleccionada, int numero_salas3d[6], char horarios_Normal[6][4][6], char horarios_3d[6][4][6])
{
	int a;
	printf("Seleccione un horario segun su tipo de funcion (Normal o 3d si es que hubiese):\n");

	if (numero_salasNormal[pelicula_seleccionada - 1] > 0)
	{
		printf("Horarios disponibles (Tipo de funcion Normal):\n");
		for (int i = 0; i < numero_salasNormal[pelicula_seleccionada - 1]; i++)
		{
			printf("%d.%s\n", i + 1, horarios_Normal[pelicula_seleccionada - 1][i]);
		}
	}
	if (numero_salas3d[pelicula_seleccionada - 1] > 0)
	{
		printf("Horarios disponibles (Tipo de funcion 3d):\n");
		for (int i = 0; i < numero_salas3d[pelicula_seleccionada - 1]; i++)
		{
			printf("%d.%s\n", numero_salasNormal[pelicula_seleccionada - 1] + i + 1, horarios_3d[pelicula_seleccionada - 1][i]);
		}
	}
	printf("%d.Cancelar\n", numero_salasNormal[pelicula_seleccionada - 1] + numero_salas3d[pelicula_seleccionada - 1] + 1);
	scanf("%d", &a);
	return a;
}

void grafica_sala(char sala[6][4][7][10], int pelicula_seleccionada, int horario_seleccionado)
{

	printf("           ----------------PANTALA------------------ \n");
	printf(" Columnas =>'1' '2' '3' '4' '5  '6' '7' '8' '9' '10' \n");
	printf("      |'1' | %c | %c | %c | %c | %c | %c | %c | %c | %c | %c |  \n", sala[pelicula_seleccionada - 1][horario_seleccionado - 1][0][0], sala[pelicula_seleccionada - 1][horario_seleccionado - 1][0][1], sala[pelicula_seleccionada - 1][horario_seleccionado - 1][0][2], sala[pelicula_seleccionada - 1][horario_seleccionado - 1][0][3], sala[pelicula_seleccionada - 1][horario_seleccionado - 1][0][4], sala[pelicula_seleccionada - 1][horario_seleccionado - 1][0][5], sala[pelicula_seleccionada - 1][horario_seleccionado - 1][0][6], sala[pelicula_seleccionada - 1][horario_seleccionado - 1][0][7], sala[pelicula_seleccionada - 1][horario_seleccionado - 1][0][8], sala[pelicula_seleccionada - 1][horario_seleccionado - 1][0][9]);
	printf("      |'2' | %c | %c | %c | %c | %c | %c | %c | %c | %c | %c |  \n", sala[pelicula_seleccionada - 1][horario_seleccionado - 1][1][0], sala[pelicula_seleccionada - 1][horario_seleccionado - 1][1][1], sala[pelicula_seleccionada - 1][horario_seleccionado - 1][1][2], sala[pelicula_seleccionada - 1][horario_seleccionado - 1][1][3], sala[pelicula_seleccionada - 1][horario_seleccionado - 1][1][4], sala[pelicula_seleccionada - 1][horario_seleccionado - 1][1][5], sala[pelicula_seleccionada - 1][horario_seleccionado - 1][1][6], sala[pelicula_seleccionada - 1][horario_seleccionado - 1][1][7], sala[pelicula_seleccionada - 1][horario_seleccionado - 1][1][8], sala[pelicula_seleccionada - 1][horario_seleccionado - 1][1][9]);
	printf("      |'3' | %c | %c | %c | %c | %c | %c | %c | %c | %c | %c |  \n", sala[pelicula_seleccionada - 1][horario_seleccionado - 1][2][0], sala[pelicula_seleccionada - 1][horario_seleccionado - 1][2][1], sala[pelicula_seleccionada - 1][horario_seleccionado - 1][2][2], sala[pelicula_seleccionada - 1][horario_seleccionado - 1][2][3], sala[pelicula_seleccionada - 1][horario_seleccionado - 1][2][4], sala[pelicula_seleccionada - 1][horario_seleccionado - 1][2][5], sala[pelicula_seleccionada - 1][horario_seleccionado - 1][2][6], sala[pelicula_seleccionada - 1][horario_seleccionado - 1][2][7], sala[pelicula_seleccionada - 1][horario_seleccionado - 1][2][8], sala[pelicula_seleccionada - 1][horario_seleccionado - 1][2][9]);
	printf("Filas |'4' | %c | %c | %c | %c | %c | %c | %c | %c | %c | %c |  \n", sala[pelicula_seleccionada - 1][horario_seleccionado - 1][3][0], sala[pelicula_seleccionada - 1][horario_seleccionado - 1][3][1], sala[pelicula_seleccionada - 1][horario_seleccionado - 1][3][2], sala[pelicula_seleccionada - 1][horario_seleccionado - 1][3][3], sala[pelicula_seleccionada - 1][horario_seleccionado - 1][3][4], sala[pelicula_seleccionada - 1][horario_seleccionado - 1][3][5], sala[pelicula_seleccionada - 1][horario_seleccionado - 1][3][6], sala[pelicula_seleccionada - 1][horario_seleccionado - 1][3][7], sala[pelicula_seleccionada - 1][horario_seleccionado - 1][3][8], sala[pelicula_seleccionada - 1][horario_seleccionado - 1][3][9]);
	printf("      |'5' | %c | %c | %c | %c | %c | %c | %c | %c | %c | %c |  \n", sala[pelicula_seleccionada - 1][horario_seleccionado - 1][4][0], sala[pelicula_seleccionada - 1][horario_seleccionado - 1][4][1], sala[pelicula_seleccionada - 1][horario_seleccionado - 1][4][2], sala[pelicula_seleccionada - 1][horario_seleccionado - 1][4][3], sala[pelicula_seleccionada - 1][horario_seleccionado - 1][4][4], sala[pelicula_seleccionada - 1][horario_seleccionado - 1][4][5], sala[pelicula_seleccionada - 1][horario_seleccionado - 1][4][6], sala[pelicula_seleccionada - 1][horario_seleccionado - 1][4][7], sala[pelicula_seleccionada - 1][horario_seleccionado - 1][4][8], sala[pelicula_seleccionada - 1][horario_seleccionado - 1][4][9]);
	printf("      |'6' | %c | %c | %c | %c | %c | %c | %c | %c | %c | %c |  \n", sala[pelicula_seleccionada - 1][horario_seleccionado - 1][5][0], sala[pelicula_seleccionada - 1][horario_seleccionado - 1][5][1], sala[pelicula_seleccionada - 1][horario_seleccionado - 1][5][2], sala[pelicula_seleccionada - 1][horario_seleccionado - 1][5][3], sala[pelicula_seleccionada - 1][horario_seleccionado - 1][5][4], sala[pelicula_seleccionada - 1][horario_seleccionado - 1][5][5], sala[pelicula_seleccionada - 1][horario_seleccionado - 1][5][6], sala[pelicula_seleccionada - 1][horario_seleccionado - 1][5][7], sala[pelicula_seleccionada - 1][horario_seleccionado - 1][5][8], sala[pelicula_seleccionada - 1][horario_seleccionado - 1][5][9]);
	printf("      |'7' | %c | %c | %c | %c | %c | %c | %c | %c | %c | %c |  \n", sala[pelicula_seleccionada - 1][horario_seleccionado - 1][6][0], sala[pelicula_seleccionada - 1][horario_seleccionado - 1][6][1], sala[pelicula_seleccionada - 1][horario_seleccionado - 1][6][2], sala[pelicula_seleccionada - 1][horario_seleccionado - 1][6][3], sala[pelicula_seleccionada - 1][horario_seleccionado - 1][6][4], sala[pelicula_seleccionada - 1][horario_seleccionado - 1][6][5], sala[pelicula_seleccionada - 1][horario_seleccionado - 1][6][6], sala[pelicula_seleccionada - 1][horario_seleccionado - 1][6][7], sala[pelicula_seleccionada - 1][horario_seleccionado - 1][6][8], sala[pelicula_seleccionada - 1][horario_seleccionado - 1][6][9]);
}

void impresion_ticket3d(char tipo[7], int numero_sala_funcion[6], int valor_total, int numero_entradas, int pelicula_seleccionada, int asiento[70], char nombre_pelicula[6][50], char horarios_3d[6][4][6], int horario_seleccionado, char nombre_usuario[20], char apellido_usuario[20], char fecha_hoy[11])
{

	printf("Compra confirmada\n");
	printf("Imprimiendo ticket\n");
	Sleep(500);
	printf("--------- Tipo: %s ----------Sala: %d--------\n", tipo, numero_sala_funcion[pelicula_seleccionada - 1]); //falta el numer ode la sala
	Sleep(500);
	printf("-------**-------------***---------------**-----\n");
	Sleep(500);
	printf("-------**----- Valor Pagado: %d ------**-----\n", valor_total);
	Sleep(500);
	printf("-------**-------------***---------------**-----\n");
	Sleep(500);

	printf("---------------- Nro Asientos: ------------------\n");
	Sleep(500);
	for (int i = 1; i <= numero_entradas; i++)
	{
		printf("-----------------##--- %d ---##-----------------\n", asiento[i]);
		Sleep(500);
	}
	printf("-------**-------------***---------------**-----\n");
	Sleep(500);
	printf("----------------## %s ##-----------------\n", nombre_pelicula[pelicula_seleccionada - 1]);
	Sleep(500);
	printf("-------**-------------***---------------**-----\n");
	Sleep(500);
	printf("------------------Hora: %s -----------------\n", horarios_3d[pelicula_seleccionada - 1][horario_seleccionado - 1]);
	Sleep(500);
	printf("-------**-------------***---------------**-----\n");
	Sleep(500);
	printf("------- Nombre: --- %s -- %s -----------\n", nombre_usuario, apellido_usuario);
	Sleep(500);
	printf("-------**-------------***---------------**-----\n");
	Sleep(500);
	printf("--- %s ------------Simple-Tickets.net--\n", fecha_hoy);
}

void impresion_ticketNormal(char tipo[7], int numero_sala_funcion[6], int valor_total, int numero_entradas, int pelicula_seleccionada, int asiento[70], char nombre_pelicula[6][50], char horarios_Normal[6][4][6], int horario_seleccionado, char nombre_usuario[20], char apellido_usuario[20], char fecha_hoy[11])
{

	printf("Compra confirmada\n");
	printf("Imprimiendo ticket\n");
	Sleep(500);
	printf("--------- Tipo: %s ----------Sala: %d--------\n", tipo, numero_sala_funcion[pelicula_seleccionada - 1]); //falta el numer ode la sala
	Sleep(500);
	printf("-------**-------------***---------------**-----\n");
	Sleep(500);
	printf("-------**----- Valor Pagado: %d ------**-----\n", valor_total);
	Sleep(500);
	printf("-------**-------------***---------------**-----\n");
	Sleep(500);

	printf("---------------- Nro Asientos: ------------------\n");
	Sleep(500);
	for (int i = 1; i <= numero_entradas; i++)
	{
		printf("-----------------##--- %d ---##-----------------\n", asiento[i]);
		Sleep(500);
	}
	printf("-------**-------------***---------------**-----\n");
	Sleep(500);
	printf("----------------## %s ##-----------------\n", nombre_pelicula[pelicula_seleccionada - 1]);
	Sleep(500);
	printf("-------**-------------***---------------**-----\n");
	Sleep(500);
	printf("------------------Hora: %s -----------------\n", horarios_Normal[pelicula_seleccionada - 1][horario_seleccionado - 1]);
	Sleep(500);
	printf("-------**-------------***---------------**-----\n");
	Sleep(500);
	printf("------- Nombre: --- %s -- %s -----------\n", nombre_usuario, apellido_usuario);
	Sleep(500);
	printf("-------**-------------***---------------**-----\n");
	Sleep(500);
	printf("--- %s ------------Simple-Tickets.net--\n", fecha_hoy);
}

int pregunta_vendedor(int dinero_recaudado, int entradas_vendidas)
{
	int termino_horario;
	printf("\n(Pregunta al Empleado)Desea Cerrar su turno?\n"); //##Pregunta al empleado cierre de turno##
	printf("1. Si\n");
	printf("2. No\n");
	scanf("%d", &termino_horario);

	while ((termino_horario <= 0) || (termino_horario > 2))
	{
		printf("Error seleccione una opcion valida\n");
		printf("1. Si\n");
		printf("2. No\n");
		scanf("%d", &termino_horario);
	}

	switch (termino_horario)
	{
	case 1:
		printf("El dinero recaudado hoy fue en total: %d\n", dinero_recaudado);
		printf("Y la cantidad de entradas vendidas hoy fueron en total: %d\n", entradas_vendidas);
		break;

	case 2:
		break;
	}
	return termino_horario;
}
