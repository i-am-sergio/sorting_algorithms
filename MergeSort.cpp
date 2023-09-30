#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include "Utilidades.h"

void Merge(std::vector<int>& myArray, int inicio, int medio, int fin) {
    int sizeIzq = medio - inicio + 1;
    int sizeDer = fin - medio;
    int* subArrayIzq = new int[sizeIzq];
    int* subArrayDer = new int[sizeDer];
    
    for (int i = 0; i < sizeIzq; i++)
        subArrayIzq[i] = myArray[inicio + i];
    for (int j = 0; j < sizeDer; j++)
        subArrayDer[j] = myArray[medio + 1 + j];

    int i = 0, j = 0, k = inicio;
    
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
    
    while (i < sizeIzq) { // Copia los elementos restantes del subArrayIzq
        myArray[k] = subArrayIzq[i];
        i++; 
        k++;
    }
    
    while (j < sizeDer) { // Copia los elementos restantes del subArrayDer
        myArray[k] = subArrayDer[j];
        j++; 
        k++;
    }
    
    delete[] subArrayIzq;
    delete[] subArrayDer;
}


void MyMergeSort(std::vector<int>& A, int inicio, int fin){
    if(inicio < fin){
        int medio = (inicio + fin) / 2; // Dividimos por la mitad
        MyMergeSort(A, inicio, medio);
        MyMergeSort(A, medio+1, fin);
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