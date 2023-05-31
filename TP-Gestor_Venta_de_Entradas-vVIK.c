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
} evento;

evento eventos[max_eventos];

int num_eventos = 0;
int numero_asientos=0;

evento CrearEvento(int num_eventos);
void ListarEventos(evento un_evento[], int num_eventos);
int SeleccionarEvento(int num_eventos);

boleto VenderBoletos(int boletos_vendidos, int numero_asientos, int EventoSeleccionado, evento un_evento[]);
void MostrarBoletosVendidos(boleto MatrizBoleto[max_eventos][numero_asientos], int boletos_vendidos, int EventoSeleccionado);

int main()
{

    evento un_evento[max_eventos];
    int EventoSeleccionado=0;

    printf("\t----------Bienvenido a VentaOnlineUwU!!----------");
    printf("\n Ingrese el numero de asientos de los cuales dispone para vender entradas: ");
    scanf("%d", &numero_asientos);

    boleto MatrizBoleto[max_eventos][numero_asientos];

    int opcion;
    do{
        printf("\n\t\tEventos: manipulacion\n");
        printf("\nEventos disponibles %i de %i eventos, que desea realizar? ", num_eventos, max_eventos);
        printf("\n1. Crear evento\n");
        printf("2. Listar eventos\n");
        printf("3. Seleccionar un evento\n");
        printf("4. Modificar evento\n");
        printf("5. Apagar sistema\n");
        printf("Ingrese una opcion: ");
        scanf("%d", &opcion);

        switch(opcion)
        {
        case 1:
            if (num_eventos < max_eventos) {
            un_evento [num_eventos] = CrearEvento(num_eventos);
            num_eventos++;
                } else printf("\nNo se pueden crear mas eventos.\n");
            break;
        case 2:
            ListarEventos(un_evento, num_eventos);
            break;
        case 3:
            ListarEventos(un_evento, num_eventos);
            EventoSeleccionado = SeleccionarEvento(num_eventos);


 int boletos_vendidos = 0;
 int opcion2;
 boleto Datos_boleto;

    do {

    printf("\n\t\tEventos: operativo\n");
    printf("\nEvento actual: [%d] Nombre: %s\n", un_evento[EventoSeleccionado-1].numero, un_evento[EventoSeleccionado-1].nombre);
    printf("\nTotal de entradas vendidas: %d/%d\n", boletos_vendidos, numero_asientos);

        printf("\nVenta de Entradas! Que accion desea realizar?\n");
        printf("1. Vender un boleto\n");
        printf("2. Cancelar la venta de un boleto\n");
        printf("3. Listar boletos vendidos\n");
        printf("4. Volver\n");
        printf("Ingrese una opcion: ");
        scanf("%d", &opcion2);

            switch (opcion2) {
            case 1:
                if (boletos_vendidos < numero_asientos){
                    Datos_boleto= VenderBoletos(boletos_vendidos, numero_asientos, EventoSeleccionado, un_evento);
                MatrizBoleto[EventoSeleccionado-1][boletos_vendidos] = Datos_boleto;
                boletos_vendidos++;
                }else printf("\nNo hay mas boletos disponibles para la venta.\n");
            break;
            case 2:
                // Cancelar venta de boleto
            break;
            case 3:
                MostrarBoletosVendidos(MatrizBoleto, boletos_vendidos, EventoSeleccionado);
            break;
            case 4:
                system("cls");
            break;
            default:
                printf("Opcion incorrecta.\n");
            break;
            }
        }while (opcion2 != 4);

            break;
        case 4:
            break;
        case 5:
            break;
        default:
            printf("Opcion incorrecta\n");
            break;
        }
    }while (opcion!=5);
    return 0;
}


evento CrearEvento(int num_eventos){
    evento nuevoEvento;
    system("cls");
    printf("\nIngrese el nombre del evento %i: ", num_eventos + 1);
    scanf("%s", nuevoEvento.nombre);
    nuevoEvento.numero=num_eventos + 1;
    printf("Evento creado exitosamente.\n");
    return nuevoEvento;
}

void ListarEventos(evento un_evento[], int num_eventos) {
        system("cls");
    printf("\nListado de eventos:\n");
    for (int i = 0; i < num_eventos; i++)
        printf("%d: %s\n", un_evento[i].numero, un_evento[i].nombre);
}

int SeleccionarEvento(int num_eventos){
    int EventoSeleccionado = 0;
        printf("\nSeleccione un evento de %i/%i: ",num_eventos, max_eventos);
        scanf("%d", &EventoSeleccionado);
        system("cls");

        if (EventoSeleccionado < 0 || EventoSeleccionado > num_eventos)
        printf("ID de evento invalido.\n");
    return EventoSeleccionado;
}

boleto VenderBoletos(int boletos_vendidos, int numero_asientos, int EventoSeleccionado, evento un_evento[])
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

void MostrarBoletosVendidos(boleto MatrizBoleto[max_eventos][numero_asientos], int boletos_vendidos, int EventoSeleccionado ) {
    printf("\nListado de boletos vendidos:\n\n");
    for (int i = 0; i < boletos_vendidos; i++) {
        printf("-------------------------------------\n");
        printf("\tEvento: %s!\n", MatrizBoleto[EventoSeleccionado-1][i].evento);
        printf("Entrada: %s %d\n", MatrizBoleto[EventoSeleccionado-1][i].tipo_entrada, MatrizBoleto[EventoSeleccionado-1][i].asiento);
        printf("Venta: $%.2f  %s\n", MatrizBoleto[EventoSeleccionado-1][i].precio, MatrizBoleto[EventoSeleccionado-1][i].fechayhora_vta); //agregar fehca y hora
        printf("Casa de Venta: %s\n", MatrizBoleto[EventoSeleccionado-1][i].nombre_casa_venta);
        printf("-------------------------------------\n\n");
    }
}


