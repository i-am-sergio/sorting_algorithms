#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include "Utilidades.h"

// Función auxiliar para fusionar dos subarray ordenados
// - myArray: el array original que se está ordenando
// - inicio: indice de inicio del subarray izquierdo
// - medio: indice final del subarray izquierdo, medio+1 indica el inicio del subarray derecho
// - fin: indice final del subarray derecho
void Merge(std::vector<int>& myArray, int inicio, int medio, int fin) {
    // Calcular tamaños de los subarray
    int sizeIzq = medio - inicio + 1;
    int sizeDer = fin - medio;
    int* subArrayIzq = new int[sizeIzq];
    int* subArrayDer = new int[sizeDer];
    
    // Copiar datos a los subarrays temporales
    for (int i = 0; i < sizeIzq; i++)
        subArrayIzq[i] = myArray[inicio + i];
    for (int j = 0; j < sizeDer; j++)
        subArrayDer[j] = myArray[medio + 1 + j];

    // Inicializar indices para los subarray y el array principal
    int i = 0, j = 0, k = inicio;
    
    // Fusionar los dos subarray en el array principal
    while (i < sizeIzq && j < sizeDer) {
        if (subArrayIzq[i] <= subArrayDer[j]) {
            myArray[k] = subArrayIzq[i];
            i++;
        } else {
            myArray[k] = subArrayDer[j];
            j++;
        }
        k++;
    }
    // Copiar los elementos restantes del subarray izquierdo (si los hay)
    while (i < sizeIzq) {
        myArray[k] = subArrayIzq[i];
        i++; 
        k++;
    }
    // Copiar los elementos restantes del subarray derecho (si los hay)
    while (j < sizeDer) {
        myArray[k] = subArrayDer[j];
        j++; 
        k++;
    }
    // Liberar memoria de los subarrays temporales
    delete[] subArrayIzq;
    delete[] subArrayDer;
}

void MyMergeSort(std::vector<int>& A, int inicio, int fin){
    if(inicio < fin){
        int medio = (inicio + fin) / 2; // Dividimos por la mitad
        MyMergeSort(A, inicio, medio); // mitad izquierda 
        MyMergeSort(A, medio+1, fin); // mitad derecha
        Merge(A,inicio,medio,fin); // Mezcla las partes ordenadas
    }
}

void MergeSort(std::vector<int>& A, int n){
    MyMergeSort(A,0,n-1);
}

void ShowInTerminal(std::vector<int>& vector){
    std::cout<<vector<<"\n";
    MergeSort(vector,vector.size());
    std::cout<<vector<<"\n";
}
void ShowInFile(std::vector<int>& vector){
    std::ofstream archivo("output.txt");
    if (archivo.is_open()) {
        archivo << vector << "\n\n";
        MergeSort(vector,vector.size());
        archivo << vector;
        archivo.close();
        std::cout << "Se ha guardado en 'output.txt'...\n";
    } else {
        std::cerr << "No se pudo abrir el archivo para escribir\n";
    }
}

int main(){
    std::vector<int> vector1 = {59, 11, 41, 55, 18, 91,100, 13, 155, 3, 7};
    ShowInTerminal(vector1);
    // ShowInFile(vector1);
    return 0;
}