#include <iostream>

// Test enum values scop
// of enum and enum class
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

// Test value which is over
// then underlying type

enum class DeviceType : char {
   Phone = 10,
   // Laptop = 300
};

void EnumTest() 
{

    // This example shows difference between enum and enum class
    // implicit conversion to int type

    Color curColor = Color::Orange;
    if (curColor == Fruit::Apple) {
        std::cout << "Enum problem with implicit comparison !" << std::endl;
    }

    ColorType color = ColorType::Orange;
    FruitType fruit = FruitType::Orange;

    //if (color == fruit) {
    //    std::cout << "Enum problem with implicit comparison !" << std::endl;
    //}

}
