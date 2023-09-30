#include <iostream>
#include <vector>

template<typename T>
void InsertionSort(std::vector<T>& V){
    
}

template<typename T>
void PrintVector(std::vector<T>& V){
    for(int i=0; i<V.size(); i++)
        std::cout<<V[i]<<" ";
}

int main(){
    std::vector<int> vector1 = {5, 1, 4, 11, 5, 9, 2, 6, 15, 3, 7};
    PrintVector(vector1);
    return 0;
}