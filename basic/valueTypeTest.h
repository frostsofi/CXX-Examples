#include <string>
#include <iostream>

void TestValueType(const std::string& iString) {
    std::cout << "Lvalue reference" << std::endl;
}

void TestValueType(const std::string&& iString) {
    std::cout << "Rvalue reference" << std::endl;
}

void ValueTypeTest() 
{
    TestValueType("Hello!");
    std::string test = "Hello!";
    TestValueType(test);
    TestValueType(std::move(test));

}