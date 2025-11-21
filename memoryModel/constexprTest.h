#include <string>
#include <iostream>
#include <random>

constexpr int GetArrSize(int sizeOfRow) {
    return sizeOfRow * 2;
}

int GetArrSizeRandom() {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> distrib(1, 6);
    return distrib(gen);
}

struct Client {
    int id;
    int cardNumber;
};

class Shop {
public:
    constexpr Shop() : id(5), typeOfProducts{1,2,2,2,3}
    {}

    constexpr int GetId() const {
        return id;
    }

    // since c++20 we can use constrexpr std::string version
    // and have virtual constexpr method
    constexpr virtual std::string GetName() const {
        return "Cacao";
    }

   constexpr ~Shop() {}

private:
    int id;
    int typeOfProducts[5];
    // std::stack<int> values; non literal type 
};

void ConstexprTest() 
{
    constexpr int matrix[GetArrSize(2)] = {1,0,0,1};

    // test constexpr function with non constexpr params
    int randomArrSize = GetArrSize(GetArrSizeRandom());

    //constexpr int matrix[GetArrSizeRandom()];
    constexpr Client cl{2, 330};
    constexpr Shop shop;
    constexpr int shopId = shop.GetId();
    // constexpr auto [id, cardNumber] = cl; only with CXX 26 compiler support
}