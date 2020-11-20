#include <stdio.h>
#include <stdlib.h>
#include <stdlib.h>
#include <windows.h>

#include "procesos.h"
#include "entradas_y_salidas.h"

int main()
{
	FILE *flujo = fopen("Cartelera.txt", "r"); // r=read, lectura y b de tipo binario ya que estoy trabajando en variable tipo char osea solo por caracter (1 byte)

	if (flujo == NULL)
	{ // errores en la apertura del archivo caso de no encontrarse etc
		perror("Error en la apertura del archivo");
		return 1;
	}
	char temp[100];
	int cont = 0;

	int num_peliculas;

	fseek(flujo, 704, SEEK_SET);
	while (feof(flujo) == 0)
	{
		fgets(temp, 100, flujo);
		cont++;
	}
	num_peliculas = cont;
	char nombre_pelicula[6][50];
	char aux1;
	int numero_salasNormal[6];
	char aux2[1];
	char horarios_Normal[6][4][6];
	char aux3;
	int numero_salas3d[6];
	char aux4[1];
	char horarios_3d[6][4][6];
	char aux5;
	char restriccion_edad[6][50];
	int numero_sala_funcion[6];
	char aux6[1];

	vaciar_Matriz(nombre_pelicula);
	vaciar_Matriz3x3(horarios_Normal);
	vaciar_Matriz3x3(horarios_3d);
	vaciar_Matriz(restriccion_edad);
	aux1 = '0';
	aux2[0] = '0';
	aux3 = '0';
	aux4[0] = '0';
	aux5 = '0';
	aux6[0] = '0';

	fseek(flujo, 704, SEEK_SET);
	for (int j = 0; j < num_peliculas; j++)
	{
		for (int i = 0; aux1 != '-'; i++)
		{
			aux1 = fgetc(flujo);
			if (aux1 != '-')
			{
				nombre_pelicula[j][i] = aux1;
			}
		}

		aux1 = '0';

		aux2[0] = fgetc(flujo);
		numero_salasNormal[j] = atoi(aux2);
		aux2[0] = '0';

		fgetc(flujo);
		for (int i = 0; i < numero_salasNormal[j]; i++)
		{
			for (int k = 0; k < 5; k++)
			{
				aux3 = fgetc(flujo);
				if (aux3 != '-')
				{
					horarios_Normal[j][i][k] = aux3;
				}
			}
			fgetc(flujo);
			aux3 = '0';
		}
		if (numero_salasNormal[j] == 0)
		{
			fgetc(flujo);
		}

		aux4[0] = fgetc(flujo);
		numero_salas3d[j] = atoi(aux4);
		aux4[0] = '0';

		fgetc(flujo);
		for (int i = 0; i < numero_salas3d[j]; i++)
		{
			for (int k = 0; k < 5; k++)
			{
				aux5 = fgetc(flujo);
				if (aux5 != ' ')
				{
					horarios_3d[j][i][k] = aux5;
				}
			}
			fgetc(flujo);
			aux5 = '0';
		}
		if (numero_salas3d[j] == 0)
		{
			fgetc(flujo);
		}

		fgets(restriccion_edad[j], 3, flujo);
		fgetc(flujo);

		aux6[0] = fgetc(flujo);
		numero_sala_funcion[j] = atoi(aux6);
		aux6[0] = '0';
		fgetc(flujo);
	}

	fclose(flujo);
	char fecha_hoy[11];
	int c;

	do
	{
		printf("ingrese la fecha de hoy en formato DD/MM/AA\n");
		scanf("%s", fecha_hoy);
		printf("Es esta la fecha de hoy?\n");
		printf("%s\n", fecha_hoy);
		printf("1.Si\n");
		printf("2.No\n");
		scanf("%d", &c);
		while ((c < 1) || (c > 2))
		{
			printf("Error, elija una opccion valida\n");
			printf("1.Si\n");
			printf("2.No\n");
			scanf("%d", &c);
		}
	} while (c == 2);

	int horario_seleccionado;
	int pelicula_seleccionada;
	int asiento[70];
	char tipo[7];
	char tipo_3d[6] = "3d";
	char si[50] = "si";

	int cap_salas[6][4][1] = {{{70}, {70}, {70}, {70}},
							  {{70}, {70}, {70}, {70}},
							  {{70}, {70}, {70}, {70}},
							  {{70}, {70}, {70}, {70}},
							  {{70}, {70}, {70}, {70}},
							  {{70}, {70}, {70}, {70}}};

	char sala[6][4][7][10];
	char sala_original[6][4][7][10];

	int valor_total;
	int dinero_recaudado = 0;
	int entradas_vendidas = 0;
	int numero_entradas;
	numero_entradas = 0;
	int termino_horario;
	bool menor_edad;
	int edad_clientes[280];
	int aceptar;
	int estado;

	char nombre_registrado[20];
	char apellido_registrado[20];
	char rut_registrado[20];

	char rut_usuario[20];
	char nombre_usuario[20];
	char apellido_usuario[20];

	int confirmacion_datos;
	int registro_anterior;
	int aux = 0;
	int numero_usuarios = 0;

	blanquemiento_salaOriginal(sala_original);

	do
	{

		do
		{

			do
			{
				do
				{
					do
					{
						menor_edad = 0;

						do
						{
							system("cls");
							logo();

							blanqueamiento_datos(rut_usuario);
							blanqueamiento_datos(nombre_usuario);
							blanqueamiento_datos(apellido_usuario);

							registro_anterior = pregunta_registro();
							if (registro_anterior == 1)
							{
								printf("Ingrese su rut de usuario sin simbolos\n");
								fflush(stdin);
								gets(rut_usuario);

								FILE *flujo2 = fopen("Registo_Usuarios.txt", "r+");

								if (flujo2 == NULL)
								{ // errores en la apertura del archivo caso de no encontrarse etc
									perror("Error en la apertura del archivo");
									return 1;
								}

								char temp[100];
								numero_usuarios = 0;
								aux = 0;
								fseek(flujo2, 245, SEEK_SET);
								while (feof(flujo2) == 0)
								{
									fgets(temp, 100, flujo2);
									aux++;
								}
								numero_usuarios = aux - 1;
								confirmacion_datos = 2;

								fseek(flujo2, 245, SEEK_SET);
								for (int i = 0; i < numero_usuarios; i++)
								{
									fscanf(flujo2, "-%s %s %s\n", nombre_registrado, apellido_registrado, rut_registrado);
									if ((strcmp(rut_registrado, rut_usuario) == 0))
									{
										printf("Efectivamente, hemos encontrado este usuario:\n");
										Sleep(500);
										printf("Nombre: %s\n", nombre_registrado);
										Sleep(500);
										printf("Apellido: %s\n", apellido_registrado);
										Sleep(500);
										printf("Rut: %s\n", rut_registrado);
										Sleep(500);
										printf("Es usted?\n");
										printf("1.Si\n");
										printf("2.No\n");
										printf("3.Cancelar\n");
										scanf("%d", &confirmacion_datos);
										while ((confirmacion_datos < 1) || (confirmacion_datos > 3))
										{
											printf("Error, elija una opccion valida\n");
											printf("1.Si\n");
											printf("2.No\n");
											printf("3.Cancelar\n");
											scanf("%d", &confirmacion_datos);
										}
										if (confirmacion_datos == 1)
										{
											break;
										}
									}
								}
								if (confirmacion_datos == 2)
								{
									printf("No hay registro de su usuario en nuestros datos registrese a continuacion:\n");
									printf("Primer nombre (minusculas)\n");
									fflush(stdin);
									gets(nombre_usuario);
									printf("Apellido Paterno(minusculas)\n");
									gets(apellido_usuario);
									fseek(flujo2, 245, SEEK_SET);
									fgets(temp, 100, flujo2);
									for (int i = 0; i < numero_usuarios; i++)
									{
										fgets(temp, 100, flujo2);
									}
									fprintf(flujo2, "-%s %s %s\n", nombre_usuario, apellido_usuario, rut_usuario);
									printf("Su usuario ha sido creado con exito\n");
								}
								else if (confirmacion_datos == 1)
								{

									printf("Se utilizara su usuario\n");
									for (int i = 0; i < 20; i++)
									{
										nombre_usuario[i] = nombre_registrado[i];
									}
									for (int i = 0; i < 20; i++)
									{
										apellido_usuario[i] = apellido_registrado[i];
									}
								}

								fclose(flujo2);
							}
							else
							{

								printf("Es necesario que se registre en la base de datos de nuestro cine, complete con sus datos personales:\n");
								printf("Primer nombre (minusculas)\n");
								fflush(stdin);
								gets(nombre_usuario);
								printf("Apellido Paterno(minusculas)\n");
								gets(apellido_usuario);
								printf("Rut personal sin simbolos\n");
								gets(rut_usuario);

								FILE *flujo3 = fopen("Registo_Usuarios.txt", "r+"); // r=read, lectura y

								if (flujo3 == NULL)
								{ // errores en la apertura del archivo caso de no encontrarse etc
									perror("Error en la apertura del archivo");
									return 1;
								}
								char temp[100];
								aux = 0;
								numero_usuarios = 0;
								fseek(flujo3, 245, SEEK_SET);
								while (feof(flujo3) == 0)
								{
									fgets(temp, 100, flujo3);
									aux++;
								}
								numero_usuarios = aux - 1;
								confirmacion_datos = 2;

								fseek(flujo3, 245, SEEK_SET);
								for (int i = 0; i < numero_usuarios; i++)
								{
									fscanf(flujo3, "-%s %s %s\n", nombre_registrado, apellido_registrado, rut_registrado);
									if ((strcmp(rut_registrado, rut_usuario) == 0))
									{
										printf("Hemos encontrado este usuario:\n");
										Sleep(500);
										printf("Nombre: %s\n", nombre_registrado);
										Sleep(500);
										printf("Apellido: %s\n", apellido_registrado);
										Sleep(500);
										printf("Rut: %s\n", rut_registrado);
										Sleep(500);
										printf("Es usted?\n");
										printf("1.Si\n");
										printf("2.No\n");
										printf("3.Cancelar\n");
										scanf("%d", &confirmacion_datos);
										while ((confirmacion_datos < 1) || (confirmacion_datos > 3))
										{
											printf("Error, elija una opccion valida\n");
											printf("1.Si\n");
											printf("2.No\n");
											printf("3.Cancelar\n");
											scanf("%d", &confirmacion_datos);
										}
										if (confirmacion_datos == 1)
										{
											break;
										}
									}
								}
								if ((confirmacion_datos == 2))
								{

									fseek(flujo3, 245, SEEK_SET);
									fgets(temp, 100, flujo3);
									for (int i = 0; i < numero_usuarios; i++)
									{
										fgets(temp, 100, flujo3);
									}
									fprintf(flujo3, "-%s %s %s\n", nombre_usuario, apellido_usuario, rut_usuario);
									printf("Su usuario ha sido creado con exito\n");
								}
								else if (confirmacion_datos == 1)
								{
									printf("Se utilizara su usuario\n");
								}

								fclose(flujo3);
							}

						} while (confirmacion_datos == 3);

						numero_entradas = cantidad_entradas();

						for (int i = 0; i < numero_entradas; i++)
						{
							edad_clientes[i] = edad_cliente_individual(i, edad_clientes);
							if (edad_clientes[i] < 18)
							{
								menor_edad = 1;
							}
						}

						pelicula_seleccionada = seleccion_pelicula(num_peliculas, nombre_pelicula);

						if ((menor_edad == 1) && (strcmp(restriccion_edad[pelicula_seleccionada - 1], si) == 0))
						{
							printf("## La pelicula seleccionada es solo para adultos ##\n");
							system("pause");
						}

					} while ((pelicula_seleccionada == (num_peliculas + 1)) || ((menor_edad == 1) && (strcmp(restriccion_edad[pelicula_seleccionada - 1], si) == 0)));

					horario_seleccionado = seleccion_horario(numero_salasNormal, pelicula_seleccionada, numero_salas3d, horarios_Normal, horarios_3d);

					if (horario_seleccionado > numero_salasNormal[pelicula_seleccionada - 1])
					{
						horario_seleccionado -= numero_salasNormal[pelicula_seleccionada - 1];
						tipo[0] = '3';
						tipo[1] = 'd';
						tipo[2] = 0;
					}
					else if (horario_seleccionado <= numero_salasNormal[pelicula_seleccionada - 1])
					{
						tipo[0] = 'n';
						tipo[1] = 'o';
						tipo[2] = 'r';
						tipo[3] = 'm';
						tipo[4] = 'a';
						tipo[5] = 'l';
						tipo[6] = 0;
					}
					while ((horario_seleccionado <= 0) || (horario_seleccionado > numero_salasNormal[pelicula_seleccionada - 1] + 1))
					{
						printf("Error, Ingrese un horario valido\n");
						scanf("%d", &horario_seleccionado);
						if (horario_seleccionado > numero_salasNormal[pelicula_seleccionada - 1])
						{
							horario_seleccionado -= numero_salasNormal[pelicula_seleccionada - 1];
							tipo[0] = '3';
							tipo[1] = 'd';
							tipo[2] = 0;
						}
						else if (horario_seleccionado <= numero_salasNormal[pelicula_seleccionada - 1])
						{
							tipo[0] = 'n';
							tipo[1] = 'o';
							tipo[2] = 'r';
							tipo[3] = 'm';
							tipo[4] = 'a';
							tipo[5] = 'l';
							tipo[6] = 0;
						}
					}

					while (cap_salas[pelicula_seleccionada - 1][horario_seleccionado - 1][0] < numero_entradas) //Pregunta por otra sala en el caso de que no hayan asientos disponibles
					{

						printf("## Error La capacidad del horario seleccionado no tiene asientos suficientes, seleccione uno distinto ##\n");

						horario_seleccionado = seleccion_horario(numero_salasNormal, pelicula_seleccionada, numero_salas3d, horarios_Normal, horarios_3d);

						if (horario_seleccionado > numero_salasNormal[pelicula_seleccionada - 1])
						{
							horario_seleccionado -= numero_salasNormal[pelicula_seleccionada - 1];
						}
						while ((horario_seleccionado <= 0) || (horario_seleccionado > numero_salasNormal[pelicula_seleccionada - 1] + 1))
						{
							printf("Error, Ingrese un horario valido\n");
							scanf("%d", &horario_seleccionado);
							if (horario_seleccionado > numero_salasNormal[pelicula_seleccionada - 1])
							{
								horario_seleccionado -= numero_salasNormal[pelicula_seleccionada - 1];
								tipo[0] = '3';
								tipo[1] = 'd';
								tipo[2] = 0;
							}
							else if (horario_seleccionado <= numero_salasNormal[pelicula_seleccionada - 1])
							{
								tipo[0] = 'n';
								tipo[1] = 'o';
								tipo[2] = 'r';
								tipo[3] = 'm';
								tipo[4] = 'a';
								tipo[5] = 'l';
								tipo[6] = 0;
							}
						}
					}

				} while (horario_seleccionado == (numero_salas3d[pelicula_seleccionada - 1]) + 1);

				if (strcmp(tipo, tipo_3d) == 0)
				{
					horario_seleccionado += numero_salas3d[pelicula_seleccionada - 1];
				}

				for (int i = 0; i < 6; i++)
				{
					for (int j = 0; j < 4; j++)
					{
						for (int k = 0; k < 7; k++)
						{
							for (int m = 0; m < 10; m++)
							{
								sala[i][j][k][m] = sala_original[i][j][k][m];
							}
						}
					}
				}
				int sala_asiento[7][10];
				enumerar_asientos(sala_asiento);

				int fila;
				int columna;

				for (int k = 1; k <= numero_entradas; k++)
				{

					grafica_sala(sala, pelicula_seleccionada, horario_seleccionado);

					printf("Seleccione un asiento para el cliente %d en forma 'fila , columna' \n", k);
					scanf("%d , %d", &fila, &columna);
					while (((fila <= 0) || (fila > 7)) || ((columna <= 0) || (columna > 10)))
					{
						printf("Este asiento no existe!!\n");
						printf("ingrese otro asiento:\n");
						scanf("%d , %d", &fila, &columna);
					}
					while (sala[pelicula_seleccionada - 1][horario_seleccionado - 1][fila - 1][columna - 1] != 'O')
					{
						printf("Este asiento ya esta ocupado!!\n");
						printf("ingrese otro asiento:\n");
						scanf("%d , %d", &fila, &columna);
					}
					asiento[k] = sala_asiento[fila - 1][columna - 1];
					sala[pelicula_seleccionada - 1][horario_seleccionado - 1][fila - 1][columna - 1] = 'X';
				}
				printf("## Se compraran los siguientes asientos ## \n");
				Sleep(500);
				for (int i = 1; i <= numero_entradas; i++)
				{
					printf("Asiento Nro: %d\n", asiento[i]);
					Sleep(500);
				}
				Sleep(700);
				printf("## Como se muestra en la figura ##\n");

				grafica_sala(sala, pelicula_seleccionada, horario_seleccionado);

				printf("Desea continuar?\n");
				printf("1.Si\n");
				printf("2.Cancelar\n");
				scanf("%d", &aceptar);

				while ((aceptar <= 0) || (aceptar > 2))
				{
					printf("Error, Ingrese una opcion valida\n");
					scanf("%d", &aceptar);
				}
				if (strcmp(tipo, tipo_3d) == 0)
				{
					horario_seleccionado -= numero_salas3d[pelicula_seleccionada - 1];
				}

			} while (aceptar == 2);

			valor_total = 0;

			for (int i = 0; i < numero_entradas; i++)
			{
				int aux = edad_clientes[i];
				printf("Precio de entrada del cliente %d:\n", i + 1);
				Sleep(500);
				printf("%d\n", valor_entrada(tipo, aux));
				valor_total += valor_entrada(tipo, aux);
			}
			Sleep(700);

			printf("## Precio total a pagar ## \n");
			printf("%d\n", valor_total);

			printf("Desea comprar?\n");
			printf("1.Si\n");
			printf("2.Cancelar\n");
			scanf("%d", &estado);
			while ((estado <= 0) || (estado > 2))
			{
				printf("Error, seleccione una opcion valida\n");
				printf("1.Si\n");
				printf("2.Cancelar\n");
				scanf("%d", &estado);
			}
			if (estado == 1)
			{

				for (int i = 0; i < 6; i++)
				{
					for (int j = 0; j < 4; j++)
					{
						for (int k = 0; k < 7; k++)
						{
							for (int m = 0; m < 10; m++)
							{
								sala_original[i][j][k][m] = sala[i][j][k][m];
							}
						}
					}
				}
			}
			else
			{

				for (int i = 0; i < 6; i++)
				{
					for (int j = 0; j < 4; j++)
					{
						for (int k = 0; k < 7; k++)
						{
							for (int m = 0; m < 10; m++)
							{
								sala[i][j][k][m] = 'O';
							}
						}
					}
				}
			}

		} while (estado == 2);
		if (strcmp(tipo, tipo_3d) == 0)
		{
			impresion_ticket3d(tipo, numero_sala_funcion, valor_total, numero_entradas, pelicula_seleccionada, asiento, nombre_pelicula, horarios_3d, horario_seleccionado, nombre_usuario, apellido_usuario, fecha_hoy);

			cap_salas[pelicula_seleccionada - 1][horario_seleccionado - 1][0] -= numero_entradas;
			entradas_vendidas += numero_entradas;
			dinero_recaudado += valor_total;
		}
		else
		{
			impresion_ticketNormal(tipo, numero_sala_funcion, valor_total, numero_entradas, pelicula_seleccionada, asiento, nombre_pelicula, horarios_Normal, horario_seleccionado, nombre_usuario, apellido_usuario, fecha_hoy);

			cap_salas[pelicula_seleccionada - 1][horario_seleccionado - 1][0] -= numero_entradas;
			entradas_vendidas += numero_entradas;
			dinero_recaudado += valor_total;
		}

		termino_horario = pregunta_vendedor(dinero_recaudado, entradas_vendidas);
		if (termino_horario == 1)
		{

			FILE *flujo4 = fopen("Registro_Turnos.txt", "a"); // r=read, lectura y

			if (flujo4 == NULL)
			{ // errores en la apertura del archivo caso de no encontrarse etc
				perror("Error en la apertura del archivo");
				return 1;
			}

			fprintf(flujo4, "Fecha de turno: %s  ---  Dinero total recaudado: %d  ---  Cantidad de entradas vendidas: %d\n", fecha_hoy, dinero_recaudado, entradas_vendidas);

			fclose(flujo4);
		}

	} while (termino_horario != 1);
	return 0;
}
