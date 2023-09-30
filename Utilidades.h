#pragma once

#include <iostream>
#include <vector>

void PrintVector(const std::vector<int>& A, std::ostream& os = std::cout){
    for(int i=0; i<A.size(); i++)
        os << A[i] <<" ";
}

std::ostream& operator<<(std::ostream& os, const std::vector<int>& A) {
    PrintVector(A, os);
    return os;
}