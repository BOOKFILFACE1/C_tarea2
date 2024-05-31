#include <emscripten.h>
#include <stdio.h>
#include <stdlib.h>

// Búsqueda Secuencial
EMSCRIPTEN_KEEPALIVE
int busqueda_secuencial(int* arr, int n, int x) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == x) return i;
    }
    return -1;
}

// Búsqueda Binaria (requiere que el arreglo esté ordenado)
EMSCRIPTEN_KEEPALIVE
int busqueda_binaria(int* arr, int n, int x) {
    int low = 0, high = n - 1;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (arr[mid] == x) return mid;
        if (arr[mid] < x) low = mid + 1;
        else high = mid - 1;
    }
    return -1;
}

// Algoritmo de Ordenamiento de la Burbuja
EMSCRIPTEN_KEEPALIVE
void ordenamiento_burbuja(int* arr, int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

// Quick Sort
void quickSort(int* arr, int low, int high);

int partition(int* arr, int low, int high) {
    int pivot = arr[high];
    int i = (low - 1);
    for (int j = low; j <= high - 1; j++) {
        if (arr[j] < pivot) {
            i++;
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }
    int temp = arr[i + 1];
    arr[i + 1] = arr[high];
    arr[high] = temp;
    return (i + 1);
}

void quickSort(int* arr, int low, int high) {
    if (low < high) {
        int pivot = partition(arr, low, high);
        quickSort(arr, low, pivot - 1);
        quickSort(arr, pivot + 1, high);
    }
}

// Método de Inserción
EMSCRIPTEN_KEEPALIVE
void insertionSort(int* arr, int n) {
    int i, key, j;
    for (i = 1; i < n; i++) {
        key = arr[i];
        j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

// Función para obtener una copia del arreglo
EMSCRIPTEN_KEEPALIVE
int* obtener_copia(int* arr, int n) {
    int* copia = (int*) malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        copia[i] = arr[i];
    }
    return copia;
}
















