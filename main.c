#include <stdio.h>

int main(void) {
    int option;
    do {
        printf("Bienvenido al menu\n");
        printf("1. Opcion 1\n");
        printf("2. Opcion 2\n");
        printf("3. Opcion 3\n");
        printf("4. Opcion 4\n");
        printf("5. Opcion 5\n");
        printf("6. Opcion 6\n");
        printf("7. Opcion 7\n");
        printf("8. Opcion 8\n");
        printf("9. Opcion 9\n");
        printf("0. Salir\n");
        printf("Seleccione una opcion: ");
        scanf("%d", &option);
        switch(option) {
            case 1:
                printf("Opcion 1\n");
                break;
            case 2:
                printf("Opcion 2\n");
                break;
            case 3:
                printf("Opcion 3\n");
                break;
            case 4:
                printf("Opcion 4\n");
                break;
            case 5:
                printf("Opcion 5\n");
                break;
            case 6:
                printf("Opcion 6\n");
                break;
            case 7:
                printf("Opcion 7\n");
                break;
            case 8:
                printf("Opcion 8\n");
                break;
            case 9:
                printf("Opcion 9\n");
                break;
            case 0:
                printf("Saliendo...\n");
                break;
            default:
                printf("Opcion no valida\n");
                break;
        }
    } while(option!=0);
    return 0;
}
