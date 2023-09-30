#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include "Utilidades.h"

void BubbleSort(std::vector<int>& A, int n){
    bool intercambio; // swap
    for (int i = 0; i < n-1; i++) {
        intercambio = false;
        for (int j = 0; j < n-i-1; j++) {
            if (A[j] > A[j + 1]) {
                std::swap(A[j], A[j + 1]);
                intercambio = true;
            }
        }
        if (intercambio == false)
            break;
    }    
}

void ShowInTerminal(std::vector<int>& vector){
    std::cout<<vector<<"\n";
    BubbleSort(vector, vector.size());
    std::cout<<vector<<"\n";
}
void ShowInFile(std::vector<int>& vector){
    std::ofstream archivo("output.txt");
    if (archivo.is_open()) {
        archivo << vector << "\n\n";
        BubbleSort(vector, vector.size());
        archivo << vector;
        archivo.close();
        std::cout << "La salida se ha guardado en 'output.txt'...\n";
    } else {
        std::cerr << "No se pudo abrir el archivo para escribir\n";
    }

}

int main(){
    std::vector<int> vector1 = {5, 1, 4, 11, 18, 9, 13, 15, 3, 7};
    ShowInTerminal(vector1);
    // ShowInFile(vector1);
    return 0;
}