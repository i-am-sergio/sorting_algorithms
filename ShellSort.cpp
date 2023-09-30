#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include "Utilidades.h"

void ShellSort(std::vector<int>& A, int n){
    // Comenzar con un espacio grande, luego ir reduciendo el espacio
    for (int gap = n / 2; gap > 0; gap /= 2)
    {
        // Realizar una ordenación por inserción con espaciado para este tamaño de espacio.
        // Los primeros elementos gap a[0..gap-1] ya están en orden con espaciado.
        // Agregar un elemento más hasta que todo A esté ordenado con espaciado.
        for (int i = gap; i < n; i += 1)
        {
            // Agregar A[i] a los elementos que ya han sido ordenados con espaciado
            // Guardar A[i] en temp y crear un hueco en la posición i
            int temp = A[i];

            // Desplazar hacia arriba los elementos previamente ordenados con espaciado
            // hasta encontrar la ubicación correcta para A[i]
            int j;
            for (j = i; j >= gap && A[j - gap] > temp; j -= gap)
                A[j] = A[j - gap];

            // Poner temp (el valor original de A[i]) en su ubicación correcta
            A[j] = temp;
        }
    }
}


void ShowInTerminal(std::vector<int>& vector){
    std::cout<<vector<<"\n";
    ShellSort(vector,vector.size());
    std::cout<<vector<<"\n";
}
void ShowInFile(std::vector<int>& vector){
    std::ofstream archivo("output.txt");
    if (archivo.is_open()) {
        archivo << vector << "\n\n";
        ShellSort(vector,vector.size());
        archivo << vector;
        archivo.close();
        std::cout << "Se ha guardado en 'output.txt'...\n";
    } else {
        std::cerr << "No se pudo abrir el archivo para escribir\n";
    }
}

int main(){
    std::vector<int> vector1 = {5, 1, 4, 55, 18, 9,100, 13, 15, 3, 7};
    ShowInTerminal(vector1);
    // ShowInFile(vector1);
    return 0;
}