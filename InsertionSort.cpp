#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include "Utilidades.h"

void InsertionSort(std::vector<int>& A){
    int i, j, current, size = A.size();
    for ( i=1; i<size; i++){
        current = A[i];
        j = i - 1;
        while(j>=0 && A[j]>current){
            A[j+1] = A[j];
            j -= 1;
        }
        A[j+1] = current;
    }
}

void ShowInTerminal(std::vector<int>& vector){
    std::cout<<vector<<"\n";
    InsertionSort(vector);
    std::cout<<vector<<"\n";
}
void ShowInFile(std::vector<int>& vector){
    std::ofstream archivo("output.txt");
    if (archivo.is_open()) {
        archivo << vector << "\n\n";
        InsertionSort(vector);
        archivo << vector;
        archivo.close();
        std::cout << "Se ha guardado en 'output.txt'...\n";
    } else {
        std::cerr << "No se pudo abrir el archivo para escribir\n";
    }
}

int main(){
    std::vector<int> vector1 = {5, 1, 4, 11, 18, 9,100, 13, 15, 3, 7};
    // ShowInTerminal(vector1);
    ShowInFile(vector1);
    return 0;
}