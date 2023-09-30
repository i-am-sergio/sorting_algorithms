#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>


void BubbleSort(std::vector<int>& A){
    int n = A.size();
    bool swapped;
    for (int i = 0; i < n - 1; i++) {
        swapped = false;
        for (int j = 0; j < n - i - 1; j++) {
            if (A[j] > A[j + 1]) {
                std::swap(A[j], A[j + 1]);
                swapped = true;
            }
        }
        if (swapped == false)
            break;
    }    
}

void PrintVector(const std::vector<int>& A, std::ostream& os = std::cout){
    for(int i=0; i<A.size(); i++)
        os << A[i] <<" ";
}

std::ostream& operator<<(std::ostream& os, const std::vector<int>& A) {
    PrintVector(A, os);
    return os;
}

void ShowInTerminal(std::vector<int>& vector){
    std::cout<<vector<<"\n";
    BubbleSort(vector);
    std::cout<<vector<<"\n";
}
void ShowInFile(std::vector<int>& vector){
    std::ofstream archivo("output.txt");
    if (archivo.is_open()) {
        archivo << vector << "\n\n";
        BubbleSort(vector);
        archivo << vector;
        archivo.close();
        std::cout << "La salida se ha guardado en 'output.txt'.\n";
    } else {
        std::cerr << "No se pudo abrir el archivo para escribir.\n";
    }

}

int main(){
    std::vector<int> vector1 = {5, 1, 4, 11, 18, 9, 13, 15, 3, 7};
    ShowInTerminal(vector1);
    // ShowInFile(vector1);
    return 0;
}