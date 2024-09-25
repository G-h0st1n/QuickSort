#include <iostream>
using namespace std;

// Función para intercambiar dos elementos
void swap(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}

// Función para particionar el array
int partition(int arr[], int low, int high) {
    int pivot = arr[high]; // Seleccionar el ultimo elemento
    int i = (low - 1); // iondice mas pequeño

    for (int j = low; j <= high - 1; j++) {

        if (arr[j] <= pivot) {
            i++; // incrementar indice del mas pequeño
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return (i + 1);
}

// Función principal de Quick Sort
void quickSort(int arr[], int low, int high) {
    if (low < high) {

        int pi = partition(arr, low, high);


        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

// Función para imprimir el array
void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++)
        cout << arr[i] << " ";
    cout << endl;
}


int main() {
    int arr[] = {10, 7, 8, 9, 1, 5};
    int n = sizeof(arr) / sizeof(arr[0]);
    quickSort(arr, 0, n - 1);
    cout << "Array ordenado: \n";
    printArray(arr, n);
    return 0;
}
