#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include "Utilidades.h"

void SelectionSort(std::vector<int>& A){
    int n = A.size();
    int indiceMin; // Indice del elemento minimo

    // Iterar en la submatriz no ordenada
    for (int i = 0; i < n - 1; i++) {
        // Encontrar el elemento mínimo en la submatriz no ordenada
        indiceMin = i; // Suponemos que el elemento actual es el mínimo
        for (int j = i + 1; j < n; j++) {
            if (A[j] < A[indiceMin])
                indiceMin = j; // Actualizar el indice del minimo si encontramos un elemento menor
        }
        // Intercambiar el elemento minimo encontrado con el primer elemento no ordenado
        if (indiceMin != i)
            std::swap(A[indiceMin], A[i]);
    }
}

void ShowInTerminal(std::vector<int>& vector){
    std::cout<<vector<<"\n";
    SelectionSort(vector);
    std::cout<<vector<<"\n";
}
void ShowInFile(std::vector<int>& vector){
    std::ofstream archivo("output.txt");
    if (archivo.is_open()) {
        archivo << vector << "\n\n";
        SelectionSort(vector);
        archivo << vector;
        archivo.close();
        std::cout << "La salida se ha guardado en 'output.txt'...\n";
    } else {
        std::cerr << "No se pudo abrir el archivo para escribir\n";
    }

}

int main(){
    std::vector<int> vector1 = {5, 1, 4, 44, 18, 9, 13, 15, 3, 7};
    ShowInTerminal(vector1);
    // ShowInFile(vector1);
    return 0;
}