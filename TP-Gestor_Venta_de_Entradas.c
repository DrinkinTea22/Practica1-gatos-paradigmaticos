// venta de entradas <algo> concierto
// formato de entradas: <tipo de entrada, nombre de casa de venta, numero de ticket y/o id, asciento, hora y fecha>

/*
1_
crear evento
listar los disponibles
poder seleccionarlos
poder borrarlos
2_
vender asientos
comprobar si x asiento esta vendido o no
*/

//espacio de trabajo abajo

#include <stdio.h>
#include <time.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#define constante 100
#define maximo_eventos 5
#define boletos 20

typedef struct
{
    char tipo_entrada[constante];
    int asiento;
    float precio;
    char nombre_casa_venta[constante];
    char evento[constante];
} boleto;

typedef struct
{
    int numero;
    int cantidad_entradas;
    char nombre[constante];
} evento;


//<retorno> <nombre variable> (<parametros>)
//int numero_asientos(void); deprecated
void status(char texto[]);
//evento manipulacion
void menu_eventos(int evento_numero_maximo);
evento CrearEvento(int eventos_creados, int evento_numero_maximo);
void ListarEvento(evento evento_disponibles[], int evento_numero_maximo);
int SeleccionarEvento(int eventos_creados, int evento_numero_maximo);
void ModificarEvento(int evento_seleccionado, evento un_evento[]);
//evento operativo
int menu_boletos(int evento_seleccionado, int boletos_disponibles, int eventos_creados, int evento_numero_maximo, evento un_evento[], int cantidad_entradas);
boleto VenderBoletos(int evento_seleccionado, int boletos_disponibles, evento un_evento[]);
void ListarInformacionBoleto(int evento_seleccionado, int BoletoVendido_Contador, boleto BoletoVendido[maximo_eventos][boletos]);
int Seleccionar_boleto(int a);
boleto borrar_boleto(int seleccion, int cantidad_entradas, boleto BoletoVendido[maximo_eventos][boletos], int evento_seleccionado );

int main()
{
    printf("\t----------Bienvenido a VentaOnlineUwU!!----------");
    menu_eventos(maximo_eventos);

    return 0;
}

/*deprecated
int numero_asientos(void){
    int asientos;
    printf("\n Ingrese el numero de asientos de los cuales dispone para vender entradas: ");
    scanf("%d", &asientos);
    return asientos;
}
*/
//escribir estatus de cierta parte del programa
void status(char texto[])
{
    printf("%s", texto);
}
//selector de operaciones entre eventos
void menu_eventos(int evento_numero_maximo)
{
    status("\n\t\tEventos: manipulacion\n");
    int boletos_disponibles=boletos;
    int evento_seleccionado=0;
    int eventos_creados=0;
    int opcion;
    evento un_evento[evento_numero_maximo];

    un_evento[0].cantidad_entradas=0;
    un_evento[1].cantidad_entradas=0;
    un_evento[2].cantidad_entradas=0;
    un_evento[3].cantidad_entradas=0;
    un_evento[4].cantidad_entradas=0;
    //eventos disponibles

    while (opcion!=5)
    {
        printf("\nEventos disponibles %i\\%i eventos, ¿que desea realizar? ", eventos_creados, evento_numero_maximo);

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
            if(eventos_creados < evento_numero_maximo)
            {
                un_evento[eventos_creados] = CrearEvento(eventos_creados, evento_numero_maximo);
                eventos_creados++;  //se creó un evento
            }
            else
            {
                status("\nno se puede crear mas eventos!");
            }
            break;
        case 2:
            ListarEvento(un_evento, eventos_creados);
            break;
        case 3:
            ListarEvento(un_evento, eventos_creados);
            evento_seleccionado = SeleccionarEvento(eventos_creados, evento_numero_maximo);
            /*
            esta funcion requiere de:

            -evento seleccionado = (evento_seleccionado)
            -numero de boletos = (boletos_disponibles)
            -numero de eventos creados = (eventos_creados)
            -maximo de eventos que la empresa puede manejar = (evento_numero_maximo)
            -vector que contiene numero "id" y un nombre = un_evento
            */
            //se llevo a cabo la seleccion, continuar en menu_boletos()
            un_evento[evento_seleccionado].cantidad_entradas=menu_boletos(evento_seleccionado, boletos_disponibles, eventos_creados, evento_numero_maximo, un_evento,  un_evento[evento_seleccionado].cantidad_entradas);
            break;
        case 4:
            ListarEvento(un_evento, eventos_creados);
            evento_seleccionado = SeleccionarEvento(eventos_creados, evento_numero_maximo);
            ModificarEvento(evento_seleccionado, un_evento);
            break;
        case 5:
            break;
        default:
            printf("Opcion incorrecta\n");
            break;
        }
    }
}
evento CrearEvento(int eventos_creados, int evento_numero_maximo)
{
    evento informacion;
    //system("cls");
    printf("\nIngrese el nombre del evento %i: ", eventos_creados+1);
    scanf("%s", informacion.nombre);
    //aqui numero=eventos_creados+1 ya que se quiere mostrar opciones de 1 hasta evento_numero_maximo en lugar de 0 hasta evento_numero_maximo
    informacion.numero = (eventos_creados+1);

    return informacion;
}
void ListarEvento(evento evento_disponibles[], int evento_numero_maximo)
{
    //system("cls");
    printf("\nListado de eventos: ");
    for(int i=0; i < evento_numero_maximo; i++)
    {
        printf("\n %i: %s", evento_disponibles[i].numero, evento_disponibles[i].nombre);
    }
    printf("\n");
}
int SeleccionarEvento(int eventos_creados, int evento_numero_maximo)
{
    int seleccion;

    //verificar que el evento exista "no ser menor a cero o mayor a los eventos creados"
    do
    {
        printf("\nSeleccione un evento de %i/%i: ", eventos_creados, evento_numero_maximo);
        scanf("%d", &seleccion);
        //system("cls");

    }
    while(seleccion<0 || seleccion>eventos_creados);
    return seleccion;
}

void ModificarEvento(int evento_seleccionado, evento un_evento[]) {
    printf("\nEvento seleccionado: %s\n", un_evento[evento_seleccionado - 1].nombre);
    printf("Ingrese el nuevo nombre del evento: ");
    scanf(" %[^\n]s", un_evento[evento_seleccionado - 1].nombre);
    printf("El evento ha sido modificado exitosamente.\n");
}

int menu_boletos(int evento_seleccionado, int boletos_disponibles, int eventos_creados, int evento_numero_maximo, evento un_evento[], int cantidad_entradas)
{
    int opcion;
    int  seleccion; //save = es una funcion que guradara el valor de la "cantidad_entradas -1" (para la funcion de borrar/cancelar_venta_voleto)

    boleto BoletoVendido[evento_numero_maximo][boletos];
    // int BoletoVendido_Contador=0;   //desde 0 - boletos_disponibles

    //todo lo interno de un evento (ventas, tiempo, asientos disponibles, etc.)
    while (opcion!=4)
    {
        //e[a-1] se coloca de esta manera ya que seleccion comienza desde 1-evento_numero_maximo en lugar de
        //empezar por 0 que es por donde comienzan los vectores
        status("\n\t\tEventos: operativo\n");
        printf("\nSu seleccion fue el evento: %i Nombre: \"%s\"!\n", evento_seleccionado, un_evento[evento_seleccionado-1].nombre);
        printf("\nTotal de boletos vendidos %d\\%d \n", cantidad_entradas, boletos_disponibles);
        printf("\nVenta de boletos! ¿Que accion va a realizar?\n");

        printf("1. Vender un boleto\n");
        printf("2. Cancelar la venta de un boleto\n");
        printf("3. Listar boletos\n");
        printf("4. Volver\n");
        printf("Ingrese una opcion: ");
        scanf("%d", &opcion);

        printf("\n*____________________________________*");

        switch(opcion)
        {
        case 1:
            BoletoVendido[evento_seleccionado][cantidad_entradas] = VenderBoletos(evento_seleccionado,boletos_disponibles, un_evento);
            cantidad_entradas++;   //se vendio un boleto
            break;
        case 2:
            ListarInformacionBoleto(evento_seleccionado, cantidad_entradas, BoletoVendido);
            seleccion=Seleccionar_boleto(cantidad_entradas);
            borrar_boleto(seleccion, cantidad_entradas, BoletoVendido, evento_seleccionado );
            cantidad_entradas--;
            break;
        case 3:
            ListarInformacionBoleto(evento_seleccionado, cantidad_entradas, BoletoVendido);
            break;
        case 4:
            //system("cls");
            break;
        default:
            printf("Opcion incorrecta\n");
            break;
        }
    }
    return cantidad_entradas;
}
boleto VenderBoletos(int evento_seleccionado, int boletos_disponibles, evento un_evento[])
{
    boleto DatosBoleto;
    /*
    char tipo_entrada;
    int asiento;
    float precio;
    char nombre_casa_venta[constante];
    char evento[constante];
    */
    printf("\n\n****CARGA DE BOLETO**");

    printf("\nIngrese el tipo de entrada: ");
    scanf("%s", DatosBoleto.tipo_entrada);

    printf("\nIngrese el numero de asiento del boleto: ");
    scanf("%d", &DatosBoleto.asiento);

    printf("\nIngrese el precio del boleto: ");
    scanf("%f", &DatosBoleto.precio);

    strcpy(DatosBoleto.evento, un_evento[evento_seleccionado - 1].nombre);

    printf("\nIngrese el nombre de Casa de Venta: ");
    scanf("%s", DatosBoleto.nombre_casa_venta);

    return DatosBoleto;
}
void ListarInformacionBoleto(int evento_seleccionado, int BoletoVendido_Contador, boleto BoletoVendido[maximo_eventos][boletos])
{
    //system("cls");
    /*
    j = BoletoVendido contenidos
    */
    for (int j = 0; j < BoletoVendido_Contador; j++)
    {
        printf("\nListado de boletos vendidos:\n");
        printf("Boleto #%d\n", j+1);
        printf("Tipo de entrada: %s\n", BoletoVendido[evento_seleccionado][j].tipo_entrada);
        printf("Número de asiento: %d\n", BoletoVendido[evento_seleccionado][j].asiento);
        printf("Precio: %.2f\n", BoletoVendido[evento_seleccionado][j].precio);
        printf("Casa de venta: %s\n", BoletoVendido[evento_seleccionado][j].nombre_casa_venta);
        printf("Evento: %s\n", BoletoVendido[evento_seleccionado][j].evento);
        printf("\n");
    }
    printf("\n");
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
    return seleccion-1;

}

boleto borrar_boleto(int seleccion, int cantidad_entradas, boleto BoletoVendido[maximo_eventos][boletos], int evento_seleccionado )
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
        for ( int i = 0; seleccion < cantidad_entradas ; i++)
        {
            strcpy(BoletoVendido[evento_seleccionado][seleccion+i].tipo_entrada,BoletoVendido[evento_seleccionado][seleccion+i+1].tipo_entrada);
            BoletoVendido[evento_seleccionado][seleccion+i].asiento= BoletoVendido[evento_seleccionado][seleccion+i+1].asiento;
            BoletoVendido[evento_seleccionado][seleccion+i].precio=BoletoVendido[evento_seleccionado][seleccion+i+1].precio;
            strcpy(BoletoVendido[evento_seleccionado][seleccion+i].evento, BoletoVendido[evento_seleccionado][seleccion+i+1].evento);
            strcpy(BoletoVendido[evento_seleccionado][seleccion+i].nombre_casa_venta,BoletoVendido[evento_seleccionado][seleccion+i+1].nombre_casa_venta);
            cantidad_entradas--;
        }
    }
    else
    {
        printf ("\n \n No se a eliminado el boleto ");
    }
}
