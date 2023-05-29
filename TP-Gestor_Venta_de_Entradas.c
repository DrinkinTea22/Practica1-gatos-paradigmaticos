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
#define max_eventos 5

typedef struct
{
    char tipo_entrada[constante];
    int asiento;
    char hora_vta[constante];
    char fecha_vta[constante];
    float precio;
    char nombre_casa_venta[constante];
    char evento[constante];
}boleto;

typedef struct
{
    int numero;
    char nombre[constante];
}evento;

int total=0;    //no se que hará aun

//<retorno> <nombre variable> (<parametros>)
int numero_asientos(void);
void status(char a[]);
//evento manipulacion
evento menu_eventos(int maximo_eventos);
evento CrearEvento(int a, int b);
void ListarEvento(evento x[], int a);
int SeleccionarEvento(int a, int b);
//evento operativo
void menu_boletos(int seleccion, int asientos_total, int total_eventos, int maximo_eventos, evento un_evento[]);
boleto VenderBoletos(int EventoSeleccionado, int asientos_total, evento un_evento[]);
void ListarInformacionBoleto(int EventoSeleccionado, int asientos_total, boleto BoletoVendido[]);

int main(){
    printf("\t----------Bienvenido a VentaOnlineUwU!!----------");
    menu_eventos(numero_asientos());

    return 0;
}

int numero_asientos(void){
    int asientos;
    printf("\n Ingrese el numero de asientos de los cuales dispone para vender entradas: ");
    scanf("%d", &asientos);
    return asientos;
}

//escribir estatus de cierta parte del programa
void status(char a[]){
    printf("%s", a);
}
//selector de operaciones entre eventos
evento menu_eventos(int maximo_eventos){
    status("\n\t\tEventos: manipulacion\n");
    int asientos_total=max_eventos, seleccion=0;
    int opcion,total_eventos=0;
    evento un_evento[max_eventos];  //eventos disponibles

    while (opcion!=5)
    {
        printf("\nEventos disponibles %i de %i eventos, que desea realizar? ", total_eventos, max_eventos);

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
    		    if(total_eventos<maximo_eventos){
        		    un_evento[total_eventos]=CrearEvento(total_eventos, maximo_eventos);
        		    total_eventos++;            //se creó un evento
    		        }
    		    else{
    		        status("\nno se puede crear mas eventos!");  
    		    		} 
                    break;
     	  	 case 2:
                ListarEvento(un_evento, total_eventos);
                    break;
     	  	 case 3:
                ListarEvento(un_evento, total_eventos);
                seleccion=SeleccionarEvento(total_eventos, max_eventos);
                /*
                esta funcion requiere de:

                -evento seleccionado = (seleccion)
                -numero de asientos = (asientos_total)
                -numero de eventos creados = (total_eventos)
                -maximo de eventos que la empresa puede manejar = (max_eventos)
                -vector que contiene numero "id" y un nombre = un_evento
                */
                menu_boletos(seleccion, asientos_total, total_eventos, max_eventos, un_evento);     //se llevo a cabo la seleccion, continuar en menu_boletos()
                    break;
            case 4:
                //borrar();
                break;
            case 5:
                break;
       		 default:
                printf("Opcion incorrecta\n");
                    break;
   	 	}
    }
}
evento CrearEvento(int a, int b){
    evento informacion;
    system("cls");
    printf("\nIngrese el nombre del evento %i: ", a+1);
    scanf("%s", informacion.nombre);
    //aqui numero=a+1 ya que se quiere mostrar opciones de 1 hasta max_eventos en lugar de 0 hasta max_eventos
    informacion.numero=(a+1);

    return informacion;
}
void ListarEvento(evento x[], int a){
    system("cls");
    printf("\nListado de eventos: ");
    for(int i=0;i<a;i++){
        printf("\n %i: %s", x[i].numero, x[i].nombre);
    }
    printf("\n");
}
int SeleccionarEvento(int a, int b){
    int seleccion;

    //verificar que el evento exista "no ser menor a cero o mayor a los eventos creados"
    do{
        printf("\nSeleccione un evento de %i/%i: ", a, b);
        scanf("%d", &seleccion);
        system("cls");

    }while(seleccion<0 || seleccion>a);
    return seleccion;
}
void menu_boletos(int EventoSeleccionado, int asientos_total, int total_eventos, int maximo_eventos, evento un_evento[]){
    status("\n\t\tEventos: operativo\n");
    //e[a-1] se coloca de esta manera ya que seleccion comienza desde 1-max_eventos en lugar de 
		//empezar por 0 que es por donde comienzan los vectores
    printf("\nSu seleccion fue el evento: [%i] Nombre: %s!\n", EventoSeleccionado, un_evento[EventoSeleccionado-1].nombre);
    int opcion;
    //d = max_eventos (que permite la empresa)
    boleto BoletoVendido[asientos_total];
    //todo lo interno de un evento (ventas, tiempo, asientos disponibles, etc.)

    printf("\nTotal de entradas actuales %d \n", asientos_total);
    while (opcion!=4)
    {
        printf("\nVenta de Entradas! ¿Que accion va a realizar?\n");

        printf("1. Vender un boleto\n");
        printf("2. Cancelar la venta de un boleto\n");
        printf("3. Listar boletos\n");
        printf("4. Volver\n");
        printf("Ingrese una opcion: ");
        scanf("%d", &opcion);

        printf("\n*________________________________________________________________________________________________________*");

   	 	switch(opcion)
   	 	{
    		    case 1:
                BoletoVendido[EventoSeleccionado]=VenderBoletos(EventoSeleccionado,asientos_total, un_evento);
                EventoSeleccionado++;   //se vendio un boleto
                    break;
     	  	 case 2:
                //modificar();
                    break;
       		 case 3:
                ListarInformacionBoleto(EventoSeleccionado, asientos_total, BoletoVendido);
                    break;
       		 case 4:
           			system("cls");
                    break;
       		 default:
                printf("Opcion incorrecta\n");
                    break;
   	 	}
    }
}
boleto VenderBoletos(int EventoSeleccionado, int asientos_total, evento un_evento[]){
    boleto DatosBoleto;
    /*
    char tipo_entrada;
    int asiento;
    char hora_vta[constante];
    char fecha_vta[constante];
    float precio;
    char nombre_casa_venta[constante];
    char evento[constante];    
    */
    printf("\n\n*******CARGA DE BOLETO*******");

    printf("\nIngrese el tipo de entrada: ");
    scanf("%s", DatosBoleto.tipo_entrada);

    printf("\nIngrese el numero de asiento del boleto: ");
    scanf("%d", &DatosBoleto.asiento);

    printf("\nIngrese el precio del boleto: ");
    scanf("%f", &DatosBoleto.precio);

    //obtencion de fecha/hora
    time_t t;
    t = time(NULL);
    struct tm informacion = *localtime(&t);
    DatosBoleto.fecha_vta[informacion.tm_mday, informacion.tm_mon+1, informacion.tm_year+1900]; 
    DatosBoleto.hora_vta[informacion.tm_hour, informacion.tm_min, informacion.tm_sec];
    
    strcpy(DatosBoleto.evento, un_evento[EventoSeleccionado - 1].nombre);
    //DatosBoleto[EventoSeleccionado].evento = un_evento[EventoSeleccionado].nombre;

    printf("\nIngrese el nombre de Casa de Venta");
    scanf("%s", DatosBoleto.nombre_casa_venta);

    return DatosBoleto;
}
void ListarInformacionBoleto(int EventoSeleccionado, int asientos_total, boleto BoletoVendido[]){
    system("cls");

    printf("\nListado de boletos vendidos:\n");
    for (int i = 1; i < EventoSeleccionado; i++){
        printf("Boleto #%d\n", i);
        printf("Tipo de entrada: %s\n", BoletoVendido[i].tipo_entrada);
        printf("Número de asiento: %d\n", BoletoVendido[i].asiento);
        printf("Hora de venta: %s\n", BoletoVendido[i].hora_vta);
        printf("Fecha de venta: %s\n", BoletoVendido[i].fecha_vta);
        printf("Precio: %.2f\n", BoletoVendido[i].precio);
        printf("Casa de venta: %s\n", BoletoVendido[i].nombre_casa_venta);
        printf("Evento: %s\n", BoletoVendido[i].evento);
        printf("\n");
    }
   printf("\n");    
    /*
    char tipo_entrada;
    int asiento;
    char hora_vta[constante];
    char fecha_vta[constante];
    float precio;
    char nombre_casa_venta[constante];
    char evento[constante];    
    
    */
}




