#include <string>
#include <iostream>

constexpr int GetArrSize(int sizeOfRow) {
    return sizeOfRow * 2;
}

struct Client {
    int id;
    int cardNumber;
};

void ConstexprTest() 
{
    constexpr int matrix[GetArrSize(2)] = {1,0,0,1};
    constexpr Client cl{2, 330};
    // constexpr auto [id, cardNumber] = cl; only with CXX 26 compiler support
}