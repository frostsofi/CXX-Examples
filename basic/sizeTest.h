#include <iostream>

namespace SizeTestName {
    class Basic {
        void Foo() {}
    };

    class Derived : public Basic {
        void Foo() {}
        int x = 42;
    };

    class BasicPolymorphic {
        virtual void Foo() {}
    };

    class DerivedPolymorphic : public BasicPolymorphic {
        virtual void Foo() override {}
        int x = 42;
    };
}

struct Empty {

};

struct PersonInfo {
    int age; // 8
    double weight; // 8
    int id; //4
}; // 24

struct PersonInfoOptimal {
    int age; // 4
    int id; //4
    double weight; // 8
}; // 16

struct alignas(16) PersonInfoOptimalAlignas {
    int age;
    int id;
    double weight;
};

void SizeTest() 
{
    int x = 45;
    int* pX = &x;
    int& rX = x;

    std::cout << sizeof(pX) << std::endl;

    // sizeof of ref and underlying type
    // is always the same
    if (sizeof(rX) == sizeof(x)) {
        std::cout << "The sizeof ref and underlying type is the same !" << std::endl;
    }

    constexpr size_t arrSize = 4;
    int arr[arrSize]{2,3,1,2};
    if (sizeof(arr) == arrSize*sizeof(int)) {
        std::cout << sizeof(arr) << std::endl;
        std::cout << "The sizeof of array the same as elements count multiply on underlying type !" << std::endl;
    }

    Empty newStruct;
    std::cout << sizeof(newStruct) << std::endl;

    PersonInfo info1{22, 87, 10};
    std::cout << alignof(info1) << std::endl;
    std::cout << sizeof(info1) << std::endl;

    PersonInfoOptimal info2{22, 87, 10};
    std::cout << alignof(info2) << std::endl;
    std::cout << sizeof(info2) << std::endl;

    PersonInfoOptimalAlignas info3{22, 87, 10};
    std::cout << alignof(info3) << std::endl;
    std::cout << sizeof(info3) << std::endl;

    alignas(8) int xx = 24;
    std::cout << alignof(xx) << std::endl;
    std::cout << sizeof(xx) << std::endl;

    SizeTestName::Basic* pBasic1 = new SizeTestName::Basic();
    SizeTestName::Basic* pBasic2 = new SizeTestName::Derived();
    std::cout << sizeof(*pBasic1) << std::endl;
    std::cout << sizeof(*pBasic2) << std::endl;

    delete pBasic1;
    delete pBasic2;

    SizeTestName::BasicPolymorphic* pPolyBasic1 = new SizeTestName::BasicPolymorphic();
    SizeTestName::BasicPolymorphic* pPolyBasic2 = new SizeTestName::DerivedPolymorphic();
    std::cout << sizeof(*pPolyBasic1) << std::endl;
    std::cout << sizeof(*pPolyBasic2) << std::endl;
}
