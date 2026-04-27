//Algoritmo voraces: "Kruskal"

#include <stdio.h>

#define MAX 300  

struct Arista {
    int origen;
    int destino;
    int peso;
};

int padre[100];

void crearConjuntos(int n) {
    for (int i = 0; i < n; i++) padre[i] = i;
}

int encontrar(int v) {
    if (padre[v] == v) return v;
    return padre[v] = encontrar(padre[v]);
}

void unir(int a, int b) {
    a = encontrar(a);
    b = encontrar(b);
    if (a != b) padre[b] = a;
}

void ordenarAristas(struct Arista aristas[], int cantidad) {
    for (int i = 0; i < cantidad - 1; i++) {
        for (int j = 0; j < cantidad - i - 1; j++) {
            if (aristas[j].peso > aristas[j+1].peso) {
                struct Arista temp = aristas[j];
                aristas[j] = aristas[j+1];
                aristas[j+1] = temp;
            }
        }
    }
}

void kruskal(struct Arista aristas[], int vertices, int cantidad) {
    crearConjuntos(vertices);
    ordenarAristas(aristas, cantidad);

    int pesoTotal = 0;
    printf("\n\nAristas seleccionadas:\n");

    for (int i = 0; i < cantidad; i++) {
        int u = aristas[i].origen;
        int v = aristas[i].destino;
        int w = aristas[i].peso;

        if (encontrar(u) != encontrar(v)) {
            printf("%d ----- %d = %d\n", u, v, w);
            pesoTotal += w;
            unir(u, v);
        }
    }

    printf("Peso total: %d\n", pesoTotal);
}

int main() {
    int vertices = 20;   // casas
    int cantidad = 33; //aristas

    struct Arista aristas[MAX] = {
        {0, 1, 100}, {0, 3, 85}, {0, 3, 30}, {1, 2, 100},
        {1, 4, 40}, {1, 5, 45}, {1, 6, 70}, {2, 6, 55},
        {2, 7, 60}, {3, 15, 50}, {4, 8, 10}, {5, 9, 55},
        {6, 10, 15}, {6, 11, 20}, {7, 11, 40}, {7, 13, 85},
        {7, 14, 70}, {8, 9, 60}, {8, 15, 90}, {9, 10, 80},
        {9, 16, 45}, {10, 12, 60}, {11, 12, 50}, {12, 18, 2},
        {13, 14, 120}, {13, 14, 105}, {13, 18, 55}, {13, 19, 60},
        {14, 19, 195}, {15, 17, 205}, {16, 17, 5}, {17, 19, 230},
        {18, 19, 25}
    };
    
    printf("\nAlgoritmo voraces: Kruskal\n");
    
    kruskal(aristas, vertices, cantidad);

    return 0;
}