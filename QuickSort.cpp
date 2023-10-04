#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include "Utilidades.h"

int particion(std::vector<int>& A, int bajo, int alto) {
    int pivot = A[alto]; // Elegir el pivote
    // Índice del elemento más pequeño y que indica
    // la posición correcta del pivote encontrada hasta ele momento
    int i = (bajo - 1);

    for (int j = bajo; j <= alto - 1; j++) {
        // Si el elemento actual es menor que el pivote
        if (A[j] < pivot) {
            // Se incrementa el indice del elemento más pequeño
            i++;
            std::swap(A[i], A[j]);
        }
    }

    std::swap(A[i + 1], A[alto]);
    return (i + 1);
}
 
void MyQuickSort(std::vector<int>& A, int bajo, int alto)
{
    if (bajo < alto) {
        // pi es el índice de partición, A[p] está ahora en el lugar correcto
        int pivote = particion(A, bajo, alto);
        // Ordenar por separado los elementos antes y despues de la particion
        MyQuickSort(A, bajo, pivote - 1);
        MyQuickSort(A, pivote + 1, alto);
    }
}
 

void QuickSort(std::vector<int>& A, int n){
    MyQuickSort(A, 0, n - 1);
}


void ShowInTerminal(std::vector<int>& vector){
    std::cout<<vector<<"\n";
    QuickSort(vector,vector.size());
    std::cout<<vector<<"\n";
}
void ShowInFile(std::vector<int>& vector){
    std::ofstream archivo("output.txt");
    if (archivo.is_open()) {
        archivo << vector << "\n\n";
        QuickSort(vector,vector.size());
        archivo << vector;
        archivo.close();
        std::cout << "Se ha guardado en 'output.txt'...\n";
    } else {
        std::cerr << "No se pudo abrir el archivo para escribir\n";
    }
}

int main(){
    std::vector<int> vector1 = {5, 1, 4, 55, 180, 9,100, 13, 15, 3, 7};
    ShowInTerminal(vector1);
    // ShowInFile(vector1);
    return 0;
}