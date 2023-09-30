#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include "Utilidades.h"

// Función para convertir un subarbol en un heap
void heapify(std::vector<int>& A, int n, int i)
{
    int mayor = i;      // Inicializamos el indice del mayor como la raiz del subarbol
    int l = 2 * i + 1;   // Calculamos el indice del hijo izquierdo: left = 2 * i + 1
    int r = 2 * i + 2;   // Calculamos el indice del hijo derecho: right = 2 * i + 2

    if (l < n && A[l] > A[mayor]) // Si el hijo izquierdo es mayor que la raiz
        mayor = l;

    if (r < n && A[r] > A[mayor]) // Si el hijo derecho es mayor que el mayor actual
        mayor = r;

    if (mayor != i) { // Si el mayor no es la raiz
        std::swap(A[i], A[mayor]); // Intercambiamos el valor de la raiz con el mayor
        heapify(A, n, mayor);      // Llamamos recursivamente para asegurarnos de que el subarbol también sea un heap
    }
}


void HeapSort(std::vector<int>& A){
    int n = A.size();
    // Construir un heap (reorganizar el vector)
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(A, n, i);

    // Extraer elementos del heap uno por uno
    for (int i = n - 1; i > 0; i--) { 
        std::swap(A[0], A[i]); // Mueve el current root al final
        heapify(A, i, 0); // call max heapify on the reduced heap
    }
}

void ShowInTerminal(std::vector<int>& vector){
    std::cout<<vector<<"\n";
    HeapSort(vector);
    std::cout<<vector<<"\n";
}
void ShowInFile(std::vector<int>& vector){
    std::ofstream archivo("output.txt");
    if (archivo.is_open()) {
        archivo << vector << "\n\n";
        HeapSort(vector);
        archivo << vector;
        archivo.close();
        std::cout << "Se ha guardado en 'output.txt'...\n";
    } else {
        std::cerr << "No se pudo abrir el archivo para escribir\n";
    }
}

int main(){
    std::vector<int> vector1 = {5, 111, 4, 11, 18, 9,30, 13, 15, 3, 7};
    ShowInTerminal(vector1);
    // ShowInFile(vector1);
    return 0;
}