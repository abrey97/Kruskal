//Algoritmo voraces: "Kruskal"

#include <stdio.h>

#define MAX 200  // máximo de aristas

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
    printf("Aristas seleccionadas en el MST:\n");

    for (int i = 0; i < cantidad; i++) {
        int u = aristas[i].origen;
        int v = aristas[i].destino;
        int w = aristas[i].peso;

        if (encontrar(u) != encontrar(v)) {
            printf("%d -- %d == %d\n", u, v, w);
            pesoTotal += w;
            unir(u, v);
        }
    }

    printf("Peso total del MST: %d\n", pesoTotal);
}

int main() {
    int vertices = 20;   // casas A–T
    int cantidad = /* número de aristas */;

    struct Arista aristas[MAX] = {
        // Aquí debes meter las conexiones de tu mapa:
        // {origen, destino, peso}
        // Ejemplo:
        {0, 1, 10}, {0, 2, 6}, {0, 3, 5}, {1, 3, 15}, {2, 3, 4}
        // ...
    };

    kruskal(aristas, vertices, cantidad);

    return 0;
}
