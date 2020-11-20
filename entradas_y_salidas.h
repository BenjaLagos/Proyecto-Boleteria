//prototipos

void logo();

int valor_entrada(char tipo[7], int aux);
int pregunta_registro();
int edad_cliente_individual(int i, int edad_clientes[280]);

int seleccion_pelicula(int num_peliculas, char nombre_pelicula[6][50]);
int seleccion_horario(int numero_salasNormal[6], int pelicula_seleccionada, int numero_salas3d[6], char horarios_Normal[6][4][6], char horarios_3d[6][4][6]);

void grafica_sala(char sala[6][4][7][10], int pelicula_seleccionada, int horario_seleccionado);

void impresion_ticket3d(char tipo[7], int numero_sala_funcion[6], int valor_total, int numero_entradas, int pelicula_seleccionada, int asiento[70], char nombre_pelicula[6][50], char horarios_3d[6][4][6], int horario_seleccionado, char nombre_usuario[20], char apellido_usuario[20], char fecha_hoy[11]);
void impresion_ticketNormal(char tipo[7], int numero_sala_funcion[6], int valor_total, int numero_entradas, int pelicula_seleccionada, int asiento[70], char nombre_pelicula[6][50], char horarios_Normal[6][4][6], int horario_seleccionado, char nombre_usuario[20], char apellido_usuario[20], char fecha_hoy[11]);

int pregunta_vendedor(int dinero_recaudado, int entradas_vendidas);

