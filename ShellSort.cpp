#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include "Utilidades.h"

void ShellSort(std::vector<int>& A, int n) {
    // El gap (espaciado) se refiere al espacio entre los elementos que se comparan
    // Iniciar con un espacio grande, reduciendo progresivamente el espacio
    for (int gap = n / 2; gap > 0; gap /= 2) {
        // Realizar una ordenación por inserción con espaciado
        // Los primeros elementos, A[0] hasta A[gap-1], 
        // ya están en orden con el espaciado actual.
        // Agregar un elemento hasta que todo el array esté ordenado con el gap actual
        for (int i = gap; i < n; i += 1) {
            // Agregar A[i] a los elementos que ya han sido ordenados con el gap actual.
            // Guardar A[i] en temp y crear un hueco en la posición i.
            int temp = A[i];
            // Desplazar hacia arriba los elementos previamente ordenados con el gap actual
            // hasta encontrar la ubicación correcta para A[i].
            int j;
            for (j = i; j >= gap && A[j - gap] > temp; j -= gap)
                A[j] = A[j - gap];

            // Colocar temp en su ubicación correcta
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