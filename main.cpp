#include <iostream>

void TestValueType(const std::string& iString) {
    std::cout << "Lvalue reference" << std::endl;
}

void TestValueType(const std::string&& iString) {
    std::cout << "Rvalue reference" << std::endl;
}

enum Color {
    Orange,
    Yellow
};

 enum Fruit {
   //Orange,
   Apple
};

enum class ColorType {
    Orange,
    Yellow
};

enum class FruitType {
   Orange,
   Apple
};

enum class DeviceType : char {
   Phone = 10,
   // Laptop = 300
};

int main() 
{

    // Expression types
    TestValueType("Hello!");
    std::string test = "Hello!";
    TestValueType(test);
    TestValueType(std::move(test));

    // Enum 
    Color curColor = Color::Orange;
    if (curColor == Fruit::Apple) {
        std::cout << "Enum problem with implicit comparison !" << std::endl;
    }

    ColorType color = ColorType::Orange;
    FruitType fruit = FruitType::Orange;

    //if (color == fruit) {
    //    std::cout << "Enum problem with implicit comparison !" << std::endl;
    //}

    return 0;
}