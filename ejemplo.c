#include <stdio.h>

struct animal {
    char especie[20];
    char raza[20];
    char nombre[20];
    float peso;
    int altura;
    char propietario[50];
};

function animal cargar(char especie[20], char raza[20], char nombre[20], float peso, int altura, char propietario[50]);

fuction void modificar(animal a);

fuction animal[] listarAnimales();

function void menu();

int main(){



}

function void menu(){
    int opcion;
    printf("1. Cargar animal\n");
    printf("2. Modificar animal\n");
    printf("3. Listar animales\n");
    printf("4. Salir\n");
    printf("Ingrese una opcion: ");
    scanf("%d", &opcion);
    switch(opcion){
        case 1:
            cargar();
            break;
        case 2:
            modificar();
            break;
        case 3:
            listarAnimales();
            break;
        case 4:
            break;
        default:
            printf("Opcion incorrecta\n");
            break;
    }
}

