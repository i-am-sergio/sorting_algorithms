#include <iostream>
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

void PrintVector(const std::vector<int>& A){
    for(int i=0; i<A.size(); i++)
        std::cout<<A[i]<<" ";
}

std::ostream& operator<<(std::ostream& os, const std::vector<int>& A) {
    PrintVector(A);
    return os;
}

int main(){
    std::vector<int> vector1 = {5, 1, 4, 11, 18, 9, 13, 15, 3, 7};
    std::cout<<vector1<<"\n";
    BubbleSort(vector1);
    std::cout<<vector1<<"\n";
    return 0;
}