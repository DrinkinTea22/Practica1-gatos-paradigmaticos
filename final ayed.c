#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#define dimension 50

typedef struct{
    char nombre[50];
    int telefono;
    char direccion[50];
}agenda;

//prototipo funciones
int numcrearcontacto(void);
agenda cargaragenda(int a);
void imprimiragenda(int a, agenda b[]);
int numborrarcontacto(int a);

int main()
{
    agenda contactos[dimension];
    
    int c;
    int i=0, acumulador=0;
    int flag;
    do{
        printf("\ncontactos creados: %d de %d", i, dimension);
        printf("\n+para crear contactos presione 1\n+para borrar contactos presione 2\n+para mostrar contactos presione 3\n+presione 4 para cerrar sesion\n\nseleccion: ");
        scanf("%d", &flag);
        if(flag==1){
            c=numcrearcontacto();
            acumulador+=c;
            
            for(i; i<acumulador;i++){
            contactos[i] = cargaragenda(i);
            }
        }
        if(flag==2){
            
            //prevenir la eliminacion de (nada)
            if(c==0 || i==0){
                printf("no se han encontrado contactos para borrar!");
                system("cls");      //limpiar consola(windows/dos)
                system("clear");    //limpiar consola(linux)
                goto *main();       //reiniciar
            }
            
            int c=numborrarcontacto(acumulador);
            
            for(int i=c-1; i<=acumulador;i++){
                contactos[i] = contactos[i+1];
            }
            //pena mental
            acumulador--;
            c--;
            i--;
            if(acumulador<=0)
            acumulador=0;
            if(c<=0)
            c=0;
            if(i<=0)
            i=0;
            //pena mental            
        }
        if(flag==3 && i>0){     //prevenir que muestre contactos inexistentes
            imprimiragenda(i, contactos);
        }
        if(flag==3 && i==0){
            printf("aun no hay contactos en la agenda!");
            system("cls");      //limpiar consola(windows/dos)
            system("clear");    //limpiar consola(linux)
            goto *main();       //reiniciar
        }
    }while(flag!=4);
    

    return 0;
}

//declarar funciones
int numcrearcontacto(void){
    int i;
    do{
        printf("\ningrese la cantidad de contactos que quiera crear: ");
        scanf("%d", &i);
    }while(i<1);    //prevenir valores menores a 1, no tendría sentido
    return i;
}

agenda cargaragenda(int a){
    agenda datos;
    printf("\ningrese el nombre del contacto[%d]: ", a+1);
    scanf("%s", datos.nombre);
    printf("\ningrese el numero de telefono del contacto[%d]: ", a+1);
    scanf("%d", &datos.telefono);
    printf("\ningrese la direccion del contacto[%d]: ", a+1);
    scanf("%s", datos.direccion);
    
    return datos;
}

void imprimiragenda(int a, agenda b[]){
    int N=a;

    for(int i=0; i<N;i++){
        printf("\n#contacto numero %d\n|nombre\t\t|numero\t\t|direccion", i+1);
        
        printf("\n|%s\t\t|", b[i].nombre);
        printf("%d\t\t|", b[i].telefono);
        printf("%s\n", b[i].direccion);
    }
}
int numborrarcontacto(int a){
    int borrar;
    int str = (a/a);
    if(a==0)
    str=0;
    do{
        if(a==1)
        printf("contacto %d es el unico disponible: ", a);
        else
        printf("ingrese el numero del contacto a borrar desde %d hasta %d: ", str, a);
        
        scanf("%d", &borrar);
    }while(borrar>a || borrar<0);
    return borrar;
}