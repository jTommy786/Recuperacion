#include <stdio.h>
#include <string.h>

#define MAX_PELEADORES 6
#define MAX_NOMBRE 30

int main() {
    char peleadores[MAX_PELEADORES][MAX_NOMBRE];
    char finalistas[3][MAX_NOMBRE];
    int puntos[3];
    int opcion, ganador;

    do {
        printf("\nMenu:\n");
        printf("1. Ingresar peleadores\n");
        printf("2. Insertar resultados\n");
        printf("3. Mostrar finalistas\n");
        printf("4. Salir\n");
        printf("Seleccione una opcion: ");

        while (scanf("%d", &opcion) != 1 || opcion < 1 || opcion > 4) {
            printf("Entrada invalida. Intente nuevamente: ");
            while(getchar() != '\n'); // Limpiar el buffer de entrada
        }

        switch (opcion) {
            case 1:
                for (int i = 0; i < MAX_PELEADORES; i++) {
                    printf("Ingrese el nombre del boxeador %d: ", i + 1);
                    scanf("%s", peleadores[i]);
                }
                break;

            case 2:
                for (int i = 0; i < 3; i++) {
                    printf("\nCombate entre:\n");
                    printf("1. %s\n", peleadores[i * 2]);
                    printf("2. %s\n", peleadores[i * 2 + 1]);

                    printf("Seleccione el numero del ganador (1 o 2): ");
                    while (scanf("%d", &ganador) != 1 || ganador < 1 || ganador > 2) {
                        printf("Entrada invalida. Ingrese 1 o 2: ");
                        while(getchar() != '\n'); // Limpiar el buffer de entrada
                    }

                    strcpy(finalistas[i], peleadores[i * 2 + (ganador - 1)]);

                    printf("Ingrese los puntos obtenidos por %s: ", finalistas[i]);
                    while (scanf("%d", &puntos[i]) != 1 || puntos[i] < 0) {
                        printf("Entrada invalida. Ingrese un numero valido de puntos: ");
                        while(getchar() != '\n'); // Limpiar el buffer de entrada
                    }
                }
                break;

            case 3:
                int max1 = 0, max2 = 0, p2 = -1, p = -1;
                for (int i = 0; i < 3; i++) {
                    if (puntos[i] > max1) {
                        max2 = max1;
                        p = p2;
                        max1 = puntos[i];
                        p2 = i;
                    } else if (puntos[i] > max2) {
                        max2 = puntos[i];
                        p2 = i;
                    }
                }
                
                printf("\nFinalistas:\n");
                if (p2 != -1) {
                    printf("%s con %d puntos\n", finalistas[p2], puntos[p2]);
                }
                if (p != -1) {
                    printf("%s con %d puntos\n", finalistas[p], puntos[p]);
                }
                break;

            case 4:
                printf("Saliendo del programa...\n");
                break;
        }
    } while (opcion != 4);

    return 0;
}
