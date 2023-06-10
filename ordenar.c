/* 
Evaluación para Programación No Numérica II 
I.U.P "Santiago Mariño" extensión Maracay

Algoritmos:
Fisher-Yates
Gnome Sort or Stupid Sort
Bubble Sort
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX 10
#define AZUL    "\e[104m"
#define MAGENTA "\e[105m"
#define RESET   "\e[0m"

void mezclar(int a[]) {
    int i, j, t;
    for (i = 0; i < MAX; i = i + 1) {
        a[i] = i;
    }
    for (i = MAX - 1; i > 0; i = i - 1) {
        j = rand() % (i + 1);
        t = a[j];
        a[j] = a[i];
        a[i] = t;
    }
}

void mostrar_color(const int a[]) {
    int i;
    for (i = 0; i < MAX; i = i + 1) {
        printf("%s%02d%s%s", (i < 1 || *(i + a) >= *(i - 1 + a)) ? AZUL : MAGENTA, a[i], RESET, (i < (MAX - 1)) ? "," : "");
    }
    printf("\n");
}

void gnome_sort(int a[], int n) {
    int i = 0;
    
    while (i < n) {
        if (i == 0 || a[i] >= a[i - 1]) {
            i++;
        } else {
            int temp = a[i];
            a[i] = a[i - 1];
            a[i - 1] = temp;
            i--;
        }
    }
}

void burbuja(int a[], int n) {
    int i, j;
    
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (a[j] > a[j + 1]) {
                int temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
            }
        }
    }
}

int main() {
    int lista[MAX];
    srand(time(0));
    mezclar(lista);
    
    printf("Lista original:\n");
    mostrar_color(lista);
    
    printf("\n--- Gnome Sort ---\n");
    gnome_sort(lista, MAX);
    printf("Lista ordenada con Gnome Sort:\n");
    mostrar_color(lista);
    
    printf("\n--- Bubble Sort ---\n");
    mezclar(lista); // Re-shuffle the array
    burbuja(lista, MAX);
    printf("Lista ordenada con Bubble Sort:\n");
    mostrar_color(lista);
    
    return 0;
}