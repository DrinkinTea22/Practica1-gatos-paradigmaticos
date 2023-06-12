#include <stdio.h>
#include <time.h>
#include <string.h>
#include <stdlib.h>

#define constante 100
#define max_eventos 5

typedef struct
{
    char tipo_entrada[constante];
    int asiento;
    char fechayhora_vta[constante];
    float precio;
    char nombre_casa_venta[constante];
    char evento[constante];
} boleto;

typedef struct
{
    int numero;
    char nombre[constante];
    int cantidad_entradas;
} evento;

evento eventos[max_eventos];

int num_eventos = 0;
int numero_asientos=0;
int EventoSeleccionado=0;

evento CrearEvento(int* num_eventos);
void ListarEventos(evento un_evento[], int num_eventos);
int SeleccionarEvento(int num_eventos);
void ModificarEvento(int EventoSeleccionado, evento un_evento[]);

int borrar_boleto(int seleccion, evento un_evento[max_eventos], boleto MatrizBoleto[max_eventos][numero_asientos], int EventoSeleccionado );

int Seleccionar_boleto(int a);
boleto VenderBoletos( int numero_asientos, int EventoSeleccionado, evento un_evento[max_eventos]);

void MostrarBoletosVendidos(boleto MatrizBoleto[max_eventos][numero_asientos], evento un_evento[max_eventos], int EventoSeleccionado);

void MergeSort(boleto MatrizBoleto[max_eventos][numero_asientos], int ini, int fin, int EventoSeleccionado);
void Mezclar(boleto MatrizBoleto[max_eventos][numero_asientos],int ini,int med,int fin, int EventoSeleccionado);

void quickSort(boleto MatrizBoleto[max_eventos][numero_asientos], int posComienzo, int posFinal,int EventoSeleccionado);
int particionado(boleto MatrizBoleto[max_eventos][numero_asientos], int posComienzo, int posFinal, int EventoSeleccionado);
void intercambio(boleto* a, boleto* b);

void Ordenar_evento_burbuja (evento un_evento[max_eventos], boleto MatrizBoleto[max_eventos][numero_asientos]);

int main()
{
    evento un_evento[max_eventos];


    printf("\t----------Bienvenido a VentaOnlineUwU!!----------");
    printf("\n Ingrese el numero de asientos de los cuales dispone para vender entradas: ");
    scanf("%d", &numero_asientos);

    boleto MatrizBoleto[max_eventos][numero_asientos];
    //int tamano_vector = sizeof(MatrizBoleto) / sizeof(MatrizBoleto[0][0]);
    //alt: MatrizBoleto[x][n] -> x*n= tamano de MatrizBoleto

    int opcion;
    int seleccion;
    do
    {
        printf("\n\t\tEventos: manipulacion\n");
        printf("\nEventos disponibles %i de %i eventos, que desea realizar? ", num_eventos, max_eventos);
        printf("\n1. Crear evento\n");
        printf("2. Listar eventos\n");
        printf("3. Seleccionar un evento\n");
        printf("4. Modificar evento\n");
        printf("5. Ordenar eventos por cantidad de entradas!\n");
        printf("6. Apagar sistema\n");
        printf("Ingrese una opcion: ");
        scanf("%d", &opcion);

        switch(opcion)
        {
        case 1:
            if (num_eventos < max_eventos)
            {
                un_evento[num_eventos] = CrearEvento(&num_eventos);
                num_eventos++;
            }
            else printf("\nNo se pueden crear mas eventos.\n");
            break;
        case 2:
            ListarEventos(un_evento, num_eventos);
            break;
        case 3:
            ListarEventos(un_evento, num_eventos);
            EventoSeleccionado = SeleccionarEvento(num_eventos);

            int opcion2;
            boleto Datos_boleto;

            do
            {
                printf("\n\t\tEventos: operativo\n");
                printf("\nEvento actual: [%d] Nombre: %s\n", un_evento[EventoSeleccionado-1].numero, un_evento[EventoSeleccionado-1].nombre);
                printf("\nTotal de entradas vendidas: %d/%d\n", un_evento[EventoSeleccionado-1].cantidad_entradas, numero_asientos);

                printf("\nVenta de Entradas! Que accion desea realizar?\n");
                printf("1. Vender un boleto\n");
                printf("2. Cancelar la venta de un boleto\n");
                printf("3. Listar boletos vendidos\n");
                printf("4. Ordenar los boletos por precio!\n");
                printf("5. Ordenar los boletos por numero de asiento!\n");
                printf("6. Volver\n");
                printf("Ingrese una opcion: ");
                scanf("%d", &opcion2);

                switch (opcion2)
                {
                case 1:
                    if (un_evento[EventoSeleccionado-1].cantidad_entradas < numero_asientos)
                    {
                        Datos_boleto= VenderBoletos(numero_asientos, EventoSeleccionado, un_evento);
                        MatrizBoleto[EventoSeleccionado-1][un_evento[EventoSeleccionado-1].cantidad_entradas] = Datos_boleto;
                        un_evento[EventoSeleccionado-1].cantidad_entradas++;
                    }
                    else printf("\nNo hay mas boletos disponibles para la venta.\n");
                    break;
                case 2:
                    if (un_evento[EventoSeleccionado-1].cantidad_entradas <=0)
                    {
                        printf("\nNo se han vendido boletos aun!\n");
                    }
                    else
                    {
                        system("cls");
                        MostrarBoletosVendidos(MatrizBoleto, un_evento, EventoSeleccionado);
                        seleccion=Seleccionar_boleto(un_evento[EventoSeleccionado-1].cantidad_entradas);
                        borrar_boleto(seleccion,un_evento, MatrizBoleto, EventoSeleccionado );
                    }
                    break;
                case 3:
                    MostrarBoletosVendidos(MatrizBoleto, un_evento, EventoSeleccionado);
                    break;
                case 4:
                    MergeSort(MatrizBoleto, 0, un_evento[EventoSeleccionado-1].cantidad_entradas - 1, EventoSeleccionado);
                    system("cls");
                    printf("\n------------------------------------------\n\n");
                    printf("Los boletos han sido ordenados por precio!\n\n");
                    printf("------------------------------------------\n");
                    break;
                case 5:
                    quickSort(MatrizBoleto, 0, un_evento[EventoSeleccionado-1].cantidad_entradas - 1, EventoSeleccionado);
                    system("cls");
                    printf("\n-----------------------------------------------------\n\n");
                    printf("Los boletos han sido ordenados por numero de asiento!\n\n");
                    printf("-----------------------------------------------------\n");
                    break;
                case 6:
                    system("cls");
                    break;
                default:
                    printf("Opcion incorrecta.\n");
                    break;
                }
            }
            while (opcion2 != 6);

            break;
        case 4:
            ListarEventos(un_evento, num_eventos);
            EventoSeleccionado = SeleccionarEvento(num_eventos);
            ModificarEvento(EventoSeleccionado, un_evento);
            break;
        case 5:
            Ordenar_evento_burbuja (un_evento,MatrizBoleto);
            break;
        case 6:
            break;
        default:
            printf("Opcion incorrecta\n");
            break;
        }
    }
    while (opcion!=6);
    return 0;
}

evento CrearEvento(int* num_eventos)
{
    evento nuevoEvento;
    system("cls");
    printf("\nIngrese el nombre del evento %i: ", (*num_eventos) + 1);
    scanf("%s", nuevoEvento.nombre);
    nuevoEvento.numero = (*num_eventos) + 1;
    nuevoEvento.cantidad_entradas = 0;
    printf("Evento creado exitosamente.\n");
    return nuevoEvento;
}

void ListarEventos(evento un_evento[], int num_eventos)
{
    system("cls");
    printf("\nListado de eventos:\n");
    for (int i = 0; i < num_eventos; i++)
        printf("%d: %s\n", un_evento[i].numero, un_evento[i].nombre);
}

int SeleccionarEvento(int num_eventos)
{
    int EventoSeleccionado = 0;
    printf("\nSeleccione un evento de %i/%i: ",num_eventos, max_eventos);
    scanf("%d", &EventoSeleccionado);
    system("cls");

    if (EventoSeleccionado < 0 || EventoSeleccionado > num_eventos)
        printf("ID de evento invalido.\n");
    return EventoSeleccionado;
}

void ModificarEvento(int EventoSeleccionado, evento un_evento[])
{
    printf("\nEvento seleccionado: %s\n", un_evento[EventoSeleccionado - 1].nombre);
    printf("Ingrese el nuevo nombre del evento: ");
    scanf(" %[^\n]s", un_evento[EventoSeleccionado - 1].nombre);
    printf("El evento ha sido modificado exitosamente.\n");
}

boleto VenderBoletos( int numero_asientos, int EventoSeleccionado, evento un_evento[max_eventos])
{
    boleto DatosBoleto;
    system("cls");

    printf("----------Venta de Boletos----------\n");

    printf("Ingrese el tipo de entrada: ");
    scanf("%s", DatosBoleto.tipo_entrada);

    printf("Ingrese el numero de asiento del boleto: ");
    scanf("%d", &DatosBoleto.asiento);

    printf("Ingrese el precio del boleto: ");
    scanf("%f", &DatosBoleto.precio);

    //obtencion de fecha/hora

    time_t now;
    struct tm *now_tm;
    now = time(NULL);
    now_tm = localtime(&now);
    strftime (DatosBoleto.fechayhora_vta,50,"%Y-%m-%d %H:%M:%S",now_tm);

    strcpy(DatosBoleto.evento, un_evento[EventoSeleccionado-1].nombre);
    printf("Ingrese el nombre de Casa de Venta:  ");
    scanf("%s", DatosBoleto.nombre_casa_venta);

    system("cls");
    return DatosBoleto;
}

void MostrarBoletosVendidos(boleto MatrizBoleto[max_eventos][numero_asientos],evento un_evento[max_eventos], int EventoSeleccionado )
{
    system("cls");
    printf("\nListado de boletos vendidos:\n\n");
    for (int i = 0; i < un_evento[EventoSeleccionado-1].cantidad_entradas; i++)
    {
        printf("-------------------------------------\n");
        printf("\tEvento: %s!\n", MatrizBoleto[EventoSeleccionado-1][i].evento);
        printf("Entrada %d: %s %d\n",i+1, MatrizBoleto[EventoSeleccionado-1][i].tipo_entrada, MatrizBoleto[EventoSeleccionado-1][i].asiento);
        printf("Venta: $%.2f  %s\n", MatrizBoleto[EventoSeleccionado-1][i].precio, MatrizBoleto[EventoSeleccionado-1][i].fechayhora_vta); //agregar fehca y hora
        printf("Casa de Venta: %s\n", MatrizBoleto[EventoSeleccionado-1][i].nombre_casa_venta);
        printf("-------------------------------------\n\n");
    }
}

int Seleccionar_boleto(int a)
{
    int seleccion;

    //verificar que el evento exista "no ser menor a cero o mayor a los eventos creados"
    do
    {
        printf("\nSeleccione un boleto de %i: ", a);
        scanf("%d", &seleccion);

    }
    while(seleccion<0 || seleccion>a);
    return (seleccion-1);
}

int borrar_boleto(int seleccion, evento un_evento[max_eventos], boleto MatrizBoleto[max_eventos][numero_asientos], int EventoSeleccionado )
{
    char sino;
    do
    {
        fflush(stdin);
        printf("¿Seguro que quiere eliminar este boleto? s/n: ");
        scanf("%c", &sino);
    }
    while (sino!='n' && sino!='s' && sino!='N' && sino!='S');

    if (sino=='s' || sino=='S')
    {
        for (int i = seleccion; i < un_evento[EventoSeleccionado - 1].cantidad_entradas; i++)
        {
            strcpy(MatrizBoleto[EventoSeleccionado - 1][i].tipo_entrada, MatrizBoleto[EventoSeleccionado - 1][i + 1].tipo_entrada);
            MatrizBoleto[EventoSeleccionado - 1][i].asiento = MatrizBoleto[EventoSeleccionado - 1][i + 1].asiento;
            MatrizBoleto[EventoSeleccionado - 1][i].precio = MatrizBoleto[EventoSeleccionado - 1][i + 1].precio;
            strcpy(MatrizBoleto[EventoSeleccionado - 1][i].evento, MatrizBoleto[EventoSeleccionado - 1][i + 1].evento);
            strcpy(MatrizBoleto[EventoSeleccionado - 1][i].nombre_casa_venta, MatrizBoleto[EventoSeleccionado - 1][i + 1].nombre_casa_venta);
        }
        un_evento[EventoSeleccionado - 1].cantidad_entradas--;
        printf("\nEl boleto ha sido eliminado exitosamente.\n");
    }
    else printf("\nNo se ha eliminado el boleto.\n");

    return un_evento[EventoSeleccionado - 1].cantidad_entradas;
}

void MergeSort(boleto MatrizBoleto[max_eventos][numero_asientos], int ini, int fin, int EventoSeleccionado)
{
    if (ini<fin)
    {
        int med = (ini+fin)/2;
        MergeSort(MatrizBoleto, ini, med, EventoSeleccionado);
        MergeSort(MatrizBoleto, med+1, fin, EventoSeleccionado);
        Mezclar(MatrizBoleto, ini, med, fin, EventoSeleccionado);
    }
    return;
}

void Mezclar(boleto MatrizBoleto[max_eventos][numero_asientos], int ini, int med, int fin, int EventoSeleccionado)
{
    int n1 = med - ini + 1;
    int n2 = fin - med;

    boleto izq[n1], der[n2];

    for (int i = 0; i < n1; i++)
        izq[i] = MatrizBoleto[EventoSeleccionado - 1][ini + i];
    for (int j = 0; j < n2; j++)
        der[j] = MatrizBoleto[EventoSeleccionado - 1][med + 1 + j];

    int i = 0, j = 0, k = ini;

    while (i < n1 && j < n2)
    {
        if (izq[i].precio <= der[j].precio)
        {
            MatrizBoleto[EventoSeleccionado - 1][k] = izq[i];
            i++;
        }
        else
        {
            MatrizBoleto[EventoSeleccionado - 1][k] = der[j];
            j++;
        }
        k++;
    }

    while (i < n1)
    {
        MatrizBoleto[EventoSeleccionado - 1][k] = izq[i];
        i++;
        k++;
    }

    while (j < n2)
    {
        MatrizBoleto[EventoSeleccionado - 1][k] = der[j];
        j++;
        k++;
    }
}
void intercambio(boleto* a, boleto* b)
{
	boleto t = *a;
	*a = *b;
	*b = t;
}
int particionado(boleto MatrizBoleto[max_eventos][numero_asientos], int posComienzo, int posFinal, int EventoSeleccionado)
{
	// elegir la referencia
	boleto pivot = MatrizBoleto[EventoSeleccionado - 1][posFinal];

    // posicion del valor mas pequeno e indicar
    // la posicion derecha de la referencia encontrada hasta ahora
	int i = (posComienzo - 1);

	for (int j = posComienzo; j <= posFinal - 1; j++) {

        // si el valor actual es mas pequeno que la referencia
		if (MatrizBoleto[EventoSeleccionado - 1][j].asiento <= pivot.asiento) {

            //incrementar la posicion del valor mas pequeno
			i++;
            //en posicion de vector i(comienzo) intercambiar con posicion de vector j(i-1)
			intercambio(&MatrizBoleto[EventoSeleccionado - 1][i], &MatrizBoleto[EventoSeleccionado - 1][j]);
		}
	}
	intercambio(&MatrizBoleto[EventoSeleccionado - 1][i+1], &MatrizBoleto[EventoSeleccionado - 1][posFinal]);
	return (i + 1);
}
void quickSort(boleto MatrizBoleto[max_eventos][numero_asientos], int posComienzo, int posFinal, int EventoSeleccionado)
{
	if (posComienzo < posFinal) {

		int indiceParticion = particionado(MatrizBoleto, posComienzo, posFinal, EventoSeleccionado);

		// ordenar los valores previos
		// particionar y particionar de nuevo
		quickSort(MatrizBoleto, posComienzo,indiceParticion - 1, EventoSeleccionado);
		quickSort(MatrizBoleto, indiceParticion + 1, posFinal, EventoSeleccionado);
	}
}

void Ordenar_evento_burbuja (evento un_evento[max_eventos], boleto MatrizBoleto[max_eventos][numero_asientos]){
    int i, j, k;
    evento aux_evento;
    boleto aux_boleto[numero_asientos];

    system("cls");

    if (num_eventos!=0)
    {
        for(i=0;i<num_eventos;i++){
            for ( j=i+1; j < num_eventos; j++)
            {
                if (un_evento[i].cantidad_entradas>un_evento[j].cantidad_entradas)
                {
                    //carga al auxiliar evento
                    aux_evento.cantidad_entradas=un_evento[i].cantidad_entradas;
                    aux_evento.numero=un_evento[i].numero,
                    strcpy(aux_evento.nombre,un_evento[i].nombre);

                    //remplazo eentre espacisos del vector
                    un_evento[i].cantidad_entradas=un_evento[j].cantidad_entradas;
                    un_evento[i].numero=un_evento[j].numero,
                    strcpy(un_evento[i].nombre,un_evento[j].nombre);

                    //Carga del vector desde el auxiliar
                    un_evento[j].cantidad_entradas=aux_evento.cantidad_entradas;
                    un_evento[j].numero= aux_evento.numero,
                    strcpy(un_evento[j].nombre,aux_evento.nombre);



                    for (k = 0; k < numero_asientos; k++)
                    {
                        //carga auxilia boletos
                        strcpy(aux_boleto[k].tipo_entrada, MatrizBoleto[i][k].tipo_entrada);
                        aux_boleto[k].asiento = MatrizBoleto[i][k].asiento;
                        aux_boleto[k].precio = MatrizBoleto[i][k].precio;
                        strcpy(aux_boleto[k].evento, MatrizBoleto[i][k].evento);
                        strcpy(aux_boleto[k].nombre_casa_venta, MatrizBoleto[i][k].nombre_casa_venta);

                        //remplazo eentre espacisos de LA MATRIZ
                        strcpy(MatrizBoleto[i][k].tipo_entrada, MatrizBoleto[j][k].tipo_entrada);
                        MatrizBoleto[i][k].asiento = MatrizBoleto[j][k].asiento;
                        MatrizBoleto[i][k].precio = MatrizBoleto[j][k].precio;
                        strcpy(MatrizBoleto[i][k].evento, MatrizBoleto[j][k].evento);
                        strcpy(MatrizBoleto[i][k].nombre_casa_venta, MatrizBoleto[j][k].nombre_casa_venta);

                        //Carga de LA MATRIZ desde el auxiliar
                        strcpy(MatrizBoleto[j][k].tipo_entrada, aux_boleto[k].tipo_entrada);
                        MatrizBoleto[j][k].asiento = aux_boleto[k].asiento;
                        MatrizBoleto[j][k].precio = aux_boleto[k].precio;
                        strcpy(MatrizBoleto[j][k].evento, aux_boleto[k].evento);
                        strcpy(MatrizBoleto[j][k].nombre_casa_venta, aux_boleto[k].nombre_casa_venta);
                    }


                }

            }

        }
        printf("-----------------------------------------------------------\n\n");
        printf("Los eventos han sido ordenados por la cantidad de entradas!\n\n");
        printf("-----------------------------------------------------------\n");
    }
    else
    {
        printf("-------------------------------------\n\n");
        printf ("****No hay eventos para ordenar.****\n\n");
        printf("-------------------------------------\n");
    }



    return;
}
