#include <iostream>

class Basic {
    void Foo() {}
};

class Derived : public Basic {
    void Foo() {}
};

class BasicPolymorphic {
    virtual void Foo() {}
};

class DerivedPolymorphic : public BasicPolymorphic {
    virtual void Foo() override {}
};

int TypeidTest() 
{
    int x = 45;
    std::cout << typeid(x).name() << std::endl;

    const int& refX1 = x;
    std::cout << typeid(refX1).name() << std::endl;

    int const& refX2 = x;
    std::cout << typeid(refX2).name() << std::endl;

    const int* pX1 = &x;
    std::cout << typeid(pX1).name() << std::endl;

    int* const pX2 = &x;
    std::cout << typeid(pX2).name() << std::endl;

    Basic* pBasic1 = new Basic();
    Basic* pBasic2 = new Derived();
    std::cout << typeid(*pBasic1).name() << std::endl;
    std::cout << typeid(*pBasic2).name() << std::endl;

    delete pBasic1;
    delete pBasic2;

    BasicPolymorphic* pPolyBasic1 = new BasicPolymorphic();
    BasicPolymorphic* pPolyBasic2 = new DerivedPolymorphic();
    std::cout << typeid(*pPolyBasic1).name() << std::endl;
    std::cout << typeid(*pPolyBasic2).name() << std::endl;

    delete pPolyBasic1;
    delete pPolyBasic2;

    std::cout << typeid(*pBasic1).name() << std::endl;
    // std::cout << typeid(*pPolyBasic1).name() << std::endl; rte
}
