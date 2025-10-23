#include <vector>
#include <concepts>

template <typename T> 
requires std::unsigned_integral<T>
using Indexes = std::vector<T>;

using TextUnit = std::string;

int UsingTest() 
{

    // Test template using constraint
    Indexes<unsigned int> a;
    // Indexes<int> b;

    TextUnit header = "News";
}
